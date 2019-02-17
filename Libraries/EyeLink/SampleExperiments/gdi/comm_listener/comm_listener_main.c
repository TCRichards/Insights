/*****************************************************/
/* Windows 95/98/NT/2000/XP sample experiment in C   */
/* For use with Version 2.0 of EyeLink Windows API   */
/*                                                   */
/*      (c) 1997-2002 by SR Research Ltd.            */
/* For non-commercial use by Eyelink licencees only  */
/*                                                   */
/* THIS FILE: broadcast_main.c (NEW)                 */
/* CONTENTS:                                         */
/* - Stub for Windows (WinMain(), etc)               */
/* - app_main() for listener:                        */
/*   - initialize without connecting to tracker      */  
/*   - do usual display, calibration setup           */
/*   - wait for another computer to connect          */
/*   - open broadcast (listener) connectionm         */
/*   - find gaze coords set by other program         */
/*   - track modes, process as needed                */
/*   - repeat till closed                            */
/* - NOTE: This is a passive program, that does not  */ 
/*       send commands to tracker, open files, etc.  */
/*       Reading of gaze coord seting may fail on    */
/*       older trackers.                             */
/*                                                   */
/*                                                   */
/* NEW FOR Windows 2000/XP, EyeLink API 2.1 or later */
/*****************************************************/

/*****************************************************/
/* NOTE: REQUIRES NEW VERSIONS:                      */
/*                                                   */
/* EYE TRACKERS:                                     */
/* EyeLink I version 2.1 or higher                   */
/* EyeLink II version 1.1 or higher                  */
/*                                                   */
/* WINDOWS API FILES:                                */
/* eyelink_exptkit.dll version 2.1 or higher         */
/* eyelink_exptkit.lib June 12, 2002 or later        */
/* Header files dated June 13, 2002 or later:        */
/* eyelink.h                                         */
/* eyelink.h                                         */
/* eye_data.h                                        */
/* eyetypes.h                                        */
/* w32_exptsppt.h                                    */
/*****************************************************/

#include <windows.h>
#include <windowsx.h>

#include "gdi_expt.h"
#include "w32_demo.h"
#include <stdio.h>

extern void listening_loop(void);


           // the application instance: required to create windows and get resources
HANDLE application_instance = NULL;  

           // display information: size, colors, refresh rate
DISPLAYINFO dispinfo;

           // The colors of the target and background for calibration and drift correction
COLORREF target_foreground_color = RGB(0,0,0);   // targets
COLORREF target_background_color = RGB(200,200,200);   // background

ELINKADDR connected_address;   // address of comm_simple (from message)


/********* WAIT FOR A CONNECTION MESSAGE **********/

           // waits for a inter-application message
           // checks message, responds to complete connection
           // this is a very simple example of data exchange
int wait_for_connection(void)
{
  int i;
  int first_pass = 1;   // draw display only after first failure
  char message[100];

  while(1)          // loop till a message received
    {
      i = eyelink_node_receive(connected_address, message);
      if(i > 0)     // do we have a message?
        {           // is it the expected application?
          if(!_stricmp(message, "NAME comm_simple")) 
            {              // yes: send "OK" and proceed
              return 0;
            }
        }

      if(first_pass)   // If not, draw title screen
        {
          first_pass = 0;  // don't draw more than once

          clear_full_screen_window(target_background_color);
          get_new_font("Times Roman", SCRHEIGHT/32, 1);         // select a font
          i = 1;
          graphic_printf(PALETTERGB(0,0,0), -1, 0, SCRWIDTH/15, i++*SCRHEIGHT/26, 
                    "EyeLink Data Listener and Communication Demonstration");
          graphic_printf(PALETTERGB(0,0,0), -1, 0, SCRWIDTH/15, i++*SCRHEIGHT/26, 
                    "Copyright 2002 SR Research Ltd.");
          i++;
          graphic_printf(PALETTERGB(0,0,0), -1, 0, SCRWIDTH/15, i++*SCRHEIGHT/26, 
                    "Waiting for COMM_SIMPLE application to send startup message...");
          graphic_printf(PALETTERGB(0,0,0), -1, 0, SCRWIDTH/15, i++*SCRHEIGHT/26, 
                    "Press ESC to quit");
        }

      i = getkey();         // check for exit
      if(i==ESC_KEY || i==TERMINATE_KEY) return 1;
    }
}


/*********** MAIN: SETUP, CLAENUP **********/

int app_main(void)
{
  int i;

         // open DLL to allow unconnected communications
  if(open_eyelink_connection(-1)) 
    return -1;    // abort if we can't open link

  eyelink_set_name("comm_listener");  // set our network name

  get_display_information(&dispinfo);     // get display size, characteristics
      
     // NOTE: Camera display does not support 16-color modes
  if(dispinfo.palsize==16)      // 16-color modes not functional
    {
      alert_printf("This program cannot use 16-color displays");
      goto shutdown;
    }

  flush_getkey_queue();                 // initialize getkey() system
  if(make_full_screen_window(application_instance))  // create the window
      goto shutdown;
  if(init_expt_graphics(full_screen_window, NULL))   // register window for cal/image
      goto shutdown;  

     // in this simple example, we don't use calibration 
     // graphics at all so we don't bother to set them up.

  while(1)  // Loop through one or more sessions
    {
                // wait for connection to listen to, or aborted
      if(wait_for_connection()) goto shutdown;  

                // now we can start to listen in
      if(eyelink_broadcast_open())
        {
          alert_printf("Cannot open broadcast connection to tracker");
          goto shutdown;     
        }

          // enable link data reception by EyeLink DLL
      eyelink_reset_data(1);   
          // NOTE: this function can discard some link data
      eyelink_data_switch(RECORD_LINK_SAMPLES | RECORD_LINK_EVENTS);

      pump_delay(500);       // tell COM_SIMPLE it's OK to proceed        
      eyelink_node_send(connected_address, "OK", 10); 

      clear_full_screen_window(target_background_color);
      get_new_font("Times Roman", SCRHEIGHT/32, 1);         // select a font
      i = 1;
      graphic_printf(target_foreground_color, -1, 0, SCRWIDTH/15, i++*SCRHEIGHT/26, 
                    "Listening in on link data and tracker mode...");

      listening_loop();   // listen and process data and messages
                          // returns when COMM_SIMPLE closes connection to tracker

      if(break_pressed())  // make sure we're still alive
         goto shutdown;   
    }

shutdown:                // CLEANUP
  pump_delay(500);	/* give tracker time to execute all commands */
  close_expt_graphics();           // tell EXPTSPPT to release window
  close_eyelink_connection();        // make sure EYELINK DLL is released
  close_full_screen_window();
  return 0;
}

        // WinMain - Windows calls this to execute application
int PASCAL WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
  application_instance = application_instance = hInstance;  // record the application instance for accessing resources
  full_screen_window = NULL;
  app_main();                        // call our real program
  close_eyelink_connection();        // make sure EYELINK DLL is released
  if(full_screen_window)
    close_full_screen_window();
  return 0;
} 
