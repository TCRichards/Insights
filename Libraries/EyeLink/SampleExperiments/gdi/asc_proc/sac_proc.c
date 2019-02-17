/* EYELINK SUPPORT: ASC PROCESS EXAMPLE */
/* 17/5/96 by Dave Stampe: 		*/

// SIMPLE PROCESSOR FOR SACCADIC GAP EXPT

#include <stdlib.h>
#include <stdio.h>
//#include <conio.h>
#include <math.h>
#include <ctype.h>
//#include <dos.h>
#include <string.h>
#include <setjmp.h>

#include "eyetypes.h"
#include "read_asc.h"

/*********** SACCADE EXPT PROCESS ***********/


	// assume we started reading a "TRIALID" message
	// before we called this
int process_trial(void)
{
		// some variables pre-set to 0
  char *token;
  long etime;
  long target_on_time = 0;
  long first_sacc_time = 0;
  int num_saccades = 0;
  int have_blink = 0;
  int response_button = 0;
  long button_time = 0;
  int target_posn;
  int is_left;
  int correct_response = 0;
  int target_delay;
  int trial_number;
  int block_number;

			// continue to process the TRIALID message

  asc_string();				// Skip ID string (for EDFVIEW)
  block_number = asc_long();		// read numeric data: block, trial number 
  trial_number = asc_long();
  target_posn = asc_long();		// Target offset: positive = right
  target_delay = asc_long();		// Delay to erase: negative = gap trial
  is_left = (target_posn < 320);	// left or right?
  if(asc_errors()) return -1;           // any errors?

  while(1)
    {
      token = asc_read_line();          // get first word on line
      if(token[0]==0) return -1;	// end of file

      else if (match("START"))		// START: select eye to process
	{
	  asc_start_block();
	}

      else if (match("MSG"))		// message
	{
	  etime = asc_long();  		// message time
	  token = asc_string();         // first word of message

	  if(match("DRAWN"))		// new target drawn
	    {
	      target_on_time = etime;
	    }
	  else if(match("TRIAL_RESULT")) // trial result
	    {
	      response_button = asc_long();
	    }
	  else if(match("TRIAL"))        // trial is OK?
	    {
	      token = asc_string();
	      if(match("OK") && response_button!=0) // report data, only if OK
		{
		  // A VERY SIMPLE DATA REPORT: FORMAT AS REQUIRED.

  printf("trial:%d\t delay:%d\t sac_rt:%ld\t but_rt:%ld\t corr:%d\t nsac:%d\t blink:%d\n",
	  trial_number, target_delay, first_sacc_time-target_on_time,
	  button_time-target_on_time, correct_response, num_saccades, have_blink);

		}
	      return 0;		// done trial!
	    }
	}

      else if (match("BUTTON"))		// button
	{
	  asc_read_button();
	  if(a_button.s==1 && (a_button.b==3 || a_button.b==2))
	    {
	      button_time = a_button.t;
	      response_button = a_button.b;
	      correct_response = ((is_left==1 && a_button.b==2) ||
					   (is_left==0 && a_button.b==3));
	    }
	}

      else if (match("ESACC"))	// end saccade
	{
	  if(asc_read_esacc(1)) continue;  // skip if wrong eye

			  // ignore if smaller than 1 degree
			  // or if we haven't displayed target yet
	  if(a_esacc.ampl>1.0 && target_on_time>0)
	    {
	      num_saccades++;
	      if(num_saccades==1) first_sacc_time = a_esacc.st;
	    }
	}
      else if (match("EBLINK"))	// blink
	{
	  have_blink++;
	}
		// IGNORE EVERYTHING ELSE
    }
}


	// call with file name to process
	// returns error flag if can't open file
int process_file(char *fname)
{
  char ascname[120];
  char *token;
  long etime;

  add_extension(fname, ascname, "asc", 0);	// make file name
  if(asc_open_file(ascname)) return -1;		// can't open file!!!

  while(1)
    {
      token = asc_read_line();          // get first word on line
      if(token[0]==0) break;
      else if (match("MSG"))		// message
	{
	  etime = asc_long();  		// message time
	  token = asc_string();         // first word of message
	  if(match("TRIALID"))
	    {
	      process_trial();  	// process trial data
	    }
	}   	// IGNORE EVERYTHING ELSE
    }
  asc_close_file();
  return 0;
}


/***************************************/

int main(int argc, char *argv[])
{
  char name[100];
  
  if(argc<2)
    {
      printf("\nASC file name? "); 
      gets(name);
    }
  else
    {
      strcpy(name, argv[1]);
    }

  if(strlen(name) == 0)
    {
      return 0;	  // no name entered
    }

  if(process_file(name))
    {
      printf("Error in processing file.\n");
      return 1;
    }
  return 0;  
}
