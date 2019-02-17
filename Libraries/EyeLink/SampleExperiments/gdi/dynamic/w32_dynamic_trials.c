/*****************************************************/
/* Windows 95/98/NT/2000/XP sample experiment in C   */
/* For use with Version 2.0 of EyeLink Windows API   */
/*                                                   */
/*      (c) 1997-2002 by SR Research Ltd.            */
/* For non-commercial use by Eyelink licencees only  */
/*                                                   */
/* THIS FILE: w32_pursuit_trials.c                   */
/* CONTENTS:                                         */
/* - run_trials() loops through trials, and handles  */
/*   aborted/repeated trial requests                 */
/* - do_pursuit_trial() interperts trial number       */
/*   and supplies appropriate TRIALID label and      */
/*   stimuli for each trial                          */
/* - See documentation for more details              */  
/*                                                   */
/*                                                   */
/* CHANGES FOR Windows 2000/XP, EyeLink 2.0:  NEW    */
/*                                                       */
/* CHANGES FOR Windows 2000/XP, EyeLink API 2.1:         */
/* - change delay numbers in messages to first item      */
/*****************************************************/
 
#include <windows.h>
#include <windowsx.h>

#include "gdi_expt.h"
#include "w32_demo.h"

#include "w32_targets.h"

/*********** SINUSOIDAL PURSUIT DRAWING AND MOTION ***************/

#include <math.h>

#define PI 3.14159

#define FRACT2RAD(x)  (2*PI*(x))         // fraction of cycles-> radians
#define DEG2RAD(x)    ((2*PI/360*(x))    // degrees -> radians

int sine_amplitude;    // amplitude of sinusoid (pixels, center-to-left)
int sine_plot_x;         // center of sineusiod
int sine_plot_y;         
float sine_frequency;    // sine cycles per second
float sine_start_phase;  // in degrees, 0=center moving right
int sine_cycle_count;

UINT32 min_target_duration = 2000;   // random target change interval
UINT32 max_target_duration = 4000;
UINT32 next_target_time;   // time of last target switch
int current_target;        // current target used 

UINT32 target_report_interval = 50;  // report sine phase every 50 msec
UINT32 last_report_time;

     // callback from run_dynamic_trial
     // Args: t is time of vertical retrace
     //       dt is time from start of trial
     //       *xp, *yp are used to return postion of fixation target
     // Returns: 0 to continue, 1 to end trial
int prev_x, prev_y, outer_diameter;

int __cdecl sinusoidal_drawing(UINT32 t, UINT32 dt, int *xp, int *yp)
{
  float phase;   // phase in fractions of cycle
  int tchange = 0;
  int x, y;
                             // phase of sinusoid
  phase =(float)(sine_start_phase/360 + (dt/1000.0)*sine_frequency);
                             // compute target position

  if(dt >= next_target_time)
    {
      current_target = (current_target==2) ? 3 : 2;
      next_target_time = dt + 
        (rand()%(max_target_duration-min_target_duration))+min_target_duration;
      tchange = 1;
    }

  x =(int)( sine_plot_x + sine_amplitude*sin(FRACT2RAD(phase)));
  y = sine_plot_y;
  move_target(0, x, y, current_target);

  
  GdiFlush();  // do after drawing
  
  last_report_time = dt;
  eyemsg_printf("%d POSN %d %d", current_msec()-t, x, y);

  if (prev_x!=-1 && prev_y!=-1)
      eyemsg_printf("!V FILLBOX 0 0 0 %d %d %d %d", 
        prev_x-(outer_diameter+1)/2, 
        prev_y-(outer_diameter+1)/2, 
        prev_x+(outer_diameter+1)/2, 
        prev_y+(outer_diameter+1)/2);    
  
  eyemsg_printf("!V FIXPOINT 255 0 0 0 0 0 %d %d %d 0", x, y, outer_diameter);

  if(tchange)
    {
      eyemsg_printf("%d TSET %d %d %d", current_msec()-t, current_target, x, y);
    }

  if(xp) *xp = x;  // return fixation point location
  if(yp) *yp = y;
    
  prev_x = x ;
  prev_y = y;


  // check if proper number of cycles executed
  if(floor(phase-sine_start_phase/360) >= sine_cycle_count) 
    return 1;
  else
    return 0;
}


/*********** SINUSOIDAL TRIAL SETUP AND RUN **********/

        // setup, run sinusiodal pursuit trial
        // do_change controls target changes
int do_sine_trial(int do_change)
{
  int i;
                  // blank background bitmap
  HBITMAP background;

  background = blank_bitmap(target_background_color);
  if(!background) return TRIAL_ERROR;
                  // red targets (for minimal phosphor persistance)
  initialize_targets(RGB(255, 0, 0), target_background_color);

  sine_amplitude = SCRWIDTH/3;  // about 10 degrees for 20 deg sweep
  sine_plot_x = SCRWIDTH/2;     // center of display
  sine_plot_y = SCRHEIGHT/2;         
  sine_frequency = 0.4F;         // 0,4 Hz, 2.5 sec/cycle
  sine_start_phase = 270;       // start at left
  sine_cycle_count = 10;        // 25 seconds  

  if(do_change)               // do we do target flip?
    {
      current_target = 2;     // yes: set up for flipping
      next_target_time = 0;
      last_report_time = 0;
    }
  else
    {
      current_target = 1;              // round target
      next_target_time = 0xFFFFFFFF;   // disable target flipping
      last_report_time = 0xFFFFFFFF;
    }
  
  set_offline_mode();		     // Must be offline to draw to EyeLink screen
  eyecmd_printf("clear_screen 0");   // clear tracker display
                                     // add boxes at left, right extrema
  eyecmd_printf("draw_filled_box %d %d %d %d  7", sine_plot_x-16, sine_plot_y-16, 
  					    sine_plot_x+16, sine_plot_y+16);
  eyecmd_printf("draw_filled_box %d %d %d %d  7", sine_plot_x+sine_amplitude-16, sine_plot_y-16, 
  					    sine_plot_x+sine_amplitude+16, sine_plot_y+16);
  eyecmd_printf("draw_filled_box %d %d %d %d  7", sine_plot_x-sine_amplitude-16, sine_plot_y-16, 
  					    sine_plot_x-sine_amplitude+16, sine_plot_y+16);
                                     // add expected track line
  eyecmd_printf("draw_line %d %d %d %d  15", sine_plot_x+sine_amplitude-16, sine_plot_y, 
  					    sine_plot_x-sine_amplitude+16, sine_plot_y);

  prev_x = -1;
  prev_y = -1;
  i = run_dynamic_trial(background, 200*1000L, sinusoidal_drawing); 

  DeleteObject(background);
  free_targets();

  return i;
}



/*********** SACCADIC GAP/STEP/OVERLAP ***************/

INT32 overlap_interval = 200;     // gap <0, overlap >0
UINT32 prestep_delay = 600;       // time from trial start to move
UINT32 trial_duration = 2000;     // total trial duration

int fixation_x;    // position of initial fixation  target
int fixation_y;
int goal_x;        // position of final saccade target
int goal_y;                

int fixation_visible;  // used to detect changes 
int goal_visible;

     // callback from run_dynamic_trial
     // Args: t is time of vertical retrace
     //       dt is time from start of trial
     //       *xp, *yp are used to return postion of fixation target
     // Returns: 0 to continue, 1 to end trial

int __cdecl saccadic_drawing(UINT32 t, UINT32 dt, int *xp, int *yp)
{
  int fv;   // indicates if fixation target visible
  int gv;   // indicates if goal target visible
   
  if (t==0 && dt==0)
     eyemsg_printf("!V FIXPOINT 255 255 255 255 255 255 %d %d %d 0", 
        fixation_x, fixation_y, outer_diameter);     

              // compute fixation visibility
  fv = (dt <  prestep_delay+overlap_interval) ? 1 : 0;
              // draw or hide fixation target
  move_target(0, fixation_x, fixation_y, fv);

              // compute goal visibility
  gv = (dt >= prestep_delay) ? 1 : 0;
              // draw or hide goal target
  move_target(1, goal_x, goal_y, gv);

  GdiFlush();  // do only after both draws

  if(dt > 0)  // no message for initial setup
    {
      if(fv != fixation_visible)  // mark fixation offset
      {  
          eyemsg_printf("%d HIDEFIX", current_msec()-t);
          eyemsg_printf("!V FILLBOX 0 0 0 %d %d %d %d", 
              fixation_x-(outer_diameter+1)/2, 
              fixation_y-(outer_diameter+1)/2, 
              fixation_x+(outer_diameter+1)/2, 
              fixation_y+(outer_diameter+1)/2);    
      }
      if(gv != goal_visible)      // mark target onset
      {   
          eyemsg_printf("%d SHOWGOAL", current_msec()-t);
          eyemsg_printf("!V FIXPOINT 255 255 255 255 255 255 %d %d %d 0", 
              goal_x, goal_y, outer_diameter);     
      }
    }

  fixation_visible = fv;   // record state for change detection
  goal_visible = gv;

  if(xp) *xp = fixation_x;  // return fixation point location
  if(yp) *yp = fixation_y;
                  // check if trial timed out
  if(dt > trial_duration) 
    return 1;
  else
    return 0;
}


/*********** SACCADIC TRIAL SETUP AND RUN **********/

        // run saccadic trial
        // gso = -1 for gap, 0 for step, 1 for overlap
        // dir = 0 for left, 1 for right
int do_saccadic_trial(int gso, int dir)
{
  int i;
  HBITMAP background;    // blank background bitmap

  background = blank_bitmap(target_background_color);
  if(!background) return TRIAL_ERROR;
                  // white targets (for visibility)
  initialize_targets(RGB(200, 200, 200), target_background_color);

  overlap_interval = 200 * gso;  // gap <0, overlap >0

  fixation_x = SCRWIDTH/2;    // position of initial fixation  target
  fixation_y = SCRHEIGHT/2;
                              // position of goal (10 deg. saccade) 
  goal_x = fixation_x + (dir ? SCRWIDTH/3 : -SCRWIDTH/3); 
  goal_y = fixation_y;                
  
  set_offline_mode();		     // Must be offline to draw to EyeLink screen
  eyecmd_printf("clear_screen 0");   // clear tracker display
                                     // add boxes at fixation goal targets
  eyecmd_printf("draw_filled_box %d %d %d %d  7", fixation_x-16, fixation_y-16, 
  					    fixation_x+16, fixation_y+16);
  eyecmd_printf("draw_filled_box %d %d %d %d  7", goal_x-16, goal_y-16, 
  					    goal_x+16, goal_y+16);
 
  // V_CRT command is recorded for EyeLink Data Viewer analysis
  // Adding a custom specific reaction time defintion, with the saccades as RT end event
  // "SYNCTIME" as RT start event.  Saccade must be more than 2.0 degrees and falls within
  // 50 pixels of the saccade goal.  Grammer:
  // !V V_CRT SACCADE SYNCTIME amplitude x y diameter
  eyemsg_printf("!V V_CRT SACCADE SYNCTIME	2.0	%d	 %d	 50", goal_x, goal_y);			
           
  // run sequence and trial
  i = run_dynamic_trial(background, 200*1000L, saccadic_drawing); 
                        // clean up background bitmap
  DeleteObject(background);
  free_targets();

  return i;
}


/************************************************/

#define NTRIALS 8

char *trial_titles[NTRIALS] = {"Sinusoid", "Sinusoid with Target Changes",
                               " Gap Left", "Gap Right", 
                               "Step Left", "Step Right", 
                               "Overlap Left", "Overlap Right" };

char *trial_labels[2][NTRIALS] = {	{"Sinusoid", "Sinusoid", "Gap","Gap","Step", "Step", "Overlap", "Overlap" },
									{"No_Change", "Target_change", "left", "right", "left", "right", "left", "right"}};

int trial_gso[NTRIALS] = {0, 0, -1, -1, 0, 0, 1, 1 }; 
int trial_dir[NTRIALS] = {0, 0,  0,  1, 0, 1, 0, 1 }; 


         // FOR EACH TRIAL:
         // - set title, TRIALID
         // - Create bitmaps and EyeLink display graphics
         // - Check for errors in creating bitmaps
         // - Run the trial recording loop
         // - Delete bitmaps
         // - Return any error code

              // Given trial number, execute trials
              // Returns trial result code
int do_dynamic_trial(int num)
{
  // This supplies the title at the bottom of the eyetracker display 
  eyecmd_printf("record_status_message '%s, TRIAL %d/%d' ", trial_titles[num-1], num, NTRIALS);

  // Always send a TRIALID message before starting to record. 
  // It should contain trial condition data required for analysis.
  eyemsg_printf("TRIALID %d %s %s", num, trial_labels[0][num-1], trial_labels[1][num-1]);

  // TRIAL_VAR_DATA message is recorded for EyeLink Data Viewer analysis
  // It specifies the list of trial variables value for the trial 
  // This must be specified within the scope of an individual trial (i.e., after 
  // "TRIALID" and before "TRIAL_RESULT") 
  eyemsg_printf("!V TRIAL_VAR_DATA %d %s %s", num, trial_labels[0][num-1], trial_labels[1][num-1]);

        // Actually run the trial: display a single word
  switch(num)
    {
    case 1:
      return do_sine_trial(0); 
    case 2:
      return do_sine_trial(1); 
    default:
      return do_saccadic_trial(trial_gso[num-1], trial_dir[num-1]);
    }
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

  outer_diameter = SCRWIDTH/60;

  target_foreground_color = RGB(200,200,200);  // set background for calibration
  target_background_color = RGB(0,0,0);        // This should match the display 
  set_calibration_colors(target_foreground_color, target_background_color); 

  // TRIAL_VAR_LABELS message is recorded for EyeLink Data Viewer analysis
  // It specifies the list of trial variables for the trial 
  // This should be written once only and put before the recording of individual trials
  eyemsg_printf("TRIAL_VAR_LABELS TRIAL TYPE DIRECTION");

      // SET UP FOR HORIZONTAL-ONLY CALIBRATION
  eyecmd_printf("horizontal_target_y = %d", SCRHEIGHT/2); // vertical position
  eyecmd_printf("calibration_type = H3");             // Setup calibration type

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
      i = do_dynamic_trial(trial);
      end_realtime_mode();          // safety: make sure realtime mode stopped

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

  if(delayed_retrace_count)
    alert_printf("%d Delayed retrace cycles", delayed_retrace_count);
  return 0;
}

