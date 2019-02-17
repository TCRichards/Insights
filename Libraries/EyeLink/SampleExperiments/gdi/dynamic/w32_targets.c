/*********************************************************/
/* Windows 95/98/NT/2000/XP sample experiment in C       */
/* For use with Version 2.0 of EyeLink Windows API       */
/*                                                       */
/*      (c) 1997-2002 by SR Research Ltd.                */
/* For non-commercial use by Eyelink licencees only      */
/*                                                       */
/* THIS FILE: w32_targets.c                        */
/* CONTENTS:                                        
/* - implements moving targets that can change shape     */
/* - targets are drawn on top of a background bitmap     */
/* - square images are blitted over bitmap, and erased   */
/*   by copying sections of background over them         */
/* - a set of shapes are created, shape 0 is invisible   */
/* - targets can be moved or changged by move_target()   */
/* - See documentation for more details                  */  
/*                                                       */
/*                                                       */
/* CHANGES FOR Windows 2000/XP, EyeLink 2.0:  NEW        */
/*********************************************************/

#include <windows.h>
#include <windowsx.h>

#include "gdi_expt.h"
#include "w32_demo.h"  /* header file for this experiment */

#include "w32_targets.h"

/************** CREATE TARGET BITMAPS *************/

#undef NTARGETS
#undef NSHAPES

// NOTES: targets are bitmaps copied to screen directly
// they are erased by restoring background saved before drawing
            
#define NSHAPES 4   // up to 4 patterns (0..3), target 0 is invisible

typedef struct {
       HBITMAP bitmap;  // bitmap
       int h, w;        // height and width
       int xo, yo;      // offset of top-left from plot position
  } SHAPE;

SHAPE shapes[NSHAPES];  


#define NTARGETS 2   // up to 2 targets for saccadic tasks

typedef struct {
       int shape;   // which bitmap
       int drawn;   // is is drawn?
       int x, y;  // top-left motion detect
  } TARGET;

TARGET targets[NTARGETS];


HBITMAP target_background_bitmap;   // bitmap used to erase targets


      // Create the target patterns
      // Targets: 0=none (used to clear), 1=0.5 degree disk, 2=\, 3=/
      // redfine as eeded for your targets
int create_shape(int n, COLORREF fgcolor, COLORREF bgcolor)   
{
  HDC hdc;
  HBITMAP hbm;
  HDC mdc;
  HBRUSH oBrush;
  HPEN   oPen;
  HBITMAP obm;
  int width, height;
  
  hdc = GetDC(NULL);                 
  mdc = CreateCompatibleDC(hdc);     // create display-compatible memory context

  switch(n)                     // set size of target
    {
      case 0:       // invible target
      case 1:       // filled circle
      case 2:        // "\" line                                 
      case 3:        // "/" line
      default:
        width  = (int)((SCRWIDTH/30.0)*0.5);   // all targets are 0.5 by 0.5 degrees
        height = (int)((SCRHEIGHT/22.5)*0.5);
        break;
    }
  shapes[n].w = width;      // initialize shape data
  shapes[n].h = height;
  shapes[n].xo = width/2;
  shapes[n].yo = height/2;
                                     // create target bitmap
  hbm = CreateCompatibleBitmap(hdc, width, height);  // create bitmap
  if(!hbm) 
    {
      DeleteDC(mdc);
      ReleaseDC(NULL, hdc);
      return -1;
    }
  shapes[n].bitmap = hbm;
                                     // clear bitmap background
  obm = SelectObject(mdc, hbm);      
  oBrush = SelectObject(mdc, CreateSolidBrush(bgcolor | 0x02000000L)); 
  PatBlt(mdc, 0, 0, width, height, PATCOPY);
  DeleteObject(SelectObject(mdc, oBrush));

  SetROP2(mdc, R2_COPYPEN);     // make sure we are drawing
  switch(n)                     // draw the target bitmap
    {
      case 0:       // invisible target
      default:
        break;
      case 1:       // filled circle
        oPen = SelectObject(mdc, CreatePen(PS_NULL, 0, 0));   // no outline
        oBrush = SelectObject(mdc, CreateSolidBrush(fgcolor|0x02000000L)); 
        Ellipse(mdc, 0, 0, width-1, height-1);               // draw filled ellipse
        break;
      case 2:        // "\" line                                        // set line pen
        oPen = SelectObject(mdc, CreatePen(PS_SOLID, SCRWIDTH/200, fgcolor|0x02000000L)); 
        MoveToEx(mdc, 0, 0, NULL);
        LineTo(mdc, width-1, height-1);                      // draw "\"
        break;
      case 3:        // "/" line
        oPen = SelectObject(mdc, CreatePen(PS_SOLID, SCRWIDTH/200, fgcolor|0x02000000L)); 
        MoveToEx(mdc, width-1, 0, NULL);                     // draw "/"
        LineTo(mdc, 0, height-1);
        break;
    }

  DeleteObject(SelectObject(mdc, oPen));  // Release the GDI resources
  DeleteObject(SelectObject(mdc, oBrush));
  SelectBitmap(mdc, obm);     
  DeleteDC(mdc);
  ReleaseDC(NULL, hdc);
  return 0;
}


      // Create the target patterns
      // set all targets as not drawn, pattern 0
      // redefine as eeded for your targets
int initialize_targets(COLORREF fgcolor, COLORREF bgcolor)   
{
  int i;

  for(i=0;i<NSHAPES;i++)      // mark targets as uninitialized
    shapes[i].bitmap = NULL;  

  for(i=0;i<NSHAPES;i++)   // create 0.5 degree targets
    create_shape(i, fgcolor, bgcolor);

  for(i=0;i<NTARGETS;i++)  // initialize targets to invisible
    {          
       targets[i].drawn = 0;
       targets[i].shape = 0;
    }
  return 0;
}


    // clean up targets after trial
void free_targets(void)
{
  int i;

  for(i=0;i<NSHAPES;i++)
    if(shapes[i].bitmap)
      {
        DeleteObject(shapes[i].bitmap);
        shapes[i].bitmap = NULL;
      }
}


/************** TARGET DRAW/ERASE/MOVE **************/


     // draw target n, centered at x, y, using shape
     // will only draw if target is erased
void draw_target(int n, int x, int y, int shape)  
{                      
  HBITMAP obm;        // Bitmap data structure
  HDC hdc;          // Display context (to create memory context)
  HDC mdc;          // Memory context to draw bitmap in

  if(shapes[n].bitmap == NULL) return;  // check if valid shape
  if(targets[n].drawn) return;          // don't redraw

  targets[n].drawn = 1;         // mark as drawn
  targets[n].shape = shape;     // record drawing information
  targets[n].x = x;
  targets[n].y = y;

  if(shape == 0) return;   // shape 0 = not visible

  hdc = GetDC(full_screen_window);                // prepare to blit bitmap
  mdc = CreateCompatibleDC(hdc);                  // Memory DC
  obm = SelectObject(mdc, shapes[shape].bitmap);  // Select bitmap into memory DC
                                                  // copy shape to dispaly 
  BitBlt(hdc, x-shapes[shape].xo, y-shapes[shape].yo,   
         shapes[shape].w, shapes[shape].h, mdc, 0, 0, SRCCOPY);
  
  SelectBitmap(mdc, obm);                // Deselect bitmap
  DeleteDC(mdc);                         // get rid of memory DC
  ReleaseDC(full_screen_window, hdc);
}

     // erase target by copying back background bitmap
     // will only erase if target is drawn
void erase_target(int n)  
{                      
  HDC hdc;
  HDC mdc;
  HBITMAP obm;

  if(targets[n].drawn == 0) return;  // check if drawn
  targets[n].drawn = 0;              // mark as erased

  hdc = GetDC(full_screen_window);   // prepare to copy background bitmap
  mdc = CreateCompatibleDC(hdc);    
  obm = SelectObject(mdc, target_background_bitmap); // select background bitmap
  
  BitBlt(hdc,                        // copy proper part of background to display
         targets[n].x-shapes[targets[n].shape].xo, 
         targets[n].y-shapes[targets[n].shape].yo, 
         shapes[targets[n].shape].w,  
         shapes[targets[n].shape].h,  
         mdc, 
         targets[n].x-shapes[targets[n].shape].xo, 
         targets[n].y-shapes[targets[n].shape].yo, 
         SRCCOPY);   // copy relevant part to display

  SelectBitmap(mdc, obm);           // release GDI resources
  DeleteDC(mdc);
  ReleaseDC(full_screen_window, hdc);
}


    // call after screen erased so targets know they're not visible
    // this will permit them to be redrawn
void target_reset(void)
{
  int i;

  for(i=0;i<NTARGETS;i++)
    targets[i].drawn = 0;
}


   // handles moving target, changing shape
   // target will be hidden it if shape = 0
void move_target(int n, int x, int y, int shape)
{
  if(shape == 0)     // hide target only
    {
      erase_target(n);
    }
  else if(shape!=targets[n].shape ||   // only redraw if something changed
          x != targets[n].x || 
          y != targets[n].y ||
          targets[n].drawn == 0)
    {
      erase_target(n);              // erase old target
      draw_target(n, x, y, shape);  // draw with new information
    }
}


