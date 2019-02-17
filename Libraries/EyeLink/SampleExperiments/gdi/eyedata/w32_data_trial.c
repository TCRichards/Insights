/*********************************************************/
/* Windows 95/98/NT/2000/XP sample experiment in C       */
/* For use with Version 2.0 of EyeLink Windows API       */
/*                                                       */
/*      (c) 1997-2002 by SR Research Ltd.                */
/* For non-commercial use by Eyelink licencees only      */
/*                                                       */
/* THIS FILE: w32_data_trial.c                           */
/* CONTENTS:                                             */
/* - end_trial(): blank display, stop recording          */
/*                cleans up, gives Windows time          */
/* - run_trial(): perfoems actual trial sequence:        */
/*     - drift correction (possible recalibration)       */
/*     - start recording                                 */
/*     - display stimulus to subject                     */
/*     - wait for data, select which eye's data to use   */
/*     - loop while drawing gaze cursor from samples     */  
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
/* - use wait_for_block_start() to ensure data available */
/* - select eye to use at start of trial                 */
/* - eliminate delay during cursor draw                  */
/* - eliminate getkey() for monitoring trial aborts      */
/* - add cleanup code after loop                         */
/* - Add 2000/XP realtime mode cleanup to end_trial()    */
/*                                                       */
/* CHANGES FOR Windows 2000/XP, EyeLink API 2.1:         */
/* - change delay numbers in messages to first item      */
/*********************************************************/

#include <windows.h>
#include <windowsx.h>

#include "gdi_expt.h"
#include "w32_demo.h"  /* header file for this experiment */



/************** GAZE POSITION CURSOR **************/

static int last_cursor_x, last_cursor_y;  // cursor position for erasing
static int gaze_cursor_drawn = 0;         // set if curor is currently

void invert_ellipse(int x, int y)  /* draw target at (x,y) */
{                      
  HPEN oPen;
  HBRUSH oBrush;                
  HDC hdc;

  if(x==MISSING || y==MISSING) return;
  hdc = GetDC(full_screen_window);  

  oBrush = SelectObject(hdc, CreateSolidBrush(RGB(0xFF,0xFF,0xFF)));
  oPen = SelectObject(hdc, CreatePen(PS_NULL, 0, 0));
  SetROP2(hdc, R2_NOT);
  Ellipse(hdc, x-SCRWIDTH/60, y-SCRHEIGHT/45, x+SCRWIDTH/60, y+SCRHEIGHT/45);
  SetROP2(hdc, R2_COPYPEN);
  DeleteObject(SelectObject(hdc, oBrush));
  DeleteObject(SelectObject(hdc, oPen));
  ReleaseDC(full_screen_window, hdc);
}


                // erases previously drawn gaze cursor
void erase_gaze_cursor(void)
{
  if(!gaze_cursor_drawn) return;         // prevent re-erase
  invert_ellipse(last_cursor_x, last_cursor_y);
  gaze_cursor_drawn = 0;
}

                // draws eye gaze cursor
                // erases, moves if currently drawn
void draw_gaze_cursor(int x, int y)
{
  if(gaze_cursor_drawn && abs(last_cursor_x-x)<2 && abs(last_cursor_y-y)<2) return;
  if(gaze_cursor_drawn) erase_gaze_cursor();
  invert_ellipse(x, y);
  last_cursor_x = x;
  last_cursor_y = y;
  gaze_cursor_drawn = 1;
}


/********* PERFORM AN EXPERIMENTAL TRIAL  *******/

		// End recording: adds 100 msec of data to catch final events
static void end_trial(void)
{
  erase_gaze_cursor();
  clear_full_screen_window(target_background_color);    /* hide display */
  end_realtime_mode();   // NEW: ensure we release realtime lock
  pump_delay(100);       // CHANGED: allow Windows to clean up  
                         // while we record additional 100 msec of data 
  stop_recording();
}

	/* Run a single trial, recording to EDF file and sending data through link */
	/* This example draws to a bitmap, then copies it to display for fast stimulus onset */ 

	// The order of operations is:
	// - Set trial title, ID for analysis
        // - Draw to bitmap and create EyeLink display graphics
	// - Drift correction
	// - start recording
	// - Copy bitmap to display
	// - start recording
	// - unblank display
	// - loop till button press, timeout, or abort, drawing gaze cursor	
	// - stop recording, handle abort and exit
	
	// NEW CODE FOR GAZE CURSOR:
	// - uses the eyelink_newest_float_sample() to get latest update
	// - discards other data: see w32_playback_trial.c for example
	//   of how to read all samples and events from link
	//   Both these methods of getting data can be used simultaneously.
	 
int realtime_data_trial(HBITMAP gbm, UINT32 time_limit)
{
  UINT32 trial_start;	// trial start time (for timeout) 
  UINT32 drawing_time;  // retrace-to-draw delay
  int button;		// the button pressed (0 if timeout) 
  int error;            // trial result code

  ALLF_DATA evt;        // buffer to hold sample and event data
  int eye_used = -1;    // indicates which eye's data to display
  float x, y;		// gaze position 

    // NOTE: TRIALID AND TITLE MUST HAVE BEEN SET BEFORE DRIFT CORRECTION!
    // FAILURE TO INCLUDE THESE MAY CAUSE INCOMPATIBILITIES WITH ANALYSIS SOFTWARE!

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
  

    //ensure the eye tracker has enough time to switch modes (to start recording).
  set_offline_mode();
  pump_delay(50);
  
  // Start data recording to EDF file, BEFORE DISPLAYING STIMULUS 
	// You should always start recording 50-100 msec before required
	// otherwise you may lose a few msec of data 
  
	// NEW CODE FOR GAZE CURSOR: tell start_recording() to send link data
  gaze_cursor_drawn = 0;	      	// initialize gaze cursor state
  error = start_recording(1,1,1,1);	// record with link data enabled
  if(error != 0) return error;          // ERROR: couldn't start recording
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

  if(!eyelink_wait_for_block_start(100, 1, 0))  // wait for link sample data
    {
      end_trial();
      alert_printf("ERROR: No link samples received!");
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

     // Trial loop: till timeout or response -- added code for reading samples and moving cursor
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
  
                // NEW CODE FOR GAZE CURSOR 
  
      if(eyelink_newest_float_sample(NULL)>0)  // check for new sample update
	{
	  eyelink_newest_float_sample(&evt);   // get a copy of the sample
          x = evt.fs.gx[eye_used];             // get gaze position from sample 
	  y = evt.fs.gy[eye_used];
	  if(x!=MISSING_DATA && 
             y!=MISSING_DATA &&
             evt.fs.pa[eye_used]>0)   // make sure pupil is present
	    {
	      draw_gaze_cursor((int)x,(int)y);  // show and move cursor
	    }
	   else
	    {
	      erase_gaze_cursor();    // hide cursor if no pupil
	    }
	}
    }                       // END OF RECORDING LOOP

  end_realtime_mode();      // safety cleanup code
  while(getkey());          // dump any accumulated key presses

			   // report response result: 0=timeout, else button number
  eyemsg_printf("TRIAL_RESULT %d", button);
			   // Call this at the end of the trial, to handle special conditions
  return check_record_exit();
}

