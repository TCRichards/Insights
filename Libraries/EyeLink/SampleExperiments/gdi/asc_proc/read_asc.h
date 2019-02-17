/* ASC FILE READ SUPPORT FUNCTIONS  */
/*     (c) 1996-2002 by SR Research      */
/*     18 May '96 by Dave Stampe    */
/*     For non-commercial use only  */

// VOLATILE STRING NOTE:
// Functions that return strings reference
// a temporary copy-- this will be overwritten on the next
// token read or line read.  Use it for comparisons only,
// or copy it if you need a permanent record.

	// STRING COMPARISONS:
	// use variable "token" when reading strings
int _cmpnocase(char *a, char *b);
int _cmpnocasepart(char *a, char *b);

	// this will check for full-word match
#define match(a)     (!_cmpnocase(token,a))

	// this will check the first characters of the word
#define matchpart(a) (!_cmpnocasepart(token,a))

/********* ADD EXTENSION TO FILE NAME **********/

			// copies file name from <in> to <out>
			// if no extenasion given, adds <ext>
			// <force> is nonzero, ALWAYS replaces extension
void add_extension(char *in, char *out, char *ext, int force);


/****************** ASC FILE OPEN, LINE READ ****************/

		// opens ASC file (adds .ASC extension if none given)
		// returns 0 if OK, -1 if error
int asc_open_file(char *fname);

		// closes ASC file if open
void asc_close_file(void);

		// Starts new ASC file line, returns first word
		// skips blank lines and comments
		// returns "" if end of file
		// NOTE: word string is volatile!
char *asc_read_line(void);

	 // returns 0 if more tokens available, 1 if at end of line
int asc_at_eol(void);

	// rewinds to start of line:
	// asc_read_line() can again be used to read first word.
void asc_rewind_line(void);


	// returns 0 if no errors so far in line, else error code
int asc_errors(void);

#define NUMBER_EXPECTED -32000	// read string when number expected
#define LINE_TOO_SHORT  -32001  // missing token
#define SYNTAX_ERROR    -32002	// unexpected word


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


int asc_set_bookmark(BOOKMARK *bm);

int asc_goto_bookmark(BOOKMARK *bm);

extern BOOKMARK last_block_bookmark;

int asc_rewind_trial(void);

/****************** ASC DATA ELEMENT READ ****************/

	// NOTE: when reading a float or long,
	// if missing data ('.') or non-numberical values
	// are encountered, MISSING_DATA is returned.

#define MISSING_DATA -32768

		// reads integer or long value
		// returns MISSING_VALUE if '.' or non-numeric
long asc_long(void);

		// reads floating-point value
		// returns MISSING_VALUE if '.' or non-numeric
double asc_float(void);

		// returns pointer to next token (VOLATILE)
		// returns "" if end of line
char *asc_string(void);

		// returns pointer to rest of line text (VOLATILE)
		// returns "" if end of line
char *asc_rest_of_line(void);


		// reads "L" or "R" code for eye event
		// returns LEFT_EYE, RIGHT_EYE, or -1 if error
int asc_eye(void);

#define LEFT_EYE  0	// codes for eyes (also index into sample data)
#define RIGHT_EYE 1


/*************** SELECT EVENTS BY EYE ****************/

	// After opening the file, set prefferred_eye
	// to the code for the eye you wish to process
	// After starting a data block, selected_eye
	// will contain the code for the eye that can be used
	// (depends on preferred_eye and which eye(s) data is available)

extern int preferred_eye;	// which eye's data to use if present
extern int selected_eye;	// eye to select events from

			// call with event eye code
			// returns 0 if event is from unused eye, else 1
int asc_pass_eye(int eye);


/************ ASC BLOCK START READ ***********/

	// This reads all data associated with block starts
	// It sets flags, and selects the eye to process

extern int block_has_left;	// nonzero if left eye data present
extern int block_has_right;     // nonzero if right eye data present

extern int block_has_samples;   // nonzero if samples present
extern int block_has_events;    // nonzero if events present

extern int samples_have_velocity;    // nonzero if samples have velocity data
extern int samples_have_resolution;  // nonzero if samples have resolution data
extern int events_have_resolution;   // nonzero if events have resolution data

extern int pupil_size_is_diameter;   // 0 if pupil units is area, 1 if diameter

  // Before calling, the token "START" must have been read by asc_read_line()
  // Scans the file for all block-start data
  // Sets data flags, selects eye to use for event processing
  // Returns: 0 if OK, else error encountered

int asc_start_block(void);


/************** ASC SAMPLE READ *************/

	// Reads a file line, processes if sample
	// Places data in the a_sample structure
	// If not sample, rewinds line for event processing

#ifndef ASCSAMPLEDEF
#define ASCSAMPLEDEF
typedef struct {
		UINT32 t;      // time of sample
		float x[2];    // X position (left and right eyes)
		float y[2];    // Y position (left and right eyes)
		float p[2];    // pupil size (left and right eyes)
		float resx;    // resolution (if samples_have_resolution==1)
		float resy;
		float velx[2]; // velocity (if samples_have_velocity==1)
		float vely[2]; // (left and right eyes)
	       } ASC_SAMPLE;
#endif

extern ASC_SAMPLE a_sample;	// asc_read_sample() places data here

		// returns -1 if error, 0 if sample read,
		// else 1 (not sample: use asc_read_line() as usual).
		// x, y, p read to index of proper eye in a_sample
		// For example, if right-eye data only,
		// data is placed in a_sample.x[RIGHT_EYE],
		// but not in a_sample.x[LEFT_EYE].
		// Both are filled if binocular data.
int asc_read_sample(void);


/********** ASC EVENT DATA READ *************/

	// Data from event lines can be read to structures
	// which are in global data for fast access.
	// One routine reads each type of end events, and button events.
	// All start events are read by asc_read_start()
	// For eye events, usually only one eye's events are read,
	// and this is automatically selected if the <select_eye>
	// argument is nonzero.

	// DEFINITIONS OF EVENT DATA STRUCTURES

	 // "EFIX" event data structure, filled by asc_read_efix()
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

	 // "ESACC" event data structure, filled by asc_read_esacc()
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

	 // "EBLINK" event data structure, filled by asc_read_eblink()
#ifndef ASCEBLINKDEF
#define ASCEBLINKDEF
typedef struct {
		int eye;     // eye
		UINT32 st;   // start time
		UINT32 et;   // end time
		UINT32 d;    // duration
	       } ASC_EBLINK;
#endif

	 // "SBLINK", "SSACC", "SFIX" events, read by asc_read_start()
#ifndef ASCSTARTDEF
#define ASCSTARTDEF
typedef struct {
		int eye;     // eye
		UINT32 st;   // start time
	       } ASC_START;
#endif

	 // "BUTTON" event data structure, filled by asc_read_button()
#ifndef ASCBUTTONDEF
#define ASCBUTTONDEF
typedef struct {
		UINT32 t;    // time of button press
		int b;	     // button number (1-8)
		int s;	     // button change (1=pressed, 0=released)
	       } ASC_BUTTON;
#endif

	// Global event data, filled by asc_read functions

extern ASC_EFIX a_efix;     // asc_read_efix() places data here
extern ASC_ESACC a_esacc;   // asc_read_esacc() places data here
extern ASC_EBLINK a_eblink; // asc_read_eblink() places data here
extern ASC_START a_start;   // asc_read_start() places data here
extern ASC_BUTTON a_button; // asc_read_button() places data here


	// EVENT DATA READING ROUTINES
	// All return 0 if data read, -1 if error, 1 if skipped

	// must have read "EFIX" with asc_read_line() before calling
	// returns -1 if error, 1 if skipped (wrong eye), 0 if read
	// if <select_eye>==1, will skip unselected eye in binocular data
int asc_read_efix(int select_eye);

	// must have read "ESACC" with asc_read_line() before calling
	// returns -1 if error, 0 if skipped (wrong eye), 1 if read
	// if <select_eye>==1, will skip unselected eye in binocular data
int asc_read_esacc(int select_eye);


	// must have read "EBLINK" with asc_read_line() before calling
	// returns -1 if error, 0 if skipped (wrong eye), 1 if read
	// if <select_eye>==1, will skip unselected eye in binocular data
int asc_read_eblink(int select_eye);


	// must have read "BUTTON" with asc_read_line() before calling
	// returns -1 if error, 0 if read OK
int asc_read_button(void);

	// must have read "SBLINK", "SSACC", or "SFIX"
	// with asc_read_line() before calling
	// returns -1 if error, 0 if skipped (wrong eye), 1 if read
	// if <select_eye>==1, will skip unselected eye in binocular data
int asc_read_start(int select_eye);
