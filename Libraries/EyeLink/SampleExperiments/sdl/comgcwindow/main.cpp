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
#define ELCALLTYPE WINAPI 

#include <sdl_text_support.h>
#include "gcwindow.h"

#include "SREyeLink_i.c"
#include "Com_SDL__core_graphics_i.c"

CComPtr<IEyeLink> eyelink = NULL;
CComPtr<IEyeLinkUtil> eyelinkUtil= NULL;
CComPtr<ISDLCoreGraphics> graphics= NULL;

inline bool isFailed(HRESULT result)
{
	if(FAILED(result))
	{
		IErrorInfo  *errinfo;
		HRESULT hr = GetErrorInfo(0,&errinfo);
		if(!FAILED(hr)) //found err info
		{
			BSTR msg;
			errinfo->GetDescription(&msg);
			USES_CONVERSION;
			printf("%s\n",W2A(msg));

		}
		return true;
	}
	else return false; 
}

DISP_INFO dispinfo; /* display information: size, colors, refresh rate */
/* Name for experiment: goes in task bar, and in EDF file */
char program_name[100] = "Eyelink Sample Experiment 2.0";
SDL_Surface  *window = NULL;

/*The colors of the target and background for calibration and drift correct */
SDL_Color target_background_color ={192,192,192};
SDL_Color target_foreground_color ={0,0,0};


int exit_eyelink()
{
	/* CLEANUP*/
	if(graphics)
	{
		eyelinkUtil->setCalibrationInterface(NULL);
		graphics.Release();          /* tell EXPTSPPT to release window */
		graphics = NULL;
	}
	eyelink->close();      /* disconnect from tracker */
	return 0;
}

int end_expt(char * our_file_name)
{
	USES_CONVERSION;
	/*END: close, transfer EDF file */
	eyelink->setOfflineMode(); /* set offline mode so we can transfer file */
	eyelinkUtil->pumpDelay(500);    /* delay so tracker is ready */
	/* close data file */
	eyelink->sendCommand(A2W("close_data_file"));

		  
	  

	short breakPressed;
	  eyelink->breakPressed(&breakPressed);
      if(breakPressed)
	  return exit_eyelink(); /* don't get file if we aborted experiment */
	if(our_file_name[0]&& eyelink_is_connected())   /* make sure we created a file */
	{
		eyelinkUtil->setCalibrationInterface(NULL);
		graphics.Release();          /* tell EXPTSPPT to release window */
		graphics = NULL;
		eyelink->receiveDataFile(A2W(our_file_name), A2W(""));
	}
	/* transfer the file, ask for a local name */

	return exit_eyelink();
}

int get_tracker_sw_version(BSTR ver )
{
	int ln = 0;
	int st =0;
	char verstr[100];
	wsprintf(verstr,"%S",ver); 
	ln = strlen(verstr);
	while(ln>0 && verstr[ln -1]==' ')  
		verstr[--ln] = 0; // trim 

	// find the start of the version number
	st = ln;
	while(st>0 && verstr[st -1]!=' ')  st --; 
	return atoi(&verstr[st]);
	
}

int app_main(char * trackerip, DISP_INFO * disp)
{
	USES_CONVERSION;
	char our_file_name[260] = "TEST";

	BSTR verstr = NULL;
	short eyelink_ver = 0;
	int tracker_software_ver = 0;

	if(isFailed(eyelink->open(A2W(trackerip),0))) 
	  return -1;       /* abort if we can't open link*/
	eyelink->setOfflineMode();
	eyelinkUtil->flushGetkeyQueue();/* initialize getkey() system */
	eyelink->getTrackerVersion(&eyelink_ver);
	
	if (eyelink_ver == 3)
	{
	  eyelink->getTrackerVersionString(&verstr);
	  tracker_software_ver = get_tracker_sw_version(verstr);
	}


	dispinfo = *disp;
	if(FAILED(graphics->setVideoMode(disp->width,disp->height,disp->bits, disp->refresh))) 
	  return exit_eyelink();   /* register window with EXPTSPPT*/

	window = SDL_GetVideoSurface();

	clear_full_screen_window(target_background_color);    /* clear screen */
	get_new_font("Times Roman", SCRHEIGHT/32, 1);         /* select a font */
														/* Draw text */
	graphic_printf(window, target_foreground_color, CENTER, SCRWIDTH/2, 1*SCRHEIGHT/30,
				 "EyeLink Demonstration Experiment: Sample Code");
	graphic_printf(window, target_foreground_color, CENTER,SCRWIDTH/2, 2*SCRHEIGHT/30,
				 "Included with the Experiment Programming Kit for Windows");
	graphic_printf(window, target_foreground_color, CENTER,SCRWIDTH/2, 3*SCRHEIGHT/30,
				 "All code is Copyright (c) 1997-2002 SR Research Ltd.");
	graphic_printf(window, target_foreground_color, CENTER,SCRWIDTH/5, 4*SCRHEIGHT/30,
				 "Source code may be used as template for your experiments.");

	SDL_Flip(window);
	if(our_file_name[0])    /* If file name set, open it */
	{
	  /* add extension */
	  if(!strstr(our_file_name, ".")) strcat(our_file_name, ".EDF");  
	  HRESULT res= eyelink->openDataFile(A2W(our_file_name)); /* open file */
	  if(isFailed(res))                           /* check for error */
		{
		  printf("Cannot create EDF file '%s'", our_file_name);
		  return exit_eyelink();
		}                                /* add title to preamble */
	  char buf[200];
	  sprintf(buf,"add_file_preamble_text 'RECORDED BY %s' ", program_name);
	  eyelink->sendCommand(A2W(buf));
	}

	/* Now configure tracker for display resolution */
	/* Set display resolution */
	char buf[200];
	sprintf(buf,"screen_pixel_coords = 0 0 %ld %ld",dispinfo.width, dispinfo.height);
	eyelink->sendCommand(A2W(buf));
	/* Setup calibration type */
	eyelink->sendCommand(A2W("calibration_type = HV9"));                  

	/* Add resolution to EDF file */
	sprintf(buf,"DISPLAY_COORDS 0 0 %ld %ld",dispinfo.width, dispinfo.height);
	eyelink->sendMessage(A2W(buf));
	if(dispinfo.refresh>40)
	{
		sprintf(buf,"FRAMERATE %1.2f Hz.", dispinfo.refresh);
		eyelink->sendMessage(A2W(buf));
	}

	/* SET UP TRACKER CONFIGURATION */
	/* set parser saccade thresholds (conservative settings) */
  if(eyelink_ver>=2)
    {
      eyelink->sendCommand(A2W("select_parser_configuration 0"));  // 0 = standard sensitivity
	  if(eyelink_ver == 2) //turn off scenelink camera stuff
	  {
		eyelink->sendCommand(A2W("scene_camera_gazemap = NO"));
	  }
    }
  else
    {
      eyelink->sendCommand(A2W("saccade_velocity_threshold = 35"));
      eyelink->sendCommand(A2W("saccade_acceleration_threshold = 9500"));
    }
		      // set EDF file contents 
  eyelink->sendCommand(A2W("file_event_filter = LEFT,RIGHT,FIXATION,SACCADE,BLINK,MESSAGE,BUTTON"));
  if(tracker_software_ver>=4)
	eyelink->sendCommand(A2W("file_sample_data  = LEFT,RIGHT,GAZE,AREA,GAZERES,STATUS,HTARGET"));
  else
	eyelink->sendCommand(A2W("file_sample_data  = LEFT,RIGHT,GAZE,AREA,GAZERES,STATUS"));
		      // set link data (used for gaze cursor) 
  eyelink->sendCommand(A2W("link_event_filter = LEFT,RIGHT,FIXATION,SACCADE,BLINK,BUTTON"));
  
  if(tracker_software_ver>=4)
	eyelink->sendCommand(A2W("link_sample_data  = LEFT,RIGHT,GAZE,GAZERES,AREA,STATUS,HTARGET"));
  else
	eyelink->sendCommand(A2W("link_sample_data  = LEFT,RIGHT,GAZE,GAZERES,AREA,STATUS"));

	/* Program button #5 for use in drift correction */
	eyelink->sendCommand(A2W("button_function 5 'accept_target_fixation'"));

	/* make sure we're still alive */
	  short isConnected;
	  short breakPressed;
	  eyelink->isConnected(&isConnected);
	  eyelink->breakPressed(&breakPressed);
      if(!isConnected || breakPressed)
		return end_expt(our_file_name);  

	/* 
	   RUN THE EXPERIMENTAL TRIALS (code depends on type of experiment)
	   Calling run_trials() performs a calibration followed by trials
	   This is equivalent to one block of an experiment
	   It will return ABORT_EXPT if the program should exit 
	*/
	run_trials();
	return end_expt(our_file_name);
}


void clear_full_screen_window(SDL_Color c)
{
	SDL_FillRect(window, NULL, SDL_MapRGB(window->format, c.r,  c.g, c.b));
	SDL_Flip(window);
	SDL_FillRect(window, NULL, SDL_MapRGB(window->format, c.r,  c.g, c.b)); 

}


#include <SDL/SDL_ttf.h>
int main(int argc, char ** argv)
{
	TTF_Init(); // initialize ttf fonts library
	HRESULT result = CoInitialize(NULL); // initialize com library
	result = eyelink.CoCreateInstance(CLSID_EyeLink); // create an eyelink object			
	if(result != S_OK){printf("failed to get eyelink object \n"); return -1;} 
	result = eyelinkUtil.CoCreateInstance(CLSID_EyeLinkUtil);	// create an eyelinkUtil object
	if(result != S_OK){printf("failed to get eyelink object \n"); return -1;}
	result = graphics.CoCreateInstance(CLSID_SDLCoreGraphics);  // create an SDLCoreGraphics object 
	if(result != S_OK){printf("failed to get eyelink object \n"); return -1;}

	eyelinkUtil->setCalibrationInterface(graphics); // tell eyelink util to use SDLCoreGraphics

	DISP_INFO disp;
	memset(&disp,0,sizeof(disp));
	disp.bits = 32;
	disp.refresh = 85;
	disp.width = SCRWIDTH;
	disp.height = SCRHEIGHT;

	
	app_main("100.1.1.1", &disp);/* call our real program */

	if(graphics)
	{
		eyelinkUtil->setCalibrationInterface(NULL);
		graphics.Release();          /* tell EXPTSPPT to release window */
		graphics = NULL;
	}

	eyelink.Release();
	eyelinkUtil.Release();
	CoUninitialize();

	return 0;
}
