/*****************************************************************************
 * Copyright (c) 1997 - 2003 by SR Research Ltd., All Rights Reserved        *
 *                                                                           *
 * This software is provided as is without warranty of any kind.  The entire *
 * risk as to the results and performance of this software is assumed by the *
 * user. SR Research Ltd. disclaims all warranties, either express or implied*
 * ,including but not limited, the implied warranties of merchantability,    *
 * fitness for a particular purpose, title and noninfringement, with respect *
 * to this software.                                                         *
 *                                                                           *
 *                                                                           *
 * For non-commercial use by Eyelink licencees only                          *
 *                                                                           *
 * Windows 95/98/NT/2000/XP sample experiment in C                           *
 * For use with Version 2.0 of EyeLink Windows API                           *
 *****************************************************************************/


#include "gcwindow.h"
#include <gazecursor.h>

/********* PERFORM AN EXPERIMENTAL TRIAL  *******/


/* End recording: adds 100 msec of data to catch final events */
static void end_trial(void)
{
  clear_full_screen_window(target_background_color);    /* hide display */
  eyelinkUtil->endRealTimeMode();   /* NEW: ensure we release realtime lock */
  eyelinkUtil->pumpDelay(100);       /* CHANGED: allow Windows to clean up   */
                         /* while we record additional 100 msec of data  */
  eyelink->stopRecording();
  short ky;
  eyelink->getKey(&ky);
  while(ky) {eyelink->getKey(&ky);};
}

/*
	Run a single trial, recording to EDF file and sending data through link
	This example draws to a bitmap, then copies it to display for fast stimulus onset

	 The order of operations is:
	- Set trial title, ID for analysis
	- Draw foreground, background bitmaps and create EyeLink display graphics
	- Drift correction
	- start recording
	- <DON'T copy bitmap to display: draw window when first sample arrives>
	- loop till button press, timeout, or abort, drawing gaze contingent window
	- stop recording, dispose of bitmaps, handle abort and exit

	NEW CODE FOR GAZE CONTINGENT DISPLAY:
	- create both foreground and background bitmaps
	- uses the eyelink_newest_float_sample() to get latest update
	- initialize window with initialize_gc_window()
	- moves window with redraw_gc_window()

	Run gaze-contingent window trial
	<fgbm> is bitmap to display within window
	<bgbm> is bitmap to display outside window
	<wwidth, wheight> is size of window in pixels
	<mask> flags whether to treat window as a mask
	<time_limit> is the maximum time the stimuli are displayed
*/
int gc_window_trial(SDL_Surface * fgbm, SDL_Surface * bgbm,
                    int wwidth, int wheight, int mask, UINT32 time_limit)
{
  USES_CONVERSION;
  char buf[200];        //a2w conversion buffer
  double trial_start=0;	/* trial start time (for timeout)  */
  double drawing_time;  /* retrace-to-draw delay */
  short button;			/* the button pressed (0 if timeout)  */


//  ALLF_DATA evt;         /* buffer to hold sample and event data */
  int first_display = 1; /* used to determine first drawing of display   */
  short eye_used = 0;      /* indicates which eye's data to display */
  float x, y;			 /* gaze position  */

	/*
	 NOTE: TRIALID AND TITLE MUST HAVE BEEN SET BEFORE DRIFT CORRECTION!
	 FAILURE TO INCLUDE THESE MAY CAUSE INCOMPATIBILITIES WITH ANALYSIS SOFTWARE!
	 */

	/*
		 DO PRE-TRIAL DRIFT CORRECTION
		 We repeat if ESC key pressed to do setup.
	*/

  while(1)
    {              /* Check link often so we can exit if tracker stopped */
	  short isConnected;
	  eyelink->isConnected(&isConnected);
      if(!isConnected) return EL_ABORT_EXPT;
	   /*
			We let do_drift_correct() draw target in this example
			3rd argument would be 0 if we already drew the display
	   */
	  HRESULT hr = eyelink->doDriftCorrect((short)(SCRWIDTH/2), (short)(SCRHEIGHT/2), 1, 1);
	  if(!FAILED(hr)) break;
           /* repeat if ESC was pressed to access Setup menu  */
      //if(error!=27) break;
    }

    clear_full_screen_window(target_background_color);   /* make sure display is blank */

	/*
		Start data recording to EDF file, BEFORE DISPLAYING STIMULUS
		You should always start recording 50-100 msec before required
		otherwise you may lose a few msec of data

		tell start_recording() to send link data
	*/
  HRESULT hr = eyelink->startRecording(1,1,1,1);	/* record with link data enabled */
  if(FAILED(hr)) return EL_TRIAL_ERROR;      /* ERROR: couldn't start recording */
                              /* record for 100 msec before displaying stimulus  */
  eyelinkUtil->beginRealTimeMode(100);   /* Windows 2000/XP: no interruptions from now on */

    /* DONT DISPLAY OUR IMAGES TO SUBJECT until we have first gaze postion! */
  SDL_BlitSurface(bgbm,NULL,window,NULL);
  initialize_dynamic_cursor(window, min(wwidth,wheight) ,fgbm);
  short res;
  eyelink->waitForBlockStart(100, 1, 0, &res);
  if(!res)  /* wait for link sample data */
    {
      end_trial();
      printf("ERROR: No link samples received!");
      return EL_TRIAL_ERROR;
    }
  eyelink->eyeAvailable(&eye_used); /* determine which eye(s) are available  */
  switch(eye_used)		      /* select eye, add annotation to EDF file	 */
    {
      case EL_RIGHT:
        eyelink->sendMessage(A2W("EYE_USED 1 RIGHT"));
        break;
      case EL_BINOCULAR:           /* both eye's data present: use left eye only */
        eye_used = EL_LEFT;
      case EL_LEFT:
        eyelink->sendMessage(A2W("EYE_USED 0 LEFT"));
        break;
    }
                                 /* Now get ready for trial loop */
  eyelink->flushKeybuttons(0);   /* reset keys and buttons from tracker  */
                       /*
						we don't use getkey() especially in a time-critical trial
						as Windows may interrupt us and cause an unpredicatable delay
                        so we would use buttons or tracker keys only
					   */


     /*Trial loop: till timeout or response -- added code for reading samples and moving cursor */
	while(1)
	{                            /* First, check if recording aborted  */
		double cur_time;
		eyelinkUtil->currentTime(&cur_time);
		EL_TRIAL_RESULT isRecording;
		eyelink->isRecording(&isRecording);

		if(isRecording!=0) return isRecording;
								 /* Check if trial time limit expired */
		if(cur_time > trial_start+time_limit && trial_start!=0)
		{
			eyelink->sendMessage(A2W("TIMEOUT"));    /* message to log the timeout  */
			end_trial();                 /* local function to stop recording */
			button = 0;                  /* trial result message is 0 if timeout  */
			break;                       /* exit trial loop */
		}

		short breakPressed;
	  eyelink->breakPressed(&breakPressed);
      if(breakPressed)     /* check for program termination or ALT-F4 or CTRL-C keys */
		{
			end_trial();         /* local function to stop recording */
			return EL_ABORT_EXPT;   /* return this code to terminate experiment */
		}
		short escPressed;
	  eyelink->escapePressed(&escPressed);
		if(escPressed)    /* check for local ESC key to abort trial (useful in debugging)    */
		 {
			end_trial();         /* local function to stop recording */
			return EL_SKIP_TRIAL;   /* return this code if trial terminated */
		 }

			/* BUTTON RESPONSE TEST */
			/* Check for eye-tracker buttons pressed */
			/* This is the preferred way to get response data or end trials	 */
		eyelink->getLastButtonPress(NULL,&button);
		  //button = eyelink_last_button_press(NULL);
		if(button!=0)       /* button number, or 0 if none pressed */
		{
			sprintf(buf,"ENDBUTTON %d", button);
			eyelink->sendMessage(A2W(buf));  /* message to log the button press */
			end_trial();                            /* local function to stop recording */
			break;                                  /* exit trial loop */
		}

		/* NEW CODE FOR GAZE CONTINGENT WINDOW  */
		ISample *sample = NULL;
		HRESULT hr = eyelink->getNewestSample(&sample);
		if(!FAILED(hr))  /* check for new sample update */
		{
			float pa;
			 /* yes: get gaze position from sample  */
			sample->get_gx((EL_EYE)eye_used,&x);
			sample->get_gy((EL_EYE)eye_used,&y);
			sample->get_pa((EL_EYE)eye_used,&pa);
			if(x!=EL_MISSING_DATA && y!=EL_MISSING_DATA && pa>0)     /* make sure pupil is present */
			{

			  if(first_display)  /* mark display start AFTER first drawing of window */
				{
				  eyelinkUtil->currentDoubleUsec(&drawing_time); /* time of retrace */
				  trial_start = drawing_time;   /* record the display onset time  */
				}

			  draw_gaze_cursor((int)x, (int)y);  /* move window if visible */

			  if(first_display)  /* mark display start AFTER first drawing of window */
				{
				  first_display = 0;
				  double cmsec;
				  eyelinkUtil->currentDoubleUsec(&cmsec);
				  drawing_time = cmsec - drawing_time; /* delay from retrace */
				  sprintf(buf,"%d DISPLAY ON", drawing_time);
				  eyelink->sendMessage(A2W(buf));	/* message for RT recording in analysis  */
				  sprintf(buf,"SYNCTIME %d", drawing_time);
				  eyelink->sendMessage(A2W(buf));	/* message marks zero-plot time for EDFVIEW  */
				  //SDL_Flip(window);
				  SDL_BlitSurface(bgbm,NULL,window,NULL);
				}

			}
			else
			{
				/*
					Don't move window during blink
				 */
			}
		}
	}                       /* END OF RECORDING LOOP */

  eyelinkUtil->endRealTimeMode();      /* safety cleanup code */
  short ky;
  eyelink->getKey(&ky);
  while(ky) {eyelink->getKey(&ky);};          /* dump any accumulated key presses */

  /* report response result: 0=timeout, else button number */
  sprintf(buf,"TRIAL_RESULT %d", button);
  eyelink->sendMessage(A2W(buf));

  /* Call this at the end of the trial, to handle special conditions */
  EL_TRIAL_RESULT status;
  eyelink->getRecordingStatus(&status);
  return status;
}

