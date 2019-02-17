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
/* NEW FOR Windows 2000/XP, EyeLink API 2.10 or later    */
/*********************************************************/

#include <windows.h> 
#include <stdlib.h>

#include "gdi_expt.h"
#include "w32_demo.h"

      // functions to map gaze from tracker to local pixels
extern INT16 track2local_x(INT16 x);
extern INT16 track2local_y(INT16 y);


/************** GAZE POSITION CURSOR **************/

static int last_cursor_x, last_cursor_y; // cursor rect for erase
static int gaze_cursor_drawn = 0; 

                    // draw or erase cursor
void invert_gaze_cursor(int x, int y)  
{                      
  HPEN oPen;
  HBRUSH oBrush;                
  HDC hdc;
                    // check for valid position                  
  if(x==MISSING || y==MISSING || !full_screen_window) return;
                    // set up to draw hollow green cursor 
  hdc = GetDC(full_screen_window);  
  oBrush = SelectObject(hdc, GetStockObject(NULL_BRUSH));
  oPen = SelectObject(hdc, CreatePen(PS_SOLID,SCRWIDTH/200, RGB(0,255,0)));
                    // invert cursor colors (black->green, or green->black)
  SetROP2(hdc, R2_XORPEN);
  Ellipse(hdc, x-SCRWIDTH/60, y-SCRHEIGHT/45, x+SCRWIDTH/60, y+SCRHEIGHT/45);
  GdiFlush();
                    // restore DC to default state
  SetROP2(hdc, R2_COPYPEN);
  SelectObject(hdc, oBrush);
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


/********* PERFORM AN EXPERIMENTAL TRIAL  *******/
	 
int record_mode_display(void)
{
  ALLF_DATA evt;
  UINT16 key;
  int eye_used = -1;   // which eye to show gaze for
  float x, y;	       // gaze position 
  float ox=-1, oy=-1;  // old gaze position (to determine change) 

                                 // create font for position display
  get_new_font( "Arial", SCRWIDTH/50, 0);
  gaze_cursor_drawn = 0;         // init gaze cursor state
  while(getkey()) {};		 // dump any pending local keys 

        // enable link data reception without changing tracker mode
  eyelink_reset_data(1);   
  eyelink_data_switch(RECORD_LINK_SAMPLES | RECORD_LINK_EVENTS);
  
  while(1)    // loop while in record mode
    {
      if(eyelink_tracker_mode() != EL_RECORD_MODE) break;

      key = getkey();            // Local keys/abort test
      if(key==TERMINATE_KEY)     // test ALT-F4 or end of execution
         break;
      else if(key)             // OTHER: echo to tracker for control
	 eyelink_send_keybutton(key,0,KB_PRESS);

               // CODE FOR PLOTTING GAZE CURSOR 
      if(eyelink_newest_float_sample(NULL)>0)  // new sample?
	{
	  eyelink_newest_float_sample(&evt);  // get the sample data
	  if(eye_used == -1)   // set which eye to track by first sample
	    {
	      eye_used = eyelink_eye_available(); 
	      if(eye_used == BINOCULAR)  // use left eye if both tracked
	         eye_used = LEFT_EYE;
	    }
	  else
	    {
	      x = evt.fs.gx[eye_used];   // get gaze position from sample 
	      y = evt.fs.gy[eye_used];

	      if(x!=MISSING_DATA && y!=MISSING_DATA &&
	         evt.fs.pa[eye_used]>0)  // plot if not in blink
                {                        // plot in local coords  
	           draw_gaze_cursor(track2local_x((INT16)x), 
                                    track2local_y((INT16)y));
                              // report gaze position (tracker coords)
                   if(ox!=x || oy!=y)   // only draw if changed
                     {
                       graphic_printf(target_foreground_color, target_background_color, 
                                      0,(int) (SCRWIDTH*0.87), 0, " %4.0f  ", x);
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
                         // print tracker timestamp of sample
               graphic_printf(target_foreground_color, target_background_color, 
                              0, (int)(SCRWIDTH*0.75), 0, " % 8d ", evt.fs.time);
	     }
	}
    }	

  erase_gaze_cursor();   // erase gaze cursor if visible
  return 0;
}

