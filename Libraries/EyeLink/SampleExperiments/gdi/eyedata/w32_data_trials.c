/*****************************************************/
/* Windows 95/98/NT/2000/XP sample experiment in C   */
/* For use with Version 2.0 of EyeLink Windows API   */
/*                                                   */
/*      (c) 1997-2002 by SR Research Ltd.            */
/* For non-commercial use by Eyelink licencees only  */
/*                                                   */
/* THIS FILE: w32_data_trials.c                      */
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
/*****************************************************/
 
#include <windows.h>
#include <windowsx.h>

#include "gdi_expt.h"
#include "w32_demo.h"  /* header file for this experiment */


/*********** TRIAL SELECTOR **********/

#define NTRIALS 1   // simple demonstration

       // There is only one data trial. followed by playing back the data.
       // Returns trial result code
int do_data_trial(int num)
{
  int i;
  HBITMAP bitmap;

        // This supplies the title at the bottom of the eyetracker display 
  eyecmd_printf("record_status_message 'GAZE CURSOR TEST' ");
  set_offline_mode();		     // Must be offline to draw to EyeLink screen

           // NEW command (EL I v2.1, EL II V1.1)
           // Marks where next playback will begin in file
           // If not used, playback begins from start of recording
  eyecmd_printf("mark_playback_start");

        // Always send a TRIALID message before starting to record. 
        // It should contain trial condition data required for analysis.
  eyemsg_printf("TRIALID GRID");
 
  // TRIAL_VAR_DATA message is recorded for EyeLink Data Viewer analysis
  // It specifies the list of trial variables value for the trial 
  // This must be specified within the scope of an individual trial (i.e., after 
  // "TRIALID" and before "TRIAL_RESULT") 
  eyemsg_printf("!V TRIAL_VAR_DATA Playback");

  // IMGLOAD command is recorded for EyeLink Data Viewer analysis
  // It displays a default image on the overlay mode of the trial viewer screen. 
  // Writes the image filename + path info
  eyemsg_printf("!V IMGLOAD FILL images/grid.png");	

  // IAREA command is recorded for EyeLink Data Viewer analysis
  // It creates a set of interest areas by reading the segment files
  // Writes segmentation filename + path info
  eyemsg_printf("!V IAREA FILE segments/grid.ias"); 

  bitmap = draw_grid_to_bitmap_segment("grid.ias", "segments", 1);

  if(!bitmap)
    {
      eyemsg_printf("ERROR: could not create bitmap");
      return SKIP_TRIAL;
    }
 

  // Save the bitmap and transfer to the tracker pc
  // Since it takes a long time to save a bitmap to disk, the sv_options option 
  // should be set as SV_NOREPLACE
  bitmap_save_and_backdrop(bitmap, 0, 0, 0, 0, "grid.png", "images", SV_NOREPLACE,
			      0, 0, (UINT16)(BX_MAXCONTRAST|((eyelink_get_tracker_version(NULL)>=2)?0:BX_GRAYSCALE)));


  i = realtime_data_trial(bitmap, 60000L);  // display gaze cursor during recording
  
  playback_trial();                            // Play back trial's data

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
  
  target_foreground_color = RGB(255,255,255);          // set background for calibration
  target_background_color = RGB(60,60,60);    // This should match the display 
  set_calibration_colors(target_foreground_color, target_background_color); 
   
  // TRIAL_VAR_LABELS message is recorded for EyeLink Data Viewer analysis
  // It specifies the list of trial variables for the trial 
  // This should be written once only and put before the recording of individual trials
  eyemsg_printf("TRIAL_VAR_LABELS CONDITION");
    
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
      i = do_data_trial(trial);
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

