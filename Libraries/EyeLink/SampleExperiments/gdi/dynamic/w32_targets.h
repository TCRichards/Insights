/*********************************************************/
/* Windows 95/98/NT/2000/XP sample experiment in C       */
/* For use with Version 2.0 of EyeLink Windows API       */
/*                                                       */
/*      (c) 1997-2002 by SR Research Ltd.                */
/* For non-commercial use by Eyelink licencees only      */
/*                                                       */
/* THIS FILE: w32_targets.h                              */
/* CONTENTS:                                             */
/* - defines for drawing functions                       */
/* - all functions defined in w32_targets.h              */
/*   or in w32_dynamic_trial.h                           */
/*                                                       */
/*                                                       */
/* CHANGES FOR Windows 2000/XP, EyeLink 2.0:  NEW        */
/*********************************************************/


extern HBITMAP target_background_bitmap;   // bitmap used to erase targets

      // Create the target patterns
      // Targets: 0=none (used to clear), 1=0.5 degree disk, 2=\, 3=/
      // redfine as eeded for your targets
int initialize_targets(COLORREF fgcolor, COLORREF bgcolor);

      // call to delete target resources
void free_targets(void);

     // draw target, using pattern n, centered at x, y
void draw_target(int n, int x, int y, int shape);


     // erase target by erasing to background color
void erase_target(int n);


    // call after screen erased so targets know they're not visible
void target_reset(void);


   // handles moving target, changing shape,
   // and hides it if shape = 0
void move_target(int n, int x, int y, int shape);


      // count of frames with retrace delayed more than 20%
int delayed_retrace_count;

	/* Run a single trial, recording to EDF file and sending data through link */
	
	// NEW CODE FOR PURSUIT:
	// - in realtime mode continuously
	// - calls function <ontrol> to determine what to draw and where
        // - predraws drift correction target at start position
	// - draws just after vertical refresh
        
        // first argument is full-screen background bitmap 
        // third argument is a call back function (see below)
        //   this function is called immediately after refresh,
        //   and must erase and draw targets and write out any messages       
	 
int run_dynamic_trial(HBITMAP hbm, UINT32 time_limit, 
                     int (__cdecl * drawfn)(UINT32 t, UINT32 dt, int *x, int *y));

     // callback function from run_dynamic_trial
     // Args: t is time of vertical retrace
     //       dt is time from start of trial
     //       *xp, *yp are used to return postion of fixation target
     // Returns: 0 to continue, 1 to end trial
//  int drawfn(UINT32 t, UINT32 dt, int *x, int *y));

