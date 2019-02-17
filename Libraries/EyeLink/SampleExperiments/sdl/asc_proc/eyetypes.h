/* EYELINK PORTABLE EXPT SUPPORT    */
/* (c) 1996-2002 by SR Research    */
/*     8 June '97 by Dave Stampe    */
/*     For non-commercial use only  */
/*				    */
/*  Platform-portable types         */

/* This module is for user applications   */
/* Use is granted for non-commercial      */
/* applications by Eyelink licencees only */

/************** WARNING **************/
/*                                   */
/* UNDER NO CIRCUMSTANCES SHOULD     */
/* PARTS OF THESE FILES BE COPIED OR */
/* COMBINED.  This will make your    */
/* code impossible to upgrade to new */
/* releases in the future, and       */
/* SR Research will not give tech    */
/* support for reorganized code.     */
/*                                   */
/* This file should not be modified. */
/* If you must modify it, copy the   */
/* entire file with a new name, and  */
/* change the the new file.          */
/*                                   */
/************** WARNING **************/

/* 22 May '97: Macintosh types validated (Same as DOS) */
/* 5 June '97: WIN32 types validated (Same as DOS) */

/*#define FARTYPE _far */  /* unusual--for some mixed-model builds */
#define FARTYPE            /* make blank for most DOS, 32-bit, ANSI C */

#ifdef __cplusplus 	/* For C++ definitions */
extern "C" {
#endif

#ifndef BYTEDEF
	#define BYTEDEF 1

	typedef unsigned char  byte;
	typedef short          INT16;
	typedef long           INT32;
	typedef unsigned short UINT16;
	typedef unsigned long  UINT32;
#endif

#ifndef MICRODEF            /* Special high-resolution time structure */
	#define MICRODEF 1
	typedef struct {
		INT32  msec;	/* SIGNED for offset computations */
		INT16  usec;
	} MICRO ;
#endif

#ifdef __cplusplus	/* For C++ definitions */
}
#endif
