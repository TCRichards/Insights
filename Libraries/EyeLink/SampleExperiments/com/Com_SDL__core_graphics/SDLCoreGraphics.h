// SDLCoreGraphics.h : Declaration of the CSDLCoreGraphics

#ifndef __SDLCOREGRAPHICS_H_
#define __SDLCOREGRAPHICS_H_

#include "resource.h"       // main symbols
#include <SDL/SDL.h>
/////////////////////////////////////////////////////////////////////////////
// CSDLCoreGraphics
class ATL_NO_VTABLE CSDLCoreGraphics : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CSDLCoreGraphics, &CLSID_SDLCoreGraphics>,
	public IDispatchImpl<ISDLCoreGraphics, &IID_ISDLCoreGraphics, &LIBID_COM_SDL__CORE_GRAPHICSLib>
{
	SDL_Surface * screen;
	SDL_Surface * image; 
	int background;
	int foreground;


	SDL_Rect lastTarget;
	SDL_Rect lastLastTarget;
	int sdlaudio;

	int width;
	int height;

	
	HDC dc;
	LPSTR bmpBits;
	void clearWindow();
	short translateKeyEvent(SDL_Event *event);
	char  translateKeymodifier(SDL_Event *event);
	int getKeyEvents(int *dt);
	void drawImageTitle();
	char title[150];
public:
	CSDLCoreGraphics();
	virtual ~CSDLCoreGraphics();

DECLARE_REGISTRY_RESOURCEID(IDR_SDLCOREGRAPHICS)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CSDLCoreGraphics)
	COM_INTERFACE_ENTRY(ISDLCoreGraphics)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()
		virtual HRESULT STDMETHODCALLTYPE playCalibrationBeep(CAL_BEEP_ID sound);
		virtual HRESULT STDMETHODCALLTYPE setupCalibrationDisplay( void);
        virtual HRESULT STDMETHODCALLTYPE exitCalibrationDisplay( void);
        virtual HRESULT STDMETHODCALLTYPE recordAbortHide( void);
        virtual HRESULT STDMETHODCALLTYPE exitImageDisplay( void);
        virtual HRESULT STDMETHODCALLTYPE clearCalibrationDisplay( void);     
        virtual HRESULT STDMETHODCALLTYPE eraseCalibrationTarget( void);
        virtual HRESULT STDMETHODCALLTYPE drawCalibrationTarget(short x,short y);
        virtual HRESULT STDMETHODCALLTYPE setupImageDisplay(short width,short height);
		virtual HRESULT STDMETHODCALLTYPE setVideoMode( 
            int width,
            int height,
            int bpp, 
			int refresh) ;

	    virtual HRESULT STDMETHODCALLTYPE drawCameraImage( 
            /* [in] */ IPicture __RPC_FAR *cameraImage);
		virtual HRESULT STDMETHODCALLTYPE setImageTitle( 
            /* [in] */ BSTR title);
		virtual HRESULT STDMETHODCALLTYPE getInputKey( 
            /* [retval][out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *keyEvents);

		virtual HRESULT STDMETHODCALLTYPE setForeground( 
            int r,
            int g,
            int b);
        
        virtual HRESULT STDMETHODCALLTYPE setBackground( 
            int r,
            int g,
            int b);
		virtual HRESULT STDMETHODCALLTYPE alert( 
            /* [in] */ BSTR text);
// ISDLCoreGraphics
public:
};

#endif //__SDLCOREGRAPHICS_H_
