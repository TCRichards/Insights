/*******************************************************************************
 * EYELINK EXPT SUPPORT: SDL PLATFORM										   *
 * (c) 1996-2002 by SR Research Ltd.                                           *
 * by Suganthan Subramaniam                                                    *
 * EYELINK II: 3 February 2003                                                 *
 *     For non-commercial use only                                             *
 * Provides hardware acclareted cursor drawing with SDL_Flip                   *
 * This module is for user applications. Use is granted for non-commercial     *
 * applications by Eyelink licencees only                                      *
 *                                                                             *
 *                                                                             *
 **************************************** WARNING ******************************
 *                                                                             *
 * UNDER NO CIRCUMSTANCES SHOULD PARTS OF THESE FILES BE COPIED OR COMBINED.   *
 * This will make your code impossible to upgrade to new releases in the future*
 * and SR Research will not give tech support for reorganized code.            *
 *                                                                             *
 * This file should not be modified. If you must modify it, copy the entire    *
 * file with a new name, and change the the new file.                          *
 *******************************************************************************/


#ifndef __SR_RESEARCH_FONTMAPPINGS_H__
#define __SR_RESEARCH_FONTMAPPINGS_H__
typedef struct 
{
	char * filename;
	char * font_name;
	char * font_face; /* not used for now */
}FONT_MAP;
#define FONTMAPPINGS {\
	{"Arial.ttf", 	"Arial", 				"Regular"},\
	{"arialbd.ttf", "Arial", 				"Bold"},\
	{"arialbi.ttf", "Arial", 				"Bold Italic"},\
	{"ariali.ttf",	"Arial", 				"Italic"},\
	{"ariblk.ttf", 	"Arial Black", 			"Regular"},\
	{"comic.ttf", 	"Comic Sans MS", 		"Regular"},\
	{"comicbd.ttf", "Comic Sans MS", 		"Bold"},\
	{"cour.ttf", 	"Courier New", 			"Regular"},\
	{"courbd.ttf", 	"Courier New", 			"Bold"},\
	{"courbi.ttf", 	"Courier New", 			"Bold Italic"},\
	{"couri.ttf", 	"Courier New", 			"Italic"},\
	{"georgia.ttf", "Georgia", 				"Regular"},\
	{"georgiab.ttf","Georgia", 				"Bold"},\
	{"georgiai.ttf","Georgia", 				"Italic"},\
	{"georgiaz.ttf","Georgia", 				"Bold Italic"},\
	{"impact.ttf", 	"Impact", 				"Regular"},\
	{"l_10646.ttf", "Lucida Sans Unicode", 	"Regular"},\
	{"lucon.ttf", 	"Lucida Console", 		"Regular"},\
	{"marlett.ttf", "Marlett", 				"Regular"},\
	{"micross.ttf", "Microsoft Sans Serif",	"Regular"},\
	{"pala.ttf", 	"Palatino Linotype", 	"Regular"},\
	{"palab.ttf", 	"Palatino Linotype", 	"Bold"},\
	{"palabi.ttf", 	"Palatino Linotype", 	"Bold Italic"},\
	{"palai.ttf", 	"Palatino Linotype", 	"Italic"},\
	{"symbol.ttf", 	"Symbol", 				"Regular"},\
	{"tahoma.ttf", 	"Tahoma", 				"Regular"},\
	{"tahomabd.ttf","Tahoma", 				"Bold"},\
	{"times.ttf", 	"Times New Roman", 		"Regular"},\
	{"timesbd.ttf", "Times New Roman", 		"Bold"},\
	{"timesbi.ttf", "Times New Roman", 		"Bold Italic"},\
	{"timesi.ttf", 	"Times New Roman", 		"Italic"},\
	{"trebuc.ttf", 	"Trebuchet MS",			"Regular"},\
	{"trebucbd.ttf","Trebuchet MS",			"Bold"},\
	{"trebucbi.ttf","Trebuchet MS",			"Bold Italic"},\
	{"trebucit.ttf","Trebuchet MS",			"Italic"},\
	{"verdana.ttf",	"Verdana", 				"Regular"},\
	{"verdanab.ttf","Verdana", 				"Bold"},\
	{"verdanai.ttf","Verdana", 				"Italic"},\
	{"verdanaz.ttf","Verdana", 				"Bold Italic"},\
	{"webdings.ttf","Webdings", 			"Regular"},\
	{"wingding.ttf","Wingdings", 			"Regular"},\
	{0,0,0}\
	}

#endif

