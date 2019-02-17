// SDLCoreGraphics.cpp : Implementation of CSDLCoreGraphics
#include "stdafx.h"
#include "Com_SDL__core_graphics.h"
#include "SDLCoreGraphics.h"
#include "SDL/SDL_Mixer.h"
SDL_Surface * RenderText_GDI(HFONT font, SDL_Color * color,
                              const char * str);

#define MAGNIFY 1
#define MISSING ((short)0xdead)
#define TARGETWIDTH  10
#define TARGETHEIGHT 10
#define SDL_CORE_ERROR (((((1<<15)|4))<<16)|1)
/////////////////////////////////////////////////////////////////////////////
// CSDLCoreGraphics

CSDLCoreGraphics::CSDLCoreGraphics()
{
	screen = NULL; 
	background = 0;
	foreground = 0;

	
	lastTarget.x= lastTarget.y = MISSING;
	lastLastTarget.x=lastLastTarget.y =MISSING;
	lastTarget.w = lastLastTarget.w = TARGETWIDTH;
	lastTarget.h = lastLastTarget.h = TARGETHEIGHT;
	sdlaudio = 0;

	width =0;
	height = 0;
	image = NULL;
	dc = NULL;

}
CSDLCoreGraphics::~CSDLCoreGraphics()
{
	printf("releasing CSDLCoreGraphics\n");
	fflush(NULL);
	SDL_Quit();// close down SDL window
}
HRESULT CSDLCoreGraphics::setVideoMode(int width, int height,  int bpp, int refresh) 
{
	if ( SDL_Init(SDL_INIT_VIDEO ) < 0 ) // initialize video 
	{
	  printf( "Couldn't initialize SDL: %s\n",SDL_GetError());
	  return SDL_CORE_ERROR;
	}
#if defined(WIN32) && !defined(_WIN64)
	screen= SDL_SetVideoModeEx(width,height,bpp,refresh, SDL_FULLSCREEN|SDL_DOUBLEBUF|SDL_HWSURFACE); // open full screen window with given dimension and refresh
#else
	screen= SDL_SetVideoMode(width,height,bpp,SDL_FULLSCREEN|SDL_DOUBLEBUF|SDL_HWSURFACE); // open full screen window with given dimension
#endif
	if(!screen)
	{
		printf( "SDL_SetVideoMode failed: %s\n",SDL_GetError());
		return SDL_CORE_ERROR;
	}
	foreground = SDL_MapRGB(screen->format,255,0,0); // initialize the foreground and background colors
	background = SDL_MapRGB(screen->format,0,0,0);


	if(SDL_InitSubSystem(SDL_INIT_AUDIO)<0) // try to open audio so the target sounds can be played.
	  {
		  sdlaudio =0; //  sdl audio is not supported.
		  printf("Audio error %s \n", SDL_GetError());
	  }
	  else
	  {
		// open 44.1KHz, signed 16bit, system byte order,
		//      stereo audio, using 1024 byte chunks
		  if(Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, 1, 1024)==-1) {  // open mixer
			printf("Mix_OpenAudio: %s\n", Mix_GetError());
			sdlaudio =0;
		}
		else
		{
			Mix_Volume(1,MIX_MAX_VOLUME/2);
			sdlaudio = 1;
		}
	  }
	// we passed
	return S_OK;
}

HRESULT CSDLCoreGraphics::setForeground(int r,int g,int b)
{
	foreground = SDL_MapRGB(screen->format,r,g,b); 
	return S_OK;
}        
HRESULT CSDLCoreGraphics::setBackground(int r,int g,int b)
{
	background = SDL_MapRGB(screen->format,r,g,b);
	return S_OK;
}


void CSDLCoreGraphics::clearWindow()
{
	SDL_FillRect(screen,NULL,background); // clear back buffer
	SDL_Flip(screen);					  // set the back buffer to fore buffer
	SDL_FillRect(screen,NULL,background); // also clear the previous fore buffer(the current back buffer)
}

// calibration related functions
HRESULT CSDLCoreGraphics::setupCalibrationDisplay( void)
{
	clearWindow();  // clear the window and initialize last target positions
	lastLastTarget.x = MISSING;
	lastLastTarget.y = MISSING;
	lastTarget.x = MISSING;
	lastTarget.y =MISSING;
	return S_OK;
}


HRESULT CSDLCoreGraphics::eraseCalibrationTarget( void)
{
	if(lastLastTarget.x !=MISSING && lastLastTarget.y !=MISSING )  // erase the calibration target on the back buffer. 
	{
		clearWindow();
		lastLastTarget.x = MISSING;
		lastLastTarget.y =MISSING;
		// note no flip here.
	}
	return S_OK;
}

HRESULT CSDLCoreGraphics::drawCalibrationTarget(short x,short y)
{
	SDL_Rect rect;
	rect.x = x;
	rect.y = y;
	rect.w = TARGETWIDTH;
	rect.h = TARGETHEIGHT;
	SDL_FillRect(screen,&rect,foreground); // draw the calibration target to the back buffer
	SDL_Flip(screen); // flip the buffer
	lastLastTarget.x = lastTarget.x; // update last target positions
	lastLastTarget.y = lastTarget.y;
	lastTarget.x = x;
	lastTarget.y =y;
	return S_OK;
}



HRESULT CSDLCoreGraphics::exitCalibrationDisplay( void)
{
	clearWindow(); // nothing to do here except clearing the window.
	return S_OK;
}
HRESULT CSDLCoreGraphics::recordAbortHide( void)
{
	clearWindow();
	return S_OK;
}

HRESULT CSDLCoreGraphics::clearCalibrationDisplay( void)
{
	clearWindow();
	return S_OK;
}


// end of calibration

// audio related functions
HRESULT  CSDLCoreGraphics::playCalibrationBeep(CAL_BEEP_ID sound)
{
	// play requested sound for targets
  if(!sdlaudio) return SDL_CORE_ERROR; // no audio
  char *soundfile = NULL;
  switch(sound)// select the sound to play
  {
	case DC_TARG_BEEP:  
	case CAL_TARG_BEEP:
        soundfile =  "type.wav";
        break;
	case DC_GOOD_BEEP:
    case CAL_GOOD_BEEP:
        soundfile =  "qbeep.wav";
        break;
	case DC_ERR_BEEP:
    case CAL_ERR_BEEP:
        soundfile =  "error.wav";
        break;
  }
  SDL_RWops * sf = SDL_RWFromFile(soundfile,"rb"); // read sound
  if(sf)
  {
    Mix_Chunk *chunk = Mix_LoadWAV_RW(sf,0); //load the sound
	if(chunk)
	{
		if(Mix_PlayChannelTimed(-1, chunk, 0,100)==-1)  // play the sound
		{
				printf("Mix_PlayChannel: %s\n",Mix_GetError());
		}
	}
	SDL_FreeRW(sf); // free the sound
	return S_OK;
  }
  else
	  return SDL_CORE_ERROR; // cannot open sound file
  	  
  
}
// end of audio
// IMAGE display related functions

HRESULT CSDLCoreGraphics::setupImageDisplay(short width,short height)
{
	// magnify the image
	width *=MAGNIFY;
	height *=MAGNIFY;

	// update image size
	this->width =width;
	this->height = height;

	// free any unfreed objects
	if(image) SDL_FreeSurface(image);
	if(dc) DeleteDC(dc);



	// create sdl surface that hold the image so that blit can be done
	image = SDL_CreateRGBSurface(SDL_SWSURFACE,width, height, 32,0, 0, 0, 0);

	HBITMAP bitmap;
	BITMAPINFO  pbmi;


	dc = CreateCompatibleDC(NULL);  //Create a drawing surface 
	memset(&pbmi,0,sizeof(BITMAPINFO));
	pbmi.bmiHeader.biSize = sizeof(BITMAPINFO);
	pbmi.bmiHeader.biWidth = width;
	pbmi.bmiHeader.biHeight =  height;
	pbmi.bmiHeader.biPlanes = 1;
	pbmi.bmiHeader.biBitCount = 32; 
	pbmi.bmiHeader.biCompression = BI_RGB;
	pbmi.bmiHeader.biXPelsPerMeter = 0;
	pbmi.bmiHeader.biYPelsPerMeter = 0;
	pbmi.bmiHeader.biClrUsed = 0;
	pbmi.bmiHeader.biClrImportant = 0;
	pbmi.bmiHeader.biSizeImage = width*4*height;

	// Create a DIB section that we can use to read the font bits out of
	bitmap = CreateDIBSection(dc, &pbmi, DIB_RGB_COLORS, (void **) &bmpBits, NULL, 0);
	SelectObject(dc,bitmap); // select the bitmap into dc
	return S_OK;
}

HRESULT CSDLCoreGraphics::drawCameraImage(IPicture __RPC_FAR *cameraImage)
{	
	long lWidth = -1;
	long lHeight = -2;

	// Note: the width and height of IPicture will not match with the sizes given in setupImageDisplay
	cameraImage->get_Width(&lWidth); // get the width
	cameraImage->get_Height(&lHeight); // get the height 
	// since coordinate system is different we have to invert the y-axis (api-191)
	HRESULT rv = cameraImage->Render(dc, 0, height, width, -height,0, 0, lWidth, lHeight, 0); // draw the image to the dc(magnified)
	if (!SUCCEEDED(rv))	return rv;
	
	// Now we have the rendered image in bmpBits. So, we copy the memory to image
	
	if (SDL_MUSTLOCK(image)) SDL_LockSurface(image); // lock image if need to
     // since our sdl image and the bitmap match in dimension and depth we can just do a single memcpy and not go through line by line
	 memcpy(image->pixels,bmpBits,(width * 4*height)); 
     if (SDL_MUSTLOCK(image)) SDL_UnlockSurface(image);// unlock image if need to
     
	

	 SDL_FillRect(screen,NULL,background); // clear back buffer
	 SDL_Rect dst = {(screen->w-image->w)/2,(screen->h-image->h)/2,0,0}; 
	 SDL_BlitSurface(image,NULL,screen,&dst); // copy the image to the center
	 drawImageTitle();
	 SDL_Flip(screen); // display the image
	return rv;
}
HRESULT CSDLCoreGraphics::exitImageDisplay( void)
{
	clearWindow(); // clear window
	if(image) // release image
	{
		SDL_FreeSurface(image);
		image = NULL;
	}

	if(dc) // release dc
	{
		DeleteDC(dc);
		dc = NULL;
	}
	return S_OK;
}
#define MAX_EVENT_COLLECT 20
//
//#define KEYINPUT_EVENT              0x1
//#define MOUSE_INPUT_EVENT           0x4
//#define MOUSE_MOTION_INPUT_EVENT    0x5
//#define MOUSE_BUTTON_INPUT_EVENT    0x6
//KEYDOWN = 1 
//KEYUP    = 0 
//
//+---------+-------------+---------+
//|8bits    |8bits state  |16bit key|
//+---------+-------------+---------+
//|1(always)|KEYDOWN/KEYUP|value    |
//+---------+-------------+---------+
//
#define MAKEEVENT(key, mod) ((((mod<<8) | 1)<<16)|key)
char CSDLCoreGraphics::translateKeymodifier(SDL_Event *event)  // translate the key events so the eyelink host understand
{
	char mod=0;

	if(event->key.keysym.mod &KMOD_LSHIFT) mod = mod |EL_MOD_LSHIFT;
	if(event->key.keysym.mod &KMOD_RSHIFT) mod = mod |EL_MOD_RSHIFT;
	if(event->key.keysym.mod &KMOD_LALT)   mod = mod |EL_MOD_LALT;
	if(event->key.keysym.mod &KMOD_RALT)   mod = mod |EL_MOD_RALT;
	if(event->key.keysym.mod &KMOD_LCTRL)  mod = mod |EL_MOD_LCTRL;
	if(event->key.keysym.mod &KMOD_RCTRL)  mod = mod |EL_MOD_RCTRL;


	return mod;
}


short CSDLCoreGraphics::translateKeyEvent(SDL_Event *event)  // translate the key events so the eyelink host understand
{
  short key;
  switch (event->type)
    {
      case SDL_KEYDOWN:       // message: key pressed 
        switch(event->key.keysym.sym)       // process keys we want only, xlat to EYELINK codes
          {
            case SDLK_F1:  key = EL_F1_KEY;  break;
            case SDLK_F2:  key = EL_F2_KEY;  break;
            case SDLK_F3:  key = EL_F3_KEY;  break;
            case SDLK_F4:  key = EL_F4_KEY;  break;
            case SDLK_F5:  key = EL_F5_KEY;  break;
            case SDLK_F6:  key = EL_F6_KEY;  break;
            case SDLK_F7:  key = EL_F7_KEY;  break;
            case SDLK_F8:  key = EL_F8_KEY;  break;
            case SDLK_F9:  key = EL_F9_KEY;  break;
            case SDLK_F10: key = EL_F10_KEY; break;
            case SDLK_PAGEUP: key = EL_PAGE_UP;    break;
            case SDLK_PAGEDOWN:  key = EL_PAGE_DOWN;  break;
            case SDLK_UP:    key = EL_CURS_UP;    break;
            case SDLK_DOWN:  key = EL_CURS_DOWN;  break;
            case SDLK_LEFT:  key = EL_CURS_LEFT;  break;
            case SDLK_RIGHT: key = EL_CURS_RIGHT; break;

            case SDLK_BACKSPACE:    key = '\b';      break;	// these keys may be wrongly translated!
            case SDLK_RETURN:  key = EL_ENTER_KEY; break;
            case SDLK_ESCAPE:  key = EL_ESC_KEY;   break;
            case SDLK_TAB:     key = '\t';      break;

            default:	     // not an emulation key!
              key = event->key.keysym.sym;
              break;
          }
        return (key==EL_JUNK_KEY) ? 0 : key;
    }
  return 0;
}


int CSDLCoreGraphics::getKeyEvents(int *dt)  // collect the input events and format it
{
	int ret = 0;
    INT16 mode = -1;
    SDL_Event event[MAX_EVENT_COLLECT];
    SDL_PumpEvents();
    ret=SDL_PeepEvents(event,MAX_EVENT_COLLECT,SDL_GETEVENT,SDL_KEYDOWNMASK); // check for key presses
	if(ret >0) // there are some events
	{
		for(int i =0; i < ret; i++)
		{			
			dt[i] = MAKEEVENT(translateKeyEvent(event),translateKeymodifier(event));//(((1<<8) | 1)<<16)|translateKeyEvent(event);
		}
		if(ret <MAX_EVENT_COLLECT) // we may have more events to collect so, dont clear the queue yet.
			while(SDL_PeepEvents(event,MAX_EVENT_COLLECT,SDL_GETEVENT,SDL_ALLEVENTS)> 0); // clear out all other events	
		return ret;
	}
	return 0;
}


//
//we are expected to return an array of integers that contains the event
//
//each entry on the array is a coded event.
//the format of the integer is:
//32 bits on an integer
//first 8 bits are event type. we only care about key events so it is always 1.(KEYINPUT_EVENT)
//The second 8 bits are the state. either the key is up or down. we only care about key down, 
//so this value is always 1.
//The rest of the 16 bits are the key value.
//
//
//+---------+-------------+---------+
//|8bits    |8bits state  |16bit key|
//+---------+-------------+---------+
//|1(always)|KEYDOWN/KEYUP|value    |
//+---------+-------------+---------+
//
//
HRESULT CSDLCoreGraphics::getInputKey(SAFEARRAY __RPC_FAR * __RPC_FAR *keyEvents)
{
   int dt[MAX_EVENT_COLLECT]; // temporary key queue
   int lend = getKeyEvents(dt); // get the key events


   if(!lend) return SDL_CORE_ERROR; // no key to collect


   SAFEARRAY * events;
   SAFEARRAYBOUND rgsabound[1];
   rgsabound[0].lLbound = 0;  
   rgsabound[0].cElements = lend; // length of the safe array
   
   events = SafeArrayCreate(VT_I4, 1, rgsabound); // create a safe array
   if(!events) return E_OUTOFMEMORY; // return error we failed to create an array
	


   int* intv = NULL;
   HRESULT hr = SafeArrayAccessData(events,(void HUGEP**)&intv); // update the safe array with values from temporary key queue value
   if(SUCCEEDED(hr))
   {
	for(int i=0; i <= lend; i++)
	{		
		intv[i] =dt[i];		
	}
	hr = SafeArrayUnaccessData(events);	
	if(FAILED(hr)) return SDL_CORE_ERROR;
	*keyEvents = events; // set the return value to our safe array
   }	
   return hr;

}


/*
we need to display the text to the user.  We simply print out to the console.
*/
HRESULT CSDLCoreGraphics::alert(BSTR text)
{
	USES_CONVERSION;
	printf("%s\n",W2A(text)); 
	return S_OK;
}

HRESULT CSDLCoreGraphics::setImageTitle(BSTR title)
{
	USES_CONVERSION;
	strcpy(this->title,W2A(title));
	return S_OK;
}


void CSDLCoreGraphics::drawImageTitle()
{
	SDL_Rect rect;
	if(image)
	{
		HFONT font = (HFONT)GetStockObject(SYSTEM_FONT); // get the system font. 
		SDL_Color color = {200,100,50,0}; 
		SDL_Surface *txt = RenderText_GDI(font,&color,title); // draw the text 
		rect.x = (screen->w-image->w)/2;
		rect.y = ((screen->h-image->h)/2)+image->h;
		SDL_BlitSurface(txt,NULL,screen,&rect); // blit the text to the back buffer
	}
	
}