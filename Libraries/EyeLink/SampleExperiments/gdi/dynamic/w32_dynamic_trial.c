/*********************************************************/
/* Windows 95/98/NT/2000/XP sample experiment in C       */
/* For use with Version 2.0 of EyeLink Windows API       */
/*                                                       */
/*      (c) 1997-2002 by SR Research Ltd.                */
/* For non-commercial use by Eyelink licencees only      */
/*                                                       */
/* THIS FILE: w32_dynamic_trial.c                        */
/* CONTENTS:                                             */
/* - end_trial(): blank display, stop recording          */
/*                cleans up, gives Windows time          */
/* - run_dynamic_trial(): performs actual trial          */
/*     - display background bitmap                       */
/*     - predraw target for drift correction             */
/*     - drift correction (possible recalibration)       */
/*     - start recording                                 */
/*     - enter realtime mode                             */
/*     - loop while drawing in refresh-locked mode       */  
/*     - wait for timeout, button press, or abort        */
/*     - send result message to EDF file                 */
/*     - blank display, stop recording                   */
/*     - report any errors or reqest for repeat          */
/* - See documentation for more details                  */  
/*                                                       */
/*                                                       */
/* CHANGES FOR Windows 2000/XP, EyeLink 2.0:  NEW        */
/*                                                       */
/* CHANGES FOR Windows 2000/XP, EyeLink API 2.1:         */
/* - change delay numbers in messages to first item      */
/*********************************************************/

#include <windows.h>
#include <windowsx.h>

#include "gdi_expt.h"
#include "w32_demo.h"  /* header file for this experiment */

#include "w32_targets.h"

int delayed_retrace_count = 0;


/********* PERFORM AN EXPERIMENTAL TRIAL  *******/

		// End recording: adds 100 msec of data to catch final events
static void end_trial(void)
{
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
	// - start recording
	// - loop till button press, timeout, or abort, drawing gaze target	
	// - stop recording, handle abort and exit
	
	// NEW CODE FOR PURSUIT:
	// - in realtime mode continuously
	// - calls function drawfn() to determine what to draw and where
        // - predraws drift correction target at start position
	// - draws just after vertical refresh

        // first argument is background bitmap for targets 
        // third argument ispointer to drawing function:
        //         int drawfn(UINT32 t, int *x, int *y)
        //  where t = time from trial start in msec (-1 for initial target)
        //  x, y are pointers to integer to hold a reference position
        //    which is usually center or fixation target X,Y for drift correction
        //  this function is called immediately after refresh,
        //  and must erase and draw targets and write out any messages       
        //  this function returns 0 to continue, 1 to end trial
	 
int run_dynamic_trial(HBITMAP hbm, UINT32 time_limit, 
                      int (__cdecl * drawfn)(UINT32 t, UINT32 dt, int *x, int *y))
{
  UINT32 trial_start = 0;	// trial start time (for timeout) 
  UINT32 drawing_time;
  UINT32 t;

  UINT32 ut;
  UINT32 last_retrace_time = 0;

  int button;		// the button pressed (0 if timeout) 
  int error;            // trial result code
  int x, y;    // used to get targt x,y 

    // NOTE: TRIALID AND TITLE MUST HAVE BEEN SET BEFORE DRIFT CORRECTION!
    // FAILURE TO INCLUDE THESE MAY CAUSE INCOMPATIBILITIES WITH ANALYSIS SOFTWARE!

  target_background_bitmap = hbm;

	   // DO PRE-TRIAL DRIFT CORRECTION 
	   // We repeat if ESC key pressed to do setup. 
           // we predraw target for drift correction in this example
  while(1)
    {              // Check link often so we can exit if tracker stopped
      if(!eyelink_is_connected()) return ABORT_EXPT;
                   // (re) draw display and target at starting point
      display_bitmap(full_screen_window, hbm, 0, 0);
      target_reset();
      drawfn(0, 0, &x, &y);

 	   // We drift correct at the current target location
      	   // 3rd argument is 0 because we already drew the display
      error = do_drift_correct((INT16)x, (INT16)y, 0, 1);
           // repeat if ESC was pressed to access Setup menu 
      if(error!=27) break;
    }
        // The screen was erased after drift correction because we had it draw the target
        // If we drew the target, we could erase it now.         
  

    //ensure the eye tracker has enough time to switch modes (to start recording).
  set_offline_mode();
  pump_delay(50);

	// Start data recording to EDF file, BEFORE DISPLAYING STIMULUS 
	// You should always start recording 50-100 msec before required
	// otherwise you may lose a few msec of data 
  
	// NEW CODE FOR PURSUIT: refresh-locked drawing
  error = start_recording(1,1,0,0);	// record with link data disabled
  if(error != 0) return error;          // ERROR: couldn't start recording
                              // record for 100 msec before displaying stimulus 
  begin_realtime_mode(100);   // Windows 2000/XP: no interruptions from now on

                                 // Now get ready for trial loop
  eyelink_flush_keybuttons(0);   // reset keys and buttons from tracker 
                       // we don't use getkey() especially in a time-critical trial
                       // as Windows may interrupt us and cause an unpredicatable delay
                       // so we would use buttons or tracker keys only  

     // Trial loop: till timeout or response -- added code for reading samples and moving target
  while(1) 
    {                            // First, check if recording aborted 
      if((error=check_recording())!=0) return error;  
                                 // Check if trial time limit expired
      if(trial_start>0 &&
        current_time()-trial_start > time_limit)
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
                // THIS MIGHT NOT BE PRESENT IN REAL DYNAMIC EXPERIMENTS
      button = eyelink_last_button_press(NULL);
      if(button!=0)       // button number, or 0 if none pressed
	{
	   eyemsg_printf("ENDBUTTON %d", button);  // message to log the button press
	   end_trial();                            // local function to stop recording
	   break;                                  // exit trial loop
	 }
  
                // NEW CODE FOR RETRACE-LOCKED DYNAMIC DISPLAYS
      wait_for_video_refresh();
      ut = current_usec();     // microseconds for retrace delay test
      t = current_msec();      // milliseconds for everything else

      if(trial_start == 0)     // is this the first time we draw?
        {
          trial_start = t;     // record the display onset time 
          drawfn(t, 0, &x, &y);
          drawing_time = current_msec() - t;
          eyemsg_printf("%d DISPLAY ON", drawing_time);	 // message for RT recording in analysis 
          eyemsg_printf("SYNCTIME %d", drawing_time);	 // message marks zero-plot time for EDFVIEW 
        }
      else   // not first: just do drawing
        {
          if(drawfn(t, t-trial_start, &x, &y))
            {
              eyemsg_printf("TIMEOUT");    // message to log the timeout 
              end_trial();                 // local function to stop recording
	      button = 0;                  // trial result message is 0 if timeout 
	      break;                       // exit trial loop
            }
        }
                               // check if retrace detection delayed too much
      if(last_retrace_time &&   
         ut-last_retrace_time > 1.2*1000000.0/dispinfo.refresh)
        {
          delayed_retrace_count++;      
          eyemsg_printf("DELAYED_RETRACE %1.2lf", 
            ((double)ut-(double)last_retrace_time)/(1000000.0/dispinfo.refresh)-1.0 );
        }
      last_retrace_time = ut;
    }                       // END OF RECORDING LOOP

  end_realtime_mode();      // safety cleanup code
  while(getkey());          // dump any accumulated key presses

			   // report response result: 0=timeout, else button number
  eyemsg_printf("TRIAL_RESULT %d", button);
			   // Call this at the end of the trial, to handle special conditions
  return check_record_exit();
}

