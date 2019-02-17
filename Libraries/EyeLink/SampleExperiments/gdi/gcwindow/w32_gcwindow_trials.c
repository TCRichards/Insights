/*****************************************************/
/* Windows 95/98/NT/2000/XP sample experiment in C   */
/* For use with Version 2.0 of EyeLink Windows API   */
/*                                                   */
/*      (c) 1997-2002 by SR Research Ltd.            */
/* For non-commercial use by Eyelink licencees only  */
/*                                                   */
/* THIS FILE: w32_gcwindox_trials.c                  */
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

#include "gdi_expt.h"
#include "w32_demo.h"  /* header file for this experiment */


/************ TEXT FOR TRIAL ***********/

static char fg_text[] = 
"Buck did not read the newspapers, or he would have known that trouble was "
"brewing, not alone for himself, but for every tide-water dog, strong of "
"muscle and with warm, long hair, from Puget Sound to San Diego.  Because "
"men, groping in the Arctic darkness, had found a yellow metal, and because "
"steamship and transportation companies were booming the find, thousands of "
"men were rushing into the Northland.  These men wanted dogs, and the dogs "
"they wanted were heavy dogs, with strong muscles by which to toil, and furry "
"coats to protect them from the frost. \n"
"   Buck lived at a big house in the sun-kissed Santa Clara Valley.  Judge "
"Miller's place, it was called.  It stood back from the road, half hidden "
"among the trees, through which glimpses could be caught of the wide cool "
"veranda that ran around its four sides.";

static char bg_text[] = 
"Xxxx xxx xxx xxxx xxx xxxxxxxxxx, xx xx xxxxx xxxx xxxxx xxxx xxxxxxx xxx "
"xxxxxxx, xxx xxxxx xxx xxxxxxx, xxx xxx xxxxx xxxx-xxxxx xxx, xxxxxx xx "
"xxxxxx xxx xxxx xxxx, xxxx xxxx, xxxx Xxxxx Xxxxx xx Xxx Xxxxx.  Xxxxxxx "
"xxx, xxxxxxx xx xxx Xxxxxx xxxxxxxx, xxx xxxxx x xxxxxx xxxxx, xxx xxxxxxx "
"xxxxxxxxx xxx xxxxxxxxxxxxxx xxxxxxxxx xxxx xxxxxxx xxx xxxx, xxxxxxxxx xx "
"xxx xxxx xxxxxxx xxxx xxx Xxxxxxxxx.  Xxxxx xxx xxxxxx xxxx, xxx xxx xxxx "
"xxxx xxxxxx xxxx xxxxx xxxx, xxxx xxxxxx xxxxxxx xx xxxxx xx xxxx, xxx xxxxx "
"xxxxx xx xxxxxxx xxxx xxxx xxx xxxxx. \n"
"   Xxxx xxxxx xx x xxx xxxxx xx xxx xxx-xxxxxx Xxxxx Xxxxx Xxxxxx.  Xxxxx "
"Xxxxxx'x xxxxx, xx xxx xxxxxx.  Xx xxxxx xxxx xxxx xxx xxxx, xxxx xxxxxx "
"xxxxx xxx xxxxx, xxxxxxx xxxxx xxxxxxxx xxxxx xx xxxxxx xx xxx xxxx xxxx "
"xxxxxxx xxxx xxx xxxxxx xxx xxxx xxxxx.";


/********* PREPARE BITMAPS FOR TRIALS  **********/

HBITMAP fgbm=NULL, bgbm=NULL;

         // Create foreground and background bitmaps of text
static int create_text_bitmaps(void)
{
  RECT margins;                // margins for text
          
  margins.top = SCRHEIGHT/20;  // set margin in about 1°
  margins.left = SCRWIDTH/20;
  margins.right = SCRWIDTH - SCRWIDTH/20;
  margins.bottom = SCRHEIGHT - SCRHEIGHT/20;
    
  target_foreground_color = RGB(0,0,0);         // color of calibration target
  target_background_color = RGB(255,255,255);   // background for drift correction
  set_calibration_colors(target_foreground_color, target_background_color); // tell EXPTSPPT the colors

  get_new_font("Courier New", SCRHEIGHT/32, 1);   // create a monospaced font
                                 

  // Draw text and EyeLink graphics
  fgbm = text_bitmap_segment(fg_text, RGB(0,0,0), RGB(255,255,255), margins, SCRHEIGHT/15, 0, 
		"text.ias", "segments", SV_NOREPLACE); // Create bitmap and its segmentation (if it does not exist)
 

  // IAREA command is recorded for EyeLink Data Viewer analysis
  // It creates a set of interest areas by reading the segment files
  // Writes segmentation filename + path info 	
  eyemsg_printf("!V IAREA FILE segments/text.ias"); 

  // Draw text and EyeLink graphics for the background bitmap
  bgbm = text_bitmap(bg_text, RGB(0,0,0), RGB(255,255,255), margins, SCRHEIGHT/15, 0);

  
  if(!fgbm || !bgbm)  // Check that both bitmaps exist.
    {
      eyemsg_printf("ERROR: could not load image");
      alert_printf("ERROR: could not load an image file");
      if(fgbm) DeleteObject(fgbm);
      if(bgbm) DeleteObject(bgbm);
      return SKIP_TRIAL;
    }
  return 0;
}

         // Create foreground and background bitmaps of picture
         // EyeLink graphics: blank display with box at center
         // type: 0 = blank background, 1= blank fovea (mask), 2 = blurred background
static int create_image_bitmaps(int type)
{ 
  target_foreground_color = RGB(0,0,0);         // color of calibration target
  target_background_color = RGB(128,128,128);   // background for drift correction
  set_calibration_colors(target_foreground_color, target_background_color); // tell EXPTSPPT the colors

  clear_full_screen_window(target_background_color);
// NOTE:  *** THE FOLLOWING TEXT SHOULD NOT APPEAR IN A REAL EXPERIMENT!!!! ****
  get_new_font("Arial", 24, 1);
  graphic_printf(target_foreground_color, -1, 1, SCRWIDTH/2, SCRHEIGHT/2, "Loading image...");

  switch(type)
    {  
      case 0:     // blank background
        fgbm = image_file_bitmap("images/sacrmeto.jpg", 0, SCRWIDTH,SCRHEIGHT,target_background_color);
        bgbm = blank_bitmap(target_background_color);
        break;
      case 1:     // blank fovea
        fgbm = blank_bitmap(target_background_color);
        bgbm = image_file_bitmap("images/sacrmeto.jpg", 0, SCRWIDTH,SCRHEIGHT,target_background_color);
        break;
      case 2:     // normal and blurred bitmaps, stretched to fit display
        fgbm = image_file_bitmap("images/sacrmeto.jpg", 0, SCRWIDTH,SCRHEIGHT,target_background_color);
        bgbm = image_file_bitmap("images/sac_blur.jpg", 0, SCRWIDTH,SCRHEIGHT,target_background_color);
        break;
    }

  eyecmd_printf("clear_screen 0");                   // clear EyeLink display
  eyecmd_printf("draw_box %d %d %d %d 15",          // Box around fixation point
           SCRWIDTH/2-16, SCRHEIGHT/2-16, SCRWIDTH/2+16, SCRHEIGHT/2+16);

  if(!fgbm || !bgbm)  // Check that both bitmaps exist.
    {
      eyemsg_printf("ERROR: could not load image");
      alert_printf("ERROR: could not load an image file");
      if(fgbm) DeleteObject(fgbm);
      if(bgbm) DeleteObject(bgbm);
      return SKIP_TRIAL;
    }
  return 0;
}


/*********** TRIAL SELECTOR **********/

#define NTRIALS 5  // 5 trials for gaze contingent demp

         // FOR EACH TRIAL:
         // - set title, TRIALID
         // - Create bitmaps and EyeLink display graphics
         // - Check for errors in creating bitmaps
         // - Run the trial recording loop
         // - Delete bitmaps
         // - Return any error code

         // Given trial number, execute trials
         // Returns trial result code
int do_gcwindow_trial(int num)
{
  int i;


   set_offline_mode();		     // Must be offline to draw to EyeLink screen

  switch(num)
    {            // #1: gaze-contingent text, normal in window, "xx" outside
      case 1:
	   // This supplies the title at the bottom of the eyetracker display 
        eyecmd_printf("record_status_message 'GC TEXT (WINDOW)' ");
	   // Always send a TRIALID message before starting to record. 
	   // It should contain trial condition data required for analysis.
        eyemsg_printf("TRIALID GCTXTW");
		
		// TRIAL_VAR_DATA message is recorded for EyeLink Data Viewer analysis
		// It specifies the list of trial variables value for the trial 
		// This must be specified within the scope of an individual trial (i.e., after 
		// "TRIALID" and before "TRIAL_RESULT") 
		eyemsg_printf("!V TRIAL_VAR_DATA TEXT TEXT MASK");

		if(create_text_bitmaps())
          {
            eyemsg_printf("ERROR: could not create bitmap");
            return SKIP_TRIAL;
          }
		
		// IMGLOAD command is recorded for EyeLink Data Viewer analysis
		// It displays a default image on the overlay mode of the trial viewer screen. 
		// Writes the image filename + path info
		eyemsg_printf("!V IMGLOAD FILL images/text.png");	
		
		// Save the bitmap and transfer to the tracker pc
		// Since it takes a long time to save a bitmap to disk, the sv_options option 
		// should be set as SV_NOREPLACE
		bitmap_save_and_backdrop(fgbm, 0, 0, 0, 0,
                       "text.png", "images", SV_NOREPLACE,
			      0, 0, BX_NODITHER|BX_GRAYSCALE);
		
        i = gc_window_trial(fgbm, bgbm, SCRWIDTH/4, SCRHEIGHT/3, 0, 60000L);  // Gaze-contingent window, normal text
        DeleteObject(fgbm);
        DeleteObject(bgbm);
        return i;

      case 2:    // #2: gaze-contingent text, "xx" in window, normal outside
        eyecmd_printf("record_status_message 'GC TEXT (MASK)' ");
        eyemsg_printf("TRIALID GCTXTM");

		// TRIAL_VAR_DATA message is recorded for EyeLink Data Viewer analysis
		// It specifies the list of trial variables value for the trial 
		// This must be specified within the scope of an individual trial (i.e., after 
		// "TRIALID" and before "TRIAL_RESULT") 
		eyemsg_printf("!V TRIAL_VAR_DATA TEXT MASK TEXT");
        if(create_text_bitmaps())
          {
            eyemsg_printf("ERROR: could not create bitmap");
            return SKIP_TRIAL;
          }

		// IMGLOAD command is recorded for EyeLink Data Viewer analysis
		// It displays a default image on the overlay mode of the trial viewer screen. 
		// Writes the image filename + path info
		eyemsg_printf("!V IMGLOAD FILL images/text.png");	
		
		// Save the bitmap and transfer to the tracker pc
		// Since it takes a long time to save a bitmap to disk, the sv_options option 
		// should be set as SV_NOREPLACE
		bitmap_save_and_backdrop(fgbm, 0, 0, 0, 0,
                       "text.png", "images", SV_NOREPLACE,
			      0, 0, BX_NODITHER|BX_GRAYSCALE);

        i = gc_window_trial(bgbm, fgbm, SCRWIDTH/4, SCRHEIGHT/3, 1, 60000L);  // Gaze-contingent window, masked text
        DeleteObject(fgbm);
        DeleteObject(bgbm);
        return i;

      case 3:    // #3: Image, normal in window, blank outside
        eyecmd_printf("record_status_message 'GC IMAGE (WINDOW)' ");
        eyemsg_printf("TRIALID GCTXTW");

		// TRIAL_VAR_DATA message is recorded for EyeLink Data Viewer analysis
		// It specifies the list of trial variables value for the trial 
		// This must be specified within the scope of an individual trial (i.e., after 
		// "TRIALID" and before "TRIAL_RESULT") 		
		eyemsg_printf("!V TRIAL_VAR_DATA IMAGE IMAGE MASK");

        if(create_image_bitmaps(0))
          {
            eyemsg_printf("ERROR: could not create bitmap");
            return SKIP_TRIAL;
          }

		// IMGLOAD command is recorded for EyeLink Data Viewer analysis
		// It displays a default image on the overlay mode of the trial viewer screen. 
		// Writes the image filename + path info
		eyemsg_printf("!V IMGLOAD FILL images/sacrmeto.jpg");	

  
		// Transfer the bitmap to tracker PC as backdrop for gaze cursors
		bitmap_to_backdrop(fgbm, 0, 0, 0, 0,
			0, 0, (UINT16)(BX_MAXCONTRAST|((eyelink_get_tracker_version(NULL)>=2)?0:BX_GRAYSCALE)));
		
        i = gc_window_trial(fgbm, bgbm, SCRWIDTH/4, SCRHEIGHT/3, 0, 60000L);  // Gaze-contingent window, normal image
        DeleteObject(fgbm);
        DeleteObject(bgbm);
        return i;

      case 4:    // #4: Image, blank in window, normal outside
        eyecmd_printf("record_status_message 'GC IMAGE (MASK)' ");
        eyemsg_printf("TRIALID GCTXTM");

		// TRIAL_VAR_DATA message is recorded for EyeLink Data Viewer analysis
		// It specifies the list of trial variables value for the trial 
		// This must be specified within the scope of an individual trial (i.e., after 
		// "TRIALID" and before "TRIAL_RESULT") 		
		eyemsg_printf("!V TRIAL_VAR_DATA IMAGE MASK IMAGE");

        if(create_image_bitmaps(1))
          {
            eyemsg_printf("ERROR: could not create bitmap");
            return SKIP_TRIAL;
          }

		// IMGLOAD command is recorded for EyeLink Data Viewer analysis
		// It displays a default image on the overlay mode of the trial viewer screen. 
		// Writes the image filename + path info
		eyemsg_printf("!V IMGLOAD FILL images/sacrmeto.jpg");	
		
		// Transfer the bitmap to tracker PC as backdrop for gaze cursors
		bitmap_to_backdrop(bgbm, 0, 0, 0, 0,
			0, 0, (UINT16)(BX_MAXCONTRAST|((eyelink_get_tracker_version(NULL)>=2)?0:BX_GRAYSCALE)));
		

        i = gc_window_trial(fgbm, bgbm, SCRWIDTH/4, SCRHEIGHT/3, 1, 60000L);  // Gaze-contingent window, masked image
        DeleteObject(fgbm);
        DeleteObject(bgbm);
        return i;

      case 5:    // #5: Image, blurred outside window
        eyecmd_printf("record_status_message 'GC IMAGE (BLURRED)' ");
        eyemsg_printf("TRIALID GCTXTB");

		// TRIAL_VAR_DATA message is recorded for EyeLink Data Viewer analysis
		// It specifies the list of trial variables value for the trial 
		// This must be specified within the scope of an individual trial (i.e., after 
		// "TRIALID" and before "TRIAL_RESULT") 		
		eyemsg_printf("!V TRIAL_VAR_DATA IMAGE IMAGE BLURRED");

        if(create_image_bitmaps(2))
          {
            eyemsg_printf("ERROR: could not create bitmap");
            return SKIP_TRIAL;
          }


		// IMGLOAD command is recorded for EyeLink Data Viewer analysis
		// It displays a default image on the overlay mode of the trial viewer screen. 
		// Writes the image filename + path info
		eyemsg_printf("!V IMGLOAD FILL images/sacrmeto.jpg");	
		
		// Transfer the bitmap to tracker PC as backdrop for gaze cursors
		bitmap_to_backdrop(fgbm, 0, 0, 0, 0,
			0, 0, (UINT16)(BX_MAXCONTRAST|((eyelink_get_tracker_version(NULL)>=2)?0:BX_GRAYSCALE)));
		
        i = gc_window_trial(fgbm, bgbm, SCRWIDTH/4, SCRHEIGHT/3, 0, 60000L);  // Gaze-contingent window, masked image
        DeleteObject(fgbm);
        DeleteObject(bgbm);
        return i;
    }
  return ABORT_EXPT;  // illegal trial number  
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
                 // INITIAL CALIBRATION: matches following trials
  target_foreground_color = RGB(0,0,0);         // color of calibration target
  target_background_color = RGB(200,200,200);   // background for drift correction
  set_calibration_colors(target_foreground_color, target_background_color); // tell EXPTSPPT the colors
   
  // TRIAL_VAR_LABELS message is recorded for EyeLink Data Viewer analysis
  // It specifies the list of trial variables for the trial 
  // This should be written once only and put before the recording of individual trials
  eyemsg_printf("TRIAL_VAR_LABELS TYPE CENTRAL PERIPHERAL");

  if(SCRWIDTH!=800 || SCRHEIGHT!=600)
    alert_printf("Display mode is not 800x600, resizing will slow loading.");

  		/* PERFORM CAMERA SETUP, CALIBRATION */
  do_tracker_setup();
				/* loop through trials */
  for(trial=1;trial<=NTRIALS;trial++)
    {
      if(eyelink_is_connected()==0 || break_pressed())    /* drop out if link closed */
	{
	  return ABORT_EXPT;
	}
				/* RUN THE TRIAL */
      i = do_gcwindow_trial(trial);
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

