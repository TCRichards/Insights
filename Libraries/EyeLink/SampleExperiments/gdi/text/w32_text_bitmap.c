/**********************************************************/
/* Windows 95/98/NT/2000/XP experiment C support          */
/* For use with Version 2.0 of EyeLink Windows API        */
/*                                                        */
/*      (c) 1997-2002 by SR Research Ltd.                 */
/* For non-commercial use by Eyelink licencees only       */
/*                                                        */
/* THIS FILE: w32_text_bitmap.c                           */
/* CONTENTS:                                              */
/* - draw left-justified text to bitmap,tracker graphics  */
/*                                                        */
/*                                                        */
/* CHANGES FOR Windows 2000/XP, EyeLink 2.0:              */
/* - change header file to w32_exptsppt2.h                */
/* - add GdiFlush after drawing poerations                */
/**********************************************************/
 
#include <windows.h>
#include <windowsx.h>
#include <stdio.h>
#include <io.h>
#include <errno.h>

#include "gdi_expt.h"
#include "w32_demo.h"

/********** DRAW FORMATTED TEXT ***********/

       // Draw text within margins, left-justified, with word-wrap.
       // Draw to <hdc> context, so it supports display and bitmaps   
       // (bitmap must already be created and selected into context).
       // Draw boxes for each word on EyeLink tracker display if <dotrack> set
       // Use font selected with get_new_font(), and draws it in <color>
       // RECT <margins> sets margins, and <lspace> sets pixels between lines
void draw_text_box(HDC hdc, char *txt, COLORREF color, RECT margins, int lspace, int dotrack)
{
  short x, y;              // drawing position
  char *sword, *eword;     // word start, end pointer
  int swx, ewx;            // word start, end position
  char *sispace, *c;       // text pointers
  int height;              // height of characters
  SIZE size;
  TEXTMETRIC tm;

  if(dotrack) eyecmd_printf("clear_screen 0");	// clear eye tracker display

  SetBkMode(hdc, TRANSPARENT);        // set text color
  SetTextColor(hdc, color);
  SelectObject(hdc, current_font);    // Select cached font into context

  GetTextMetrics(hdc, &tm);           // Get height of characters
  height = tm.tmHeight;
  SetTextJustification(hdc, 0, 0) ;   // set normal text spacing
  SetTextAlign(hdc, TA_LEFT | TA_TOP);

  x = (short)margins.left;                   // initial drawing position
  y = (short)margins.top;  
  c = txt;                            // initial text to scan

  while(*c)   // loop through lines of text
    {
nextword:                 // START NEW WORD:
      sispace = c;            // scan over any leading spaces
      while(*c==' ') c++;
      if(c!=sispace)          // advance over the spaces (if any)
        {
          GetTextExtentPoint32(hdc, sispace, c-sispace, &size);                    
          x += (short)size.cx;
        }
      if(*c==0) break;    // handle end-of-text 
      if(*c=='\n')        // handle end-of-line before word
        {
          c++;            // skip over end-of-line character
nextline:                        // START NEW LINE:
          x = (short)margins.left;                      // return to start of line
          y += lspace;                           // top of new  line
          if(y+height > margins.bottom) break;  // stop if it would go outside margins
          goto nextword;                         // continue to print
        }
      swx = x;            // continue in current line: 
      sword = c;                                  // record start of this word
      while(*c && !isspace(*c) && *c!='\n') c++;  // scan till end of word
      if(sword==c) goto nextword;                 // no word: continue by skipping spaces
      eword = c;                                  // record end of word
      GetTextExtentPoint32(hdc, sword, eword-sword, &size);   // width of word                 
      ewx = size.cx + swx;                        // position of end of word
      if(ewx > margins.right)    // would it extend past right margin?
        {
          c = sword;                   // restore text pointer
          goto nextline;               // start a new line with current word
        }
      TextOut(hdc, x, y, sword, eword-sword);      // Print the word
      if(dotrack)                                  // draw box on EyeLink display
          eyecmd_printf("draw_box %d %d %d %d 15", swx, y, ewx, y+height);
      x = ewx;                                     // update current printing location
    }

  GdiFlush();     // ADDED for Wimdows 2000/XP: Forces drawing to be immediate      

  SelectObject(hdc, GetStockObject(SYSTEM_FONT));  // deselect the font
}


/********** DRAW FORMATTED TEXT AND SAVE SEGMENTATION ***********/

       // Draw text within margins, left-justified, with word-wrap.
       // Draw to <hdc> context, so it supports display and bitmaps   
       // (bitmap must already be created and selected into context).
       // Draw boxes for each word on EyeLink tracker display if <dotrack> set
       // Use font selected with get_new_font(), and draws it in <color>
       // RECT <margins> sets margins, and <lspace> sets pixels between lines
	   // Save the segmentation info into the text. 
	   // In the current implementation, the bottom edge of the line N overlaps with the 
	   // top edge of line N+1 and in each line, the left edge of word N overlaps with 
	   // the right edge of word N+1;  
	   // Extra space (twice the width of letter 'M') is added to the the first and 
       // last segments of each line 
void draw_text_box_segment(HDC hdc, char *txt, COLORREF color, 
		RECT margins, int lspace, int dotrack, char *filename)
{
  long x, y;				// drawing position
  int count_AI=0, j;		// count the total number of segments        
  char *sword, *eword, wholeword[200], previous_word[200];     // word start, end pointer, wholeword and prebious word
  int swx, ewx;				// word start, end position
  char *sispace, *c;		// text pointers
  int height ;				// height of characters
  int  end_line=0, previous_end_line=1, further_left, end_text=1;  // check whether it is end of a line  
  SIZE size, M_size;		// Size info (width and height of a rectangle)
  TEXTMETRIC tm;			// Text Metrics
  FILE *seg_file;			// handle to segment file
  RECT previous;			// Rect info for the previous segment


  further_left = margins.left;
  previous.left = margins.left;
  previous.right = margins.left;
  previous.top = margins.top;
  previous.bottom = margins.top;	// Initialization of the previous segment information;

  seg_file = fopen(filename, "wt");		// open segmentation file; overwritten if previous such file exists
  if(!seg_file) 
	eyemsg_printf("Error in opening the file to record segments");
  
  // REQUIRED FOR EVIEW
  if(dotrack) eyecmd_printf("clear_screen 0");	// clear eye tracker display
      
  GetTextExtentPoint32(hdc, "M", 1, &M_size);   // width of word                 
  SetBkMode(hdc, TRANSPARENT);        // set text color
  SetTextColor(hdc, color);
  SelectObject(hdc, current_font);    // Select cached font into context

  GetTextMetrics(hdc, &tm);           // Get height of characters
  height = tm.tmHeight;
  SetTextJustification(hdc, 0, 0) ;   // set normal text spacing
  SetTextAlign(hdc, TA_LEFT | TA_TOP);

  x = margins.left;                   // initial drawing position
  y = margins.top;  
  c = txt;                            // initial text to scan
	
  strcpy(previous_word, "");		 // Intialize strings 
  strcpy(wholeword, "");

  while(*c)   // loop through lines of text
    {
	  end_line=0;

nextword:                 // START NEW WORD:
      sispace = c;            // scan over any leading spaces
      while(*c==' ') c++;
      if(c!=sispace)          // advance over the spaces (if any)
        {
          GetTextExtentPoint32(hdc, sispace, c-sispace, &size);                    
          x += size.cx;
        }
	  
		if(*c==0)			// handle end-of-text 
			break;		
	
		 if(*c=='\n')        // handle end-of-line before word
        {
          c++;            // skip over end-of-line character
nextline: 
		  end_line=1;
// START NEW LINE:
          x = margins.left;                      // return to start of line
          y += lspace;                           // top of new  line
         
		  if(y+height > margins.bottom)			 // Exceeding the page limit
		  {  
			fprintf(seg_file, "RECTANGLE\t%d\t%d\t%d\t%d\t%d\t%s\n",
				count_AI, previous_end_line? (previous.left-2*M_size.cx):(previous.left+further_left)/2, 
				previous.top, end_line?(previous.right+2*M_size.cx):(previous.right+swx)/2, 
				previous.bottom, previous_word);
			
			end_text=0;						// Abnormal end of text	  
			break;  
		  }	  
			   // stop if it would go outside margins
          goto nextword;                         // continue to print
        }
      swx = x;            // continue in current line: 
      sword = c;          // record start of this word
      
	  j=0;
	  while(*c && !isspace(*c) && *c!='\n') 
	  {	  
		  wholeword[j]=*c;
		  j++;
		  c++;				// scan till end of word and copy the word
	  }  
	  wholeword[j]='\0';	// Zero terminate the string
		  
	if(sword==c) goto nextword;                 // no word: continue by skipping spaces

	  eword = c;                                  // record end of word
      GetTextExtentPoint32(hdc, sword, eword-sword, &size);   // width of word                 
      ewx = size.cx + swx;                        // position of end of word
      if(ewx > margins.right)    // would it extend past right margin?
        {
          c = sword;                   // restore text pointer
          goto nextline;               // start a new line with current word
        }
      TextOut(hdc, x, y, sword, eword-sword);      // Print the word
      if(dotrack)                                  // draw box on EyeLink display
          eyecmd_printf("draw_box %d %d %d %d 15", swx, y, ewx, y+height);

    // If it is the first segment in the text.
	if (count_AI==1)
		previous_end_line=1;				

	// General cases: Record the information regarding the last segment;
	if (count_AI>=1)
		fprintf(seg_file, "RECTANGLE\t%d\t%d\t%d\t%d\t%d\t%s\n",
			count_AI, previous_end_line? (previous.left-2*M_size.cx):(previous.left+further_left)/2, 
			previous.top, end_line?(previous.right+2*M_size.cx):(previous.right+swx)/2, 
			previous.bottom, previous_word);


	  further_left = previous.right;		    // The right border of the word before the previous word 
	  previous.left=swx;
	  previous.right=ewx;
	  previous.top=y-(lspace-height)/2;
	  previous.bottom=y+(height+lspace)/2;
	  strcpy(previous_word, wholeword);
	  previous_end_line=end_line;				// Record information regarding the last segment

	  x = ewx;                                  // update current printing location
	  count_AI++;												
 }

  // Normal ending of the text: record the current segment info
  if (end_text)
	fprintf(seg_file, "RECTANGLE\t%d\t%d\t%d\t%d\t%d\t%s\n",
		count_AI, previous_end_line? (previous.left-2*M_size.cx):(swx+further_left)/2, y-(lspace-height)/2, 
		ewx+2*M_size.cx, y+(height+lspace)/2, wholeword);

  GdiFlush();     // ADDED for Wimdows 2000/XP: Forces drawing to be immediate      

  SelectObject(hdc, GetStockObject(SYSTEM_FONT));  // deselect the font
  fclose(seg_file);
}


/************ CREATE BITMAP WITH FORMATTED TEXT ***********/

      // Draw text to full-screen sized bitmap, cleared to <bgcolor>
      // Draw boxes for each word on EyeLink tracker display if <dotrack> set
      // Use font selected with get_new_font(), and draws it in <fgcolor>
      // RECT <margins> sets margins, and <lspace> sets pixels between lines
HBITMAP text_bitmap(char *txt, COLORREF fgcolor, COLORREF bgcolor, 
                               RECT margins, int lspace, int dotrack)
{
  HDC hdc;
  HBITMAP hbm;
  HDC mdc;
  HBRUSH oBrush;
  HBITMAP obm;

  hdc = GetDC(NULL);                 
  mdc = CreateCompatibleDC(hdc);     // create display-compatible memory context
  hbm = CreateCompatibleBitmap(hdc, SCRWIDTH, SCRHEIGHT);
  obm = SelectObject(mdc, hbm);      // create DDB bitmap, select into context
                                     
  oBrush = SelectObject(mdc, CreateSolidBrush(bgcolor | 0x02000000L));  // brush to fill with 
  PatBlt(mdc, 0, 0, SCRWIDTH, SCRHEIGHT, PATCOPY);                      // CLEAR BITMAP
  DeleteObject(SelectObject(mdc, oBrush));

  draw_text_box(mdc, txt, fgcolor, margins, lspace, dotrack);  // DRAW THE TEXT

  GdiFlush();     // ADDED for Wimdows 2000/XP: Forces drawing to be immediate      

  SelectBitmap(mdc, obm);     // Release the GDI resources
  DeleteDC(mdc);
  ReleaseDC(NULL, hdc);
  return hbm;                 // Return the new bitmap
}


/************ CREATE BITMAP WITH FORMATTED TEXT AND SAVE SEGMENTATION INFO ***********/

      // Draw text to full-screen sized bitmap, cleared to <bgcolor>
      // Draw boxes for each word on EyeLink tracker display if <dotrack> set
      // Use font selected with get_new_font(), and draws it in <fgcolor>
      // RECT <margins> sets margins, and <lspace> sets pixels between lines
	  // <dottrack> determines whether outlines of the word segment is displayed over the tracker PC.
	  // Splice the path and filename to record the segmentation information
	  // If the segmentation file already exists, it will not overwritten the file 
	  // if <sv_options> is set as SV_NOREPLACE
HBITMAP text_bitmap_segment(char *txt, COLORREF fgcolor, COLORREF bgcolor, 
                  RECT margins, int lspace, int dotrack, char *fname, char *path, INT16 sv_options)
{
  HDC hdc;
  HBITMAP hbm;
  HDC mdc;
  HBRUSH oBrush;
  HBITMAP obm;
  char com_fname[200];

  hdc = GetDC(NULL);                 
  mdc = CreateCompatibleDC(hdc);     // create display-compatible memory context
  hbm = CreateCompatibleBitmap(hdc, SCRWIDTH, SCRHEIGHT);
  obm = SelectObject(mdc, hbm);      // create DDB bitmap, select into context
                                     
  oBrush = SelectObject(mdc, CreateSolidBrush(bgcolor | 0x02000000L));  // brush to fill with 
  PatBlt(mdc, 0, 0, SCRWIDTH, SCRHEIGHT, PATCOPY);                      // CLEAR BITMAP
  DeleteObject(SelectObject(mdc, oBrush));

  create_path(path, 1, 1);			// Create path if it does not exist 
  splice_fname(fname, path, com_fname);   // Splice 'path' to 'fname', store in 'com_fname'
 
  if (!file_exists(com_fname) || sv_options!=SV_NOREPLACE)    
	draw_text_box_segment(mdc, txt, fgcolor, margins, lspace, dotrack, com_fname);  
			// DRAW THE TEXT AND SAVE SEGMENTATION OF THE TEXT
  else
	draw_text_box(mdc, txt, fgcolor, margins, lspace, dotrack);  
			// DRAW THE TEXT ONLY WITHOUT SAVING
  
  GdiFlush();     // ADDED for Wimdows 2000/XP: Forces drawing to be immediate      

  SelectBitmap(mdc, obm);     // Release the GDI resources
  DeleteDC(mdc);
  ReleaseDC(NULL, hdc);
  return hbm;                 // Return the new bitmap
}