/**********************************************************/
/* Windows 95/98/NT/2000/XP experiment C support          */
/* For use with Version 2.0 of EyeLink Windows API        */
/*                                                        */
/*      (c) 1997-2002 by SR Research Ltd.                 */
/* For non-commercial use by Eyelink licencees only       */
/*                                                        */
/* THIS FILE: w32_grid_bitmap.c                           */
/* CONTENTS:                                              */
/* - draw bitmap containing grid of colored letters       */
/* - also draw boxes on tracker display for reference     */
/*                                                        */
/*                                                        */
/* CHANGES FOR Windows 2000/XP, EyeLink 2.0:              */
/* - change header file to w32_exptsppt2.h                */
/**********************************************************/
 

#include <windows.h>
#include <windowsx.h>
#include <stdio.h>

#include "gdi_expt.h"
#include "w32_demo.h"       /* header file for this experiment */


/*********** DRAW GRID OF LETTERS ************/

                          // 5 colors used to draw the grid of letters
COLORREF lettercolor[5] = { PALETTERGB( 0xFF, 0xFF, 0x60 ),
                            PALETTERGB( 0x60, 0xcF, 0xFF ),
                            PALETTERGB( 0xFF, 0x00, 0xFF ),  
                            PALETTERGB( 0x00, 0xFF, 0x40 ),  
                            PALETTERGB( 0xFF, 0xFF, 0xFF ) };

       // Draws a grid of letters to a DDB bitmap                
       // This can be rapidly copied to the display
       // Also draw boxes to the EyeLink tracker display for feedback
       // Returns: Handle of bitmap
HBITMAP draw_grid_to_bitmap(void)
{
  short i, j, x, y;
  char b[2] = "A";  // The character
  RECT r;           // RECT to draw character in
  HDC hdc;          // Display context (to create memory context)
  HDC mdc;          // Memory context to draw bitmap in
  HBITMAP hbm;      // The bitmap we are creating
  HBRUSH oBrush;    // Old GDI brush, bitmap
  HBITMAP obm;
                    // CREATE THE BITMAP
  hdc = GetDC(NULL);                                       // Display DC
  mdc = CreateCompatibleDC(hdc);                           // Memory DC
  hbm = CreateCompatibleBitmap(hdc, SCRWIDTH, SCRHEIGHT);  // Device-dependent bitmap
  obm = SelectObject(mdc, hbm);                            // attach to memory DC for drawing
                     // CLEAR THE BITMAP
  oBrush = SelectObject(mdc, 
      CreateSolidBrush(0x02000000L|target_background_color)); // Brush to clear with
  PatBlt(mdc, 0, 0, SCRWIDTH, SCRHEIGHT, PATCOPY);                       // Clear all of bitmap
  DeleteObject(SelectObject(mdc, oBrush));                               // Get rid of brush

  eyecmd_printf("clear_screen 0");     // clear eye tracker display
                     
                    // SET UP TEXT FOR DRAWING (do directly)
  SetBkMode(mdc, TRANSPARENT);                  // don't clear background
  get_new_font("Arial Bold", SCRWIDTH/25, 0);   // set up the font
  SelectFont(mdc, current_font);                // select font into memory DC

  x = SCRWIDTH/5;          // set grid spacing
  y = SCRHEIGHT/5;
  for(j=y/2;j<5*y;j+=y)    // step through 5x5 grid of a-y
    for(i=x/2;i<5*x;i+=x)   
      {
        SetTextColor(mdc, lettercolor[(i/x+j/y)%5]);     // set text color
        r.top = j - (SCRHEIGHT/36);                      // Rectangle centered on character 
        r.bottom = r.top + (SCRHEIGHT/18);
        r.left = i - (SCRWIDTH/50);
        r.right = r.left + (SCRWIDTH/25);
        DrawText(mdc, b, -1, &r, DT_CENTER|DT_VCENTER);  // Draw character directly
        b[0]++;                                          // Next letter
		
		eyecmd_printf("draw_box %d %d %d %d 15",         // Reference box on EyeLink tracker display
                       r.left, r.top, r.right, r.bottom);
       }
     
  
  // CLEAN UP AFTER DRAWING
  SelectFont(mdc, GetStockObject(SYSTEM_FONT));    // Deselect font
  SelectBitmap(mdc, obm);                          // Deselect bitmap
  DeleteDC(mdc);                                   // Get rid of drawing contexts
  ReleaseDC(NULL, hdc);
  return hbm;                                      // Return handle to new bitmap
}

       // Draws a grid of letters to a DDB bitmap                
       // This can be rapidly copied to the display
       // Also draw boxes to the EyeLink tracker display for feedback
       // Returns: Handle of bitmap
HBITMAP draw_grid_to_bitmap_segment(char *filename, char*path, int dotrack)
{
  short i, j, x, y, count=1;
  char b[2] = "A";  // The character
  RECT r;           // RECT to draw character in
  HDC hdc;          // Display context (to create memory context)
  HDC mdc;          // Memory context to draw bitmap in
  HBITMAP hbm;      // The bitmap we are creating
  HBRUSH oBrush;    // Old GDI brush, bitmap
  HBITMAP obm;
  FILE *seg_file; 
  char com_fname[100];

  create_path(path, 1, 1);			// Create path if it does not exist 
  splice_fname(filename, path, com_fname);   // Splice 'path' to 'fname', store in 'com_fname'

  seg_file = fopen(com_fname, "wt");		// open segmentation file; overwritten if previous such file exists
  if(!seg_file) 
	eyemsg_printf("Error in opening the file to record segments");

  // CREATE THE BITMAP
  hdc = GetDC(NULL);                                       // Display DC
  mdc = CreateCompatibleDC(hdc);                           // Memory DC
  hbm = CreateCompatibleBitmap(hdc, SCRWIDTH, SCRHEIGHT);  // Device-dependent bitmap
  obm = SelectObject(mdc, hbm);                            // attach to memory DC for drawing
                     // CLEAR THE BITMAP
  oBrush = SelectObject(mdc, 
      CreateSolidBrush(0x02000000L|target_background_color)); // Brush to clear with
  PatBlt(mdc, 0, 0, SCRWIDTH, SCRHEIGHT, PATCOPY);                       // Clear all of bitmap
  DeleteObject(SelectObject(mdc, oBrush));                               // Get rid of brush

  eyecmd_printf("clear_screen 0");     // clear eye tracker display
                     
                    // SET UP TEXT FOR DRAWING (do directly)
  SetBkMode(mdc, TRANSPARENT);                  // don't clear background
  get_new_font("Arial Bold", SCRWIDTH/25, 0);   // set up the font
  SelectFont(mdc, current_font);                // select font into memory DC

  x = SCRWIDTH/5;          // set grid spacing
  y = SCRHEIGHT/5;
  for(j=y/2;j<5*y;j+=y)    // step through 5x5 grid of a-y
    for(i=x/2;i<5*x;i+=x)   
      {
        SetTextColor(mdc, lettercolor[(i/x+j/y)%5]);     // set text color
        r.top = j - (SCRHEIGHT/36);                      // Rectangle centered on character 
        r.bottom = r.top + (SCRHEIGHT/18);
        r.left = i - (SCRWIDTH/50);
        r.right = r.left + (SCRWIDTH/25);
        DrawText(mdc, b, -1, &r, DT_CENTER|DT_VCENTER);  // Draw character directly
		
		if (dotrack)									 // Reference box on EyeLink tracker display
			eyecmd_printf("draw_box %d %d %d %d 15",        
                       r.left, r.top, r.right, r.bottom);
      
		fprintf(seg_file, "TEXT\t%d\t%d\t%d\t%d\t%d\t%s\n",
			count, (count-1)%5*SCRWIDTH/5, (count-1)/5*SCRHEIGHT/5, 
			((count-1)%5+1)*SCRWIDTH/5, ((count-1)/5+1)*SCRHEIGHT/5, b);  
					// write to the segmentation file;
        
		b[0]++;  
		count ++; // Next letter
	
	}
                        // CLEAN UP AFTER DRAWING
  SelectFont(mdc, GetStockObject(SYSTEM_FONT));    // Deselect font
  SelectBitmap(mdc, obm);                          // Deselect bitmap
  DeleteDC(mdc);                                   // Get rid of drawing contexts
  ReleaseDC(NULL, hdc);
  
  fclose(seg_file);
  return hbm;                                      // Return handle to new bitmap
}

