/*********************************************************/
/* Windows 95/98/NT/2000/XP sample experiment in C       */
/* For use with Version 2.0 of EyeLink Windows API       */
/*                                                       */
/*      (c) 1997-2002 by SR Research Ltd.                */
/* For non-commercial use by Eyelink licencees only      */
/*                                                       */
/* THIS FILE: w32_gcontrol_trial.c                       */
/* CONTENTS:                                             */
/* - end_trial(): blank display, stop recording          */
/*                cleans up, gives Windows time          */
/* - run_trial(): perfoems actual trial sequence:        */
/*     - drift correction (possible recalibration)       */
/*     - start recording                                 */
/*     - display stimulus to subject                     */
/*     - wait for data, select which eye's data to use   */
/*     - loop while looking for fixupdate events         */  
/*     - wait for timeout, button press, or abort        */
/*     - send result message to EDF file                 */
/*     - blank display, stop recording                   */
/*     - report any errors or reqest for repeat          */
/* - See documentation for more details                  */  
/*                                                       */
/*                                                       */
/* CHANGES FOR Windows 2000/XP, EyeLink 2.0:             */
/* - use w32_exptsppt2.h                                 */
/* - add realtime mode during entire display period      */
/* - display onset message refs retrace sync before draw */
/* - add wait_for_srawing() to rectangle invert          */
/* - use wait_for_block_start() to ensure data available */
/* - select eye to use at start of trial                 */
/* - eliminate getkey() for monitoring trial aborts      */
/* - add cleanup code after loop                         */
/* - Add 2000/XP realtime mode cleanup to end_trial()    */
/*                                                       */
/* CHANGES FOR Windows 2000/XP, EyeLink API 2.1:         */
/* - change delay numbers in messages to first item      */
/*********************************************************/

#include <windows.h>
#include <windowsx.h>

#include "eyelink.h"
#include "gdi_expt.h"
#include "w32_demo.h"  /* header file for this experiment */


/*********** DISPLAY GRAPHICS ************/

// see w32_bitmap_trial.c for draw_grid_to_bitmap() and display_bitmap()

              // inverts RECT area to highlight/unhighlight selection
void invert_rect(RECT *r) 
{                      
  HDC hdc;         // display drawing context

  if(!full_screen_window) return;    // make sure window is still open 
  hdc = GetDC(full_screen_window);   // get drawing context 

  SetROP2(hdc, R2_NOT);                                  // operation = invert
  Rectangle(hdc, r->left, r->top, r->right, r->bottom);  // invert rectangle (don't need brush for invert)
  SetROP2(hdc, R2_COPYPEN);                              // reset GDI mode
  ReleaseDC(full_screen_window, hdc);                    // release context
  wait_for_drawing(full_screen_window);
}


/********* GAZE CONTROL REGIONS *********/

	// This code must determine:
	// - which region an updatre is in
	// - update region dwell times
	// - trigger on dwell time
	// - do fixup for drift

                        // CONTROL REGION DEFINITION 
typedef struct {
		int triggered;	// is triggered
		long avgxsum;	// average position accumulators
		long avgysum;
		long dwell;	// total time in region
		RECT rsense;	// region for gaze
		RECT rdraw;	// rectangle for invert
		int cx, cy;	// center for drift correction
		} REGION;
		
long dwell_threshold = 700;	// msec of gaze in region required to trigger
		
#define NREGIONS  25            // array of control regions 
REGION rgn[NREGIONS];

int last_region = -1;	  // region with gaze at last update
int current_region = -1;  // region currently accumulating gaze time

		// process triggering of a new region:
                // remove higghlight from old region, highlight new region
void trigger_region(int region)
{
  int i;
  
  for(i=0;i<NREGIONS;i++)   // scan thru all regions
    {
      if(i==region)	    // is this the new region?
        {
          if(rgn[i].triggered==0)       // highlight new region
            invert_rect(&(rgn[i].rdraw));
          rgn[i].triggered = 1;  
        }
      else  		
        {
          if(rgn[i].triggered)		// unhighlight old region
            invert_rect(&(rgn[i].rdraw));
          rgn[i].triggered = 0;  
        }
    }    
} 			


           // Clear region data when gaze switches to new region	
void reset_regions(void)
{
  int i;
  
  for(i=0;i<NREGIONS;i++)   // reset data for all regions
    {
      rgn[i].avgxsum = 0;   
      rgn[i].avgysum = 0;
      rgn[i].dwell = 0;
    }
  current_region = -1;      // no region currently selected
  last_region = -1;
} 			

	    // Initial setup of region data
void init_regions(void)
{
  int i;
  int x,y;
  
  for(i=0;i<NREGIONS;i++)   // For all regions:
    {
      x = (i%5) * (SCRWIDTH / 5) + (SCRWIDTH / 10);    // compute center of region
      y = (i/5) * (SCRHEIGHT / 5) + (SCRHEIGHT / 10);
      rgn[i].cx = x;                                   // record center for drift correction
      rgn[i].cy = y;
      SetRect(&(rgn[i].rdraw), x,y,x,y);
      SetRect(&(rgn[i].rsense), x,y,x,y);
      InflateRect(&(rgn[i].rdraw), SCRWIDTH/30, SCRHEIGHT/22);   // define highlighting rectangle
      InflateRect(&(rgn[i].rsense), SCRWIDTH/10, SCRHEIGHT/10);  // define gaze-accumulation rectangle
    }
} 			

	// Determine which region gaze is in
	// return 0-24 for a valid region, -1 if not in any region
int which_region(int x, int y)
{
  int i;
  POINT pt;
  
  pt.x = x;                    // set POINT with gaze location
  pt.y = y;
  for(i=0;i<NREGIONS;i++)      // scan all regions for gaze position match
    if(PtInRect(&(rgn[i].rsense), pt)) return i;
  
  return -1;                   // not in any region
}

		// Process a fixation-update event:
		// Detect and handle a switch between regions
		// Otherwise, accumulate time and position in region
		// Trigger region when time exceeds threshold
void process_fixupdate(int x, int y, long dur)
{
   int avgx, avgy;
   int i = which_region(x, y);     // which region is gaze in
   
   if(i == -1)		    // NOT IN ANY REGION:
     {                          // allow one update outside of a region before resetting
       if(last_region == -1)	// 2 in a row: reset all regions
         {
           reset_regions();
         }
     }
   else if(i == current_region)	   // STILL IN CURRENT REGION 
     {
       rgn[i].dwell += dur;	      // accumulate time, position
       rgn[i].avgxsum += dur * x;
       rgn[i].avgysum += dur * y;
       if(rgn[i].dwell>dwell_threshold && !rgn[i].triggered)  // did this region trigger yet?
         {
           trigger_region(i);		        // TRIGGERED:
           avgx = rgn[i].avgxsum / rgn[i].dwell;    // compute avg. gaze position
           avgy = rgn[i].avgysum / rgn[i].dwell;
                  	                        // correct for drift (may cause false saccade in data)
           eyecmd_printf("drift_correction %ld %ld %ld %ld",
                          (long)rgn[i].cx-avgx, (long)rgn[i].cy-avgy,
                          (long)rgn[i].cx, (long)rgn[i].cy); 
	  						// Log triggering to EDF file
           eyemsg_printf("TRIGGER %d %ld %ld %ld %ld %ld", 
                          i, avgx, avgy, rgn[i].cx, rgn[i].cy, rgn[i].dwell);
         } 
     }
   else if(i == last_region)	// TWO UPDATES OUTSIDE OF CURRENT REGION: SWITCH TO NEW REGION
     {
       reset_regions();              // clear and initialize accumulators
       rgn[i].dwell = dur;	      
       rgn[i].avgxsum = dur * x;
       rgn[i].avgysum = dur * y;
       current_region = i;           // now working with new region
     }
  last_region = i;
}


/********* RUN A GAZE-CONTROL TRIAL  *******/

		// End recording: adds 100 msec of data to catch final events
                // Reset configuration changes made previously
static void end_trial(void)
{
  clear_full_screen_window(target_background_color);    // hide display 
  end_realtime_mode();   // NEW: ensure we release realtime lock
  pump_delay(100);       // CHANGED: allow Windows to clean up  
                         // while we record additional 100 msec of data 
  stop_recording();
			 // Reset link data, disable fixation event data
  eyecmd_printf("link_event_filter = LEFT,RIGHT,FIXATION,SACCADE,BLINK,BUTTON,INPUT");
  eyecmd_printf("fixation_update_interval = 0");
  eyecmd_printf("fixation_update_accumulate = 0");
}


	/* Run a gaze-control trial, recording to EDF file and sending FIXUPDATE events through link */
	/* This example draws to a bitmap, then copies it to display for fast stimulus onset */ 

	// The order of operations is:
	// - Set trial title, ID for analysis
        // - Draw to bitmap and create EyeLink display graphics
	// - Create regions
	// - Drift correction
	// - start recording
	// - start recording
	// - loop till button press, timeout, or abort, and process FIXUPDATE events	
	// - stop recording, handle abort and exit

        // NOTE: This trial draws its own bitmap and creates control regions	 
        // This is done becuase gaze-control trials will usually generate
        // the display and the list of rregions with the same code.

        // NOTE: realtime mode and display of a bitmap is used here.
        // This is to allow experiment-quality timing.
        // A typical gaze-control interface would draw directly to the display
        // and would not use realtime mode, to increase Windows responsiveness.  

int gaze_control_trial(UINT32 time_limit)
{
  UINT32 trial_start;	// trial start time (for timeout) 
  UINT32 drawing_time;  // retrace-to-draw delay
  int button;		// the button pressed (0 if timeout) 
  int error;            // trial result code

  ALLF_DATA evt;        // buffer to hold sample and event data
  int eye_used = -1;    // indicates which eye's data to display
  int i;

  HBITMAP gbm;          // The bitmap containing the stimulus display

	   // This supplies the title at the bottom of the eyetracker display 
  eyecmd_printf("record_status_message 'GAZE CONTROL TRIAL' ");

	   // Always send a TRIALID message before starting to record. 
	   // It marks the start of the trial and should precede any other messages
	   // It should contain trial condition data required for analysis.
  eyemsg_printf("TRIALID GAZECTRL");
 
  // TRIAL_VAR_DATA message is recorded for EyeLink Data Viewer analysis
  // It specifies the list of trial variables value for the trial 
  // This must be specified within the scope of an individual trial (i.e., after 
  // "TRIALID" and before "TRIAL_RESULT") 
  eyemsg_printf("!V TRIAL_VAR_DATA GAZECTRL");

  		// Before recording, we place reference graphics on the EyeLink display
  set_offline_mode();		 // Must be offline to draw to EyeLink screen
  
  // IMGLOAD command is recorded for EyeLink Data Viewer analysis
  // It displays a default image on the overlay mode of the trial viewer screen. 
  // Writes the image filename + path info
  eyemsg_printf("!V IMGLOAD FILL images/grid.png");	

  // IAREA command is recorded for EyeLink Data Viewer analysis
  // It creates a set of interest areas by reading the segment files
  // Writes segmentation filename + path info
  eyemsg_printf("!V IAREA FILE segments/grid.ias"); 

		// Draw bitmap and EyeLink reference graphics
  gbm = draw_grid_to_bitmap_segment("grid.ias", "segments", 1);
  	
  
  // Save the bitmap and transfer to the tracker pc
  // Since it takes a long time to save a bitmap to disk, the sv_options option 
  // should be set as SV_NOREPLACE
  bitmap_save_and_backdrop(gbm, 0, 0, 0, 0, "grid.png", "images", SV_NOREPLACE,
			      0, 0, (UINT16)(BX_MAXCONTRAST|((eyelink_get_tracker_version(NULL)>=2)?0:BX_GRAYSCALE)));


	   // DO PRE-TRIAL DRIFT CORRECTION 
	   // We repeat if ESC key pressed to do setup. 
  while(1)
    {              // Check link often so we can exit if tracker stopped
      if(!eyelink_is_connected()) return ABORT_EXPT;
	   // We let do_drift_correct() draw target in this example
	   // 3rd argument would be 0 if we already drew the display
      error = do_drift_correct((INT16)(SCRWIDTH/2), (INT16)(SCRHEIGHT/2), 1, 1);
           // repeat if ESC was pressed to access Setup menu 
      if(error!=27) break;
    }

  clear_full_screen_window(target_background_color);  // make sure display is blank

        // Configure EyeLink to send fixation updates every 50 msec
  eyecmd_printf("link_event_filter = LEFT,RIGHT,FIXUPDATE");
  eyecmd_printf("fixation_update_interval = 50");
  eyecmd_printf("fixation_update_accumulate = 50");
 	
  init_regions();	// Initialize regions for this display
  
    //ensure the eye tracker has enough time to switch modes (to start recording).
  set_offline_mode();
  pump_delay(50);

	// Start data recording to EDF file, BEFORE DISPLAYING STIMULUS 
	// You should always start recording 50-100 msec before required
	// otherwise you may lose a few msec of data 
  error = start_recording(1,1,0,1);   // send events only through link
  if(error != 0)           // ERROR: couldn't start recording
    {
      DeleteObject(gbm);   // Be sure to delete bitmap before exiting!
      return error;        // Return the error code
    }
                              // record for 100 msec before displaying stimulus 
  begin_realtime_mode(100);   // Windows 2000/XP: no interruptions from now on

    // DISPLAY OUR IMAGE TO SUBJECT  by copying bitmap to display
    // Because of faster drawing speeds and good refresh locking,
    // we now place the stimulus onset message just after display refresh 
    // and before drawing the stimulus.  This is accurate and will allow 
    // drawing a new stimulus each display refresh.
    // However, we do NOT send the message after the retrace--this may take too long
    // instead, we add a number to the message that represents the delay 
    // from the event to the message in msec
  wait_for_video_refresh();	  // synchronize before drawing so all seen at once
  drawing_time = current_msec();                   // time of retrace
  trial_start = drawing_time;

  display_bitmap(full_screen_window, gbm, 0, 0);  // COPY BITMAP to display
  wait_for_drawing(full_screen_window);          // wait till Windows finished drawing
  
  drawing_time = current_msec()-drawing_time;    // delay from retrace (time to draw)
  eyemsg_printf("%d DISPLAY ON", drawing_time);	 // message for RT recording in analysis 
  eyemsg_printf("SYNCTIME %d", drawing_time);	 // message marks zero-plot time for EDFVIEW 

  DeleteObject(gbm);             // Delete the bitmap 

  get_new_font("Times Roman", 24, 1);     // Print a title for the trial (for demo only)
  graphic_printf(target_foreground_color, -1, 1, SCRWIDTH/2, 24, "Gaze Control Trial");
	
  if(!eyelink_wait_for_block_start(100, 0, 1))  // wait for link event data
    {
      end_trial();
      alert_printf("ERROR: No link events received!");
      return TRIAL_ERROR;
    }
  eye_used = eyelink_eye_available(); // determine which eye(s) are available 
  switch(eye_used)		      // select eye, add annotation to EDF file	
    {			
      case RIGHT_EYE:
        eyemsg_printf("EYE_USED 1 RIGHT");
        break;
      case BINOCULAR:           // both eye's data present: use left eye only
        eye_used = LEFT_EYE;
      case LEFT_EYE:
        eyemsg_printf("EYE_USED 0 LEFT");
        break;
    }
                                 // Now get ready for trial loop
  eyelink_flush_keybuttons(0);   // reset keys and buttons from tracker 
                       // we don't use getkey() especially in a time-critical trial
                       // as Windows may interrupt us and cause an unpredicatable delay
                       // so we would use buttons or tracker keys only  

     // Trial loop: till timeout or response -- added code for processing FIXUPDATE events
  while(1) 
    {                            // First, check if recording aborted 
      if((error=check_recording())!=0) return error;  
                                 // Check if trial time limit expired
      if(current_time() > trial_start+time_limit)
        {
          eyemsg_printf("TIMEOUT");    // message to log the timeout 
	  end_trial();                 // local function to stop recording
	  button = 0;                  // trial result message is 0 if timeout 
	  break;                       // exit trial loop
	}

      if(break_pressed())     // check for program termination or ALT-F4 or CTRL-C keys
	{
	   end_trial();         // local function to stop recording
	   return ABORT_EXPT;   // return this code to terminate experiment
	 }

      if(escape_pressed())    // check for local ESC key to abort trial (useful in debugging)   
         {
	   end_trial();         // local function to stop recording
	   return SKIP_TRIAL;   // return this code if trial terminated
         }

		/* BUTTON RESPONSE TEST */
		// Check for eye-tracker buttons pressed
		// This is the preferred way to get response data or end trials	
      button = eyelink_last_button_press(NULL);
      if(button!=0)       // button number, or 0 if none pressed
	{
	   eyemsg_printf("ENDBUTTON %d", button);  // message to log the button press
	   end_trial();                            // local function to stop recording
	   break;                                  // exit trial loop
	 }
  
		// GET FIXUPDATE EVENTS, PROCESS

      i = eyelink_get_next_data(NULL);    // Check for data from link
      if(i == FIXUPDATE)	  // only process FIXUPDATE events
	{
	   eyelink_get_float_data(&evt);   // get a copy of the FIXUPDATE event 
	   if(evt.fe.eye == eye_used)	   // only process if it's from the desired eye?
	     {                             // get average position and duration of the update 
	       process_fixupdate((int)evt.fe.gavx, (int)evt.fe.gavy,     // Process event 
	       			 evt.fe.entime-evt.fe.sttime);
	     }
	}
    }       // end of loop
			   // report response result: 0=timeout, else button number
  eyemsg_printf("TRIAL_RESULT %d", button);
			   // Call this at the end of the trial, to handle special conditions
  return check_record_exit();
}

