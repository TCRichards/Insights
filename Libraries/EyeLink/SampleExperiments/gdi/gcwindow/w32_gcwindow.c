/**********************************************************/
/* Windows 95/98/NT/2000/XP experiment C support          */
/* For use with Version 2.0 of EyeLink Windows API        */
/*                                                        */
/*      (c) 1997-2002 by SR Research Ltd.                 */
/* For non-commercial use by Eyelink licencees only       */
/*                                                        */
/* THIS FILE: w32_gcwindow.c                              */
/* CONTENTS:                                              */
/* - draw and move rectangular gaze-contingent window     */
/*                                                        */
/*                                                        */
/* CHANGES FOR Windows 2000/XP, EyeLink 2.0:              */
/* - now included in developer's kit                      */
/* - use GdiSetBatchLimit() to allow erasing and drawing  */
/*   of differences with minimum possible delay           */  
/**********************************************************/

#include <windows.h>
#include <windowsx.h>

#include "gdi_expt.h"

/************* DISPLAY PART OF BITMAP **********/

        // Copies a rectangular area of a bitmap to the display
        // Copies rectangle <xs1, ys1, xs2, ys2> of DDB <hbm> 
        // Places top-left corner at <xd, yd> 
        // <hbm> is source bitmap, <hwnd> is the window to draw to
static void display_rect_bitmap(HWND hwnd, HBITMAP hbm, int xd, int yd, 
                                int xs1, int ys1, int xs2, int ys2)
{
  HDC hdc;
  HDC mdc;
  HBITMAP obm;
  int h, w;

  if(!hwnd || !hbm) return;
  w = xs2 - xs1 + 1;
  h = ys2 - ys1 + 1;

  hdc = GetDC(hwnd);                // display drawing context
  mdc = CreateCompatibleDC(hdc);    // memory context
  obm = SelectObject(mdc, hbm);     // select bitmap
  
  BitBlt(hdc, xd, yd, w, h, mdc, xs1, ys1, SRCCOPY);   // copy relevant part to display

  SelectBitmap(mdc, obm);           // release GDI resources
  DeleteDC(mdc);
  ReleaseDC(hwnd, hdc);
}



/********** FAST GAZE-CONTINGENT WINDOW ************/
  
        // This gaze-contingent window uses differential updates for speed.
        // If the window moves a small amount, then only a small area
        // of the display will actually need to be redrawn.
        // These functions identify and update the regions 
        // that need to be redrawn using the foreground and background bitmaps.
 
        // This variable determines if the foreground or background area is redrawn first.
        // If <erase_first> is zero, then the background area is updated first.  
        // This will help to hide visual information in the window.
        // Otherwise, the foreground area is updated first, to hide information outside.
        // So it should be set only if the window is masking foveal information.
static int erase_first = 1;

static int window_w = 90;     // the width of the window in pixels
static int window_h = 75;     // The height of the window in pixels

static int curr_wl, curr_wr;  // The sides of the window as currently drawn
static int curr_wt, curr_wb;

#define GCWINDOQW_HIDDEN   0     // window not visible
#define GCWINDOQW_VISIBLE  1     // window visible
#define GCWINDOQW_INIT    -1     // window not yet drawn

static int window_drawn;      // window state (on of the GCWINDOW_xxx values).

static int last_x, last_y;    // last drawn position, for motion detection
static int wdeadband;

static HWND hwnd;      // the window we will draw in
static RECT dr;        // the display rectangle
static HBITMAP fgbm;   // foreground bitmap
static HBITMAP bgbm;   // background bitmap

        // Initial setup of gaze-contingent window before drawing it.
        // Sets size of window, and whether it is a foveal mask.
        // If height or width is -1, the window will be a bar covering the display
        // <deadband> sets number of pixels of anti-jitter applied  
void CALLTYPE initialize_gc_window(int wwidth, int wheight, 
                          HBITMAP window_bitmap, HBITMAP background_bitmap,
                          HWND window, RECT display_rect, int is_mask, int deadband)    
{
  window_w = wwidth;        // set window parameters
  window_h = wheight;
  erase_first = !is_mask;

  window_drawn = GCWINDOQW_INIT;       // "false" window covers full screen 
  dr = display_rect;
  hwnd = window;
  fgbm = window_bitmap;
  bgbm = background_bitmap;
  
  curr_wt = dr.top;             // This will properly draw window and background
  curr_wl = dr.left;
  curr_wr = dr.right;
  curr_wb = dr.bottom;


  wdeadband = deadband;
  last_x = last_y = MISSING;
}

#define MIN(a,b) ((a<b)?(a):(b))
#define MAX(a,b) ((a>b)?(a):(b))

        // Fill in required areas with background bitmap 
static void erase_gc_window(HBITMAP fg, HBITMAP bg, int wl, int wt, int wr, int wb)
{
  if(wt>curr_wb || wb<curr_wt || wl>curr_wr || wr<curr_wl)  // if no intersection,
    {                                                       // just erase current window
      display_rect_bitmap(hwnd, bg, curr_wl, curr_wt,
                                                  curr_wl, curr_wt, curr_wr, curr_wb);
    }
  else                  // otherwise, update non-intersecting regions 
    {
      if(curr_wt<wt)    // erase any needed top
	display_rect_bitmap(hwnd, bg, curr_wl, curr_wt, 
                                                    curr_wl, curr_wt, curr_wr, wt-1);

      if(curr_wb>wb)    // erase any needed bottom
	display_rect_bitmap(hwnd, bg, curr_wl, wb+1, 
                                                    curr_wl, wb+1, curr_wr, curr_wb);

      if(curr_wl<wl)    // erase any needed left
	display_rect_bitmap(hwnd, bg, curr_wl, MAX(wt, curr_wt),
                                                    curr_wl, MAX(wt, curr_wt),
                                                    wl-1, MIN(wb, curr_wb));
      if(curr_wr>wr)    // erase any needed right
	display_rect_bitmap(hwnd, bg, wr+1, MAX(wt, curr_wt),
                                                    wr+1, MAX(wt, curr_wt),
					            curr_wr, MIN(wb, curr_wb));
    }
}

        // Fill in required areas with foreground bitmap 
static void draw_gc_window(HBITMAP fg, HBITMAP bg, int wl, int wt, int wr, int wb)
{
  if( wt>curr_wb || wb<curr_wt ||        // if no intersection or window not drawn:
      wl>curr_wr || wr<curr_wl || 
      window_drawn==GCWINDOQW_INIT )    
    {                                   // just fill in all of window
      display_rect_bitmap(hwnd, fg, wl, wt, wl, wt, wr, wb);
    }
  else                  // Otherwise, fill in new regions
    {
      if(wt<curr_wt)    // draw any needed top
	display_rect_bitmap(hwnd, fg, wl, wt, wl, wt, wr, curr_wt-1);

      if(wb>curr_wb)    // draw any needed bottom
	display_rect_bitmap(hwnd, fg, wl, curr_wb+1, wl, curr_wb+1, wr, wb);

      if(wl<curr_wl)    // draw any needed left
	display_rect_bitmap(hwnd, fg, wl, MAX(wt, curr_wt),
                                                    wl, MAX(wt, curr_wt),
				                    curr_wl-1, MIN(wb, curr_wb));
      if(wr>curr_wr)    // draw any needed right
	display_rect_bitmap(hwnd, fg, curr_wr+1, MAX(wt, curr_wt),
                                                    curr_wr+1, MAX(wt, curr_wt),
					            wr, MIN(wb, curr_wb));
    }
}

       // Draw GC window at a new location
       // The first time window is drawn, 
       // the background outside the window will be filled in too.
       // If X or Y is MISSING_DATA (defined in eyelink.h), window is hidden. 
void CALLTYPE redraw_gc_window(int x, int y)
{
  int wt, wl, wb, wr;

  if(last_x==MISSING_DATA || x==MISSING_DATA) last_x = x;    // record old position if valid
  else if(x < last_x-wdeadband) x = last_x = x+wdeadband;    // deadband filter
  else if(x > last_x+wdeadband) x = last_x = x-wdeadband;
  else x = last_x;

  if(last_y==MISSING_DATA  || y==MISSING_DATA) last_y = y;   // same for Y coordinate
  else if(y < last_y-wdeadband) y = last_y = y+wdeadband;
  else if(y > last_y+wdeadband) y = last_y = y-wdeadband;
  else y = last_y;

  wt = (window_h<0) ? dr.left   : y - (window_h>>1);          // compute new window edges
  wb = (window_h<0) ? dr.bottom : wt + window_h - 1;  
  wl = (window_w<0) ? dr.left   : x - (window_w>>1);
  wr = (window_w<0) ? dr.right  : wl + window_w - 1;

  GdiSetBatchLimit(50);  // allow ops to accumulate

  if(erase_first)    // draw background first
    {
      if(window_drawn != GCWINDOQW_HIDDEN) 
      erase_gc_window(fgbm, bgbm, wl, wt, wr, wb);  
      if(x==MISSING_DATA || y==MISSING_DATA)  // window is not visible
        {
          window_drawn = GCWINDOQW_HIDDEN;
          return;
        }
      draw_gc_window(fgbm, bgbm, wl, wt, wr, wb);
    }
  else              // draw foreground first
    {
      if(x==MISSING_DATA || y==MISSING_DATA)   // window is not visible
        {
          if(window_drawn != GCWINDOQW_HIDDEN) 
            erase_gc_window(fgbm, bgbm, wl, wt, wr, wb);
          window_drawn = GCWINDOQW_HIDDEN;
          return;
        }
      draw_gc_window(fgbm, bgbm, wl, wt, wr, wb);
      if(window_drawn != GCWINDOQW_HIDDEN) 
        erase_gc_window(fgbm, bgbm, wl, wt, wr, wb);
    }

  wait_for_drawing(NULL);   // make sure we are not delayed
  GdiSetBatchLimit(1);      // restore immediate drawing

  curr_wl = wl;   // record new window edges.
  curr_wr = wr;
  curr_wt = wt;
  curr_wb = wb;
  window_drawn = GCWINDOQW_VISIBLE;
}


