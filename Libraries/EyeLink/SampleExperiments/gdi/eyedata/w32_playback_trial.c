/*********************************************************/
/* Windows 95/98/NT/2000/XP sample experiment in C       */
/* For use with Version 2.0 of EyeLink Windows API       */
/*                                                       */
/*      (c) 1997-2002 by SR Research Ltd.                */
/* For non-commercial use by Eyelink licencees only      */
/*                                                       */
/* THIS FILE: w32_playback_trial.c                       */
/* CONTENTS:                                             */
/* - playback_trial(): gets, plots last trial's data     */
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
/* - use wait_for_block_start() to ensure data available */
/* - select eye to use at start of trial                 */
/*********************************************************/

#include <windows.h>
#include <windowsx.h>

#include "gdi_expt.h"
#include "w32_demo.h"  /* header file for this experiment */


	// Plays back last trial's data
	// Prints white "F" for fixations
	// Connects samples with black line
int playback_trial(void)
{
  COLORREF white = RGB(0xF0, 0xF0, 0xF0);   // define the drawing colors
  COLORREF grey  = RGB(0xA0, 0xA0, 0xA0);
  COLORREF black = RGB(0, 0, 0);
  HDC hdc;           // GDI drawing context
  HPEN oPen;         // Saves original pen

  ALLF_DATA evt;	// buffer for sample and event data
  int eye_used = 0;		// which eye's data is used for plotting
  float x, y;		// gaze position
  int last_sam_x = MISSING_DATA;  // last sample position for drawing lines
  int last_sam_y;
  int i;
  INT16 sample_rate = 250;

  ILINKDATA *idata = eyelink_data_status();

                         // Set up the display
  clear_full_screen_window(grey);         // erase display
  get_new_font("Times Roman", 24, 0);     // title of screen
  graphic_printf(black, -1, 1, SCRWIDTH/2, 24, "Playing back last trial...");

  set_offline_mode();           // set up eye tracker for playback
  eyelink_playback_start();     // start data playback

      // wait for first data to arrive
      // Failure may mean no data or file not open

      // This function discards other data in file (buttons and messages)
      // until the start of recording.
      // If you need these events, then don't use this function.
      // Instead, wait for a sample or event before setting eye_data,
      // and have a timeout if no data is available in 2000 msec.
  if(!eyelink_wait_for_block_start(2000, 1, 1))
    {
      alert_printf("ERROR: playback data did not start!");
      return -1;
    }

  eye_used = eyelink_eye_available();
  if(eye_used==BINOCULAR) eye_used = LEFT_EYE;    // use left eye if both available

                                   // determine sample rate
  i = eyelink2_mode_data(&sample_rate, NULL, NULL, NULL);
  if(i==-1 || sample_rate<250) sample_rate = 250;  // EyeLink I: sample rate = 4 msec           //

  while(getkey()) {};     // clear out any pending local keys

  hdc = GetDC(full_screen_window);      // set up white line for plotting samples
  oPen = SelectObject(hdc, CreatePen(PS_SOLID, 1, white));
  get_new_font("Arial Bold", 20, 0);       // set font for drawing fixation marks

  while(1)   // LOOP WHILE DATA AVAILABLE
    {
      if(escape_pressed() || break_pressed()      // exit if ESC, ALT-F4, or CTRL-C pressed
                          || eyelink_last_button_press(NULL))  // tracker button also exits
        {
          clear_full_screen_window(target_background_color);  // hide display
	  eyelink_playback_stop();                            // stop playback
          return 0;
	}
	    // PROCESS PLAYBACK DATA FROM LINK
      i = eyelink_get_next_data(NULL);   // check for new data item
      if(i==0)	                         // 0: no new data
        {                                // Check if playback has completed
	  if((eyelink_current_mode() & IN_PLAYBACK_MODE)==0) break;
        }

      if(i == ENDFIX)	// Was it a fixation event ?
	{		// PLOT FIXATIONS
	  eyelink_get_float_data(&evt);   // get copy of fixation event
	  if(evt.fe.eye == eye_used)	   // is it the eye we are plotting?
	    {                             // Print a black "F" at average position
              graphic_printf(black, -1, 1, (int)evt.fe.gavx, (int)evt.fe.gavy, "F");
	    }
	}

#ifdef LOST_DATA_EVENT       // AVAILABLE IN V2.1 OR LATER DLL ONLY
      else if(i == LOST_DATA_EVENT)
	{
	  alert_printf("Lost data in sequence");
	}
#endif
                        // Process samples: connect with lines
      else if(i==SAMPLE_TYPE)
	{
	  eyelink_get_float_data(&evt);  // get copy of sample
	  if(eye_used != -1)             // do we know which eye yet?
	    {
	      //msec_delay(1000/sample_rate);             // delay for real-time playback
	      x = evt.fs.gx[eye_used];   // get gaze position from sample
	      y = evt.fs.gy[eye_used];
	      if(x!=MISSING_DATA && y!=MISSING_DATA &&
	         evt.fs.pa[eye_used]>0 )   // check if pupil is present
                {
		  if(last_sam_x != MISSING_DATA)   // everything ready: connect with line
		    {
                      MoveToEx(hdc, last_sam_x, last_sam_y, NULL);
                      LineTo(hdc, (int)x, (int)y);
                    }
		  last_sam_x = (int)x;                  // record position for next sample
		  last_sam_y = (int)y;
		}
	      else	// no pupil present: must be in blink
                {
		  last_sam_x = MISSING;
		}
	     }
	   else
             {                       // if we don't know which eye yet, check which eye present
     	       eye_used = eyelink_eye_available();
	       if(eye_used==BINOCULAR) eye_used = LEFT_EYE;  // use left eye if both available
	     }
	 }
     }         // END OF PLAYBACK LOOP

  eyelink_playback_stop();                  // Stop data playback
  DeleteObject(SelectObject(hdc, oPen));    // Restore original GDI pen
  ReleaseDC(full_screen_window, hdc);       // Release display context

  get_new_font("Times Roman", 24, 0);       // Print completion message
  graphic_printf(black, -1, 1, SCRWIDTH/2, 50, "Done: Press any key to continue.");
  while(getkey())  {};                      // wait for new button or key press
  while(!getkey() && !eyelink_last_button_press(NULL)) {};
  return 0;
}

