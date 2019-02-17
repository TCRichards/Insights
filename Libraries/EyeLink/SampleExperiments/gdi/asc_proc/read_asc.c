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

		// compare a to b, not case sensitive
int _cmpnocase(char *a, char *b)
{
  while(*a && *b) if(toupper(*a++)!=toupper(*b++)) return 1;
  if(*a || *b) return 1;
  return 0;
}

		// compare a to b, b may be shorter
int _cmpnocasepart(char *a, char *b)
{
  while(*a && *b) if(toupper(*a++)!=toupper(*b++)) return 1;
  if(*b) return 1;
  return 0;
}

/********* ADD EXTENSION TO FILE NAME **********/

			// copies file name from <in> to <out>
			// if no extension given, adds <ext>
			// <force> is nonzero, ALWAYS replaces extension
void add_extension(char *in, char *out, char *ext, int force)
{
  char *c;
  
  if(in != out) strcpy(out, in);
  c = strstr(in,".");
  if(c)
    {
      if(!force) return;
      *c = 0;
    }
  if(!ext || ext[0]==0) return;
  if(ext[0]!='.') strcat(out,".");
  strcat(out, ext);
}


/************ STRING PARSE ROUTINES *************/

#define iswhite(c) ((int)((c)==' ' || (c)== '\t' || (c)=='\r'))

	/* parse token out of string */
	/* *s is current parse pointer */
	/* returns pointer to buffer with token */
	/* will take text out of "quotes" -> quotes */

static char parseout[100];
static char *parseptr;

#define MISSING_DATA -32768

#define NUMBER_EXPECTED -32000
#define LINE_TOO_SHORT  -32001
#define SYNTAX_ERROR    -32002

static int line_error = 0;

static int iseol(char *s)
{
  char *c = s;

  while(iswhite(*c)) c++;        			/* skip whitespace */
  if(*c=='\n' || !*c)
    return 1;
  else return 0;
}


static char *parse(char **s)
{
  char *c = *s;
  char *p = parseout;
  char *e;

  parseout[0] = 0;
  while(iswhite(*c)) c++;        /* skip whitespace */

  if(iseol(c))	/* EOL/comment */
    {
      *s = c;
      return parseout;
    }

  while(!iswhite(*c) && !iseol(c)) *p++ = *c++;  /* copy till whitespace */
  *p = 0;
  *s = c+1;
  return parseout;
}


/****************** ASC FILE PARSER ****************/


static FILE *asc_file = NULL;
static char asc_line[320];
static long last_asc_line;

int asc_open_file(char *fname)
{
  if(asc_file) fclose(asc_file);
  if(!(asc_file=fopen(fname, "r"))) return -1;
  return 0;
}


void asc_close_file(void)
{
  if(asc_file)
    fclose(asc_file);
  asc_file = NULL;
}


char *asc_read_line(void)
{
  char *c;

next_line:
  if(!asc_file) return "";
  if(feof(asc_file)) return "";

  last_asc_line = ftell(asc_file);	// record position for restart

  asc_line[0] = 0;			// prevents repeated line at eof
  fgets(asc_line, 290, asc_file);
  parseptr = asc_line;
  line_error = 0;
  c = parse(&parseptr);
  if(!*c || *c=='/' || *c=='#' || !isprint(*c)) goto next_line;

  return c;
}


int asc_at_eol(void)
{
  return iseol(parseptr);
}


void asc_rewind_line(void)
{
  if(!asc_file) return;
  fseek(asc_file, last_asc_line, SEEK_SET);
}


int asc_errors(void)
{
  return line_error;
}


/****************** ASC DATA ELEMENT READ ****************/

long asc_long(void)
{
 char *s = parse(&parseptr);
 char *e;
 long l;

 if(!*s)
   {
     line_error = LINE_TOO_SHORT;
     return MISSING_DATA;
   }
 if(*s=='.') return MISSING_DATA;
 l = strtol(s,&e,0);
 if(*e)
   {
     line_error = NUMBER_EXPECTED;
     return MISSING_DATA;
   }
 return l;
}


double asc_float(void)
{
 char *s = parse(&parseptr);
 char *e;
 double f;

 if(!*s)
   {
     line_error = LINE_TOO_SHORT;
     return MISSING_DATA;
   }
 if(*s=='.') return MISSING_DATA;
 f = strtod(s,&e);
 if(*e)
   {
     line_error = NUMBER_EXPECTED;
     return MISSING_DATA;
   }
 return f;
}


char *asc_string(void)
{
 char *s = parse(&parseptr);

 if(!*s)
   {
     line_error = LINE_TOO_SHORT;
     return "";
   }
 return s;
}


char *asc_rest_of_line(void)
{
  char *c = parseptr;

  while(iswhite(*c)) c++;        /* skip whitespace */
  parseptr = c;
  if(strlen(c)>0 && c[strlen(c)-1]=='\n') c[strlen(c)-1] = 0;
  return c;
}



#define LEFT_EYE  0
#define RIGHT_EYE 1

int asc_eye(void)
{
  char *c = asc_string();

  if(!_cmpnocase(c, "L")) return LEFT_EYE;
  else if(!_cmpnocase(c, "R")) return RIGHT_EYE;
  else
    {
      line_error = SYNTAX_ERROR;
      return MISSING_DATA;
    }
}


/*************** USEFUL PARSING ROUTINES ****************/


int preferred_eye = LEFT_EYE;	// which eye's data to use if present
int selected_eye = LEFT_EYE;	// eye to select events from

			// call with event eye code
			// returns 0 if event is from unused eye
int asc_pass_eye(int eye)
{
  if(eye==selected_eye) return 1;
  else return 0;
}

/***************** BOOKMARKS ***********/

#ifndef ABOOKMARKDEF
#define ABOOKMARKDEF
typedef struct {
		long fpos;
		long blkpos;

		int seleye;	// which eye's data to use if present
		int has_left;
		int has_right;
		int has_samples;
		int has_events;
		int vel;
		int sam_res;
		int evt_res;
		int pupil_dia;
	       } BOOKMARK;
#endif

long last_block_start;

int asc_set_bookmark(BOOKMARK *bm)
{
  bm->fpos = last_asc_line;
  bm->blkpos = last_block_start;
  bm->seleye = selected_eye;
  bm->has_left = block_has_left;
  bm->has_right = block_has_right;
  bm->has_samples = block_has_samples;
  bm->has_events = block_has_events;
  bm->vel = samples_have_velocity;
  bm->sam_res = samples_have_resolution;
  bm->evt_res = events_have_resolution;
  bm->pupil_dia = pupil_size_is_diameter;

  return 0;
}


int asc_goto_bookmark(BOOKMARK *bm)
{
  last_asc_line     = bm->fpos;
  last_block_start  = bm->blkpos;

  selected_eye      = bm->seleye;
  block_has_left    = bm->has_left;
  block_has_right   = bm->has_right;
  block_has_samples = bm->has_samples;
  block_has_events  = bm->has_events;

  samples_have_velocity   = bm->vel;
  samples_have_resolution = bm->sam_res;
  events_have_resolution  = bm->evt_res;
  pupil_size_is_diameter  = bm->pupil_dia;

  asc_rewind_line();

  return 0;
}


BOOKMARK last_block_bookmark;

int asc_rewind_trial(void)
{
  char *token;
  asc_goto_bookmark(&last_block_bookmark);

  token = asc_read_line();          // get first word on line
  if(!match("START")) return -1;
  asc_start_block();
  return 0;
}



/****************** ASC BLOCK START READ ****************/


int block_has_left;
int block_has_right;

int block_has_samples;
int block_has_events;

int samples_have_velocity;
int samples_have_resolution;
int events_have_resolution;

int pupil_size_is_diameter;

	// assume that asc_read_line() returned "START"
	// before we called this
	// Scans the file for all block-start data
	// Sets data flags, selects eye to use for event processing
int asc_start_block(void)
{
  block_has_left = block_has_right = 0;
  block_has_samples = block_has_events = 0;
  samples_have_velocity = 0;
  samples_have_resolution = 0;
  events_have_resolution = 0;
  pupil_size_is_diameter = 0;

  asc_set_bookmark(&last_block_bookmark);
  last_block_start = last_asc_line;

  while(!asc_at_eol())			// Scan "START" for data types
    {
      char *c = asc_string();
      if(!strcmp(c, "LEFT"))         block_has_left = 1;
      else if(!strcmp(c, "RIGHT"))   block_has_right = 1;
      else if(!strcmp(c, "SAMPLES")) block_has_samples = 1;
      else if(!strcmp(c, "EVENTS"))  block_has_events = 1;
    }
					// Select eye to use in block
  if(preferred_eye==LEFT_EYE && block_has_left)
					selected_eye = LEFT_EYE;
  else if(preferred_eye==RIGHT_EYE && block_has_right)
					selected_eye = RIGHT_EYE;
  else if(block_has_left)  selected_eye = LEFT_EYE;
  else if(block_has_right) selected_eye = RIGHT_EYE;

  while(1)
    {
      char *token = asc_read_line();

      if(match("VPRESCALER") || match("PRESCALER")) continue;
      else if(match("SAMPLES"))
	while(!asc_at_eol())	    // Scan "SAMPLES" for data types
	  {
	    token = asc_string();
	    if(matchpart("RES"))      samples_have_resolution = 1;
	    else if(matchpart("VEL")) samples_have_velocity = 1;
	  }
      else if(match("EVENTS"))
	while(!asc_at_eol())	   // Scan "EVENTS" for data types
	  {
	    token = asc_string();
	    if(matchpart("RES"))      events_have_resolution = 1;
	  }
      else if(match("PUPIL"))
	while(!asc_at_eol())	   // Scan "EVENTS" for data types
	  {
	    token = asc_string();
	    if(matchpart("DIA"))  pupil_size_is_diameter = 1;
	  }
      else			   // past start data: rewind and exit
	{
	  asc_rewind_line();
	  return asc_errors();
	}
    }
}


/****************** ASC SAMPLE READ ****************/

#ifndef ASCSAMPLEDEF
#define ASCSAMPLEDEF
typedef struct {
		UINT32 t;      // time of sample
		float x[2];    // X position
		float y[2];    // Y position
		float p[2];    // pupil
		float resx;    // resolution (if samples_have_resolution==1)
		float resy;
		float velx[2];  // velocity (if samples_have_velocity==1)
		float vely[2];
	       } ASC_SAMPLE;
#endif

ASC_SAMPLE a_sample;	// asc_read_sample() places data here

		// returns -1 if error, 0 if sample read,
		//  else 1 (not sample: use asc_read_line() as usual).
		// x, y, p read to index of proper eye in a_sample
int asc_read_sample(void)
{
  char *token = asc_read_line();
  if(token[0]==0) return 0;		// end of file
  if(!isdigit(token[0]))	// not a sample
    {
      asc_rewind_line();    		// restart line\
      return 1;
    }

  a_sample.t = strtol(token, NULL, 10);  // time
  if(block_has_left)
    {
      a_sample.x[LEFT_EYE] = asc_float();
      a_sample.y[LEFT_EYE] = asc_float();
      a_sample.p[LEFT_EYE] = asc_float();
    }
  else
    {
      a_sample.x[LEFT_EYE] = MISSING_DATA;
      a_sample.y[LEFT_EYE] = MISSING_DATA;
      a_sample.p[LEFT_EYE] = MISSING_DATA;
    }
  if(block_has_right)
    {
      a_sample.x[RIGHT_EYE] = asc_float();
      a_sample.y[RIGHT_EYE] = asc_float();
      a_sample.p[RIGHT_EYE] = asc_float();
    }
  else
    {
      a_sample.x[RIGHT_EYE] = MISSING_DATA;
      a_sample.y[RIGHT_EYE] = MISSING_DATA;
      a_sample.p[RIGHT_EYE] = MISSING_DATA;
    }
  if(samples_have_velocity)
    {
      if(block_has_left)
	{
	  a_sample.velx[LEFT_EYE] = asc_float();
	  a_sample.vely[LEFT_EYE] = asc_float();
	}
      if(block_has_right)
	{
	  a_sample.velx[RIGHT_EYE] = asc_float();
	  a_sample.vely[RIGHT_EYE] = asc_float();
	}
    }
  if(samples_have_resolution)
    {
      a_sample.resx = asc_float();
      a_sample.resy = asc_float();
    }
  if(asc_errors()) return -1;
  return 0;
}



/****************** ASC EFIX READ ****************/

#ifndef ASCEFIXDEF
#define ASCEFIXDEF
typedef struct {
		int eye;     // eye
		UINT32 st;   // start time
		UINT32 et;   // end time
		UINT32 d;    // duration
		float x;     // X position
		float y;     // Y position
		float p;     // pupil
		float resx;  // resolution (if events_have_resolution==1)
		float resy;
	       } ASC_EFIX;
#endif

ASC_EFIX a_efix;   // asc_read_efix() places data here

	// must have read "EFIX" with asc_read_line() before calling
	// returns -1 if error, 1 if skipped (wrong eye), 0 if read
	// if <select_eye>==1, will skip unselected eye in binocular data
int asc_read_efix(int select_eye)
{
  int eye = asc_eye();
  if(select_eye && !asc_pass_eye(eye)) return 1;

  a_efix.eye = eye;
  a_efix.st = asc_long();
  a_efix.et = asc_long();
  a_efix.d  = asc_long();
  a_efix.x  = asc_float();
  a_efix.y  = asc_float();
  a_efix.p  = asc_float();

  if(events_have_resolution)
    {
      a_efix.resx  = asc_float();
      a_efix.resy  = asc_float();
    }

  return asc_errors() ? -1 : 0;
}

/****************** ASC ESACC READ ****************/

#ifndef ASCESACCDEF
#define ASCESACCDEF
typedef struct {
		int eye;     // eye
		UINT32 st;   // start time
		UINT32 et;   // end time
		UINT32 d;    // duration
		float sx;    // start X position
		float sy;    // start Y position
		float ex;    // end X position
		float ey;    // end Y position
		float ampl;  // amplitude in degrees
		float pvel;  // peak velocity, degr/sec
		float resx;  // resolution (if events_have_resolution==1)
		float resy;
	       } ASC_ESACC;
#endif

ASC_ESACC a_esacc;   // asc_read_esacc() places data here

	// must have read "ESACC" with asc_read_line() before calling
	// returns -1 if error, 0 if skipped (wrong eye), 1 if read
	// if <select_eye>==1, will skip unselected eye in binocular data
int asc_read_esacc(int select_eye)
{
  int eye = asc_eye();
  if(select_eye && !asc_pass_eye(eye)) return 1;

  a_esacc.eye = eye;
  a_esacc.st = asc_long();
  a_esacc.et = asc_long();
  a_esacc.d  = asc_long();
  a_esacc.sx  = asc_float();
  a_esacc.sy  = asc_float();
  a_esacc.ex  = asc_float();
  a_esacc.ey  = asc_float();
  a_esacc.ampl  = asc_float();
  a_esacc.pvel  = asc_float();

  if(events_have_resolution)
    {
      a_esacc.resx  = asc_float();
      a_esacc.resy  = asc_float();
    }

  return asc_errors() ? -1 : 0;
}

/****************** ASC EBLINK READ ****************/

#ifndef ASCEBLINKDEF
#define ASCEBLINKDEF
typedef struct {
		int eye;     // eye
		UINT32 st;   // start time
		UINT32 et;   // end time
		UINT32 d;    // duration
	       } ASC_EBLINK;
#endif

ASC_EBLINK a_eblink;   // asc_read_eblink() places data here

	// must have read "EBLINK" with asc_read_line() before calling
	// returns -1 if error, 0 if skipped (wrong eye), 1 if read
	// if <select_eye>==1, will skip unselected eye in binocular data
int asc_read_eblink(int select_eye)
{
  int eye = asc_eye();
  if(select_eye && !asc_pass_eye(eye)) return 1;

  a_eblink.eye = eye;
  a_eblink.st = asc_long();
  a_eblink.et = asc_long();
  a_eblink.d  = asc_long();

  return asc_errors() ? -1 : 0;
}


/****************** ASC BUTTON READ ****************/

#ifndef ASCBUTTONDEF
#define ASCBUTTONDEF
typedef struct {
		UINT32 t;    // time of button press
		int b;	     // button number (1-8)
		int s;	     // button change (1=pressed, 0=released)
	       } ASC_BUTTON;
#endif

ASC_BUTTON a_button;   // asc_read_button() places data here

	// must have read "BUTTON" with asc_read_line() before calling
	// returns -1 if error, 0 if read OK
int asc_read_button(void)
{
  a_button.t = asc_long();
  a_button.b = asc_long();
  a_button.s = asc_long();

  return asc_errors() ? -1 : 0;
}


/****************** ASC START-EVENT READ ****************/

	// This is used to read SBLINK, SSACC, SFIX, etc.

#ifndef ASCSTARTDEF
#define ASCSTARTDEF
typedef struct {
		int eye;     // eye
		UINT32 st;   // start time
	       } ASC_START;
#endif

ASC_START a_start;   // asc_read_start() places data here

	// must have read "SBLINK", "SSACC", or "SFIX"
	// with asc_read_line() before calling
	// returns -1 if error, 0 if skipped (wrong eye), 1 if read
	// if <select_eye>==1, will skip unselected eye in binocular data
int asc_read_start(int select_eye)
{
  int eye = asc_eye();
  if(select_eye && !asc_pass_eye(eye)) return 1;

  a_start.eye = eye;
  a_start.st = asc_long();

  return asc_errors() ? -1 : 0;
}


