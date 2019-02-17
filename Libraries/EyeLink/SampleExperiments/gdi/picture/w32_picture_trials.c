/*****************************************************/
/* Windows 95/98/NT/2000/XP sample experiment in C   */
/* For use with Version 2.0 of EyeLink Windows API   */
/*                                                   */
/*      (c) 1997-2002 by SR Research Ltd.            */
/* For non-commercial use by Eyelink licencees only  */
/*                                                   */
/* THIS FILE: w32_picture_trials.c                   */
/* CONTENTS:                                         */
/* - run_trials() loops through trials, and handles  */
/*   aborted/repeated trial requests                 */
/* - do_text_trial() interperts trial number         */
/*   and supplies appropriate TRIALID label and      */
/*   creates a stimulus bitmap for each trial        */
/* - See documentation for more details              */  
/*                                                   */
/*                                                   */
/* CHANGES FOR Windows 2000/XP, EyeLink 2.0:         */
/* - use w32_exptsppt.h                              */
/* - add end_realtime_mode() to clean up trials      */
/* - use image_file_bitmap() to load images          */
/*****************************************************/

#include <windows.h>
#include <windowsx.h>
#include <stdio.h>
#include "gdi_expt.h"
#include "w32_demo.h"  /* header file for this experiment */
 
char *images[3] = { "images/sacrmeto.jpg", "images/sac_blur.jpg", "images/composite.jpg" };

	// Retrieves the width information for the specified bitmap
	// hbm: handle to the bitmap object
	// GetObject function retrieves information for the specified graphics object
int bitmap_width(HBITMAP hbm)
{
  BITMAP bm;
  GetObject(hbm, sizeof(bm), &bm);
  return bm.bmWidth;
}	


	// Retrieves the height information for the specified bitmap
	// hbm: handle to the bitmap object
	// GetObject function retrieves information for the specified graphics object
int bitmap_height(HBITMAP hbm)
{
  BITMAP bm;
  GetObject(hbm, sizeof(bm), &bm);
  return bm.bmHeight;
}	



	// Adds individual pieces of source bitmap to create a composite picture
	// Top-left placed at (x,y)
	// If either the width or height of the display is 0, simply copy the bitmap 
	// to the display without chaning its size. Otherwise, stretches the bitmap to to 
	// fit the dimensions of the destination display area
int add_bitmap(HBITMAP src, HBITMAP dst, int x, int y, int width, int height)
{
  HDC src_mdc, dst_mdc;
  HBITMAP osrc, odst;
	
  dst_mdc = CreateCompatibleDC(NULL);	// Create a memory context for BITMAP
  src_mdc = CreateCompatibleDC(NULL);
  odst = SelectObject(dst_mdc, dst);	// Select bitmap into memory DC
  osrc = SelectObject(src_mdc, src);
  
  
  if(width==0 || height==0)
    BitBlt( dst_mdc, x, y, bitmap_width(src), bitmap_height(src), src_mdc, 0, 0, SRCCOPY);	
	// Use BitBlt to copy to display, do not resize
  else
    StretchBlt( dst_mdc, x, y, width, height, src_mdc, 0, 0, 
                bitmap_width(src), bitmap_height(src), SRCCOPY);	
  // Use StretchBlt to stretch and copy to display	
  
  SelectObject(dst_mdc, odst);			// release GDI resources
  SelectObject(src_mdc, osrc);
  DeleteDC(dst_mdc);
  DeleteDC(src_mdc);

  return 0;
}


	// Creates a composite bitmap based on individual pieces
HBITMAP composite_image(void)
{
  int i;
  char		segment_message[200];	// store segment information  
  HBITMAP	bkgr, img;				// Handle to the background and forground bitmaps;
  char		*small_images[4]={"images/hearts.jpg", "images/party.jpg", 
						 "images/squares.jpg", "images/purses.jpg"}; //Filenames of the four small images
  POINT points[4]={{0, 0}, {SCRWIDTH/2, 0}, {0, SCRHEIGHT/2}, {SCRWIDTH/2, SCRHEIGHT/2}}; 
	// The x,y coordinates of the top-left corner of the region where
	// the individual small image is displayed


  // Create a blank bitmap on which the smaller images are overlaid
  bkgr = blank_bitmap(RGB(128,128,128));		
  if(!bkgr) 
	  return NULL;

  // loop through four small images
  for (i=0; i<4; i++)  
  {	
	// Load the small images, keep the original size
	// If the image can not be loaded, delete the created blank bitmap;
	img = image_file_bitmap(small_images[i], 1, 0, 0, 0);		
	if(!img)
		goto cleanup;

	// Add the current bitmap to the blank bitmap at x, y position, resizing the 
	// bitmap to the specified width and height
	// If the original size is to be kept, set the width and height paremeters to 0
	add_bitmap(img, bkgr, points[i].x, points[i].y, SCRWIDTH/2, SCRHEIGHT/2);	
 
	// IMGLOAD command is recorded for EyeLink Data Viewer analysis
    // It displays a default image on the overlay mode of the trial viewer screen. 
    // Writes the image filename + path info
	// The IMGLOAD TOP_LEFT command specifies an image to use as a segment of the 
	// spatial overlay view with specific top left x,y coordinates and image width and height 					
	eyemsg_printf("!V IMGLOAD TOP_LEFT %s %d %d %d %d", small_images[i], 
		points[i].x, points[i].y, SCRWIDTH/2, SCRHEIGHT/2); 
  
	// IAREA command is recorded for EyeLink Data Viewer analysis
	// Another way of handling segment information by recording the content field 
	// in IAREA RECTANGLE command.
	// The fields are: segment id, (x, y) coordinate of top-left and bottom-right positions
	sprintf(segment_message, "!V IAREA RECTANGLE %d %d %d %d %d %s", 
	       i+1, points[i].x, points[i].y, 
		   points[i].x + SCRWIDTH/2, points[i].y + SCRHEIGHT/2, small_images[i]);
	// Record the segment info into the recording session 
	eyemsg_printf(segment_message);
	
	// Be sure to delete bitmap handle before re-using it.
	DeleteObject(img);
  }

  ///*** Important: Don't send more than 10 messages every 20 milliseconds, 
  ///***  or the EyeLink tracker may not be able to write them all to the EDF file 
  return bkgr;
 
cleanup:
  DeleteObject(bkgr);
  return NULL;
}


// Create a trial bitmap 
HBITMAP create_image_bitmap(int num)
{ 

  target_foreground_color = RGB(0,0,0);         // color of calibration target
  target_background_color = RGB(128,128,128);   // background for drift correction
  set_calibration_colors(target_foreground_color, target_background_color); // tell EXPTSPPT the colors

  clear_full_screen_window(target_background_color);
  eyecmd_printf("clear_screen 0");                   // clear EyeLink display
  eyecmd_printf("draw_box %d %d %d %d 15",          // Box around fixation point
           SCRWIDTH/2-16, SCRHEIGHT/2-16, SCRWIDTH/2+16, SCRHEIGHT/2+16);

// NOTE:  *** THE FOLLOWING TEXT SHOULD NOT APPEAR IN A REAL EXPERIMENT!!!! ****
  get_new_font("Arial", 24, 1);
  graphic_printf(target_foreground_color, -1, 1, SCRWIDTH/2, SCRHEIGHT/2, "Loading image...");

  // IMGLOAD command is recorded for EyeLink Data Viewer analysis
  // It displays a default image on the overlay mode of the trial viewer screen. 
  // Writes the image filename + path info
  switch(num)
    {  
      case 0:     // normal image
        eyemsg_printf("!V IMGLOAD FILL images/sacrmeto.jpg");
		return image_file_bitmap("images/sacrmeto.jpg", 0, SCRWIDTH,SCRHEIGHT,target_background_color);
      case 1:     // blurred image
        eyemsg_printf("!V IMGLOAD FILL images/sac_blur.jpg");
        return image_file_bitmap("images/sac_blur.jpg", 0, SCRWIDTH,SCRHEIGHT,target_background_color);
      case 2:     // composite image
        return composite_image();
    }

  return NULL;
}


/*********** TRIAL SETUP AND RUN **********/

#define NTRIALS 3

char *imgname[NTRIALS] = {"Normal", "Blurred", "Composite"};

         // FOR EACH TRIAL:
         // - set title, TRIALID
         // - Create bitmaps and EyeLink display graphics
         // - Check for errors in creating bitmaps
         // - Run the trial recording loop
         // - Delete bitmaps
         // - Return any error code

              // Given trial number, execute trials
              // Returns trial result code
int do_picture_trial(int num)
{
  HBITMAP bitmap;
  int i;

  // This supplies the title at the bottom of the eyetracker display 
  eyecmd_printf("record_status_message '%s, TRIAL %d/%d' ", imgname[num-1], num, NTRIALS);

  // Always send a TRIALID message before starting to record. 
  // It should contain trial condition data required for analysis.
  eyemsg_printf("TRIALID PIX%d %s", num, imgname[num-1]);

  // TRIAL_VAR_DATA message is recorded for EyeLink Data Viewer analysis
  // It specifies the list of trial variables value for the trial 
  // This must be specified within the scope of an individual trial (i.e., after 
  // "TRIALID" and before "TRIAL_RESULT") 
  eyemsg_printf("!V TRIAL_VAR_DATA %s", imgname[num-1]);	

  set_offline_mode();		     // Must be offline to draw to EyeLink screen

  // Create foreground and background bitmaps of picture
  bitmap = create_image_bitmap(num-1); 
  if(!bitmap)
    {
      alert_printf("ERROR: could not create image %d", num);
      return SKIP_TRIAL;
    }

  // NOTE:  *** THE FOLLOWING TEXT SHOULD NOT APPEAR IN A REAL EXPERIMENT!!!! ****
  clear_full_screen_window(target_background_color);
  get_new_font("Arial", 24, 1);
  graphic_printf(target_foreground_color, -1, 1, SCRWIDTH/2, SCRHEIGHT/2, "Sending image to EyeLink...");

  // Transfer the bitmap to tracker PC as backdrop for gaze cursors
  bitmap_to_backdrop(bitmap, 0, 0, 0, 0,
			0, 0, (UINT16)(BX_MAXCONTRAST|((eyelink_get_tracker_version(NULL)>=2)?0:BX_GRAYSCALE)));  

  // record the trial
  i = bitmap_recording_trial(bitmap, 20000L); 
 
  DeleteObject(bitmap);
  return i;
}


/*********** TRIAL LOOP **************/

	/* This code sequences trials within a block */
	/* It calls run_trial() to execute a trial, */
	/* then interperts result code. */
	/* It places a result message in the EDF file */
	/* This example allows trials to be repeated */
	/* from the tracker ABORT menu. */
int run_trials(void)
{
  int i;
  int trial;
  
  target_foreground_color = RGB(0,0,0);          // set background for calibration
  target_background_color = RGB(128,128,128);    // This should match the display 
  set_calibration_colors(target_foreground_color, target_background_color); 

  		/* PERFORM CAMERA SETUP, CALIBRATION */
  do_tracker_setup();

  // TRIAL_VAR_LABELS message is recorded for EyeLink Data Viewer analysis
  // It specifies the list of trial variables for the trial 
  // This should be written once only and put before the recording of individual trials
  eyemsg_printf("TRIAL_VAR_LABELS TYPE");
				/* loop through trials */
  for(trial=1;trial<=NTRIALS;trial++)
    {
      if(eyelink_is_connected()==0 || break_pressed())    /* drop out if link closed */
	{
	  return ABORT_EXPT;
	}
				/* RUN THE TRIAL */
      i = do_picture_trial(trial);
      end_realtime_mode();

      switch(i)         	/* REPORT ANY ERRORS */
	{
	  case ABORT_EXPT:        /* handle experiment abort or disconnect */
	    eyemsg_printf("EXPERIMENT ABORTED");
	    return ABORT_EXPT;
	  case REPEAT_TRIAL:	  /* trial restart requested */
	    eyemsg_printf("TRIAL REPEATED");
	    trial--;
	    break;
	  case SKIP_TRIAL:	  /* skip trial */
	    eyemsg_printf("TRIAL ABORTED");
	    break;
	  case TRIAL_OK:          // successful trial
	    eyemsg_printf("TRIAL OK");
	    break;
	  default:                // other error code
	    eyemsg_printf("TRIAL ERROR");
	    break;
	}
    }  // END OF TRIAL LOOP
  return 0;
}

