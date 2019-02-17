/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Fri Jul 04 16:12:26 2014
 */
/* Compiler settings for .\Com_SDL__core_graphics.idl:
    Oicf (OptLev=i2), W1, Zp8, env=Win32, ms_ext, c_ext
    error checks: allocation ref bounds_check enum stub_data 
*/
//@@MIDL_FILE_HEADING(  )


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 440
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __Com_SDL__core_graphics_h__
#define __Com_SDL__core_graphics_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __ISDLCoreGraphics_FWD_DEFINED__
#define __ISDLCoreGraphics_FWD_DEFINED__
typedef interface ISDLCoreGraphics ISDLCoreGraphics;
#endif 	/* __ISDLCoreGraphics_FWD_DEFINED__ */


#ifndef __SDLCoreGraphics_FWD_DEFINED__
#define __SDLCoreGraphics_FWD_DEFINED__

#ifdef __cplusplus
typedef class SDLCoreGraphics SDLCoreGraphics;
#else
typedef struct SDLCoreGraphics SDLCoreGraphics;
#endif /* __cplusplus */

#endif 	/* __SDLCoreGraphics_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "calibration.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

#ifndef __ISDLCoreGraphics_INTERFACE_DEFINED__
#define __ISDLCoreGraphics_INTERFACE_DEFINED__

/* interface ISDLCoreGraphics */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ISDLCoreGraphics;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("3B2F0EB0-ADEF-40BA-B2A2-BD7E904AE722")
    ISDLCoreGraphics : public ICalibration
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE setVideoMode( 
            int width,
            int height,
            int bpp,
            int refresh) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE setForeground( 
            int r,
            int g,
            int b) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE setBackground( 
            int r,
            int g,
            int b) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ISDLCoreGraphicsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ISDLCoreGraphics __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ISDLCoreGraphics __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ISDLCoreGraphics __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            ISDLCoreGraphics __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            ISDLCoreGraphics __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            ISDLCoreGraphics __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            ISDLCoreGraphics __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *setupCalibrationDisplay )( 
            ISDLCoreGraphics __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *clearCalibrationDisplay )( 
            ISDLCoreGraphics __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *drawCalibrationTarget )( 
            ISDLCoreGraphics __RPC_FAR * This,
            /* [in] */ short x,
            /* [in] */ short y);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *eraseCalibrationTarget )( 
            ISDLCoreGraphics __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *exitCalibrationDisplay )( 
            ISDLCoreGraphics __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *setupImageDisplay )( 
            ISDLCoreGraphics __RPC_FAR * This,
            /* [in] */ short width,
            /* [in] */ short height);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *drawCameraImage )( 
            ISDLCoreGraphics __RPC_FAR * This,
            /* [in] */ IPicture __RPC_FAR *cameraImage);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *setImageTitle )( 
            ISDLCoreGraphics __RPC_FAR * This,
            /* [in] */ short threshold,
            /* [in] */ short crThreshold,
            /* [in] */ BSTR camera);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *exitImageDisplay )( 
            ISDLCoreGraphics __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *playCalibrationBeep )( 
            ISDLCoreGraphics __RPC_FAR * This,
            /* [in] */ CAL_BEEP_ID beepid);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *getInputKey )( 
            ISDLCoreGraphics __RPC_FAR * This,
            /* [retval][out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *keyEvents);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *recordAbortHide )( 
            ISDLCoreGraphics __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *setVideoMode )( 
            ISDLCoreGraphics __RPC_FAR * This,
            int width,
            int height,
            int bpp,
            int refresh);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *setForeground )( 
            ISDLCoreGraphics __RPC_FAR * This,
            int r,
            int g,
            int b);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *setBackground )( 
            ISDLCoreGraphics __RPC_FAR * This,
            int r,
            int g,
            int b);
        
        END_INTERFACE
    } ISDLCoreGraphicsVtbl;

    interface ISDLCoreGraphics
    {
        CONST_VTBL struct ISDLCoreGraphicsVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISDLCoreGraphics_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ISDLCoreGraphics_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ISDLCoreGraphics_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ISDLCoreGraphics_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define ISDLCoreGraphics_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define ISDLCoreGraphics_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define ISDLCoreGraphics_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define ISDLCoreGraphics_setupCalibrationDisplay(This)	\
    (This)->lpVtbl -> setupCalibrationDisplay(This)

#define ISDLCoreGraphics_clearCalibrationDisplay(This)	\
    (This)->lpVtbl -> clearCalibrationDisplay(This)

#define ISDLCoreGraphics_drawCalibrationTarget(This,x,y)	\
    (This)->lpVtbl -> drawCalibrationTarget(This,x,y)

#define ISDLCoreGraphics_eraseCalibrationTarget(This)	\
    (This)->lpVtbl -> eraseCalibrationTarget(This)

#define ISDLCoreGraphics_exitCalibrationDisplay(This)	\
    (This)->lpVtbl -> exitCalibrationDisplay(This)

#define ISDLCoreGraphics_setupImageDisplay(This,width,height)	\
    (This)->lpVtbl -> setupImageDisplay(This,width,height)

#define ISDLCoreGraphics_drawCameraImage(This,cameraImage)	\
    (This)->lpVtbl -> drawCameraImage(This,cameraImage)

#define ISDLCoreGraphics_setImageTitle(This,threshold,crThreshold,camera)	\
    (This)->lpVtbl -> setImageTitle(This,threshold,crThreshold,camera)

#define ISDLCoreGraphics_exitImageDisplay(This)	\
    (This)->lpVtbl -> exitImageDisplay(This)

#define ISDLCoreGraphics_playCalibrationBeep(This,beepid)	\
    (This)->lpVtbl -> playCalibrationBeep(This,beepid)

#define ISDLCoreGraphics_getInputKey(This,keyEvents)	\
    (This)->lpVtbl -> getInputKey(This,keyEvents)

#define ISDLCoreGraphics_recordAbortHide(This)	\
    (This)->lpVtbl -> recordAbortHide(This)


#define ISDLCoreGraphics_setVideoMode(This,width,height,bpp,refresh)	\
    (This)->lpVtbl -> setVideoMode(This,width,height,bpp,refresh)

#define ISDLCoreGraphics_setForeground(This,r,g,b)	\
    (This)->lpVtbl -> setForeground(This,r,g,b)

#define ISDLCoreGraphics_setBackground(This,r,g,b)	\
    (This)->lpVtbl -> setBackground(This,r,g,b)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE ISDLCoreGraphics_setVideoMode_Proxy( 
    ISDLCoreGraphics __RPC_FAR * This,
    int width,
    int height,
    int bpp,
    int refresh);


void __RPC_STUB ISDLCoreGraphics_setVideoMode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ISDLCoreGraphics_setForeground_Proxy( 
    ISDLCoreGraphics __RPC_FAR * This,
    int r,
    int g,
    int b);


void __RPC_STUB ISDLCoreGraphics_setForeground_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ISDLCoreGraphics_setBackground_Proxy( 
    ISDLCoreGraphics __RPC_FAR * This,
    int r,
    int g,
    int b);


void __RPC_STUB ISDLCoreGraphics_setBackground_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ISDLCoreGraphics_INTERFACE_DEFINED__ */



#ifndef __COM_SDL__CORE_GRAPHICSLib_LIBRARY_DEFINED__
#define __COM_SDL__CORE_GRAPHICSLib_LIBRARY_DEFINED__

/* library COM_SDL__CORE_GRAPHICSLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_COM_SDL__CORE_GRAPHICSLib;

EXTERN_C const CLSID CLSID_SDLCoreGraphics;

#ifdef __cplusplus

class DECLSPEC_UUID("5A01E0D6-A278-4C47-8218-D1CD246D28C0")
SDLCoreGraphics;
#endif
#endif /* __COM_SDL__CORE_GRAPHICSLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
