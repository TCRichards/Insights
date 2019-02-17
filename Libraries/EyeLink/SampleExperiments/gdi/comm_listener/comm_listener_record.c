/*********************************************************/
/* Windows 95/98/NT/2000/XP sample experiment in C       */
/* For use with Version 2.0 of EyeLink Windows API       */
/*                                                       */
/*      (c) 1997-2002 by SR Research Ltd.                */
/* For non-commercial use by Eyelink licencees only      */
/*                                                       */
/* THIS FILE: broadcast_record_diaplay.c                 */
/* CONTENTS:                                             */
/* - draw_gaze_cursor(), erase_gaze_cursor():            */
/*     - implement simple XOR gaze cursor                */
/*                                                       */
/* - record_mode_display():                              */
/*            listens to link data, moves gaze cursor    */
/*     - enables link data reception                     */  
/*     - wait for data, select which eye's data to use   */
/*     - converts gaze position to local display coords  */  
/*     - plots gaze, prints position data                */
/*     - exits if program terminated or not record mode  */
/* - See documentation for more details                  */  
/*                                                       */
/*                                                       */
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
#include <stdio.h>
#include <string.h>

#include "gdi_expt.h"
#include "w32_demo.h"

      // functions to map gaze from tracker to local pixels
extern int track2local_x(float x);
extern int track2local_y(float y);


/************** GAZE POSITION CURSOR **************/

static int last_cursor_x, last_cursor_y; // cursor rect for erase
static int gaze_cursor_drawn = 0; 

void invert_gaze_cursor(int x, int y)  /* draw target at (x,y) */
{                      
  HPEN oPen;
  HBRUSH oBrush;                
  HDC hdc;

  if(x==MISSING || y==MISSING || !full_screen_window) return;
  hdc = GetDC(full_screen_window);  

  oBrush = SelectObject(hdc, CreateSolidBrush(RGB(0x00,0xFF,0xFF)));
  oPen = SelectObject(hdc, CreatePen(PS_NULL, 0, 0));
  SetROP2(hdc, R2_XORPEN);
  Ellipse(hdc, x-SCRWIDTH/60, y-SCRHEIGHT/45, x+SCRWIDTH/60, y+SCRHEIGHT/45);
  SetROP2(hdc, R2_COPYPEN);
  DeleteObject(SelectObject(hdc, oBrush));
  DeleteObject(SelectObject(hdc, oPen));
  ReleaseDC(full_screen_window, hdc);
}


                // erases previously drawn gaze cursor
void erase_gaze_cursor(void)
{
  if(!gaze_cursor_drawn) return;       // prevent re-erase
  invert_gaze_cursor(last_cursor_x, last_cursor_y);
  gaze_cursor_drawn = 0;
}

                // draws eye gaze cursor
                // erases, moves if currently drawn
void draw_gaze_cursor(int x, int y)
{
  if(gaze_cursor_drawn &&           // check if cursor needs redrawing
      abs(last_cursor_x-x)<2 && abs(last_cursor_y-y)<2) return;

  if(gaze_cursor_drawn)  erase_gaze_cursor(); // erase before draw
  
  invert_gaze_cursor(x, y);     // draw at new position
  msec_delay(6);            // delay so cursor won't flicker 
  last_cursor_x = x;
  last_cursor_y = y;
  gaze_cursor_drawn = 1;
}


/********* PLOT GAZE DATA DURING RECORDING  *******/

// #define PRINT_MESSAGES    // uncomment to see messages for debugging
	 
int listener_record_display(void)
{
  ALLF_DATA evt;
  UINT32 trial_start_time = 0;
  unsigned key;
  int eye_used;        // which eye to show gaze for
  float x, y;	       // gaze position 
  float ox=-1, oy=-1;  // old gaze position (to determine change) 
  int i,j=1;
                                 // create font for position display
  get_new_font( "Arial", SCRWIDTH/50, 0);
  gaze_cursor_drawn = 0;         // init gaze cursor state

  eye_used = eyelink_eye_available();
  if(eye_used==BINOCULAR) eye_used = LEFT_EYE;    // use left eye if both available
  
  while(eyelink_is_connected())  // loop while record data availablemode
    {
      key = getkey();            // Local keys/abort test
      if(key==TERMINATE_KEY)     // test ALT-F4 or end of execution
         break;

      if(!eyelink_in_data_block(1, 1)) break;  // stop if end of record data

      i = eyelink_get_next_data(NULL);   // check for new data item

      if(i == MESSAGEEVENT)   // message: check if we need the data
        {
          eyelink_get_float_data(&evt);     // get message
                           // get trial start time from "SYNCTIME" message         
          if(!_strnicmp(evt.im.text, "SYNCTIME", 8))
            {
              trial_start_time = 0;    // offset of 0, if none given
              sscanf(evt.im.text, "%*s %d", &trial_start_time);
              trial_start_time = evt.im.time - trial_start_time;  
            }
#ifdef PRINT_MESSAGES
	  graphic_printf(target_foreground_color, -1, 0, SCRWIDTH/100, j++*SCRHEIGHT/50, 
                    "MESSAGE=%s", evt.im.text);
#endif
        }

#ifdef LOST_DATA_EVENT     // only available in V2.1 or later DLL
      if(i == LOST_DATA_EVENT)   // marks lost data in stream
	alert_printf("Some link data was lost");
#endif

            // CODE FOR PLOTTING GAZE CURSOR 
      if(eyelink_newest_float_sample(NULL)>0)  // new sample?
	{
	  eyelink_newest_float_sample(&evt);  // get the sample data
          x = evt.fs.gx[eye_used];   // get gaze position from sample 
          y = evt.fs.gy[eye_used];

          if(x!=MISSING_DATA && y!=MISSING_DATA &&
             evt.fs.pa[eye_used]>0)  // plot if not in blink
            {                        // plot in local coords  
              draw_gaze_cursor(track2local_x(x), 
                               track2local_y(y));
                      // report gaze position (tracker coords)
              if(ox!=x || oy!=y)   // only draw if changed
                {
                  graphic_printf(target_foreground_color, target_background_color, 
                                 0, (int)(SCRWIDTH*0.87), 0, " %4.0f  ", x);
                  graphic_printf(target_foreground_color, target_background_color, 
                                 0, (int)(SCRWIDTH*0.93), 0, " %4.0f  ", y);
                }
              ox = x;
              oy = y;
            }
          else
            {
	      erase_gaze_cursor();   // hide cursor during blink
	    }
              // print time from start of trial
          graphic_printf(target_foreground_color, target_background_color, 
                         0, (int)(SCRWIDTH*0.75), 0, " % 8d ", 
                         evt.fs.time-trial_start_time);
        }
    }

  erase_gaze_cursor();   // erase gaze cursor if visible
  return 0;
}

