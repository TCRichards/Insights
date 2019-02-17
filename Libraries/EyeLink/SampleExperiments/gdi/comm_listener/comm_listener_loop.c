/*****************************************************/
/* Windows 95/98/NT/2000/XP sample experiment in C   */
/* For use with Version 2.0 of EyeLink Windows API   */
/*                                                   */
/*      (c) 1997-2002 by SR Research Ltd.            */
/* For non-commercial use by Eyelink licencees only  */
/*                                                   */
/* THIS FILE: w32_simple_trials.c                    */
/* CONTENTS:                                         */
/* - run_trials() loops through trials, and handles  */
/*   aborted/repeated trial requests                 */
/* - do_simple_trial() interperts trial number       */
/*   and supplies appropriate TRIALID label and      */
/*   stimuli for each trial                          */
/* - See documentation for more details              */  
/*                                                   */
/*                                                   */
/* NEW FOR Windows 2000/XP, EyeLink API 2.1 or later */
/*****************************************************/

/*****************************************************/
/* NOTE: REQUIRES NEW VERSIONS:                      */
/*                                                   */
/* EYE TRACKERS:                                     */
/* EyeLink I version 2.1 or higher                   */
/* EyeLink II version 1.1 or higher                  */
/*                                                   */
/* WINDOWS API FILES:                                */
/* eyelink_exptkit.dll version 2.1 or higher         */
/* eyelink_exptkit.lib June 12, 2002 or later        */
/* Header files dated June 13, 2002 or later:        */
/* eyelink.h                                         */
/* eyelink.h                                         */
/* eye_data.h                                        */
/* eyetypes.h                                        */
/* w32_exptsppt.h                                    */
/*****************************************************/
 
#include <windows.h>
#include <windowsx.h>

#include <stdio.h>
#include <string.h>    // for strtok() and _stricmp()

#include "gdi_expt.h"
#include "w32_demo.h"

extern int listener_record_display(void);

// #define PRINT_MESSAGES  // uncomment to see all messages for debugging

/******* MAP TRACKER TO LOCAL DISPLAY ************/

float tracker_pixel_left =   0;   // tracker gaze coord system
float tracker_pixel_top =    0;   // used to remap gaze data
float tracker_pixel_right =  0;   // to match our display resolution
float tracker_pixel_bottom = 0;

         // remap X, Y gaze coordinates to local display
int track2local_x(float x)
{
  return (int)(SCREEN_LEFT + 
           (x - tracker_pixel_left) * SCRWIDTH / 
             (tracker_pixel_right - tracker_pixel_left + 1));
}

int track2local_y(float y)
{
  return (int)(SCREEN_TOP + 
           (y - tracker_pixel_top) * SCRHEIGHT / 
             (tracker_pixel_bottom - tracker_pixel_top + 1));
}


/*********** LISTENING LOOP **************/

void listening_loop(void)
{
  int i;
  int j = 6;

  char trial_word[40];  // Trial stimulus word (from TRIALID message)
  char first_word[40];  // first word in message (determines processing)

  tracker_pixel_left = (float)SCREEN_LEFT;    // set default display mapping
  tracker_pixel_top = (float)SCREEN_TOP;
  tracker_pixel_right = (float)SCREEN_RIGHT;
  tracker_pixel_bottom = (float)SCREEN_BOTTOM;

      // Now we loop through processing any link data and messages
      // The link will be closed when the COMM_SIMPLE application exits
      // This will also close our broadcast connection and exit this loop
  while(eyelink_is_connected())
    {
      ALLF_DATA data;   // link data or messages
                               // exit if ESC or ALT-F4 pressed
      if(escape_pressed() || break_pressed()) return; 
                        
      i = eyelink_get_next_data(NULL);   // check for new data item
      if(i == 0) continue;

      if(i == MESSAGEEVENT)   // message: check if we need the data
        {
	  eyelink_get_float_data(&data);
#ifdef PRINT_MESSAGES   // optionally, show messages for debugging
          get_new_font("Times Roman", SCRHEIGHT/55, 1);         // select a font
          graphic_printf(target_foreground_color, -1, 0, SCRWIDTH/15, j++*SCRHEIGHT/55, 
                    "MESSAGE=%s", data.im.text);
#endif
          sscanf(data.im.text, "%s", first_word);  // get first word
          if(!_stricmp(first_word, "DISPLAY_COORDS"))
            {         // get COMM_SIMPLE computer display size
              sscanf(data.im.text, "%*s %f %f %f %f", 
                     &tracker_pixel_left, &tracker_pixel_top,
                     &tracker_pixel_right, &tracker_pixel_bottom);
            }
          else if(!_stricmp(first_word, "TRIALID"))
            { 
	              // get TRIALID information
              sscanf(data.im.text, "%*s %s", trial_word);
                      // Draw stimulus (exactly as was done in COMM_SIMPLE)
#ifndef PRINT_MESSAGES
	      clear_full_screen_window(target_background_color);  
#endif
                      // We scale font size for difference in display resolutions
              get_new_font("Times Roman", 
                            (int)(SCRWIDTH/25.0 * 
                              SCRWIDTH/(tracker_pixel_right-tracker_pixel_left+1)), 1);        
              graphic_printf(target_foreground_color, -1, 1,      
                             (int)(SCRWIDTH/2), (int)(SCRHEIGHT/2), "%s", trial_word);
            }
        }
                 // link data block opened for recording?
      if(eyelink_in_data_block(1, 1))
        {   
          listener_record_display(); // display gaze cursor on stimulus
                                     // clear display at end of trial
#ifndef PRINT_MESSAGES
          clear_full_screen_window(target_background_color);  
#endif
        }
    }
}

