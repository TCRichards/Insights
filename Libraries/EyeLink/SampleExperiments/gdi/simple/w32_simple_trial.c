/*********************************************************/
/* Windows 95/98/NT/2000/XP sample experiment in C       */
/* For use with Version 2.0 of EyeLink Windows API       */
/*                                                       */
/*      (c) 1997-2002 by SR Research Ltd.                */
/* For non-commercial use by Eyelink licencees only      */
/*                                                       */
/* THIS FILE: w32_simple_trial.c                         */
/* CONTENTS:                                             */
/* - end_trial(): blank display, stop recording          */
/*                cleans up, gives Windows time          */
/* - run_trial(): perfoems actual trial sequence:        */
/*     - drift correction (possible recalibration)       */
/*     - start recording                                 */
/*     - display stmulus to subject                      */
/*     - wait for timeout, button press, or abort        */
/*     - send result message to EDF file                 */
/*     - blank display, stop recording                   */
/*     - report any erros or reqest for repeat           */
/* - See documentation for more details                  */  
/*                                                       */
/*                                                       */
/* CHANGES FOR Windows 2000/XP, EyeLink 2.0:             */
/* - use w32_exptsppt2.h                                 */
/* - add realtime mode during display start              */
/* - display onset message refs retrace sync before draw */
/* - eliminate getkey() for monitoring trial aborts      */
/* - add cleanup code after loop                         */
/* - Add 2000/XP realtime mode cleanup to end_trial()    */
/*                                                       */
/* CHANGES FOR Windows 2000/XP, EyeLink API 2.1:         */
/* - change delay numbers in messages to first item      */
/*********************************************************/

/* This module is intended only for private development of experiments       */
/* Use is granted for non-commercial applications by Eyelink licencees only  */

#include <windows.h>
#include <windowsx.h>

#include "gdi_expt.h"
#include "w32_demo.h"  /* header file for this experiment */


/********* PERFORM AN EXPERIMENTAL TRIAL  *******/

		// End recording: adds 100 msec of data to catch final events
static void end_trial(void)
{
  clear_full_screen_window(target_background_color);  /* hide display */
  end_realtime_mode();   // NEW: ensure we release realtime lock
  pump_delay(100);       // CHANGED: allow Windows to clean up  
                         // while we record additional 100 msec of data 
  stop_recording();
}

	// Run a single trial, recording to EDF file only 
	// This example draws directly to the screen 
	// This limits it to simple stimuli, or to when 
	// stimulus onset time is not critial 

	// The order of operations is:
	// - Drift correction
	// - start recording
	// - display text (or other graphics)
	// - loop till button press, timeout, or abort	
	// - stop recording, handle abort and exit

int simple_recording_trial(char *text, UINT32 time_limit)
{
  UINT32 trial_start;	// trial start time (for timeout) 
  UINT32 drawing_time;  // retrace-to-draw delay
  int button;		// the button pressed (0 if timeout) 
  int error;            // trial result code

    // NOTE: TRIALID AND TITLE MUST HAVE BEEN SET BEFORE DRIFT CORRECTION!
    // FAILURE TO INCLUDE THESE MAY CAUSE INCOMPATIBILITIES WITH ANALYSIS SOFTWARE!

           // DO PRE-TRIAL DRIFT CORRECTION 
	   // We repeat if ESC key pressed to do setup. 
  while(1)
    {              // Check link often so we can exit if tracker stopped
      if(!eyelink_is_connected()) return ABORT_EXPT;
	   // We let do_drift_correct() draw target in this example
	   // 3rd argument would be 0 if we already drew the fixation target
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
  error = start_recording(1,1,0,0);   // record samples and events to EDF file only
  if(error != 0)  return error;        // return error code if failed

                              // record for 100 msec before displaying stimulus 
  begin_realtime_mode(100);   // Windows 2000/XP: no interruptions till display start marked

    // DISPLAY OUR IMAGE TO SUBJECT 
    // If graphics are very simple, you may be able to draw them 
    // in one refresh period.  Otherwise, draw to a bitmap first.
  get_new_font("Times Roman", SCRWIDTH/25, 1);        // select font for drawing

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

  graphic_printf(target_foreground_color, -1, 1,   // Draw the stimulus, centered
                 SCRWIDTH/2, SCRHEIGHT/2, "%s", text);
  wait_for_drawing(full_screen_window);          // wait till Windows finished drawing
  
  drawing_time = current_msec()-drawing_time;    // delay from retrace (time to draw)
  eyemsg_printf("%d DISPLAY ON", drawing_time);	 // message for RT recording in analysis 
  eyemsg_printf("SYNCTIME %d", drawing_time);	 // message marks zero-plot time for EDFVIEW 

                        // we would stay in realtime mode if timing is critical   
                        // for example, if a dynamic (changing) stimulus was used
                        // or if display duration accuracy of 1 video refresh. was needed
  end_realtime_mode();  // we don't care as much about time now, allow keyboard to work
     
                                 // Now get ready for trial loop
  eyelink_flush_keybuttons(0);   // reset keys and buttons from tracker 

                       // we don't use getkey() especially in a time-critical trial
                       // as Windows may interrupt us and cause an unpredicatable delay
                       // so we would use buttons or tracker keys only  

     // Trial loop: till timeout or response 
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
    }                       // END OF RECORDING LOOP
  end_realtime_mode();      // safety cleanup code
  while(getkey());          // dump any accumulated key presses

			   // report response result: 0=timeout, else button number
  eyemsg_printf("TRIAL_RESULT %d", button);
			   // Call this at the end of the trial, to handle special conditions
  return check_record_exit();
}

