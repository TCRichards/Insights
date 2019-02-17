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


#include <string.h>
#include "comm_listener.h"
#include <sdl_text_support.h>
#include <gazecursor.h>

/* functions to map gaze from tracker to local pixels */
extern float track2local_x(float x);
extern float track2local_y(float y);

int listener_position_print(float pos_x, float x_print_column, float pos_y, float y_print_column);
int listener_time_print(UINT32 trial_time, float time_print_column_start, float time_print_column_end);


/********* PLOT GAZE DATA DURING RECORDING  *******/	 
int listener_record_display(void)
{
	ALLF_DATA evt;
	UINT32 trial_start_time = 0;
	unsigned key;
	int eye_used;        /* which eye to show gaze for */
	float x, y;	       /* gaze position */
	float ox=-1, oy=-1;  /* old gaze positio (to determine change) */
	int i;

	/* create font for position display */
	get_new_font( "Arial", SCRWIDTH/50, 0);

	initialize_cursor(window, SCRWIDTH/50);

	eye_used = eyelink_eye_available();
	if(eye_used==BINOCULAR) eye_used = LEFT_EYE;/* use left eye if both available */

	while(eyelink_is_connected())  /* loop while record data availablemode */
	{
		key = getkey();            /* Local keys/abort test */
		if(key==TERMINATE_KEY)     /* test ALT-F4 or end of execution */
			break;

		if(!eyelink_in_data_block(1, 1)) 
			break;  /* stop if end of record data */
		i = eyelink_get_next_data(NULL);   /* check for new data item */
		if(i == MESSAGEEVENT)   /* message: check if we need the data */
		{
			eyelink_get_float_data(&evt);     /* get message */
			/* get trial start time from "SYNCTIME" message */
			if(!_strnicmp(evt.im.text, "SYNCTIME", 8))
			{
				trial_start_time = 0;    /* offset of 0, if none given */
				sscanf(evt.im.text, "%*s %d", &trial_start_time);
				trial_start_time = evt.im.time - trial_start_time;  
			}
#ifdef PRINT_MESSAGES
			graphic_printf(window, target_foreground_color, NONE, SCRWIDTH/100, j++*SCRHEIGHT/50, 
				"MESSAGE=%s", evt.im.text);
#endif
		}

#ifdef LOST_DATA_EVENT     /* only available in V2.1 or later DLL */
		if(i == LOST_DATA_EVENT)   /* marks lost data in stream */
			alert_printf("Some link data was lost");
#endif

		/* CODE FOR PLOTTING GAZE CURSOR  */
		if(eyelink_newest_float_sample(NULL)>0)  /* new sample? */
		{
			eyelink_newest_float_sample(&evt);  /* get the sample data */
			x = evt.fs.gx[eye_used];   /* get gaze position from sample  */
			y = evt.fs.gy[eye_used];
			/* if double-buffer then print time from start of trial here and after draw_gaze_cursor flip*/
			if (ISPAGEFLIP(window))
				listener_time_print(evt.fs.time-trial_start_time, 0.75, 0.87);
			if(x!=MISSING_DATA && y!=MISSING_DATA && 
				evt.fs.pa[eye_used]>0)  /* plot if not in blink */
			{                        /* plot in local coords */
				if(ox!=x || oy!=y)   /* only draw if changed */
					if (ISPAGEFLIP(window))
						listener_position_print(x, 0.87, y, 0.93); // print at 				
				draw_gaze_cursor((int)track2local_x(x), (int)track2local_y(y));
				/* report gaze position (tracker coords) */
				if(ox!=x || oy!=y)   /* only draw if changed */
					// print x coord at the top and 0.87 of display 
					// print y coord at the top and 0.93 of display
					listener_position_print(x, 0.87, y, 0.93); 
				ox = x;
				oy = y;
			}
			else
			{
				erase_gaze_cursor();   /* hide cursor during blink */
			}
			/* print time from start of trial */
			listener_time_print(evt.fs.time-trial_start_time, 0.75, 0.87);
		}
	}
	erase_gaze_cursor();   /* erase gaze cursor if visible */
	return 0;
}

/* Function to print x-y coordinates at the top of the display. Where the	*/
/* horizontal coordinates x_print_column and y_print_column	are				*/
/* represented relative to the total width of the display					*/
int listener_position_print(float pos_x, float x_print_column, float pos_y, float y_print_column)
{
	SDL_Rect r = {(Sint16)(SCRWIDTH*x_print_column), 0, (Sint16)(window->w -SCRWIDTH*x_print_column), 50};
	SDL_FillRect(window,&r,SDL_MapRGB(window->format,target_background_color.r, target_background_color.g, target_background_color.b));
	graphic_printf(window, target_foreground_color, NONE, (int)(SCRWIDTH*x_print_column), 0, " %4.0f  ", pos_x);
	graphic_printf(window, target_foreground_color, NONE, (int)(SCRWIDTH*y_print_column), 0, " %4.0f  ", pos_y);
	return 0;
}

/* Function to print trial time at the top of the display. Where the		*/
/* horizontal coordinates time_print_column_start and time_print_column_end */
/* are represented relative to the total width of the display				*/
int listener_time_print(UINT32 trial_time, float time_print_column_start, float time_print_column_end)
{
	SDL_Rect r = {(Sint16)(SCRWIDTH*time_print_column_start), 0, (Sint16)(SCRWIDTH*time_print_column_end - SCRWIDTH*time_print_column_start), 50};
	SDL_FillRect(window,&r,SDL_MapRGB(window->format,target_background_color.r, target_background_color.g, target_background_color.b));
	graphic_printf(window, target_foreground_color,NONE, (int)(SCRWIDTH*time_print_column_start), 0, " % 8d ", trial_time);
	return 0;
}
