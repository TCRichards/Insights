/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Fri Jul 04 16:11:49 2014
 */
/* Compiler settings for .\SREyeLink.idl:
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

#ifndef __SREyeLink_h__
#define __SREyeLink_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __ICalibration_FWD_DEFINED__
#define __ICalibration_FWD_DEFINED__
typedef interface ICalibration ICalibration;
#endif 	/* __ICalibration_FWD_DEFINED__ */


#ifndef __IELData_FWD_DEFINED__
#define __IELData_FWD_DEFINED__
typedef interface IELData IELData;
#endif 	/* __IELData_FWD_DEFINED__ */


#ifndef __ISample_FWD_DEFINED__
#define __ISample_FWD_DEFINED__
typedef interface ISample ISample;
#endif 	/* __ISample_FWD_DEFINED__ */


#ifndef __IIOEvent_FWD_DEFINED__
#define __IIOEvent_FWD_DEFINED__
typedef interface IIOEvent IIOEvent;
#endif 	/* __IIOEvent_FWD_DEFINED__ */


#ifndef __IMessage_FWD_DEFINED__
#define __IMessage_FWD_DEFINED__
typedef interface IMessage IMessage;
#endif 	/* __IMessage_FWD_DEFINED__ */


#ifndef __IBusyCal_FWD_DEFINED__
#define __IBusyCal_FWD_DEFINED__
typedef interface IBusyCal IBusyCal;
#endif 	/* __IBusyCal_FWD_DEFINED__ */


#ifndef __IELGDICal_FWD_DEFINED__
#define __IELGDICal_FWD_DEFINED__
typedef interface IELGDICal IELGDICal;
#endif 	/* __IELGDICal_FWD_DEFINED__ */


#ifndef __IEyeLinkUtil_FWD_DEFINED__
#define __IEyeLinkUtil_FWD_DEFINED__
typedef interface IEyeLinkUtil IEyeLinkUtil;
#endif 	/* __IEyeLinkUtil_FWD_DEFINED__ */


#ifndef __IEyeEvent_FWD_DEFINED__
#define __IEyeEvent_FWD_DEFINED__
typedef interface IEyeEvent IEyeEvent;
#endif 	/* __IEyeEvent_FWD_DEFINED__ */


#ifndef __IStartBlinkEvent_FWD_DEFINED__
#define __IStartBlinkEvent_FWD_DEFINED__
typedef interface IStartBlinkEvent IStartBlinkEvent;
#endif 	/* __IStartBlinkEvent_FWD_DEFINED__ */


#ifndef __IEndBlinkEvent_FWD_DEFINED__
#define __IEndBlinkEvent_FWD_DEFINED__
typedef interface IEndBlinkEvent IEndBlinkEvent;
#endif 	/* __IEndBlinkEvent_FWD_DEFINED__ */


#ifndef __IStartSaccadeEvent_FWD_DEFINED__
#define __IStartSaccadeEvent_FWD_DEFINED__
typedef interface IStartSaccadeEvent IStartSaccadeEvent;
#endif 	/* __IStartSaccadeEvent_FWD_DEFINED__ */


#ifndef __IStartFixationEvent_FWD_DEFINED__
#define __IStartFixationEvent_FWD_DEFINED__
typedef interface IStartFixationEvent IStartFixationEvent;
#endif 	/* __IStartFixationEvent_FWD_DEFINED__ */


#ifndef __IEndSaccadeEvent_FWD_DEFINED__
#define __IEndSaccadeEvent_FWD_DEFINED__
typedef interface IEndSaccadeEvent IEndSaccadeEvent;
#endif 	/* __IEndSaccadeEvent_FWD_DEFINED__ */


#ifndef __IEndFixationEvent_FWD_DEFINED__
#define __IEndFixationEvent_FWD_DEFINED__
typedef interface IEndFixationEvent IEndFixationEvent;
#endif 	/* __IEndFixationEvent_FWD_DEFINED__ */


#ifndef __IFixUpdateEvent_FWD_DEFINED__
#define __IFixUpdateEvent_FWD_DEFINED__
typedef interface IFixUpdateEvent IFixUpdateEvent;
#endif 	/* __IFixUpdateEvent_FWD_DEFINED__ */


#ifndef __IEyeLink_FWD_DEFINED__
#define __IEyeLink_FWD_DEFINED__
typedef interface IEyeLink IEyeLink;
#endif 	/* __IEyeLink_FWD_DEFINED__ */


#ifndef __EyeLinkUtil_FWD_DEFINED__
#define __EyeLinkUtil_FWD_DEFINED__

#ifdef __cplusplus
typedef class EyeLinkUtil EyeLinkUtil;
#else
typedef struct EyeLinkUtil EyeLinkUtil;
#endif /* __cplusplus */

#endif 	/* __EyeLinkUtil_FWD_DEFINED__ */


#ifndef __Sample_FWD_DEFINED__
#define __Sample_FWD_DEFINED__

#ifdef __cplusplus
typedef class Sample Sample;
#else
typedef struct Sample Sample;
#endif /* __cplusplus */

#endif 	/* __Sample_FWD_DEFINED__ */


#ifndef __ELData_FWD_DEFINED__
#define __ELData_FWD_DEFINED__

#ifdef __cplusplus
typedef class ELData ELData;
#else
typedef struct ELData ELData;
#endif /* __cplusplus */

#endif 	/* __ELData_FWD_DEFINED__ */


#ifndef __IOEvent_FWD_DEFINED__
#define __IOEvent_FWD_DEFINED__

#ifdef __cplusplus
typedef class IOEvent IOEvent;
#else
typedef struct IOEvent IOEvent;
#endif /* __cplusplus */

#endif 	/* __IOEvent_FWD_DEFINED__ */


#ifndef __Message_FWD_DEFINED__
#define __Message_FWD_DEFINED__

#ifdef __cplusplus
typedef class Message Message;
#else
typedef struct Message Message;
#endif /* __cplusplus */

#endif 	/* __Message_FWD_DEFINED__ */


#ifndef __BusyCal_FWD_DEFINED__
#define __BusyCal_FWD_DEFINED__

#ifdef __cplusplus
typedef class BusyCal BusyCal;
#else
typedef struct BusyCal BusyCal;
#endif /* __cplusplus */

#endif 	/* __BusyCal_FWD_DEFINED__ */


#ifndef __Calibration_FWD_DEFINED__
#define __Calibration_FWD_DEFINED__

#ifdef __cplusplus
typedef class Calibration Calibration;
#else
typedef struct Calibration Calibration;
#endif /* __cplusplus */

#endif 	/* __Calibration_FWD_DEFINED__ */


#ifndef __EyeEvent_FWD_DEFINED__
#define __EyeEvent_FWD_DEFINED__

#ifdef __cplusplus
typedef class EyeEvent EyeEvent;
#else
typedef struct EyeEvent EyeEvent;
#endif /* __cplusplus */

#endif 	/* __EyeEvent_FWD_DEFINED__ */


#ifndef __StartBlinkEvent_FWD_DEFINED__
#define __StartBlinkEvent_FWD_DEFINED__

#ifdef __cplusplus
typedef class StartBlinkEvent StartBlinkEvent;
#else
typedef struct StartBlinkEvent StartBlinkEvent;
#endif /* __cplusplus */

#endif 	/* __StartBlinkEvent_FWD_DEFINED__ */


#ifndef __EndBlinkEvent_FWD_DEFINED__
#define __EndBlinkEvent_FWD_DEFINED__

#ifdef __cplusplus
typedef class EndBlinkEvent EndBlinkEvent;
#else
typedef struct EndBlinkEvent EndBlinkEvent;
#endif /* __cplusplus */

#endif 	/* __EndBlinkEvent_FWD_DEFINED__ */


#ifndef __StartSaccadeEvent_FWD_DEFINED__
#define __StartSaccadeEvent_FWD_DEFINED__

#ifdef __cplusplus
typedef class StartSaccadeEvent StartSaccadeEvent;
#else
typedef struct StartSaccadeEvent StartSaccadeEvent;
#endif /* __cplusplus */

#endif 	/* __StartSaccadeEvent_FWD_DEFINED__ */


#ifndef __StartFixationEvent_FWD_DEFINED__
#define __StartFixationEvent_FWD_DEFINED__

#ifdef __cplusplus
typedef class StartFixationEvent StartFixationEvent;
#else
typedef struct StartFixationEvent StartFixationEvent;
#endif /* __cplusplus */

#endif 	/* __StartFixationEvent_FWD_DEFINED__ */


#ifndef __EndSaccadeEvent_FWD_DEFINED__
#define __EndSaccadeEvent_FWD_DEFINED__

#ifdef __cplusplus
typedef class EndSaccadeEvent EndSaccadeEvent;
#else
typedef struct EndSaccadeEvent EndSaccadeEvent;
#endif /* __cplusplus */

#endif 	/* __EndSaccadeEvent_FWD_DEFINED__ */


#ifndef __EndFixationEvent_FWD_DEFINED__
#define __EndFixationEvent_FWD_DEFINED__

#ifdef __cplusplus
typedef class EndFixationEvent EndFixationEvent;
#else
typedef struct EndFixationEvent EndFixationEvent;
#endif /* __cplusplus */

#endif 	/* __EndFixationEvent_FWD_DEFINED__ */


#ifndef __FixUpdateEvent_FWD_DEFINED__
#define __FixUpdateEvent_FWD_DEFINED__

#ifdef __cplusplus
typedef class FixUpdateEvent FixUpdateEvent;
#else
typedef struct FixUpdateEvent FixUpdateEvent;
#endif /* __cplusplus */

#endif 	/* __FixUpdateEvent_FWD_DEFINED__ */


#ifndef __EyeLink_FWD_DEFINED__
#define __EyeLink_FWD_DEFINED__

#ifdef __cplusplus
typedef class EyeLink EyeLink;
#else
typedef struct EyeLink EyeLink;
#endif /* __cplusplus */

#endif 	/* __EyeLink_FWD_DEFINED__ */


#ifndef __ELGDICal_FWD_DEFINED__
#define __ELGDICal_FWD_DEFINED__

#ifdef __cplusplus
typedef class ELGDICal ELGDICal;
#else
typedef struct ELGDICal ELGDICal;
#endif /* __cplusplus */

#endif 	/* __ELGDICal_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

/* interface __MIDL_itf_SREyeLink_0000 */
/* [local] */ 

typedef /* [v1_enum] */ 
enum EL_CONSTANT
    {	EL_MISSING_DATA	= -32768,
	EL_IN_DISCONNECT_MODE	= 16384,
	EL_IN_UNKNOWN_MODE	= 0,
	EL_IN_IDLE_MODE	= 1,
	EL_IN_SETUP_MODE	= 2,
	EL_IN_RECORD_MODE	= 4,
	EL_IN_TARGET_MODE	= 8,
	EL_IN_DRIFTCORR_MODE	= 16,
	EL_IN_IMAGE_MODE	= 32,
	EL_IN_USER_MENU	= 64,
	EL_IN_PLAYBACK_MODE	= 256,
	EL_LEFTEYE_EVENTS	= 0x8000,
	EL_RIGHTEYE_EVENTS	= 0x4000,
	EL_BLINK_EVENTS	= 0x2000,
	EL_FIXATION_EVENTS	= 0x1000,
	EL_FIXUPDATE_EVENTS	= 0x800,
	EL_SACCADE_EVENTS	= 0x400,
	EL_MESSAGE_EVENTS	= 0x200,
	EL_BUTTON_EVENTS	= 0x40,
	EL_INPUT_EVENTS	= 0x20,
	EL_EVENT_VELOCITY	= 0x8000,
	EL_EVENT_PUPILSIZE	= 0x4000,
	EL_EVENT_GAZERES	= 0x2000,
	EL_EVENT_STATUS	= 0x1000,
	EL_EVENT_GAZEXY	= 0x400,
	EL_EVENT_HREFXY	= 0x200,
	EL_EVENT_PUPILXY	= 0x100,
	EL_FIX_AVG_ONLY	= 0x8,
	EL_START_TIME_ONLY	= 0x4,
	EL_PARSEDBY_GAZE	= 0xc0,
	EL_PARSEDBY_HREF	= 0x80,
	EL_PARSEDBY_PUPIL	= 0x40,
	EL_SAMPLE_LEFT	= 0x8000,
	EL_SAMPLE_RIGHT	= 0x4000,
	EL_SAMPLE_TIMESTAMP	= 0x2000,
	EL_SAMPLE_PUPILXY	= 0x1000,
	EL_SAMPLE_HREFXY	= 0x800,
	EL_SAMPLE_GAZEXY	= 0x400,
	EL_SAMPLE_GAZERES	= 0x200,
	EL_SAMPLE_PUPILSIZE	= 0x100,
	EL_SAMPLE_STATUS	= 0x80,
	EL_SAMPLE_INPUTS	= 0x40,
	EL_SAMPLE_BUTTONS	= 0x20,
	EL_SAMPLE_HEADPOS	= 0x10,
	EL_SAMPLE_TAGGED	= 0x8,
	EL_SAMPLE_UTAGGED	= 0x4
    }	EL_CONSTANT;

typedef /* [v1_enum] */ 
enum EL_SPECIAL_KEYS
    {	EL_JUNK_KEY	= 1,
	EL_F1_KEY	= 0x3b00,
	EL_F2_KEY	= 0x3c00,
	EL_F3_KEY	= 0x3d00,
	EL_F4_KEY	= 0x3e00,
	EL_F5_KEY	= 0x3f00,
	EL_F6_KEY	= 0x4000,
	EL_F7_KEY	= 0x4100,
	EL_F8_KEY	= 0x4200,
	EL_F9_KEY	= 0x4300,
	EL_F10_KEY	= 0x4400,
	EL_PAGE_UP	= 0x4900,
	EL_PAGE_DOWN	= 0x5100,
	EL_CURS_UP	= 0x4800,
	EL_CURS_DOWN	= 0x5000,
	EL_CURS_LEFT	= 0x4b00,
	EL_CURS_RIGHT	= 0x4d00,
	EL_ESC_KEY	= 0x1b,
	EL_ENTER_KEY	= 0xd
    }	EL_SPECIAL_KEYS;

typedef /* [v1_enum] */ 
enum EL_MODIFIER_KEYS
    {	EL_MOD_NONE	= 0,
	EL_MOD_LSHIFT	= 0x1,
	EL_MOD_RSHIFT	= 0x2,
	EL_MOD_LALT	= 0x4,
	EL_MOD_RALT	= 0x8,
	EL_MOD_LCTRL	= 0x10,
	EL_MOD_RCTRL	= 0x20
    }	EL_MODIFIER_KEYS;

typedef /* [v1_enum] */ 
enum EL_EYE
    {	EL_EYE_NONE	= -1,
	EL_LEFT	= 0,
	EL_RIGHT	= 1,
	EL_BINOCULAR	= 2
    }	EL_EYE;

typedef /* [v1_enum] */ 
enum FEROPTIONS
    {	AVERAGE	= 0,
	DARKEN	= 1,
	LIGHTEN	= 2,
	MAXCONTRAST	= 4,
	NODITHER	= 8,
	GRAYSCALE	= 16,
	DOTRANSFER	= 256
    }	FEROPTIONS;

typedef /* [v1_enum] */ 
enum EL_DATA_TYPE
    {	EL_SAMPLE_TYPE	= 200,
	EL_STARTBLINK	= 3,
	EL_ENDBLINK	= 4,
	EL_STARTSACC	= 5,
	EL_ENDSACC	= 6,
	EL_STARTFIX	= 7,
	EL_ENDFIX	= 8,
	EL_FIXUPDATE	= 9,
	EL_BUTTONEVENT	= 25,
	EL_INPUTEVENT	= 28,
	EL_MESSAGEEVENT	= 24
    }	EL_DATA_TYPE;



extern RPC_IF_HANDLE __MIDL_itf_SREyeLink_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_SREyeLink_0000_v0_0_s_ifspec;

#ifndef __ICalibration_INTERFACE_DEFINED__
#define __ICalibration_INTERFACE_DEFINED__

/* interface ICalibration */
/* [unique][helpstring][dual][uuid][object][oleautomation] */ 

typedef /* [v1_enum] */ 
enum CAL_BEEP_ID
    {	CAL_ERR_BEEP	= -1,
	DC_ERR_BEEP	= -2,
	CAL_GOOD_BEEP	= 0,
	CAL_TARG_BEEP	= 1,
	DC_GOOD_BEEP	= 2,
	DC_TARG_BEEP	= 3
    }	CAL_BEEP_ID;


EXTERN_C const IID IID_ICalibration;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("5A47633B-0108-4F75-835C-CEE026626184")
    ICalibration : public IDispatch
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE setupCalibrationDisplay( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE clearCalibrationDisplay( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE drawCalibrationTarget( 
            /* [in] */ short x,
            /* [in] */ short y) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE eraseCalibrationTarget( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE exitCalibrationDisplay( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE setupImageDisplay( 
            /* [in] */ short width,
            /* [in] */ short height) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE drawCameraImage( 
            /* [in] */ IPicture __RPC_FAR *cameraImage) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE setImageTitle( 
            /* [in] */ BSTR title) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE exitImageDisplay( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE playCalibrationBeep( 
            /* [in] */ CAL_BEEP_ID beepid) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE getInputKey( 
            /* [retval][out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *keyEvents) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE recordAbortHide( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE alert( 
            /* [in] */ BSTR text) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ICalibrationVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ICalibration __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ICalibration __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ICalibration __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            ICalibration __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            ICalibration __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            ICalibration __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            ICalibration __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *setupCalibrationDisplay )( 
            ICalibration __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *clearCalibrationDisplay )( 
            ICalibration __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *drawCalibrationTarget )( 
            ICalibration __RPC_FAR * This,
            /* [in] */ short x,
            /* [in] */ short y);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *eraseCalibrationTarget )( 
            ICalibration __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *exitCalibrationDisplay )( 
            ICalibration __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *setupImageDisplay )( 
            ICalibration __RPC_FAR * This,
            /* [in] */ short width,
            /* [in] */ short height);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *drawCameraImage )( 
            ICalibration __RPC_FAR * This,
            /* [in] */ IPicture __RPC_FAR *cameraImage);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *setImageTitle )( 
            ICalibration __RPC_FAR * This,
            /* [in] */ BSTR title);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *exitImageDisplay )( 
            ICalibration __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *playCalibrationBeep )( 
            ICalibration __RPC_FAR * This,
            /* [in] */ CAL_BEEP_ID beepid);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *getInputKey )( 
            ICalibration __RPC_FAR * This,
            /* [retval][out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *keyEvents);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *recordAbortHide )( 
            ICalibration __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *alert )( 
            ICalibration __RPC_FAR * This,
            /* [in] */ BSTR text);
        
        END_INTERFACE
    } ICalibrationVtbl;

    interface ICalibration
    {
        CONST_VTBL struct ICalibrationVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICalibration_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ICalibration_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ICalibration_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ICalibration_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define ICalibration_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define ICalibration_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define ICalibration_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define ICalibration_setupCalibrationDisplay(This)	\
    (This)->lpVtbl -> setupCalibrationDisplay(This)

#define ICalibration_clearCalibrationDisplay(This)	\
    (This)->lpVtbl -> clearCalibrationDisplay(This)

#define ICalibration_drawCalibrationTarget(This,x,y)	\
    (This)->lpVtbl -> drawCalibrationTarget(This,x,y)

#define ICalibration_eraseCalibrationTarget(This)	\
    (This)->lpVtbl -> eraseCalibrationTarget(This)

#define ICalibration_exitCalibrationDisplay(This)	\
    (This)->lpVtbl -> exitCalibrationDisplay(This)

#define ICalibration_setupImageDisplay(This,width,height)	\
    (This)->lpVtbl -> setupImageDisplay(This,width,height)

#define ICalibration_drawCameraImage(This,cameraImage)	\
    (This)->lpVtbl -> drawCameraImage(This,cameraImage)

#define ICalibration_setImageTitle(This,title)	\
    (This)->lpVtbl -> setImageTitle(This,title)

#define ICalibration_exitImageDisplay(This)	\
    (This)->lpVtbl -> exitImageDisplay(This)

#define ICalibration_playCalibrationBeep(This,beepid)	\
    (This)->lpVtbl -> playCalibrationBeep(This,beepid)

#define ICalibration_getInputKey(This,keyEvents)	\
    (This)->lpVtbl -> getInputKey(This,keyEvents)

#define ICalibration_recordAbortHide(This)	\
    (This)->lpVtbl -> recordAbortHide(This)

#define ICalibration_alert(This,text)	\
    (This)->lpVtbl -> alert(This,text)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE ICalibration_setupCalibrationDisplay_Proxy( 
    ICalibration __RPC_FAR * This);


void __RPC_STUB ICalibration_setupCalibrationDisplay_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ICalibration_clearCalibrationDisplay_Proxy( 
    ICalibration __RPC_FAR * This);


void __RPC_STUB ICalibration_clearCalibrationDisplay_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ICalibration_drawCalibrationTarget_Proxy( 
    ICalibration __RPC_FAR * This,
    /* [in] */ short x,
    /* [in] */ short y);


void __RPC_STUB ICalibration_drawCalibrationTarget_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ICalibration_eraseCalibrationTarget_Proxy( 
    ICalibration __RPC_FAR * This);


void __RPC_STUB ICalibration_eraseCalibrationTarget_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ICalibration_exitCalibrationDisplay_Proxy( 
    ICalibration __RPC_FAR * This);


void __RPC_STUB ICalibration_exitCalibrationDisplay_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ICalibration_setupImageDisplay_Proxy( 
    ICalibration __RPC_FAR * This,
    /* [in] */ short width,
    /* [in] */ short height);


void __RPC_STUB ICalibration_setupImageDisplay_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ICalibration_drawCameraImage_Proxy( 
    ICalibration __RPC_FAR * This,
    /* [in] */ IPicture __RPC_FAR *cameraImage);


void __RPC_STUB ICalibration_drawCameraImage_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ICalibration_setImageTitle_Proxy( 
    ICalibration __RPC_FAR * This,
    /* [in] */ BSTR title);


void __RPC_STUB ICalibration_setImageTitle_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ICalibration_exitImageDisplay_Proxy( 
    ICalibration __RPC_FAR * This);


void __RPC_STUB ICalibration_exitImageDisplay_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ICalibration_playCalibrationBeep_Proxy( 
    ICalibration __RPC_FAR * This,
    /* [in] */ CAL_BEEP_ID beepid);


void __RPC_STUB ICalibration_playCalibrationBeep_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ICalibration_getInputKey_Proxy( 
    ICalibration __RPC_FAR * This,
    /* [retval][out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *keyEvents);


void __RPC_STUB ICalibration_getInputKey_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ICalibration_recordAbortHide_Proxy( 
    ICalibration __RPC_FAR * This);


void __RPC_STUB ICalibration_recordAbortHide_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ICalibration_alert_Proxy( 
    ICalibration __RPC_FAR * This,
    /* [in] */ BSTR text);


void __RPC_STUB ICalibration_alert_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ICalibration_INTERFACE_DEFINED__ */


#ifndef __IELData_INTERFACE_DEFINED__
#define __IELData_INTERFACE_DEFINED__

/* interface IELData */
/* [unique][helpstring][dual][uuid][object][oleautomation] */ 


EXTERN_C const IID IID_IELData;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("280E4754-46DE-4592-8A69-04A5034C0B7C")
    IELData : public IDispatch
    {
    public:
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_time( 
            /* [retval][out] */ double __RPC_FAR *result) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_eltype( 
            /* [retval][out] */ EL_DATA_TYPE __RPC_FAR *result) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IELDataVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IELData __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IELData __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IELData __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IELData __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IELData __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IELData __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IELData __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_time )( 
            IELData __RPC_FAR * This,
            /* [retval][out] */ double __RPC_FAR *result);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_eltype )( 
            IELData __RPC_FAR * This,
            /* [retval][out] */ EL_DATA_TYPE __RPC_FAR *result);
        
        END_INTERFACE
    } IELDataVtbl;

    interface IELData
    {
        CONST_VTBL struct IELDataVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IELData_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IELData_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IELData_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IELData_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IELData_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IELData_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IELData_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IELData_get_time(This,result)	\
    (This)->lpVtbl -> get_time(This,result)

#define IELData_get_eltype(This,result)	\
    (This)->lpVtbl -> get_eltype(This,result)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IELData_get_time_Proxy( 
    IELData __RPC_FAR * This,
    /* [retval][out] */ double __RPC_FAR *result);


void __RPC_STUB IELData_get_time_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IELData_get_eltype_Proxy( 
    IELData __RPC_FAR * This,
    /* [retval][out] */ EL_DATA_TYPE __RPC_FAR *result);


void __RPC_STUB IELData_get_eltype_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IELData_INTERFACE_DEFINED__ */


#ifndef __ISample_INTERFACE_DEFINED__
#define __ISample_INTERFACE_DEFINED__

/* interface ISample */
/* [unique][helpstring][dual][uuid][object][oleautomation] */ 


EXTERN_C const IID IID_ISample;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("DB4DB2DA-2B04-4F5C-A24C-95ABC3EC5002")
    ISample : public IELData
    {
    public:
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_flags( 
            /* [retval][out] */ short __RPC_FAR *flags) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_px( 
            /* [in] */ EL_EYE indx,
            /* [retval][out] */ float __RPC_FAR *px) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_py( 
            /* [in] */ EL_EYE indx,
            /* [retval][out] */ float __RPC_FAR *py) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_hx( 
            /* [in] */ EL_EYE indx,
            /* [retval][out] */ float __RPC_FAR *hx) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_hy( 
            /* [in] */ EL_EYE indx,
            /* [retval][out] */ float __RPC_FAR *hy) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_pa( 
            /* [in] */ EL_EYE indx,
            /* [retval][out] */ float __RPC_FAR *pa) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_gx( 
            /* [in] */ EL_EYE indx,
            /* [retval][out] */ float __RPC_FAR *gx) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_gy( 
            /* [in] */ EL_EYE indx,
            /* [retval][out] */ float __RPC_FAR *gy) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_rx( 
            /* [retval][out] */ float __RPC_FAR *rx) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_ry( 
            /* [retval][out] */ float __RPC_FAR *ry) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_status( 
            /* [retval][out] */ short __RPC_FAR *status) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_input( 
            /* [retval][out] */ short __RPC_FAR *input) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_buttons( 
            /* [retval][out] */ short __RPC_FAR *buttons) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_htype( 
            /* [retval][out] */ short __RPC_FAR *htype) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_hdata( 
            /* [in] */ int indx,
            /* [retval][out] */ short __RPC_FAR *hdata) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_targetDistance( 
            /* [retval][out] */ short __RPC_FAR *distance) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_targetX( 
            /* [retval][out] */ short __RPC_FAR *x) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_targetY( 
            /* [retval][out] */ short __RPC_FAR *y) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_targetFlags( 
            /* [retval][out] */ short __RPC_FAR *flags) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ISampleVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ISample __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ISample __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ISample __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            ISample __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            ISample __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            ISample __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            ISample __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_time )( 
            ISample __RPC_FAR * This,
            /* [retval][out] */ double __RPC_FAR *result);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_eltype )( 
            ISample __RPC_FAR * This,
            /* [retval][out] */ EL_DATA_TYPE __RPC_FAR *result);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_flags )( 
            ISample __RPC_FAR * This,
            /* [retval][out] */ short __RPC_FAR *flags);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_px )( 
            ISample __RPC_FAR * This,
            /* [in] */ EL_EYE indx,
            /* [retval][out] */ float __RPC_FAR *px);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_py )( 
            ISample __RPC_FAR * This,
            /* [in] */ EL_EYE indx,
            /* [retval][out] */ float __RPC_FAR *py);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_hx )( 
            ISample __RPC_FAR * This,
            /* [in] */ EL_EYE indx,
            /* [retval][out] */ float __RPC_FAR *hx);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_hy )( 
            ISample __RPC_FAR * This,
            /* [in] */ EL_EYE indx,
            /* [retval][out] */ float __RPC_FAR *hy);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_pa )( 
            ISample __RPC_FAR * This,
            /* [in] */ EL_EYE indx,
            /* [retval][out] */ float __RPC_FAR *pa);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_gx )( 
            ISample __RPC_FAR * This,
            /* [in] */ EL_EYE indx,
            /* [retval][out] */ float __RPC_FAR *gx);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_gy )( 
            ISample __RPC_FAR * This,
            /* [in] */ EL_EYE indx,
            /* [retval][out] */ float __RPC_FAR *gy);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_rx )( 
            ISample __RPC_FAR * This,
            /* [retval][out] */ float __RPC_FAR *rx);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ry )( 
            ISample __RPC_FAR * This,
            /* [retval][out] */ float __RPC_FAR *ry);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_status )( 
            ISample __RPC_FAR * This,
            /* [retval][out] */ short __RPC_FAR *status);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_input )( 
            ISample __RPC_FAR * This,
            /* [retval][out] */ short __RPC_FAR *input);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_buttons )( 
            ISample __RPC_FAR * This,
            /* [retval][out] */ short __RPC_FAR *buttons);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_htype )( 
            ISample __RPC_FAR * This,
            /* [retval][out] */ short __RPC_FAR *htype);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_hdata )( 
            ISample __RPC_FAR * This,
            /* [in] */ int indx,
            /* [retval][out] */ short __RPC_FAR *hdata);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_targetDistance )( 
            ISample __RPC_FAR * This,
            /* [retval][out] */ short __RPC_FAR *distance);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_targetX )( 
            ISample __RPC_FAR * This,
            /* [retval][out] */ short __RPC_FAR *x);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_targetY )( 
            ISample __RPC_FAR * This,
            /* [retval][out] */ short __RPC_FAR *y);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_targetFlags )( 
            ISample __RPC_FAR * This,
            /* [retval][out] */ short __RPC_FAR *flags);
        
        END_INTERFACE
    } ISampleVtbl;

    interface ISample
    {
        CONST_VTBL struct ISampleVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISample_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ISample_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ISample_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ISample_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define ISample_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define ISample_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define ISample_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define ISample_get_time(This,result)	\
    (This)->lpVtbl -> get_time(This,result)

#define ISample_get_eltype(This,result)	\
    (This)->lpVtbl -> get_eltype(This,result)


#define ISample_get_flags(This,flags)	\
    (This)->lpVtbl -> get_flags(This,flags)

#define ISample_get_px(This,indx,px)	\
    (This)->lpVtbl -> get_px(This,indx,px)

#define ISample_get_py(This,indx,py)	\
    (This)->lpVtbl -> get_py(This,indx,py)

#define ISample_get_hx(This,indx,hx)	\
    (This)->lpVtbl -> get_hx(This,indx,hx)

#define ISample_get_hy(This,indx,hy)	\
    (This)->lpVtbl -> get_hy(This,indx,hy)

#define ISample_get_pa(This,indx,pa)	\
    (This)->lpVtbl -> get_pa(This,indx,pa)

#define ISample_get_gx(This,indx,gx)	\
    (This)->lpVtbl -> get_gx(This,indx,gx)

#define ISample_get_gy(This,indx,gy)	\
    (This)->lpVtbl -> get_gy(This,indx,gy)

#define ISample_get_rx(This,rx)	\
    (This)->lpVtbl -> get_rx(This,rx)

#define ISample_get_ry(This,ry)	\
    (This)->lpVtbl -> get_ry(This,ry)

#define ISample_get_status(This,status)	\
    (This)->lpVtbl -> get_status(This,status)

#define ISample_get_input(This,input)	\
    (This)->lpVtbl -> get_input(This,input)

#define ISample_get_buttons(This,buttons)	\
    (This)->lpVtbl -> get_buttons(This,buttons)

#define ISample_get_htype(This,htype)	\
    (This)->lpVtbl -> get_htype(This,htype)

#define ISample_get_hdata(This,indx,hdata)	\
    (This)->lpVtbl -> get_hdata(This,indx,hdata)

#define ISample_get_targetDistance(This,distance)	\
    (This)->lpVtbl -> get_targetDistance(This,distance)

#define ISample_get_targetX(This,x)	\
    (This)->lpVtbl -> get_targetX(This,x)

#define ISample_get_targetY(This,y)	\
    (This)->lpVtbl -> get_targetY(This,y)

#define ISample_get_targetFlags(This,flags)	\
    (This)->lpVtbl -> get_targetFlags(This,flags)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE ISample_get_flags_Proxy( 
    ISample __RPC_FAR * This,
    /* [retval][out] */ short __RPC_FAR *flags);


void __RPC_STUB ISample_get_flags_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE ISample_get_px_Proxy( 
    ISample __RPC_FAR * This,
    /* [in] */ EL_EYE indx,
    /* [retval][out] */ float __RPC_FAR *px);


void __RPC_STUB ISample_get_px_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE ISample_get_py_Proxy( 
    ISample __RPC_FAR * This,
    /* [in] */ EL_EYE indx,
    /* [retval][out] */ float __RPC_FAR *py);


void __RPC_STUB ISample_get_py_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE ISample_get_hx_Proxy( 
    ISample __RPC_FAR * This,
    /* [in] */ EL_EYE indx,
    /* [retval][out] */ float __RPC_FAR *hx);


void __RPC_STUB ISample_get_hx_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE ISample_get_hy_Proxy( 
    ISample __RPC_FAR * This,
    /* [in] */ EL_EYE indx,
    /* [retval][out] */ float __RPC_FAR *hy);


void __RPC_STUB ISample_get_hy_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE ISample_get_pa_Proxy( 
    ISample __RPC_FAR * This,
    /* [in] */ EL_EYE indx,
    /* [retval][out] */ float __RPC_FAR *pa);


void __RPC_STUB ISample_get_pa_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE ISample_get_gx_Proxy( 
    ISample __RPC_FAR * This,
    /* [in] */ EL_EYE indx,
    /* [retval][out] */ float __RPC_FAR *gx);


void __RPC_STUB ISample_get_gx_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE ISample_get_gy_Proxy( 
    ISample __RPC_FAR * This,
    /* [in] */ EL_EYE indx,
    /* [retval][out] */ float __RPC_FAR *gy);


void __RPC_STUB ISample_get_gy_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE ISample_get_rx_Proxy( 
    ISample __RPC_FAR * This,
    /* [retval][out] */ float __RPC_FAR *rx);


void __RPC_STUB ISample_get_rx_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE ISample_get_ry_Proxy( 
    ISample __RPC_FAR * This,
    /* [retval][out] */ float __RPC_FAR *ry);


void __RPC_STUB ISample_get_ry_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE ISample_get_status_Proxy( 
    ISample __RPC_FAR * This,
    /* [retval][out] */ short __RPC_FAR *status);


void __RPC_STUB ISample_get_status_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE ISample_get_input_Proxy( 
    ISample __RPC_FAR * This,
    /* [retval][out] */ short __RPC_FAR *input);


void __RPC_STUB ISample_get_input_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE ISample_get_buttons_Proxy( 
    ISample __RPC_FAR * This,
    /* [retval][out] */ short __RPC_FAR *buttons);


void __RPC_STUB ISample_get_buttons_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE ISample_get_htype_Proxy( 
    ISample __RPC_FAR * This,
    /* [retval][out] */ short __RPC_FAR *htype);


void __RPC_STUB ISample_get_htype_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE ISample_get_hdata_Proxy( 
    ISample __RPC_FAR * This,
    /* [in] */ int indx,
    /* [retval][out] */ short __RPC_FAR *hdata);


void __RPC_STUB ISample_get_hdata_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE ISample_get_targetDistance_Proxy( 
    ISample __RPC_FAR * This,
    /* [retval][out] */ short __RPC_FAR *distance);


void __RPC_STUB ISample_get_targetDistance_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE ISample_get_targetX_Proxy( 
    ISample __RPC_FAR * This,
    /* [retval][out] */ short __RPC_FAR *x);


void __RPC_STUB ISample_get_targetX_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE ISample_get_targetY_Proxy( 
    ISample __RPC_FAR * This,
    /* [retval][out] */ short __RPC_FAR *y);


void __RPC_STUB ISample_get_targetY_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE ISample_get_targetFlags_Proxy( 
    ISample __RPC_FAR * This,
    /* [retval][out] */ short __RPC_FAR *flags);


void __RPC_STUB ISample_get_targetFlags_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ISample_INTERFACE_DEFINED__ */


#ifndef __IIOEvent_INTERFACE_DEFINED__
#define __IIOEvent_INTERFACE_DEFINED__

/* interface IIOEvent */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IIOEvent;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("D21E803C-1F82-43DA-B34B-736D871045AC")
    IIOEvent : public IELData
    {
    public:
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_data( 
            /* [retval][out] */ short __RPC_FAR *data) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IIOEventVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IIOEvent __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IIOEvent __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IIOEvent __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IIOEvent __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IIOEvent __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IIOEvent __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IIOEvent __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_time )( 
            IIOEvent __RPC_FAR * This,
            /* [retval][out] */ double __RPC_FAR *result);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_eltype )( 
            IIOEvent __RPC_FAR * This,
            /* [retval][out] */ EL_DATA_TYPE __RPC_FAR *result);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_data )( 
            IIOEvent __RPC_FAR * This,
            /* [retval][out] */ short __RPC_FAR *data);
        
        END_INTERFACE
    } IIOEventVtbl;

    interface IIOEvent
    {
        CONST_VTBL struct IIOEventVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IIOEvent_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IIOEvent_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IIOEvent_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IIOEvent_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IIOEvent_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IIOEvent_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IIOEvent_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IIOEvent_get_time(This,result)	\
    (This)->lpVtbl -> get_time(This,result)

#define IIOEvent_get_eltype(This,result)	\
    (This)->lpVtbl -> get_eltype(This,result)


#define IIOEvent_get_data(This,data)	\
    (This)->lpVtbl -> get_data(This,data)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IIOEvent_get_data_Proxy( 
    IIOEvent __RPC_FAR * This,
    /* [retval][out] */ short __RPC_FAR *data);


void __RPC_STUB IIOEvent_get_data_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IIOEvent_INTERFACE_DEFINED__ */


#ifndef __IMessage_INTERFACE_DEFINED__
#define __IMessage_INTERFACE_DEFINED__

/* interface IMessage */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IMessage;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("D8B2919D-D78C-46E9-B1AC-26216D288C3F")
    IMessage : public IELData
    {
    public:
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_text( 
            /* [retval][out] */ BSTR __RPC_FAR *text) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IMessageVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IMessage __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IMessage __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IMessage __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IMessage __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IMessage __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IMessage __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IMessage __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_time )( 
            IMessage __RPC_FAR * This,
            /* [retval][out] */ double __RPC_FAR *result);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_eltype )( 
            IMessage __RPC_FAR * This,
            /* [retval][out] */ EL_DATA_TYPE __RPC_FAR *result);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_text )( 
            IMessage __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *text);
        
        END_INTERFACE
    } IMessageVtbl;

    interface IMessage
    {
        CONST_VTBL struct IMessageVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMessage_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IMessage_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IMessage_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IMessage_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IMessage_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IMessage_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IMessage_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IMessage_get_time(This,result)	\
    (This)->lpVtbl -> get_time(This,result)

#define IMessage_get_eltype(This,result)	\
    (This)->lpVtbl -> get_eltype(This,result)


#define IMessage_get_text(This,text)	\
    (This)->lpVtbl -> get_text(This,text)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IMessage_get_text_Proxy( 
    IMessage __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *text);


void __RPC_STUB IMessage_get_text_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IMessage_INTERFACE_DEFINED__ */


#ifndef __IBusyCal_INTERFACE_DEFINED__
#define __IBusyCal_INTERFACE_DEFINED__

/* interface IBusyCal */
/* [unique][helpstring][dual][uuid][object] */ 

typedef /* [v1_enum] */ 
enum EL_BUSYCAL_JOB
    {	EL_NONE	= 0,
	SETUP_CAL_DISPLAY	= 1,
	EXIT_CAL_DISPLAY	= 2,
	RECORD_ABORT_HIDE	= 3,
	EXIT_IMAGE_DISPLAY	= 4,
	CLEAR_CAL_DISPLAY	= 5,
	ERASE_CAL_TARGET	= 6,
	CAL_TARGET_BEEP	= 7,
	DC_TARGET_BEEP	= 8,
	DRAW_CAL_TARGET	= 9,
	SETUP_IMAGE_DISPLAY	= 10,
	IMAGE_TITLE	= 11,
	DRAW_IMAGE_LINE	= 12,
	SET_IMAGE_PALETTE	= 13,
	CAL_DONE_BEEP	= 14,
	DC_DONE_BEEP	= 15,
	GET_INPUT_KEY	= 16,
	ALERT_PRINT	= 17,
	CAL_ERROR_BEEP	= 18,
	DC_ERROR_BEEP	= 19,
	JOB_EXIT	= -1
    }	EL_BUSYCAL_JOB;


EXTERN_C const IID IID_IBusyCal;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("3F8A8D25-992D-4BA0-8707-A112DC7542C9")
    IBusyCal : public ICalibration
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_job( 
            /* [retval][out] */ short __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE startCameraSetup( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE getCalLocation( 
            /* [out] */ short __RPC_FAR *x,
            /* [out] */ short __RPC_FAR *y) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE startDriftCorrect( 
            /* [in] */ short x,
            /* [in] */ short y,
            /* [in] */ VARIANT_BOOL draw,
            /* [in] */ VARIANT_BOOL allow_setup) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE getDriftCorrectResult( 
            /* [retval][out] */ short __RPC_FAR *result) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IBusyCalVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IBusyCal __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IBusyCal __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IBusyCal __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IBusyCal __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IBusyCal __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IBusyCal __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IBusyCal __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *setupCalibrationDisplay )( 
            IBusyCal __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *clearCalibrationDisplay )( 
            IBusyCal __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *drawCalibrationTarget )( 
            IBusyCal __RPC_FAR * This,
            /* [in] */ short x,
            /* [in] */ short y);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *eraseCalibrationTarget )( 
            IBusyCal __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *exitCalibrationDisplay )( 
            IBusyCal __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *setupImageDisplay )( 
            IBusyCal __RPC_FAR * This,
            /* [in] */ short width,
            /* [in] */ short height);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *drawCameraImage )( 
            IBusyCal __RPC_FAR * This,
            /* [in] */ IPicture __RPC_FAR *cameraImage);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *setImageTitle )( 
            IBusyCal __RPC_FAR * This,
            /* [in] */ BSTR title);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *exitImageDisplay )( 
            IBusyCal __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *playCalibrationBeep )( 
            IBusyCal __RPC_FAR * This,
            /* [in] */ CAL_BEEP_ID beepid);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *getInputKey )( 
            IBusyCal __RPC_FAR * This,
            /* [retval][out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *keyEvents);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *recordAbortHide )( 
            IBusyCal __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *alert )( 
            IBusyCal __RPC_FAR * This,
            /* [in] */ BSTR text);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_job )( 
            IBusyCal __RPC_FAR * This,
            /* [retval][out] */ short __RPC_FAR *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *startCameraSetup )( 
            IBusyCal __RPC_FAR * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *getCalLocation )( 
            IBusyCal __RPC_FAR * This,
            /* [out] */ short __RPC_FAR *x,
            /* [out] */ short __RPC_FAR *y);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *startDriftCorrect )( 
            IBusyCal __RPC_FAR * This,
            /* [in] */ short x,
            /* [in] */ short y,
            /* [in] */ VARIANT_BOOL draw,
            /* [in] */ VARIANT_BOOL allow_setup);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *getDriftCorrectResult )( 
            IBusyCal __RPC_FAR * This,
            /* [retval][out] */ short __RPC_FAR *result);
        
        END_INTERFACE
    } IBusyCalVtbl;

    interface IBusyCal
    {
        CONST_VTBL struct IBusyCalVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IBusyCal_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IBusyCal_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IBusyCal_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IBusyCal_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IBusyCal_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IBusyCal_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IBusyCal_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IBusyCal_setupCalibrationDisplay(This)	\
    (This)->lpVtbl -> setupCalibrationDisplay(This)

#define IBusyCal_clearCalibrationDisplay(This)	\
    (This)->lpVtbl -> clearCalibrationDisplay(This)

#define IBusyCal_drawCalibrationTarget(This,x,y)	\
    (This)->lpVtbl -> drawCalibrationTarget(This,x,y)

#define IBusyCal_eraseCalibrationTarget(This)	\
    (This)->lpVtbl -> eraseCalibrationTarget(This)

#define IBusyCal_exitCalibrationDisplay(This)	\
    (This)->lpVtbl -> exitCalibrationDisplay(This)

#define IBusyCal_setupImageDisplay(This,width,height)	\
    (This)->lpVtbl -> setupImageDisplay(This,width,height)

#define IBusyCal_drawCameraImage(This,cameraImage)	\
    (This)->lpVtbl -> drawCameraImage(This,cameraImage)

#define IBusyCal_setImageTitle(This,title)	\
    (This)->lpVtbl -> setImageTitle(This,title)

#define IBusyCal_exitImageDisplay(This)	\
    (This)->lpVtbl -> exitImageDisplay(This)

#define IBusyCal_playCalibrationBeep(This,beepid)	\
    (This)->lpVtbl -> playCalibrationBeep(This,beepid)

#define IBusyCal_getInputKey(This,keyEvents)	\
    (This)->lpVtbl -> getInputKey(This,keyEvents)

#define IBusyCal_recordAbortHide(This)	\
    (This)->lpVtbl -> recordAbortHide(This)

#define IBusyCal_alert(This,text)	\
    (This)->lpVtbl -> alert(This,text)


#define IBusyCal_get_job(This,pVal)	\
    (This)->lpVtbl -> get_job(This,pVal)

#define IBusyCal_startCameraSetup(This)	\
    (This)->lpVtbl -> startCameraSetup(This)

#define IBusyCal_getCalLocation(This,x,y)	\
    (This)->lpVtbl -> getCalLocation(This,x,y)

#define IBusyCal_startDriftCorrect(This,x,y,draw,allow_setup)	\
    (This)->lpVtbl -> startDriftCorrect(This,x,y,draw,allow_setup)

#define IBusyCal_getDriftCorrectResult(This,result)	\
    (This)->lpVtbl -> getDriftCorrectResult(This,result)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IBusyCal_get_job_Proxy( 
    IBusyCal __RPC_FAR * This,
    /* [retval][out] */ short __RPC_FAR *pVal);


void __RPC_STUB IBusyCal_get_job_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IBusyCal_startCameraSetup_Proxy( 
    IBusyCal __RPC_FAR * This);


void __RPC_STUB IBusyCal_startCameraSetup_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IBusyCal_getCalLocation_Proxy( 
    IBusyCal __RPC_FAR * This,
    /* [out] */ short __RPC_FAR *x,
    /* [out] */ short __RPC_FAR *y);


void __RPC_STUB IBusyCal_getCalLocation_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IBusyCal_startDriftCorrect_Proxy( 
    IBusyCal __RPC_FAR * This,
    /* [in] */ short x,
    /* [in] */ short y,
    /* [in] */ VARIANT_BOOL draw,
    /* [in] */ VARIANT_BOOL allow_setup);


void __RPC_STUB IBusyCal_startDriftCorrect_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IBusyCal_getDriftCorrectResult_Proxy( 
    IBusyCal __RPC_FAR * This,
    /* [retval][out] */ short __RPC_FAR *result);


void __RPC_STUB IBusyCal_getDriftCorrectResult_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IBusyCal_INTERFACE_DEFINED__ */


#ifndef __IELGDICal_INTERFACE_DEFINED__
#define __IELGDICal_INTERFACE_DEFINED__

/* interface IELGDICal */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IELGDICal;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("5A048516-843E-4A26-9B4C-B86D4F221A26")
    IELGDICal : public ICalibration
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE setCalibrationWindow( 
            /* [in] */ int hWnd) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE getTargetLocationX( 
            /* [retval][out] */ short __RPC_FAR *x) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE getTargetLocationY( 
            /* [retval][out] */ short __RPC_FAR *y) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE enableKeyCollection( 
            /* [in] */ VARIANT_BOOL en) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE setCalibrationColors( 
            /* [in] */ OLE_COLOR fg,
            /* [in] */ OLE_COLOR bg) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE setCalibrationTargetSize( 
            /* [in] */ short inner,
            /* [in] */ short outer) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE setZoomDenominator( 
            /* [in] */ short denominator) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IELGDICalVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IELGDICal __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IELGDICal __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IELGDICal __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IELGDICal __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IELGDICal __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IELGDICal __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IELGDICal __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *setupCalibrationDisplay )( 
            IELGDICal __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *clearCalibrationDisplay )( 
            IELGDICal __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *drawCalibrationTarget )( 
            IELGDICal __RPC_FAR * This,
            /* [in] */ short x,
            /* [in] */ short y);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *eraseCalibrationTarget )( 
            IELGDICal __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *exitCalibrationDisplay )( 
            IELGDICal __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *setupImageDisplay )( 
            IELGDICal __RPC_FAR * This,
            /* [in] */ short width,
            /* [in] */ short height);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *drawCameraImage )( 
            IELGDICal __RPC_FAR * This,
            /* [in] */ IPicture __RPC_FAR *cameraImage);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *setImageTitle )( 
            IELGDICal __RPC_FAR * This,
            /* [in] */ BSTR title);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *exitImageDisplay )( 
            IELGDICal __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *playCalibrationBeep )( 
            IELGDICal __RPC_FAR * This,
            /* [in] */ CAL_BEEP_ID beepid);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *getInputKey )( 
            IELGDICal __RPC_FAR * This,
            /* [retval][out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *keyEvents);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *recordAbortHide )( 
            IELGDICal __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *alert )( 
            IELGDICal __RPC_FAR * This,
            /* [in] */ BSTR text);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *setCalibrationWindow )( 
            IELGDICal __RPC_FAR * This,
            /* [in] */ int hWnd);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *getTargetLocationX )( 
            IELGDICal __RPC_FAR * This,
            /* [retval][out] */ short __RPC_FAR *x);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *getTargetLocationY )( 
            IELGDICal __RPC_FAR * This,
            /* [retval][out] */ short __RPC_FAR *y);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *enableKeyCollection )( 
            IELGDICal __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL en);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *setCalibrationColors )( 
            IELGDICal __RPC_FAR * This,
            /* [in] */ OLE_COLOR fg,
            /* [in] */ OLE_COLOR bg);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *setCalibrationTargetSize )( 
            IELGDICal __RPC_FAR * This,
            /* [in] */ short inner,
            /* [in] */ short outer);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *setZoomDenominator )( 
            IELGDICal __RPC_FAR * This,
            /* [in] */ short denominator);
        
        END_INTERFACE
    } IELGDICalVtbl;

    interface IELGDICal
    {
        CONST_VTBL struct IELGDICalVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IELGDICal_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IELGDICal_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IELGDICal_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IELGDICal_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IELGDICal_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IELGDICal_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IELGDICal_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IELGDICal_setupCalibrationDisplay(This)	\
    (This)->lpVtbl -> setupCalibrationDisplay(This)

#define IELGDICal_clearCalibrationDisplay(This)	\
    (This)->lpVtbl -> clearCalibrationDisplay(This)

#define IELGDICal_drawCalibrationTarget(This,x,y)	\
    (This)->lpVtbl -> drawCalibrationTarget(This,x,y)

#define IELGDICal_eraseCalibrationTarget(This)	\
    (This)->lpVtbl -> eraseCalibrationTarget(This)

#define IELGDICal_exitCalibrationDisplay(This)	\
    (This)->lpVtbl -> exitCalibrationDisplay(This)

#define IELGDICal_setupImageDisplay(This,width,height)	\
    (This)->lpVtbl -> setupImageDisplay(This,width,height)

#define IELGDICal_drawCameraImage(This,cameraImage)	\
    (This)->lpVtbl -> drawCameraImage(This,cameraImage)

#define IELGDICal_setImageTitle(This,title)	\
    (This)->lpVtbl -> setImageTitle(This,title)

#define IELGDICal_exitImageDisplay(This)	\
    (This)->lpVtbl -> exitImageDisplay(This)

#define IELGDICal_playCalibrationBeep(This,beepid)	\
    (This)->lpVtbl -> playCalibrationBeep(This,beepid)

#define IELGDICal_getInputKey(This,keyEvents)	\
    (This)->lpVtbl -> getInputKey(This,keyEvents)

#define IELGDICal_recordAbortHide(This)	\
    (This)->lpVtbl -> recordAbortHide(This)

#define IELGDICal_alert(This,text)	\
    (This)->lpVtbl -> alert(This,text)


#define IELGDICal_setCalibrationWindow(This,hWnd)	\
    (This)->lpVtbl -> setCalibrationWindow(This,hWnd)

#define IELGDICal_getTargetLocationX(This,x)	\
    (This)->lpVtbl -> getTargetLocationX(This,x)

#define IELGDICal_getTargetLocationY(This,y)	\
    (This)->lpVtbl -> getTargetLocationY(This,y)

#define IELGDICal_enableKeyCollection(This,en)	\
    (This)->lpVtbl -> enableKeyCollection(This,en)

#define IELGDICal_setCalibrationColors(This,fg,bg)	\
    (This)->lpVtbl -> setCalibrationColors(This,fg,bg)

#define IELGDICal_setCalibrationTargetSize(This,inner,outer)	\
    (This)->lpVtbl -> setCalibrationTargetSize(This,inner,outer)

#define IELGDICal_setZoomDenominator(This,denominator)	\
    (This)->lpVtbl -> setZoomDenominator(This,denominator)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IELGDICal_setCalibrationWindow_Proxy( 
    IELGDICal __RPC_FAR * This,
    /* [in] */ int hWnd);


void __RPC_STUB IELGDICal_setCalibrationWindow_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IELGDICal_getTargetLocationX_Proxy( 
    IELGDICal __RPC_FAR * This,
    /* [retval][out] */ short __RPC_FAR *x);


void __RPC_STUB IELGDICal_getTargetLocationX_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IELGDICal_getTargetLocationY_Proxy( 
    IELGDICal __RPC_FAR * This,
    /* [retval][out] */ short __RPC_FAR *y);


void __RPC_STUB IELGDICal_getTargetLocationY_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IELGDICal_enableKeyCollection_Proxy( 
    IELGDICal __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL en);


void __RPC_STUB IELGDICal_enableKeyCollection_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IELGDICal_setCalibrationColors_Proxy( 
    IELGDICal __RPC_FAR * This,
    /* [in] */ OLE_COLOR fg,
    /* [in] */ OLE_COLOR bg);


void __RPC_STUB IELGDICal_setCalibrationColors_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IELGDICal_setCalibrationTargetSize_Proxy( 
    IELGDICal __RPC_FAR * This,
    /* [in] */ short inner,
    /* [in] */ short outer);


void __RPC_STUB IELGDICal_setCalibrationTargetSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IELGDICal_setZoomDenominator_Proxy( 
    IELGDICal __RPC_FAR * This,
    /* [in] */ short denominator);


void __RPC_STUB IELGDICal_setZoomDenominator_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IELGDICal_INTERFACE_DEFINED__ */


#ifndef __IEyeLinkUtil_INTERFACE_DEFINED__
#define __IEyeLinkUtil_INTERFACE_DEFINED__

/* interface IEyeLinkUtil */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IEyeLinkUtil;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("3EBC7F4F-2333-4AEC-9847-EB029E5A0CDB")
    IEyeLinkUtil : public IDispatch
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE inRealTimeMode( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *result) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE flushGetkeyQueue( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE beginRealTimeMode( 
            /* [in] */ int delay) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE currentTime( 
            /* [retval][out] */ double __RPC_FAR *result) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE currentUsec( 
            /* [retval][out] */ double __RPC_FAR *result) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE currentDoubleUsec( 
            /* [retval][out] */ double __RPC_FAR *result) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE endRealTimeMode( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE pumpDelay( 
            /* [in] */ int delay) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE msecDelay( 
            /* [in] */ int delay) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE alert( 
            /* [in] */ BSTR message) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE setCalibrationInterface( 
            /* [in] */ ICalibration __RPC_FAR *ical) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE getBusyCal( 
            /* [retval][out] */ IBusyCal __RPC_FAR *__RPC_FAR *ical) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE getGDICal( 
            /* [retval][out] */ IELGDICal __RPC_FAR *__RPC_FAR *ical) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IEyeLinkUtilVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IEyeLinkUtil __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IEyeLinkUtil __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IEyeLinkUtil __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IEyeLinkUtil __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IEyeLinkUtil __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IEyeLinkUtil __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IEyeLinkUtil __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *inRealTimeMode )( 
            IEyeLinkUtil __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *result);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *flushGetkeyQueue )( 
            IEyeLinkUtil __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *beginRealTimeMode )( 
            IEyeLinkUtil __RPC_FAR * This,
            /* [in] */ int delay);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *currentTime )( 
            IEyeLinkUtil __RPC_FAR * This,
            /* [retval][out] */ double __RPC_FAR *result);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *currentUsec )( 
            IEyeLinkUtil __RPC_FAR * This,
            /* [retval][out] */ double __RPC_FAR *result);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *currentDoubleUsec )( 
            IEyeLinkUtil __RPC_FAR * This,
            /* [retval][out] */ double __RPC_FAR *result);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *endRealTimeMode )( 
            IEyeLinkUtil __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *pumpDelay )( 
            IEyeLinkUtil __RPC_FAR * This,
            /* [in] */ int delay);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *msecDelay )( 
            IEyeLinkUtil __RPC_FAR * This,
            /* [in] */ int delay);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *alert )( 
            IEyeLinkUtil __RPC_FAR * This,
            /* [in] */ BSTR message);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *setCalibrationInterface )( 
            IEyeLinkUtil __RPC_FAR * This,
            /* [in] */ ICalibration __RPC_FAR *ical);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *getBusyCal )( 
            IEyeLinkUtil __RPC_FAR * This,
            /* [retval][out] */ IBusyCal __RPC_FAR *__RPC_FAR *ical);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *getGDICal )( 
            IEyeLinkUtil __RPC_FAR * This,
            /* [retval][out] */ IELGDICal __RPC_FAR *__RPC_FAR *ical);
        
        END_INTERFACE
    } IEyeLinkUtilVtbl;

    interface IEyeLinkUtil
    {
        CONST_VTBL struct IEyeLinkUtilVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEyeLinkUtil_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IEyeLinkUtil_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IEyeLinkUtil_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IEyeLinkUtil_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IEyeLinkUtil_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IEyeLinkUtil_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IEyeLinkUtil_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IEyeLinkUtil_inRealTimeMode(This,result)	\
    (This)->lpVtbl -> inRealTimeMode(This,result)

#define IEyeLinkUtil_flushGetkeyQueue(This)	\
    (This)->lpVtbl -> flushGetkeyQueue(This)

#define IEyeLinkUtil_beginRealTimeMode(This,delay)	\
    (This)->lpVtbl -> beginRealTimeMode(This,delay)

#define IEyeLinkUtil_currentTime(This,result)	\
    (This)->lpVtbl -> currentTime(This,result)

#define IEyeLinkUtil_currentUsec(This,result)	\
    (This)->lpVtbl -> currentUsec(This,result)

#define IEyeLinkUtil_currentDoubleUsec(This,result)	\
    (This)->lpVtbl -> currentDoubleUsec(This,result)

#define IEyeLinkUtil_endRealTimeMode(This)	\
    (This)->lpVtbl -> endRealTimeMode(This)

#define IEyeLinkUtil_pumpDelay(This,delay)	\
    (This)->lpVtbl -> pumpDelay(This,delay)

#define IEyeLinkUtil_msecDelay(This,delay)	\
    (This)->lpVtbl -> msecDelay(This,delay)

#define IEyeLinkUtil_alert(This,message)	\
    (This)->lpVtbl -> alert(This,message)

#define IEyeLinkUtil_setCalibrationInterface(This,ical)	\
    (This)->lpVtbl -> setCalibrationInterface(This,ical)

#define IEyeLinkUtil_getBusyCal(This,ical)	\
    (This)->lpVtbl -> getBusyCal(This,ical)

#define IEyeLinkUtil_getGDICal(This,ical)	\
    (This)->lpVtbl -> getGDICal(This,ical)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IEyeLinkUtil_inRealTimeMode_Proxy( 
    IEyeLinkUtil __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *result);


void __RPC_STUB IEyeLinkUtil_inRealTimeMode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEyeLinkUtil_flushGetkeyQueue_Proxy( 
    IEyeLinkUtil __RPC_FAR * This);


void __RPC_STUB IEyeLinkUtil_flushGetkeyQueue_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEyeLinkUtil_beginRealTimeMode_Proxy( 
    IEyeLinkUtil __RPC_FAR * This,
    /* [in] */ int delay);


void __RPC_STUB IEyeLinkUtil_beginRealTimeMode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEyeLinkUtil_currentTime_Proxy( 
    IEyeLinkUtil __RPC_FAR * This,
    /* [retval][out] */ double __RPC_FAR *result);


void __RPC_STUB IEyeLinkUtil_currentTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEyeLinkUtil_currentUsec_Proxy( 
    IEyeLinkUtil __RPC_FAR * This,
    /* [retval][out] */ double __RPC_FAR *result);


void __RPC_STUB IEyeLinkUtil_currentUsec_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEyeLinkUtil_currentDoubleUsec_Proxy( 
    IEyeLinkUtil __RPC_FAR * This,
    /* [retval][out] */ double __RPC_FAR *result);


void __RPC_STUB IEyeLinkUtil_currentDoubleUsec_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEyeLinkUtil_endRealTimeMode_Proxy( 
    IEyeLinkUtil __RPC_FAR * This);


void __RPC_STUB IEyeLinkUtil_endRealTimeMode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEyeLinkUtil_pumpDelay_Proxy( 
    IEyeLinkUtil __RPC_FAR * This,
    /* [in] */ int delay);


void __RPC_STUB IEyeLinkUtil_pumpDelay_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEyeLinkUtil_msecDelay_Proxy( 
    IEyeLinkUtil __RPC_FAR * This,
    /* [in] */ int delay);


void __RPC_STUB IEyeLinkUtil_msecDelay_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEyeLinkUtil_alert_Proxy( 
    IEyeLinkUtil __RPC_FAR * This,
    /* [in] */ BSTR message);


void __RPC_STUB IEyeLinkUtil_alert_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEyeLinkUtil_setCalibrationInterface_Proxy( 
    IEyeLinkUtil __RPC_FAR * This,
    /* [in] */ ICalibration __RPC_FAR *ical);


void __RPC_STUB IEyeLinkUtil_setCalibrationInterface_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEyeLinkUtil_getBusyCal_Proxy( 
    IEyeLinkUtil __RPC_FAR * This,
    /* [retval][out] */ IBusyCal __RPC_FAR *__RPC_FAR *ical);


void __RPC_STUB IEyeLinkUtil_getBusyCal_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEyeLinkUtil_getGDICal_Proxy( 
    IEyeLinkUtil __RPC_FAR * This,
    /* [retval][out] */ IELGDICal __RPC_FAR *__RPC_FAR *ical);


void __RPC_STUB IEyeLinkUtil_getGDICal_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IEyeLinkUtil_INTERFACE_DEFINED__ */


#ifndef __IEyeEvent_INTERFACE_DEFINED__
#define __IEyeEvent_INTERFACE_DEFINED__

/* interface IEyeEvent */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IEyeEvent;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("FAF94525-E372-4B42-9903-F265B2E6DAA3")
    IEyeEvent : public IELData
    {
    public:
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_eye( 
            /* [retval][out] */ EL_EYE __RPC_FAR *eye) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_read( 
            /* [retval][out] */ short __RPC_FAR *read) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_sttime( 
            /* [retval][out] */ double __RPC_FAR *sttime) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IEyeEventVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IEyeEvent __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IEyeEvent __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IEyeEvent __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IEyeEvent __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IEyeEvent __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IEyeEvent __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IEyeEvent __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_time )( 
            IEyeEvent __RPC_FAR * This,
            /* [retval][out] */ double __RPC_FAR *result);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_eltype )( 
            IEyeEvent __RPC_FAR * This,
            /* [retval][out] */ EL_DATA_TYPE __RPC_FAR *result);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_eye )( 
            IEyeEvent __RPC_FAR * This,
            /* [retval][out] */ EL_EYE __RPC_FAR *eye);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_read )( 
            IEyeEvent __RPC_FAR * This,
            /* [retval][out] */ short __RPC_FAR *read);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_sttime )( 
            IEyeEvent __RPC_FAR * This,
            /* [retval][out] */ double __RPC_FAR *sttime);
        
        END_INTERFACE
    } IEyeEventVtbl;

    interface IEyeEvent
    {
        CONST_VTBL struct IEyeEventVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEyeEvent_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IEyeEvent_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IEyeEvent_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IEyeEvent_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IEyeEvent_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IEyeEvent_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IEyeEvent_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IEyeEvent_get_time(This,result)	\
    (This)->lpVtbl -> get_time(This,result)

#define IEyeEvent_get_eltype(This,result)	\
    (This)->lpVtbl -> get_eltype(This,result)


#define IEyeEvent_get_eye(This,eye)	\
    (This)->lpVtbl -> get_eye(This,eye)

#define IEyeEvent_get_read(This,read)	\
    (This)->lpVtbl -> get_read(This,read)

#define IEyeEvent_get_sttime(This,sttime)	\
    (This)->lpVtbl -> get_sttime(This,sttime)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IEyeEvent_get_eye_Proxy( 
    IEyeEvent __RPC_FAR * This,
    /* [retval][out] */ EL_EYE __RPC_FAR *eye);


void __RPC_STUB IEyeEvent_get_eye_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IEyeEvent_get_read_Proxy( 
    IEyeEvent __RPC_FAR * This,
    /* [retval][out] */ short __RPC_FAR *read);


void __RPC_STUB IEyeEvent_get_read_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IEyeEvent_get_sttime_Proxy( 
    IEyeEvent __RPC_FAR * This,
    /* [retval][out] */ double __RPC_FAR *sttime);


void __RPC_STUB IEyeEvent_get_sttime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IEyeEvent_INTERFACE_DEFINED__ */


#ifndef __IStartBlinkEvent_INTERFACE_DEFINED__
#define __IStartBlinkEvent_INTERFACE_DEFINED__

/* interface IStartBlinkEvent */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IStartBlinkEvent;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("84C93301-94CB-4CA7-A374-6FC626EB00D3")
    IStartBlinkEvent : public IEyeEvent
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct IStartBlinkEventVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IStartBlinkEvent __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IStartBlinkEvent __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IStartBlinkEvent __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IStartBlinkEvent __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IStartBlinkEvent __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IStartBlinkEvent __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IStartBlinkEvent __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_time )( 
            IStartBlinkEvent __RPC_FAR * This,
            /* [retval][out] */ double __RPC_FAR *result);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_eltype )( 
            IStartBlinkEvent __RPC_FAR * This,
            /* [retval][out] */ EL_DATA_TYPE __RPC_FAR *result);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_eye )( 
            IStartBlinkEvent __RPC_FAR * This,
            /* [retval][out] */ EL_EYE __RPC_FAR *eye);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_read )( 
            IStartBlinkEvent __RPC_FAR * This,
            /* [retval][out] */ short __RPC_FAR *read);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_sttime )( 
            IStartBlinkEvent __RPC_FAR * This,
            /* [retval][out] */ double __RPC_FAR *sttime);
        
        END_INTERFACE
    } IStartBlinkEventVtbl;

    interface IStartBlinkEvent
    {
        CONST_VTBL struct IStartBlinkEventVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IStartBlinkEvent_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IStartBlinkEvent_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IStartBlinkEvent_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IStartBlinkEvent_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IStartBlinkEvent_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IStartBlinkEvent_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IStartBlinkEvent_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IStartBlinkEvent_get_time(This,result)	\
    (This)->lpVtbl -> get_time(This,result)

#define IStartBlinkEvent_get_eltype(This,result)	\
    (This)->lpVtbl -> get_eltype(This,result)


#define IStartBlinkEvent_get_eye(This,eye)	\
    (This)->lpVtbl -> get_eye(This,eye)

#define IStartBlinkEvent_get_read(This,read)	\
    (This)->lpVtbl -> get_read(This,read)

#define IStartBlinkEvent_get_sttime(This,sttime)	\
    (This)->lpVtbl -> get_sttime(This,sttime)


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IStartBlinkEvent_INTERFACE_DEFINED__ */


#ifndef __IEndBlinkEvent_INTERFACE_DEFINED__
#define __IEndBlinkEvent_INTERFACE_DEFINED__

/* interface IEndBlinkEvent */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IEndBlinkEvent;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("6D4B7642-9D28-49D5-B52D-708A5639236E")
    IEndBlinkEvent : public IStartBlinkEvent
    {
    public:
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_entime( 
            /* [retval][out] */ double __RPC_FAR *entime) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IEndBlinkEventVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IEndBlinkEvent __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IEndBlinkEvent __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IEndBlinkEvent __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IEndBlinkEvent __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IEndBlinkEvent __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IEndBlinkEvent __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IEndBlinkEvent __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_time )( 
            IEndBlinkEvent __RPC_FAR * This,
            /* [retval][out] */ double __RPC_FAR *result);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_eltype )( 
            IEndBlinkEvent __RPC_FAR * This,
            /* [retval][out] */ EL_DATA_TYPE __RPC_FAR *result);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_eye )( 
            IEndBlinkEvent __RPC_FAR * This,
            /* [retval][out] */ EL_EYE __RPC_FAR *eye);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_read )( 
            IEndBlinkEvent __RPC_FAR * This,
            /* [retval][out] */ short __RPC_FAR *read);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_sttime )( 
            IEndBlinkEvent __RPC_FAR * This,
            /* [retval][out] */ double __RPC_FAR *sttime);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_entime )( 
            IEndBlinkEvent __RPC_FAR * This,
            /* [retval][out] */ double __RPC_FAR *entime);
        
        END_INTERFACE
    } IEndBlinkEventVtbl;

    interface IEndBlinkEvent
    {
        CONST_VTBL struct IEndBlinkEventVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEndBlinkEvent_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IEndBlinkEvent_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IEndBlinkEvent_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IEndBlinkEvent_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IEndBlinkEvent_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IEndBlinkEvent_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IEndBlinkEvent_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IEndBlinkEvent_get_time(This,result)	\
    (This)->lpVtbl -> get_time(This,result)

#define IEndBlinkEvent_get_eltype(This,result)	\
    (This)->lpVtbl -> get_eltype(This,result)


#define IEndBlinkEvent_get_eye(This,eye)	\
    (This)->lpVtbl -> get_eye(This,eye)

#define IEndBlinkEvent_get_read(This,read)	\
    (This)->lpVtbl -> get_read(This,read)

#define IEndBlinkEvent_get_sttime(This,sttime)	\
    (This)->lpVtbl -> get_sttime(This,sttime)



#define IEndBlinkEvent_get_entime(This,entime)	\
    (This)->lpVtbl -> get_entime(This,entime)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IEndBlinkEvent_get_entime_Proxy( 
    IEndBlinkEvent __RPC_FAR * This,
    /* [retval][out] */ double __RPC_FAR *entime);


void __RPC_STUB IEndBlinkEvent_get_entime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IEndBlinkEvent_INTERFACE_DEFINED__ */


#ifndef __IStartSaccadeEvent_INTERFACE_DEFINED__
#define __IStartSaccadeEvent_INTERFACE_DEFINED__

/* interface IStartSaccadeEvent */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IStartSaccadeEvent;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E0C17079-EF6F-4CE7-A8B5-63FAD29D47FC")
    IStartSaccadeEvent : public IEyeEvent
    {
    public:
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_hstx( 
            /* [retval][out] */ float __RPC_FAR *hstx) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_hsty( 
            /* [retval][out] */ float __RPC_FAR *hsty) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_gstx( 
            /* [retval][out] */ float __RPC_FAR *gstx) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_gsty( 
            /* [retval][out] */ float __RPC_FAR *gsty) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_svel( 
            /* [retval][out] */ float __RPC_FAR *svel) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_supd_x( 
            /* [retval][out] */ float __RPC_FAR *supd_x) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_supd_y( 
            /* [retval][out] */ float __RPC_FAR *supd_y) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IStartSaccadeEventVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IStartSaccadeEvent __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IStartSaccadeEvent __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IStartSaccadeEvent __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IStartSaccadeEvent __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IStartSaccadeEvent __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IStartSaccadeEvent __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IStartSaccadeEvent __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_time )( 
            IStartSaccadeEvent __RPC_FAR * This,
            /* [retval][out] */ double __RPC_FAR *result);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_eltype )( 
            IStartSaccadeEvent __RPC_FAR * This,
            /* [retval][out] */ EL_DATA_TYPE __RPC_FAR *result);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_eye )( 
            IStartSaccadeEvent __RPC_FAR * This,
            /* [retval][out] */ EL_EYE __RPC_FAR *eye);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_read )( 
            IStartSaccadeEvent __RPC_FAR * This,
            /* [retval][out] */ short __RPC_FAR *read);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_sttime )( 
            IStartSaccadeEvent __RPC_FAR * This,
            /* [retval][out] */ double __RPC_FAR *sttime);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_hstx )( 
            IStartSaccadeEvent __RPC_FAR * This,
            /* [retval][out] */ float __RPC_FAR *hstx);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_hsty )( 
            IStartSaccadeEvent __RPC_FAR * This,
            /* [retval][out] */ float __RPC_FAR *hsty);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_gstx )( 
            IStartSaccadeEvent __RPC_FAR * This,
            /* [retval][out] */ float __RPC_FAR *gstx);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_gsty )( 
            IStartSaccadeEvent __RPC_FAR * This,
            /* [retval][out] */ float __RPC_FAR *gsty);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_svel )( 
            IStartSaccadeEvent __RPC_FAR * This,
            /* [retval][out] */ float __RPC_FAR *svel);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_supd_x )( 
            IStartSaccadeEvent __RPC_FAR * This,
            /* [retval][out] */ float __RPC_FAR *supd_x);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_supd_y )( 
            IStartSaccadeEvent __RPC_FAR * This,
            /* [retval][out] */ float __RPC_FAR *supd_y);
        
        END_INTERFACE
    } IStartSaccadeEventVtbl;

    interface IStartSaccadeEvent
    {
        CONST_VTBL struct IStartSaccadeEventVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IStartSaccadeEvent_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IStartSaccadeEvent_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IStartSaccadeEvent_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IStartSaccadeEvent_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IStartSaccadeEvent_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IStartSaccadeEvent_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IStartSaccadeEvent_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IStartSaccadeEvent_get_time(This,result)	\
    (This)->lpVtbl -> get_time(This,result)

#define IStartSaccadeEvent_get_eltype(This,result)	\
    (This)->lpVtbl -> get_eltype(This,result)


#define IStartSaccadeEvent_get_eye(This,eye)	\
    (This)->lpVtbl -> get_eye(This,eye)

#define IStartSaccadeEvent_get_read(This,read)	\
    (This)->lpVtbl -> get_read(This,read)

#define IStartSaccadeEvent_get_sttime(This,sttime)	\
    (This)->lpVtbl -> get_sttime(This,sttime)


#define IStartSaccadeEvent_get_hstx(This,hstx)	\
    (This)->lpVtbl -> get_hstx(This,hstx)

#define IStartSaccadeEvent_get_hsty(This,hsty)	\
    (This)->lpVtbl -> get_hsty(This,hsty)

#define IStartSaccadeEvent_get_gstx(This,gstx)	\
    (This)->lpVtbl -> get_gstx(This,gstx)

#define IStartSaccadeEvent_get_gsty(This,gsty)	\
    (This)->lpVtbl -> get_gsty(This,gsty)

#define IStartSaccadeEvent_get_svel(This,svel)	\
    (This)->lpVtbl -> get_svel(This,svel)

#define IStartSaccadeEvent_get_supd_x(This,supd_x)	\
    (This)->lpVtbl -> get_supd_x(This,supd_x)

#define IStartSaccadeEvent_get_supd_y(This,supd_y)	\
    (This)->lpVtbl -> get_supd_y(This,supd_y)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IStartSaccadeEvent_get_hstx_Proxy( 
    IStartSaccadeEvent __RPC_FAR * This,
    /* [retval][out] */ float __RPC_FAR *hstx);


void __RPC_STUB IStartSaccadeEvent_get_hstx_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IStartSaccadeEvent_get_hsty_Proxy( 
    IStartSaccadeEvent __RPC_FAR * This,
    /* [retval][out] */ float __RPC_FAR *hsty);


void __RPC_STUB IStartSaccadeEvent_get_hsty_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IStartSaccadeEvent_get_gstx_Proxy( 
    IStartSaccadeEvent __RPC_FAR * This,
    /* [retval][out] */ float __RPC_FAR *gstx);


void __RPC_STUB IStartSaccadeEvent_get_gstx_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IStartSaccadeEvent_get_gsty_Proxy( 
    IStartSaccadeEvent __RPC_FAR * This,
    /* [retval][out] */ float __RPC_FAR *gsty);


void __RPC_STUB IStartSaccadeEvent_get_gsty_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IStartSaccadeEvent_get_svel_Proxy( 
    IStartSaccadeEvent __RPC_FAR * This,
    /* [retval][out] */ float __RPC_FAR *svel);


void __RPC_STUB IStartSaccadeEvent_get_svel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IStartSaccadeEvent_get_supd_x_Proxy( 
    IStartSaccadeEvent __RPC_FAR * This,
    /* [retval][out] */ float __RPC_FAR *supd_x);


void __RPC_STUB IStartSaccadeEvent_get_supd_x_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IStartSaccadeEvent_get_supd_y_Proxy( 
    IStartSaccadeEvent __RPC_FAR * This,
    /* [retval][out] */ float __RPC_FAR *supd_y);


void __RPC_STUB IStartSaccadeEvent_get_supd_y_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IStartSaccadeEvent_INTERFACE_DEFINED__ */


#ifndef __IStartFixationEvent_INTERFACE_DEFINED__
#define __IStartFixationEvent_INTERFACE_DEFINED__

/* interface IStartFixationEvent */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IStartFixationEvent;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C259A0BF-565A-410D-8B78-EAC9960D96CB")
    IStartFixationEvent : public IEyeEvent
    {
    public:
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_hstx( 
            /* [retval][out] */ float __RPC_FAR *hstx) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_hsty( 
            /* [retval][out] */ float __RPC_FAR *hsty) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_gstx( 
            /* [retval][out] */ float __RPC_FAR *gstx) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_gsty( 
            /* [retval][out] */ float __RPC_FAR *gsty) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_svel( 
            /* [retval][out] */ float __RPC_FAR *svel) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_supd_x( 
            /* [retval][out] */ float __RPC_FAR *supd_x) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_supd_y( 
            /* [retval][out] */ float __RPC_FAR *supd_y) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_sta( 
            /* [retval][out] */ float __RPC_FAR *sta) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IStartFixationEventVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IStartFixationEvent __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IStartFixationEvent __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IStartFixationEvent __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IStartFixationEvent __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IStartFixationEvent __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IStartFixationEvent __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IStartFixationEvent __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_time )( 
            IStartFixationEvent __RPC_FAR * This,
            /* [retval][out] */ double __RPC_FAR *result);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_eltype )( 
            IStartFixationEvent __RPC_FAR * This,
            /* [retval][out] */ EL_DATA_TYPE __RPC_FAR *result);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_eye )( 
            IStartFixationEvent __RPC_FAR * This,
            /* [retval][out] */ EL_EYE __RPC_FAR *eye);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_read )( 
            IStartFixationEvent __RPC_FAR * This,
            /* [retval][out] */ short __RPC_FAR *read);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_sttime )( 
            IStartFixationEvent __RPC_FAR * This,
            /* [retval][out] */ double __RPC_FAR *sttime);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_hstx )( 
            IStartFixationEvent __RPC_FAR * This,
            /* [retval][out] */ float __RPC_FAR *hstx);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_hsty )( 
            IStartFixationEvent __RPC_FAR * This,
            /* [retval][out] */ float __RPC_FAR *hsty);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_gstx )( 
            IStartFixationEvent __RPC_FAR * This,
            /* [retval][out] */ float __RPC_FAR *gstx);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_gsty )( 
            IStartFixationEvent __RPC_FAR * This,
            /* [retval][out] */ float __RPC_FAR *gsty);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_svel )( 
            IStartFixationEvent __RPC_FAR * This,
            /* [retval][out] */ float __RPC_FAR *svel);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_supd_x )( 
            IStartFixationEvent __RPC_FAR * This,
            /* [retval][out] */ float __RPC_FAR *supd_x);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_supd_y )( 
            IStartFixationEvent __RPC_FAR * This,
            /* [retval][out] */ float __RPC_FAR *supd_y);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_sta )( 
            IStartFixationEvent __RPC_FAR * This,
            /* [retval][out] */ float __RPC_FAR *sta);
        
        END_INTERFACE
    } IStartFixationEventVtbl;

    interface IStartFixationEvent
    {
        CONST_VTBL struct IStartFixationEventVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IStartFixationEvent_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IStartFixationEvent_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IStartFixationEvent_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IStartFixationEvent_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IStartFixationEvent_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IStartFixationEvent_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IStartFixationEvent_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IStartFixationEvent_get_time(This,result)	\
    (This)->lpVtbl -> get_time(This,result)

#define IStartFixationEvent_get_eltype(This,result)	\
    (This)->lpVtbl -> get_eltype(This,result)


#define IStartFixationEvent_get_eye(This,eye)	\
    (This)->lpVtbl -> get_eye(This,eye)

#define IStartFixationEvent_get_read(This,read)	\
    (This)->lpVtbl -> get_read(This,read)

#define IStartFixationEvent_get_sttime(This,sttime)	\
    (This)->lpVtbl -> get_sttime(This,sttime)


#define IStartFixationEvent_get_hstx(This,hstx)	\
    (This)->lpVtbl -> get_hstx(This,hstx)

#define IStartFixationEvent_get_hsty(This,hsty)	\
    (This)->lpVtbl -> get_hsty(This,hsty)

#define IStartFixationEvent_get_gstx(This,gstx)	\
    (This)->lpVtbl -> get_gstx(This,gstx)

#define IStartFixationEvent_get_gsty(This,gsty)	\
    (This)->lpVtbl -> get_gsty(This,gsty)

#define IStartFixationEvent_get_svel(This,svel)	\
    (This)->lpVtbl -> get_svel(This,svel)

#define IStartFixationEvent_get_supd_x(This,supd_x)	\
    (This)->lpVtbl -> get_supd_x(This,supd_x)

#define IStartFixationEvent_get_supd_y(This,supd_y)	\
    (This)->lpVtbl -> get_supd_y(This,supd_y)

#define IStartFixationEvent_get_sta(This,sta)	\
    (This)->lpVtbl -> get_sta(This,sta)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IStartFixationEvent_get_hstx_Proxy( 
    IStartFixationEvent __RPC_FAR * This,
    /* [retval][out] */ float __RPC_FAR *hstx);


void __RPC_STUB IStartFixationEvent_get_hstx_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IStartFixationEvent_get_hsty_Proxy( 
    IStartFixationEvent __RPC_FAR * This,
    /* [retval][out] */ float __RPC_FAR *hsty);


void __RPC_STUB IStartFixationEvent_get_hsty_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IStartFixationEvent_get_gstx_Proxy( 
    IStartFixationEvent __RPC_FAR * This,
    /* [retval][out] */ float __RPC_FAR *gstx);


void __RPC_STUB IStartFixationEvent_get_gstx_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IStartFixationEvent_get_gsty_Proxy( 
    IStartFixationEvent __RPC_FAR * This,
    /* [retval][out] */ float __RPC_FAR *gsty);


void __RPC_STUB IStartFixationEvent_get_gsty_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IStartFixationEvent_get_svel_Proxy( 
    IStartFixationEvent __RPC_FAR * This,
    /* [retval][out] */ float __RPC_FAR *svel);


void __RPC_STUB IStartFixationEvent_get_svel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IStartFixationEvent_get_supd_x_Proxy( 
    IStartFixationEvent __RPC_FAR * This,
    /* [retval][out] */ float __RPC_FAR *supd_x);


void __RPC_STUB IStartFixationEvent_get_supd_x_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IStartFixationEvent_get_supd_y_Proxy( 
    IStartFixationEvent __RPC_FAR * This,
    /* [retval][out] */ float __RPC_FAR *supd_y);


void __RPC_STUB IStartFixationEvent_get_supd_y_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IStartFixationEvent_get_sta_Proxy( 
    IStartFixationEvent __RPC_FAR * This,
    /* [retval][out] */ float __RPC_FAR *sta);


void __RPC_STUB IStartFixationEvent_get_sta_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IStartFixationEvent_INTERFACE_DEFINED__ */


#ifndef __IEndSaccadeEvent_INTERFACE_DEFINED__
#define __IEndSaccadeEvent_INTERFACE_DEFINED__

/* interface IEndSaccadeEvent */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IEndSaccadeEvent;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("B327CE59-87BB-4290-A009-5FB9339F73F1")
    IEndSaccadeEvent : public IStartSaccadeEvent
    {
    public:
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_entime( 
            /* [retval][out] */ double __RPC_FAR *entime) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_henx( 
            /* [retval][out] */ float __RPC_FAR *henx) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_heny( 
            /* [retval][out] */ float __RPC_FAR *heny) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_genx( 
            /* [retval][out] */ float __RPC_FAR *genx) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_geny( 
            /* [retval][out] */ float __RPC_FAR *geny) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_evel( 
            /* [retval][out] */ float __RPC_FAR *evel) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_avel( 
            /* [retval][out] */ float __RPC_FAR *avel) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_pvel( 
            /* [retval][out] */ float __RPC_FAR *pvel) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_eupd_x( 
            /* [retval][out] */ float __RPC_FAR *eupd_x) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_eupd_y( 
            /* [retval][out] */ float __RPC_FAR *eupd_y) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IEndSaccadeEventVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IEndSaccadeEvent __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IEndSaccadeEvent __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IEndSaccadeEvent __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IEndSaccadeEvent __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IEndSaccadeEvent __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IEndSaccadeEvent __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IEndSaccadeEvent __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_time )( 
            IEndSaccadeEvent __RPC_FAR * This,
            /* [retval][out] */ double __RPC_FAR *result);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_eltype )( 
            IEndSaccadeEvent __RPC_FAR * This,
            /* [retval][out] */ EL_DATA_TYPE __RPC_FAR *result);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_eye )( 
            IEndSaccadeEvent __RPC_FAR * This,
            /* [retval][out] */ EL_EYE __RPC_FAR *eye);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_read )( 
            IEndSaccadeEvent __RPC_FAR * This,
            /* [retval][out] */ short __RPC_FAR *read);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_sttime )( 
            IEndSaccadeEvent __RPC_FAR * This,
            /* [retval][out] */ double __RPC_FAR *sttime);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_hstx )( 
            IEndSaccadeEvent __RPC_FAR * This,
            /* [retval][out] */ float __RPC_FAR *hstx);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_hsty )( 
            IEndSaccadeEvent __RPC_FAR * This,
            /* [retval][out] */ float __RPC_FAR *hsty);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_gstx )( 
            IEndSaccadeEvent __RPC_FAR * This,
            /* [retval][out] */ float __RPC_FAR *gstx);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_gsty )( 
            IEndSaccadeEvent __RPC_FAR * This,
            /* [retval][out] */ float __RPC_FAR *gsty);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_svel )( 
            IEndSaccadeEvent __RPC_FAR * This,
            /* [retval][out] */ float __RPC_FAR *svel);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_supd_x )( 
            IEndSaccadeEvent __RPC_FAR * This,
            /* [retval][out] */ float __RPC_FAR *supd_x);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_supd_y )( 
            IEndSaccadeEvent __RPC_FAR * This,
            /* [retval][out] */ float __RPC_FAR *supd_y);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_entime )( 
            IEndSaccadeEvent __RPC_FAR * This,
            /* [retval][out] */ double __RPC_FAR *entime);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_henx )( 
            IEndSaccadeEvent __RPC_FAR * This,
            /* [retval][out] */ float __RPC_FAR *henx);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_heny )( 
            IEndSaccadeEvent __RPC_FAR * This,
            /* [retval][out] */ float __RPC_FAR *heny);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_genx )( 
            IEndSaccadeEvent __RPC_FAR * This,
            /* [retval][out] */ float __RPC_FAR *genx);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_geny )( 
            IEndSaccadeEvent __RPC_FAR * This,
            /* [retval][out] */ float __RPC_FAR *geny);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_evel )( 
            IEndSaccadeEvent __RPC_FAR * This,
            /* [retval][out] */ float __RPC_FAR *evel);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_avel )( 
            IEndSaccadeEvent __RPC_FAR * This,
            /* [retval][out] */ float __RPC_FAR *avel);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_pvel )( 
            IEndSaccadeEvent __RPC_FAR * This,
            /* [retval][out] */ float __RPC_FAR *pvel);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_eupd_x )( 
            IEndSaccadeEvent __RPC_FAR * This,
            /* [retval][out] */ float __RPC_FAR *eupd_x);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_eupd_y )( 
            IEndSaccadeEvent __RPC_FAR * This,
            /* [retval][out] */ float __RPC_FAR *eupd_y);
        
        END_INTERFACE
    } IEndSaccadeEventVtbl;

    interface IEndSaccadeEvent
    {
        CONST_VTBL struct IEndSaccadeEventVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEndSaccadeEvent_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IEndSaccadeEvent_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IEndSaccadeEvent_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IEndSaccadeEvent_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IEndSaccadeEvent_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IEndSaccadeEvent_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IEndSaccadeEvent_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IEndSaccadeEvent_get_time(This,result)	\
    (This)->lpVtbl -> get_time(This,result)

#define IEndSaccadeEvent_get_eltype(This,result)	\
    (This)->lpVtbl -> get_eltype(This,result)


#define IEndSaccadeEvent_get_eye(This,eye)	\
    (This)->lpVtbl -> get_eye(This,eye)

#define IEndSaccadeEvent_get_read(This,read)	\
    (This)->lpVtbl -> get_read(This,read)

#define IEndSaccadeEvent_get_sttime(This,sttime)	\
    (This)->lpVtbl -> get_sttime(This,sttime)


#define IEndSaccadeEvent_get_hstx(This,hstx)	\
    (This)->lpVtbl -> get_hstx(This,hstx)

#define IEndSaccadeEvent_get_hsty(This,hsty)	\
    (This)->lpVtbl -> get_hsty(This,hsty)

#define IEndSaccadeEvent_get_gstx(This,gstx)	\
    (This)->lpVtbl -> get_gstx(This,gstx)

#define IEndSaccadeEvent_get_gsty(This,gsty)	\
    (This)->lpVtbl -> get_gsty(This,gsty)

#define IEndSaccadeEvent_get_svel(This,svel)	\
    (This)->lpVtbl -> get_svel(This,svel)

#define IEndSaccadeEvent_get_supd_x(This,supd_x)	\
    (This)->lpVtbl -> get_supd_x(This,supd_x)

#define IEndSaccadeEvent_get_supd_y(This,supd_y)	\
    (This)->lpVtbl -> get_supd_y(This,supd_y)


#define IEndSaccadeEvent_get_entime(This,entime)	\
    (This)->lpVtbl -> get_entime(This,entime)

#define IEndSaccadeEvent_get_henx(This,henx)	\
    (This)->lpVtbl -> get_henx(This,henx)

#define IEndSaccadeEvent_get_heny(This,heny)	\
    (This)->lpVtbl -> get_heny(This,heny)

#define IEndSaccadeEvent_get_genx(This,genx)	\
    (This)->lpVtbl -> get_genx(This,genx)

#define IEndSaccadeEvent_get_geny(This,geny)	\
    (This)->lpVtbl -> get_geny(This,geny)

#define IEndSaccadeEvent_get_evel(This,evel)	\
    (This)->lpVtbl -> get_evel(This,evel)

#define IEndSaccadeEvent_get_avel(This,avel)	\
    (This)->lpVtbl -> get_avel(This,avel)

#define IEndSaccadeEvent_get_pvel(This,pvel)	\
    (This)->lpVtbl -> get_pvel(This,pvel)

#define IEndSaccadeEvent_get_eupd_x(This,eupd_x)	\
    (This)->lpVtbl -> get_eupd_x(This,eupd_x)

#define IEndSaccadeEvent_get_eupd_y(This,eupd_y)	\
    (This)->lpVtbl -> get_eupd_y(This,eupd_y)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IEndSaccadeEvent_get_entime_Proxy( 
    IEndSaccadeEvent __RPC_FAR * This,
    /* [retval][out] */ double __RPC_FAR *entime);


void __RPC_STUB IEndSaccadeEvent_get_entime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IEndSaccadeEvent_get_henx_Proxy( 
    IEndSaccadeEvent __RPC_FAR * This,
    /* [retval][out] */ float __RPC_FAR *henx);


void __RPC_STUB IEndSaccadeEvent_get_henx_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IEndSaccadeEvent_get_heny_Proxy( 
    IEndSaccadeEvent __RPC_FAR * This,
    /* [retval][out] */ float __RPC_FAR *heny);


void __RPC_STUB IEndSaccadeEvent_get_heny_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IEndSaccadeEvent_get_genx_Proxy( 
    IEndSaccadeEvent __RPC_FAR * This,
    /* [retval][out] */ float __RPC_FAR *genx);


void __RPC_STUB IEndSaccadeEvent_get_genx_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IEndSaccadeEvent_get_geny_Proxy( 
    IEndSaccadeEvent __RPC_FAR * This,
    /* [retval][out] */ float __RPC_FAR *geny);


void __RPC_STUB IEndSaccadeEvent_get_geny_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IEndSaccadeEvent_get_evel_Proxy( 
    IEndSaccadeEvent __RPC_FAR * This,
    /* [retval][out] */ float __RPC_FAR *evel);


void __RPC_STUB IEndSaccadeEvent_get_evel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IEndSaccadeEvent_get_avel_Proxy( 
    IEndSaccadeEvent __RPC_FAR * This,
    /* [retval][out] */ float __RPC_FAR *avel);


void __RPC_STUB IEndSaccadeEvent_get_avel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IEndSaccadeEvent_get_pvel_Proxy( 
    IEndSaccadeEvent __RPC_FAR * This,
    /* [retval][out] */ float __RPC_FAR *pvel);


void __RPC_STUB IEndSaccadeEvent_get_pvel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IEndSaccadeEvent_get_eupd_x_Proxy( 
    IEndSaccadeEvent __RPC_FAR * This,
    /* [retval][out] */ float __RPC_FAR *eupd_x);


void __RPC_STUB IEndSaccadeEvent_get_eupd_x_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IEndSaccadeEvent_get_eupd_y_Proxy( 
    IEndSaccadeEvent __RPC_FAR * This,
    /* [retval][out] */ float __RPC_FAR *eupd_y);


void __RPC_STUB IEndSaccadeEvent_get_eupd_y_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IEndSaccadeEvent_INTERFACE_DEFINED__ */


#ifndef __IEndFixationEvent_INTERFACE_DEFINED__
#define __IEndFixationEvent_INTERFACE_DEFINED__

/* interface IEndFixationEvent */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IEndFixationEvent;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("70F1B032-1E56-4405-BC67-CD9361C79EF0")
    IEndFixationEvent : public IStartFixationEvent
    {
    public:
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_entime( 
            /* [retval][out] */ double __RPC_FAR *entime) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_henx( 
            /* [retval][out] */ float __RPC_FAR *henx) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_heny( 
            /* [retval][out] */ float __RPC_FAR *heny) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_genx( 
            /* [retval][out] */ float __RPC_FAR *genx) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_geny( 
            /* [retval][out] */ float __RPC_FAR *geny) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_evel( 
            /* [retval][out] */ float __RPC_FAR *evel) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_avel( 
            /* [retval][out] */ float __RPC_FAR *avel) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_pvel( 
            /* [retval][out] */ float __RPC_FAR *pvel) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_eupd_x( 
            /* [retval][out] */ float __RPC_FAR *eupd_x) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_eupd_y( 
            /* [retval][out] */ float __RPC_FAR *eupd_y) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_ena( 
            /* [retval][out] */ float __RPC_FAR *ena) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_havx( 
            /* [retval][out] */ float __RPC_FAR *havx) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_havy( 
            /* [retval][out] */ float __RPC_FAR *havy) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_gavx( 
            /* [retval][out] */ float __RPC_FAR *gavx) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_gavy( 
            /* [retval][out] */ float __RPC_FAR *gavy) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_ava( 
            /* [retval][out] */ float __RPC_FAR *ava) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IEndFixationEventVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IEndFixationEvent __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IEndFixationEvent __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IEndFixationEvent __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IEndFixationEvent __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IEndFixationEvent __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IEndFixationEvent __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IEndFixationEvent __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_time )( 
            IEndFixationEvent __RPC_FAR * This,
            /* [retval][out] */ double __RPC_FAR *result);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_eltype )( 
            IEndFixationEvent __RPC_FAR * This,
            /* [retval][out] */ EL_DATA_TYPE __RPC_FAR *result);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_eye )( 
            IEndFixationEvent __RPC_FAR * This,
            /* [retval][out] */ EL_EYE __RPC_FAR *eye);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_read )( 
            IEndFixationEvent __RPC_FAR * This,
            /* [retval][out] */ short __RPC_FAR *read);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_sttime )( 
            IEndFixationEvent __RPC_FAR * This,
            /* [retval][out] */ double __RPC_FAR *sttime);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_hstx )( 
            IEndFixationEvent __RPC_FAR * This,
            /* [retval][out] */ float __RPC_FAR *hstx);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_hsty )( 
            IEndFixationEvent __RPC_FAR * This,
            /* [retval][out] */ float __RPC_FAR *hsty);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_gstx )( 
            IEndFixationEvent __RPC_FAR * This,
            /* [retval][out] */ float __RPC_FAR *gstx);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_gsty )( 
            IEndFixationEvent __RPC_FAR * This,
            /* [retval][out] */ float __RPC_FAR *gsty);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_svel )( 
            IEndFixationEvent __RPC_FAR * This,
            /* [retval][out] */ float __RPC_FAR *svel);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_supd_x )( 
            IEndFixationEvent __RPC_FAR * This,
            /* [retval][out] */ float __RPC_FAR *supd_x);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_supd_y )( 
            IEndFixationEvent __RPC_FAR * This,
            /* [retval][out] */ float __RPC_FAR *supd_y);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_sta )( 
            IEndFixationEvent __RPC_FAR * This,
            /* [retval][out] */ float __RPC_FAR *sta);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_entime )( 
            IEndFixationEvent __RPC_FAR * This,
            /* [retval][out] */ double __RPC_FAR *entime);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_henx )( 
            IEndFixationEvent __RPC_FAR * This,
            /* [retval][out] */ float __RPC_FAR *henx);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_heny )( 
            IEndFixationEvent __RPC_FAR * This,
            /* [retval][out] */ float __RPC_FAR *heny);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_genx )( 
            IEndFixationEvent __RPC_FAR * This,
            /* [retval][out] */ float __RPC_FAR *genx);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_geny )( 
            IEndFixationEvent __RPC_FAR * This,
            /* [retval][out] */ float __RPC_FAR *geny);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_evel )( 
            IEndFixationEvent __RPC_FAR * This,
            /* [retval][out] */ float __RPC_FAR *evel);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_avel )( 
            IEndFixationEvent __RPC_FAR * This,
            /* [retval][out] */ float __RPC_FAR *avel);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_pvel )( 
            IEndFixationEvent __RPC_FAR * This,
            /* [retval][out] */ float __RPC_FAR *pvel);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_eupd_x )( 
            IEndFixationEvent __RPC_FAR * This,
            /* [retval][out] */ float __RPC_FAR *eupd_x);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_eupd_y )( 
            IEndFixationEvent __RPC_FAR * This,
            /* [retval][out] */ float __RPC_FAR *eupd_y);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ena )( 
            IEndFixationEvent __RPC_FAR * This,
            /* [retval][out] */ float __RPC_FAR *ena);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_havx )( 
            IEndFixationEvent __RPC_FAR * This,
            /* [retval][out] */ float __RPC_FAR *havx);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_havy )( 
            IEndFixationEvent __RPC_FAR * This,
            /* [retval][out] */ float __RPC_FAR *havy);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_gavx )( 
            IEndFixationEvent __RPC_FAR * This,
            /* [retval][out] */ float __RPC_FAR *gavx);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_gavy )( 
            IEndFixationEvent __RPC_FAR * This,
            /* [retval][out] */ float __RPC_FAR *gavy);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ava )( 
            IEndFixationEvent __RPC_FAR * This,
            /* [retval][out] */ float __RPC_FAR *ava);
        
        END_INTERFACE
    } IEndFixationEventVtbl;

    interface IEndFixationEvent
    {
        CONST_VTBL struct IEndFixationEventVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEndFixationEvent_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IEndFixationEvent_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IEndFixationEvent_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IEndFixationEvent_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IEndFixationEvent_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IEndFixationEvent_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IEndFixationEvent_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IEndFixationEvent_get_time(This,result)	\
    (This)->lpVtbl -> get_time(This,result)

#define IEndFixationEvent_get_eltype(This,result)	\
    (This)->lpVtbl -> get_eltype(This,result)


#define IEndFixationEvent_get_eye(This,eye)	\
    (This)->lpVtbl -> get_eye(This,eye)

#define IEndFixationEvent_get_read(This,read)	\
    (This)->lpVtbl -> get_read(This,read)

#define IEndFixationEvent_get_sttime(This,sttime)	\
    (This)->lpVtbl -> get_sttime(This,sttime)


#define IEndFixationEvent_get_hstx(This,hstx)	\
    (This)->lpVtbl -> get_hstx(This,hstx)

#define IEndFixationEvent_get_hsty(This,hsty)	\
    (This)->lpVtbl -> get_hsty(This,hsty)

#define IEndFixationEvent_get_gstx(This,gstx)	\
    (This)->lpVtbl -> get_gstx(This,gstx)

#define IEndFixationEvent_get_gsty(This,gsty)	\
    (This)->lpVtbl -> get_gsty(This,gsty)

#define IEndFixationEvent_get_svel(This,svel)	\
    (This)->lpVtbl -> get_svel(This,svel)

#define IEndFixationEvent_get_supd_x(This,supd_x)	\
    (This)->lpVtbl -> get_supd_x(This,supd_x)

#define IEndFixationEvent_get_supd_y(This,supd_y)	\
    (This)->lpVtbl -> get_supd_y(This,supd_y)

#define IEndFixationEvent_get_sta(This,sta)	\
    (This)->lpVtbl -> get_sta(This,sta)


#define IEndFixationEvent_get_entime(This,entime)	\
    (This)->lpVtbl -> get_entime(This,entime)

#define IEndFixationEvent_get_henx(This,henx)	\
    (This)->lpVtbl -> get_henx(This,henx)

#define IEndFixationEvent_get_heny(This,heny)	\
    (This)->lpVtbl -> get_heny(This,heny)

#define IEndFixationEvent_get_genx(This,genx)	\
    (This)->lpVtbl -> get_genx(This,genx)

#define IEndFixationEvent_get_geny(This,geny)	\
    (This)->lpVtbl -> get_geny(This,geny)

#define IEndFixationEvent_get_evel(This,evel)	\
    (This)->lpVtbl -> get_evel(This,evel)

#define IEndFixationEvent_get_avel(This,avel)	\
    (This)->lpVtbl -> get_avel(This,avel)

#define IEndFixationEvent_get_pvel(This,pvel)	\
    (This)->lpVtbl -> get_pvel(This,pvel)

#define IEndFixationEvent_get_eupd_x(This,eupd_x)	\
    (This)->lpVtbl -> get_eupd_x(This,eupd_x)

#define IEndFixationEvent_get_eupd_y(This,eupd_y)	\
    (This)->lpVtbl -> get_eupd_y(This,eupd_y)

#define IEndFixationEvent_get_ena(This,ena)	\
    (This)->lpVtbl -> get_ena(This,ena)

#define IEndFixationEvent_get_havx(This,havx)	\
    (This)->lpVtbl -> get_havx(This,havx)

#define IEndFixationEvent_get_havy(This,havy)	\
    (This)->lpVtbl -> get_havy(This,havy)

#define IEndFixationEvent_get_gavx(This,gavx)	\
    (This)->lpVtbl -> get_gavx(This,gavx)

#define IEndFixationEvent_get_gavy(This,gavy)	\
    (This)->lpVtbl -> get_gavy(This,gavy)

#define IEndFixationEvent_get_ava(This,ava)	\
    (This)->lpVtbl -> get_ava(This,ava)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IEndFixationEvent_get_entime_Proxy( 
    IEndFixationEvent __RPC_FAR * This,
    /* [retval][out] */ double __RPC_FAR *entime);


void __RPC_STUB IEndFixationEvent_get_entime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IEndFixationEvent_get_henx_Proxy( 
    IEndFixationEvent __RPC_FAR * This,
    /* [retval][out] */ float __RPC_FAR *henx);


void __RPC_STUB IEndFixationEvent_get_henx_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IEndFixationEvent_get_heny_Proxy( 
    IEndFixationEvent __RPC_FAR * This,
    /* [retval][out] */ float __RPC_FAR *heny);


void __RPC_STUB IEndFixationEvent_get_heny_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IEndFixationEvent_get_genx_Proxy( 
    IEndFixationEvent __RPC_FAR * This,
    /* [retval][out] */ float __RPC_FAR *genx);


void __RPC_STUB IEndFixationEvent_get_genx_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IEndFixationEvent_get_geny_Proxy( 
    IEndFixationEvent __RPC_FAR * This,
    /* [retval][out] */ float __RPC_FAR *geny);


void __RPC_STUB IEndFixationEvent_get_geny_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IEndFixationEvent_get_evel_Proxy( 
    IEndFixationEvent __RPC_FAR * This,
    /* [retval][out] */ float __RPC_FAR *evel);


void __RPC_STUB IEndFixationEvent_get_evel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IEndFixationEvent_get_avel_Proxy( 
    IEndFixationEvent __RPC_FAR * This,
    /* [retval][out] */ float __RPC_FAR *avel);


void __RPC_STUB IEndFixationEvent_get_avel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IEndFixationEvent_get_pvel_Proxy( 
    IEndFixationEvent __RPC_FAR * This,
    /* [retval][out] */ float __RPC_FAR *pvel);


void __RPC_STUB IEndFixationEvent_get_pvel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IEndFixationEvent_get_eupd_x_Proxy( 
    IEndFixationEvent __RPC_FAR * This,
    /* [retval][out] */ float __RPC_FAR *eupd_x);


void __RPC_STUB IEndFixationEvent_get_eupd_x_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IEndFixationEvent_get_eupd_y_Proxy( 
    IEndFixationEvent __RPC_FAR * This,
    /* [retval][out] */ float __RPC_FAR *eupd_y);


void __RPC_STUB IEndFixationEvent_get_eupd_y_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IEndFixationEvent_get_ena_Proxy( 
    IEndFixationEvent __RPC_FAR * This,
    /* [retval][out] */ float __RPC_FAR *ena);


void __RPC_STUB IEndFixationEvent_get_ena_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IEndFixationEvent_get_havx_Proxy( 
    IEndFixationEvent __RPC_FAR * This,
    /* [retval][out] */ float __RPC_FAR *havx);


void __RPC_STUB IEndFixationEvent_get_havx_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IEndFixationEvent_get_havy_Proxy( 
    IEndFixationEvent __RPC_FAR * This,
    /* [retval][out] */ float __RPC_FAR *havy);


void __RPC_STUB IEndFixationEvent_get_havy_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IEndFixationEvent_get_gavx_Proxy( 
    IEndFixationEvent __RPC_FAR * This,
    /* [retval][out] */ float __RPC_FAR *gavx);


void __RPC_STUB IEndFixationEvent_get_gavx_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IEndFixationEvent_get_gavy_Proxy( 
    IEndFixationEvent __RPC_FAR * This,
    /* [retval][out] */ float __RPC_FAR *gavy);


void __RPC_STUB IEndFixationEvent_get_gavy_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IEndFixationEvent_get_ava_Proxy( 
    IEndFixationEvent __RPC_FAR * This,
    /* [retval][out] */ float __RPC_FAR *ava);


void __RPC_STUB IEndFixationEvent_get_ava_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IEndFixationEvent_INTERFACE_DEFINED__ */


#ifndef __IFixUpdateEvent_INTERFACE_DEFINED__
#define __IFixUpdateEvent_INTERFACE_DEFINED__

/* interface IFixUpdateEvent */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IFixUpdateEvent;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C4299AF5-74F3-4495-B169-EB79E960FCAB")
    IFixUpdateEvent : public IEyeEvent
    {
    public:
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_hstx( 
            /* [retval][out] */ float __RPC_FAR *hstx) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_hsty( 
            /* [retval][out] */ float __RPC_FAR *hsty) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_gstx( 
            /* [retval][out] */ float __RPC_FAR *gstx) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_gsty( 
            /* [retval][out] */ float __RPC_FAR *gsty) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_svel( 
            /* [retval][out] */ float __RPC_FAR *svel) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_supd_x( 
            /* [retval][out] */ float __RPC_FAR *supd_x) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_supd_y( 
            /* [retval][out] */ float __RPC_FAR *supd_y) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_entime( 
            /* [retval][out] */ double __RPC_FAR *entime) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_henx( 
            /* [retval][out] */ float __RPC_FAR *henx) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_heny( 
            /* [retval][out] */ float __RPC_FAR *heny) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_genx( 
            /* [retval][out] */ float __RPC_FAR *genx) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_geny( 
            /* [retval][out] */ float __RPC_FAR *geny) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_evel( 
            /* [retval][out] */ float __RPC_FAR *evel) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_avel( 
            /* [retval][out] */ float __RPC_FAR *avel) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_pvel( 
            /* [retval][out] */ float __RPC_FAR *pvel) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_eupd_x( 
            /* [retval][out] */ float __RPC_FAR *eupd_x) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_eupd_y( 
            /* [retval][out] */ float __RPC_FAR *eupd_y) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_ena( 
            /* [retval][out] */ float __RPC_FAR *ena) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_havx( 
            /* [retval][out] */ float __RPC_FAR *havx) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_havy( 
            /* [retval][out] */ float __RPC_FAR *havy) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_gavx( 
            /* [retval][out] */ float __RPC_FAR *gavx) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_gavy( 
            /* [retval][out] */ float __RPC_FAR *gavy) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_ava( 
            /* [retval][out] */ float __RPC_FAR *ava) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_sta( 
            /* [retval][out] */ float __RPC_FAR *sta) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IFixUpdateEventVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IFixUpdateEvent __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IFixUpdateEvent __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IFixUpdateEvent __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IFixUpdateEvent __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IFixUpdateEvent __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IFixUpdateEvent __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IFixUpdateEvent __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_time )( 
            IFixUpdateEvent __RPC_FAR * This,
            /* [retval][out] */ double __RPC_FAR *result);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_eltype )( 
            IFixUpdateEvent __RPC_FAR * This,
            /* [retval][out] */ EL_DATA_TYPE __RPC_FAR *result);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_eye )( 
            IFixUpdateEvent __RPC_FAR * This,
            /* [retval][out] */ EL_EYE __RPC_FAR *eye);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_read )( 
            IFixUpdateEvent __RPC_FAR * This,
            /* [retval][out] */ short __RPC_FAR *read);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_sttime )( 
            IFixUpdateEvent __RPC_FAR * This,
            /* [retval][out] */ double __RPC_FAR *sttime);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_hstx )( 
            IFixUpdateEvent __RPC_FAR * This,
            /* [retval][out] */ float __RPC_FAR *hstx);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_hsty )( 
            IFixUpdateEvent __RPC_FAR * This,
            /* [retval][out] */ float __RPC_FAR *hsty);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_gstx )( 
            IFixUpdateEvent __RPC_FAR * This,
            /* [retval][out] */ float __RPC_FAR *gstx);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_gsty )( 
            IFixUpdateEvent __RPC_FAR * This,
            /* [retval][out] */ float __RPC_FAR *gsty);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_svel )( 
            IFixUpdateEvent __RPC_FAR * This,
            /* [retval][out] */ float __RPC_FAR *svel);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_supd_x )( 
            IFixUpdateEvent __RPC_FAR * This,
            /* [retval][out] */ float __RPC_FAR *supd_x);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_supd_y )( 
            IFixUpdateEvent __RPC_FAR * This,
            /* [retval][out] */ float __RPC_FAR *supd_y);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_entime )( 
            IFixUpdateEvent __RPC_FAR * This,
            /* [retval][out] */ double __RPC_FAR *entime);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_henx )( 
            IFixUpdateEvent __RPC_FAR * This,
            /* [retval][out] */ float __RPC_FAR *henx);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_heny )( 
            IFixUpdateEvent __RPC_FAR * This,
            /* [retval][out] */ float __RPC_FAR *heny);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_genx )( 
            IFixUpdateEvent __RPC_FAR * This,
            /* [retval][out] */ float __RPC_FAR *genx);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_geny )( 
            IFixUpdateEvent __RPC_FAR * This,
            /* [retval][out] */ float __RPC_FAR *geny);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_evel )( 
            IFixUpdateEvent __RPC_FAR * This,
            /* [retval][out] */ float __RPC_FAR *evel);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_avel )( 
            IFixUpdateEvent __RPC_FAR * This,
            /* [retval][out] */ float __RPC_FAR *avel);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_pvel )( 
            IFixUpdateEvent __RPC_FAR * This,
            /* [retval][out] */ float __RPC_FAR *pvel);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_eupd_x )( 
            IFixUpdateEvent __RPC_FAR * This,
            /* [retval][out] */ float __RPC_FAR *eupd_x);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_eupd_y )( 
            IFixUpdateEvent __RPC_FAR * This,
            /* [retval][out] */ float __RPC_FAR *eupd_y);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ena )( 
            IFixUpdateEvent __RPC_FAR * This,
            /* [retval][out] */ float __RPC_FAR *ena);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_havx )( 
            IFixUpdateEvent __RPC_FAR * This,
            /* [retval][out] */ float __RPC_FAR *havx);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_havy )( 
            IFixUpdateEvent __RPC_FAR * This,
            /* [retval][out] */ float __RPC_FAR *havy);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_gavx )( 
            IFixUpdateEvent __RPC_FAR * This,
            /* [retval][out] */ float __RPC_FAR *gavx);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_gavy )( 
            IFixUpdateEvent __RPC_FAR * This,
            /* [retval][out] */ float __RPC_FAR *gavy);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ava )( 
            IFixUpdateEvent __RPC_FAR * This,
            /* [retval][out] */ float __RPC_FAR *ava);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_sta )( 
            IFixUpdateEvent __RPC_FAR * This,
            /* [retval][out] */ float __RPC_FAR *sta);
        
        END_INTERFACE
    } IFixUpdateEventVtbl;

    interface IFixUpdateEvent
    {
        CONST_VTBL struct IFixUpdateEventVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFixUpdateEvent_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IFixUpdateEvent_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IFixUpdateEvent_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IFixUpdateEvent_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IFixUpdateEvent_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IFixUpdateEvent_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IFixUpdateEvent_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IFixUpdateEvent_get_time(This,result)	\
    (This)->lpVtbl -> get_time(This,result)

#define IFixUpdateEvent_get_eltype(This,result)	\
    (This)->lpVtbl -> get_eltype(This,result)


#define IFixUpdateEvent_get_eye(This,eye)	\
    (This)->lpVtbl -> get_eye(This,eye)

#define IFixUpdateEvent_get_read(This,read)	\
    (This)->lpVtbl -> get_read(This,read)

#define IFixUpdateEvent_get_sttime(This,sttime)	\
    (This)->lpVtbl -> get_sttime(This,sttime)


#define IFixUpdateEvent_get_hstx(This,hstx)	\
    (This)->lpVtbl -> get_hstx(This,hstx)

#define IFixUpdateEvent_get_hsty(This,hsty)	\
    (This)->lpVtbl -> get_hsty(This,hsty)

#define IFixUpdateEvent_get_gstx(This,gstx)	\
    (This)->lpVtbl -> get_gstx(This,gstx)

#define IFixUpdateEvent_get_gsty(This,gsty)	\
    (This)->lpVtbl -> get_gsty(This,gsty)

#define IFixUpdateEvent_get_svel(This,svel)	\
    (This)->lpVtbl -> get_svel(This,svel)

#define IFixUpdateEvent_get_supd_x(This,supd_x)	\
    (This)->lpVtbl -> get_supd_x(This,supd_x)

#define IFixUpdateEvent_get_supd_y(This,supd_y)	\
    (This)->lpVtbl -> get_supd_y(This,supd_y)

#define IFixUpdateEvent_get_entime(This,entime)	\
    (This)->lpVtbl -> get_entime(This,entime)

#define IFixUpdateEvent_get_henx(This,henx)	\
    (This)->lpVtbl -> get_henx(This,henx)

#define IFixUpdateEvent_get_heny(This,heny)	\
    (This)->lpVtbl -> get_heny(This,heny)

#define IFixUpdateEvent_get_genx(This,genx)	\
    (This)->lpVtbl -> get_genx(This,genx)

#define IFixUpdateEvent_get_geny(This,geny)	\
    (This)->lpVtbl -> get_geny(This,geny)

#define IFixUpdateEvent_get_evel(This,evel)	\
    (This)->lpVtbl -> get_evel(This,evel)

#define IFixUpdateEvent_get_avel(This,avel)	\
    (This)->lpVtbl -> get_avel(This,avel)

#define IFixUpdateEvent_get_pvel(This,pvel)	\
    (This)->lpVtbl -> get_pvel(This,pvel)

#define IFixUpdateEvent_get_eupd_x(This,eupd_x)	\
    (This)->lpVtbl -> get_eupd_x(This,eupd_x)

#define IFixUpdateEvent_get_eupd_y(This,eupd_y)	\
    (This)->lpVtbl -> get_eupd_y(This,eupd_y)

#define IFixUpdateEvent_get_ena(This,ena)	\
    (This)->lpVtbl -> get_ena(This,ena)

#define IFixUpdateEvent_get_havx(This,havx)	\
    (This)->lpVtbl -> get_havx(This,havx)

#define IFixUpdateEvent_get_havy(This,havy)	\
    (This)->lpVtbl -> get_havy(This,havy)

#define IFixUpdateEvent_get_gavx(This,gavx)	\
    (This)->lpVtbl -> get_gavx(This,gavx)

#define IFixUpdateEvent_get_gavy(This,gavy)	\
    (This)->lpVtbl -> get_gavy(This,gavy)

#define IFixUpdateEvent_get_ava(This,ava)	\
    (This)->lpVtbl -> get_ava(This,ava)

#define IFixUpdateEvent_get_sta(This,sta)	\
    (This)->lpVtbl -> get_sta(This,sta)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IFixUpdateEvent_get_hstx_Proxy( 
    IFixUpdateEvent __RPC_FAR * This,
    /* [retval][out] */ float __RPC_FAR *hstx);


void __RPC_STUB IFixUpdateEvent_get_hstx_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IFixUpdateEvent_get_hsty_Proxy( 
    IFixUpdateEvent __RPC_FAR * This,
    /* [retval][out] */ float __RPC_FAR *hsty);


void __RPC_STUB IFixUpdateEvent_get_hsty_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IFixUpdateEvent_get_gstx_Proxy( 
    IFixUpdateEvent __RPC_FAR * This,
    /* [retval][out] */ float __RPC_FAR *gstx);


void __RPC_STUB IFixUpdateEvent_get_gstx_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IFixUpdateEvent_get_gsty_Proxy( 
    IFixUpdateEvent __RPC_FAR * This,
    /* [retval][out] */ float __RPC_FAR *gsty);


void __RPC_STUB IFixUpdateEvent_get_gsty_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IFixUpdateEvent_get_svel_Proxy( 
    IFixUpdateEvent __RPC_FAR * This,
    /* [retval][out] */ float __RPC_FAR *svel);


void __RPC_STUB IFixUpdateEvent_get_svel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IFixUpdateEvent_get_supd_x_Proxy( 
    IFixUpdateEvent __RPC_FAR * This,
    /* [retval][out] */ float __RPC_FAR *supd_x);


void __RPC_STUB IFixUpdateEvent_get_supd_x_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IFixUpdateEvent_get_supd_y_Proxy( 
    IFixUpdateEvent __RPC_FAR * This,
    /* [retval][out] */ float __RPC_FAR *supd_y);


void __RPC_STUB IFixUpdateEvent_get_supd_y_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IFixUpdateEvent_get_entime_Proxy( 
    IFixUpdateEvent __RPC_FAR * This,
    /* [retval][out] */ double __RPC_FAR *entime);


void __RPC_STUB IFixUpdateEvent_get_entime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IFixUpdateEvent_get_henx_Proxy( 
    IFixUpdateEvent __RPC_FAR * This,
    /* [retval][out] */ float __RPC_FAR *henx);


void __RPC_STUB IFixUpdateEvent_get_henx_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IFixUpdateEvent_get_heny_Proxy( 
    IFixUpdateEvent __RPC_FAR * This,
    /* [retval][out] */ float __RPC_FAR *heny);


void __RPC_STUB IFixUpdateEvent_get_heny_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IFixUpdateEvent_get_genx_Proxy( 
    IFixUpdateEvent __RPC_FAR * This,
    /* [retval][out] */ float __RPC_FAR *genx);


void __RPC_STUB IFixUpdateEvent_get_genx_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IFixUpdateEvent_get_geny_Proxy( 
    IFixUpdateEvent __RPC_FAR * This,
    /* [retval][out] */ float __RPC_FAR *geny);


void __RPC_STUB IFixUpdateEvent_get_geny_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IFixUpdateEvent_get_evel_Proxy( 
    IFixUpdateEvent __RPC_FAR * This,
    /* [retval][out] */ float __RPC_FAR *evel);


void __RPC_STUB IFixUpdateEvent_get_evel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IFixUpdateEvent_get_avel_Proxy( 
    IFixUpdateEvent __RPC_FAR * This,
    /* [retval][out] */ float __RPC_FAR *avel);


void __RPC_STUB IFixUpdateEvent_get_avel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IFixUpdateEvent_get_pvel_Proxy( 
    IFixUpdateEvent __RPC_FAR * This,
    /* [retval][out] */ float __RPC_FAR *pvel);


void __RPC_STUB IFixUpdateEvent_get_pvel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IFixUpdateEvent_get_eupd_x_Proxy( 
    IFixUpdateEvent __RPC_FAR * This,
    /* [retval][out] */ float __RPC_FAR *eupd_x);


void __RPC_STUB IFixUpdateEvent_get_eupd_x_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IFixUpdateEvent_get_eupd_y_Proxy( 
    IFixUpdateEvent __RPC_FAR * This,
    /* [retval][out] */ float __RPC_FAR *eupd_y);


void __RPC_STUB IFixUpdateEvent_get_eupd_y_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IFixUpdateEvent_get_ena_Proxy( 
    IFixUpdateEvent __RPC_FAR * This,
    /* [retval][out] */ float __RPC_FAR *ena);


void __RPC_STUB IFixUpdateEvent_get_ena_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IFixUpdateEvent_get_havx_Proxy( 
    IFixUpdateEvent __RPC_FAR * This,
    /* [retval][out] */ float __RPC_FAR *havx);


void __RPC_STUB IFixUpdateEvent_get_havx_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IFixUpdateEvent_get_havy_Proxy( 
    IFixUpdateEvent __RPC_FAR * This,
    /* [retval][out] */ float __RPC_FAR *havy);


void __RPC_STUB IFixUpdateEvent_get_havy_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IFixUpdateEvent_get_gavx_Proxy( 
    IFixUpdateEvent __RPC_FAR * This,
    /* [retval][out] */ float __RPC_FAR *gavx);


void __RPC_STUB IFixUpdateEvent_get_gavx_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IFixUpdateEvent_get_gavy_Proxy( 
    IFixUpdateEvent __RPC_FAR * This,
    /* [retval][out] */ float __RPC_FAR *gavy);


void __RPC_STUB IFixUpdateEvent_get_gavy_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IFixUpdateEvent_get_ava_Proxy( 
    IFixUpdateEvent __RPC_FAR * This,
    /* [retval][out] */ float __RPC_FAR *ava);


void __RPC_STUB IFixUpdateEvent_get_ava_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IFixUpdateEvent_get_sta_Proxy( 
    IFixUpdateEvent __RPC_FAR * This,
    /* [retval][out] */ float __RPC_FAR *sta);


void __RPC_STUB IFixUpdateEvent_get_sta_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IFixUpdateEvent_INTERFACE_DEFINED__ */


#ifndef __IEyeLink_INTERFACE_DEFINED__
#define __IEyeLink_INTERFACE_DEFINED__

/* interface IEyeLink */
/* [unique][helpstring][dual][uuid][object] */ 

typedef /* [v1_enum] */ 
enum EL_TRIAL_RESULT
    {	EL_DONE_TRIAL	= 0,
	EL_TRIAL_OK	= 0,
	EL_REPEAT_TRIAL	= 1,
	EL_SKIP_TRIAL	= 2,
	EL_ABORT_EXPT	= 3,
	EL_TRIAL_ERROR	= -1
    }	EL_TRIAL_RESULT;


EXTERN_C const IID IID_IEyeLink;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("5A58A2E8-4BFD-46A4-A1FF-CA5CA7CDDF62")
    IEyeLink : public IDispatch
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE open( 
            /* [optional][in] */ BSTR hostAddress,
            /* [optional][in] */ short busyTest) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE dummyOpen( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE getNextData( 
            /* [retval][out] */ IELData __RPC_FAR *__RPC_FAR *result) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE close( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE reset( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE stopRecording( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE doTrackerSetup( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE startRecording( 
            /* [in] */ VARIANT_BOOL file_samples,
            /* [in] */ VARIANT_BOOL file_events,
            /* [in] */ VARIANT_BOOL link_samples,
            /* [in] */ VARIANT_BOOL link_events) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE doDriftCorrect( 
            /* [in] */ short x,
            /* [in] */ short y,
            /* [in] */ VARIANT_BOOL draw,
            /* [in] */ VARIANT_BOOL allowSetup) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE doDriftCorrectEx( 
            /* [in] */ short x,
            /* [in] */ short y,
            /* [in] */ VARIANT_BOOL draw,
            /* [in] */ VARIANT_BOOL allow_setup,
            /* [retval][out] */ short __RPC_FAR *ret) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE isConnected( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *result) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE getTrackerVersion( 
            /* [retval][out] */ short __RPC_FAR *verNum) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE setOfflineMode( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE sendCommand( 
            /* [in] */ BSTR cmd) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE sendTimedCommand( 
            /* [in] */ int duration,
            /* [in] */ BSTR command) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE sendMessage( 
            /* [in] */ BSTR msg) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE getKey( 
            /* [retval][out] */ short __RPC_FAR *result) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE abort( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE commandResult( 
            /* [retval][out] */ short __RPC_FAR *result) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE inSetup( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *result) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE getCalibrationResult( 
            /* [retval][out] */ short __RPC_FAR *result) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE applyDriftCorrect( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE startSetup( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE getTrackerVersionString( 
            /* [retval][out] */ BSTR __RPC_FAR *verStr) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE getLastMessage( 
            /* [retval][out] */ BSTR __RPC_FAR *result) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE readRequest( 
            /* [in] */ BSTR sys_var) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE readReply( 
            /* [retval][out] */ BSTR __RPC_FAR *result) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE getCalibrationMessage( 
            /* [retval][out] */ BSTR __RPC_FAR *result) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE getNewestSample( 
            /* [retval][out] */ ISample __RPC_FAR *__RPC_FAR *result) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE trackerTime( 
            /* [retval][out] */ double __RPC_FAR *result) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE trackerTimeOffset( 
            /* [retval][out] */ double __RPC_FAR *result) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE trackerTimeUsec( 
            /* [retval][out] */ double __RPC_FAR *result) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE trackerTimeUsecOffset( 
            /* [retval][out] */ double __RPC_FAR *result) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE eyeAvailable( 
            /* [retval][out] */ short __RPC_FAR *result) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE getCurrentMode( 
            /* [retval][out] */ short __RPC_FAR *result) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE getEventDataFlags( 
            /* [retval][out] */ short __RPC_FAR *result) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE getEventTypeFlags( 
            /* [retval][out] */ short __RPC_FAR *result) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE flushKeybuttons( 
            /* [in] */ VARIANT_BOOL enable_button_queue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE waitForModeReady( 
            /* [in] */ int max_wait,
            /* [retval][out] */ short __RPC_FAR *result) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE exitCalibration( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE resetData( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE getTrackerMode( 
            /* [retval][out] */ short __RPC_FAR *result) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE readKeyQueue( 
            /* [retval][out] */ short __RPC_FAR *result) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE acceptTrigger( 
            /* [retval][out] */ short __RPC_FAR *result) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE startDriftCorrect( 
            /* [in] */ short x,
            /* [in] */ short y) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE setName( 
            /* [in] */ BSTR name) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE stopData( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE startPlayBack( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE stopPlayBack( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE isRecording( 
            /* [retval][out] */ EL_TRIAL_RESULT __RPC_FAR *result) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE getRecordingStatus( 
            /* [retval][out] */ EL_TRIAL_RESULT __RPC_FAR *result) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE startData( 
            /* [in] */ short flags,
            /* [in] */ VARIANT_BOOL lock) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE openDataFile( 
            BSTR fname) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE closeDataFile( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE escapePressed( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *result) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE breakPressed( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *result) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE terminalBreak( 
            /* [in] */ VARIANT_BOOL assert) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE getLastButtonPress( 
            /* [optional][out] */ double __RPC_FAR *time,
            /* [retval][out] */ short __RPC_FAR *button) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE pumpMessages( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE readKeyButton( 
            /* [out] */ short __RPC_FAR *mods,
            /* [out] */ short __RPC_FAR *state,
            /* [out] */ short __RPC_FAR *kcode,
            /* [out] */ double __RPC_FAR *time,
            /* [out] */ short __RPC_FAR *scan) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE receiveDataFile( 
            /* [in] */ BSTR src,
            /* [in] */ BSTR dest) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE userMenuSelection( 
            /* [retval][out] */ short __RPC_FAR *result) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE getButtonStates( 
            /* [retval][out] */ short __RPC_FAR *result) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE getDataCount( 
            /* [in] */ VARIANT_BOOL samples,
            /* [in] */ VARIANT_BOOL events,
            /* [retval][out] */ short __RPC_FAR *count) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE isInDataBlock( 
            /* [in] */ VARIANT_BOOL samples,
            /* [in] */ VARIANT_BOOL events,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *ret) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE waitForBlockStart( 
            /* [in] */ int max_wait,
            /* [in] */ VARIANT_BOOL samples,
            /* [in] */ VARIANT_BOOL events,
            /* [retval][out] */ short __RPC_FAR *result) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE waitForData( 
            /* [in] */ int max_wait,
            /* [in] */ VARIANT_BOOL samples,
            /* [in] */ VARIANT_BOOL events,
            /* [retval][out] */ short __RPC_FAR *result) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE sendKeybutton( 
            /* [in] */ int kcode,
            /* [in] */ short mod,
            /* [in] */ short state) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE getTargetPositionAndState( 
            /* [out] */ short __RPC_FAR *x,
            /* [out] */ short __RPC_FAR *y,
            /* [out] */ VARIANT_BOOL __RPC_FAR *visible) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE getModeData( 
            /* [out] */ short __RPC_FAR *sample_rate,
            /* [out] */ short __RPC_FAR *crmode,
            /* [out] */ short __RPC_FAR *file_filter,
            /* [out] */ short __RPC_FAR *link_filter) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE getSampleDataFlags( 
            /* [retval][out] */ short __RPC_FAR *result) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE echoKey( 
            /* [retval][out] */ short __RPC_FAR *result) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SendImageToTracker( 
            /* [in] */ IPicture __RPC_FAR *pImage,
            /* [in] */ FEROPTIONS xferoptions) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE BitmapToBackdrop( 
            /* [in] */ BSTR fname,
            /* [in] */ FEROPTIONS xferoptions) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IEyeLinkVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IEyeLink __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IEyeLink __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IEyeLink __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IEyeLink __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IEyeLink __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IEyeLink __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IEyeLink __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *open )( 
            IEyeLink __RPC_FAR * This,
            /* [optional][in] */ BSTR hostAddress,
            /* [optional][in] */ short busyTest);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *dummyOpen )( 
            IEyeLink __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *getNextData )( 
            IEyeLink __RPC_FAR * This,
            /* [retval][out] */ IELData __RPC_FAR *__RPC_FAR *result);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *close )( 
            IEyeLink __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *reset )( 
            IEyeLink __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *stopRecording )( 
            IEyeLink __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *doTrackerSetup )( 
            IEyeLink __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *startRecording )( 
            IEyeLink __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL file_samples,
            /* [in] */ VARIANT_BOOL file_events,
            /* [in] */ VARIANT_BOOL link_samples,
            /* [in] */ VARIANT_BOOL link_events);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *doDriftCorrect )( 
            IEyeLink __RPC_FAR * This,
            /* [in] */ short x,
            /* [in] */ short y,
            /* [in] */ VARIANT_BOOL draw,
            /* [in] */ VARIANT_BOOL allowSetup);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *doDriftCorrectEx )( 
            IEyeLink __RPC_FAR * This,
            /* [in] */ short x,
            /* [in] */ short y,
            /* [in] */ VARIANT_BOOL draw,
            /* [in] */ VARIANT_BOOL allow_setup,
            /* [retval][out] */ short __RPC_FAR *ret);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *isConnected )( 
            IEyeLink __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *result);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *getTrackerVersion )( 
            IEyeLink __RPC_FAR * This,
            /* [retval][out] */ short __RPC_FAR *verNum);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *setOfflineMode )( 
            IEyeLink __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *sendCommand )( 
            IEyeLink __RPC_FAR * This,
            /* [in] */ BSTR cmd);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *sendTimedCommand )( 
            IEyeLink __RPC_FAR * This,
            /* [in] */ int duration,
            /* [in] */ BSTR command);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *sendMessage )( 
            IEyeLink __RPC_FAR * This,
            /* [in] */ BSTR msg);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *getKey )( 
            IEyeLink __RPC_FAR * This,
            /* [retval][out] */ short __RPC_FAR *result);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *abort )( 
            IEyeLink __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *commandResult )( 
            IEyeLink __RPC_FAR * This,
            /* [retval][out] */ short __RPC_FAR *result);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *inSetup )( 
            IEyeLink __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *result);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *getCalibrationResult )( 
            IEyeLink __RPC_FAR * This,
            /* [retval][out] */ short __RPC_FAR *result);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *applyDriftCorrect )( 
            IEyeLink __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *startSetup )( 
            IEyeLink __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *getTrackerVersionString )( 
            IEyeLink __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *verStr);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *getLastMessage )( 
            IEyeLink __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *result);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *readRequest )( 
            IEyeLink __RPC_FAR * This,
            /* [in] */ BSTR sys_var);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *readReply )( 
            IEyeLink __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *result);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *getCalibrationMessage )( 
            IEyeLink __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *result);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *getNewestSample )( 
            IEyeLink __RPC_FAR * This,
            /* [retval][out] */ ISample __RPC_FAR *__RPC_FAR *result);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *trackerTime )( 
            IEyeLink __RPC_FAR * This,
            /* [retval][out] */ double __RPC_FAR *result);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *trackerTimeOffset )( 
            IEyeLink __RPC_FAR * This,
            /* [retval][out] */ double __RPC_FAR *result);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *trackerTimeUsec )( 
            IEyeLink __RPC_FAR * This,
            /* [retval][out] */ double __RPC_FAR *result);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *trackerTimeUsecOffset )( 
            IEyeLink __RPC_FAR * This,
            /* [retval][out] */ double __RPC_FAR *result);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *eyeAvailable )( 
            IEyeLink __RPC_FAR * This,
            /* [retval][out] */ short __RPC_FAR *result);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *getCurrentMode )( 
            IEyeLink __RPC_FAR * This,
            /* [retval][out] */ short __RPC_FAR *result);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *getEventDataFlags )( 
            IEyeLink __RPC_FAR * This,
            /* [retval][out] */ short __RPC_FAR *result);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *getEventTypeFlags )( 
            IEyeLink __RPC_FAR * This,
            /* [retval][out] */ short __RPC_FAR *result);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *flushKeybuttons )( 
            IEyeLink __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL enable_button_queue);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *waitForModeReady )( 
            IEyeLink __RPC_FAR * This,
            /* [in] */ int max_wait,
            /* [retval][out] */ short __RPC_FAR *result);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *exitCalibration )( 
            IEyeLink __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *resetData )( 
            IEyeLink __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *getTrackerMode )( 
            IEyeLink __RPC_FAR * This,
            /* [retval][out] */ short __RPC_FAR *result);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *readKeyQueue )( 
            IEyeLink __RPC_FAR * This,
            /* [retval][out] */ short __RPC_FAR *result);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *acceptTrigger )( 
            IEyeLink __RPC_FAR * This,
            /* [retval][out] */ short __RPC_FAR *result);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *startDriftCorrect )( 
            IEyeLink __RPC_FAR * This,
            /* [in] */ short x,
            /* [in] */ short y);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *setName )( 
            IEyeLink __RPC_FAR * This,
            /* [in] */ BSTR name);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *stopData )( 
            IEyeLink __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *startPlayBack )( 
            IEyeLink __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *stopPlayBack )( 
            IEyeLink __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *isRecording )( 
            IEyeLink __RPC_FAR * This,
            /* [retval][out] */ EL_TRIAL_RESULT __RPC_FAR *result);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *getRecordingStatus )( 
            IEyeLink __RPC_FAR * This,
            /* [retval][out] */ EL_TRIAL_RESULT __RPC_FAR *result);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *startData )( 
            IEyeLink __RPC_FAR * This,
            /* [in] */ short flags,
            /* [in] */ VARIANT_BOOL lock);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *openDataFile )( 
            IEyeLink __RPC_FAR * This,
            BSTR fname);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *closeDataFile )( 
            IEyeLink __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *escapePressed )( 
            IEyeLink __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *result);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *breakPressed )( 
            IEyeLink __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *result);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *terminalBreak )( 
            IEyeLink __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL assert);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *getLastButtonPress )( 
            IEyeLink __RPC_FAR * This,
            /* [optional][out] */ double __RPC_FAR *time,
            /* [retval][out] */ short __RPC_FAR *button);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *pumpMessages )( 
            IEyeLink __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *readKeyButton )( 
            IEyeLink __RPC_FAR * This,
            /* [out] */ short __RPC_FAR *mods,
            /* [out] */ short __RPC_FAR *state,
            /* [out] */ short __RPC_FAR *kcode,
            /* [out] */ double __RPC_FAR *time,
            /* [out] */ short __RPC_FAR *scan);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *receiveDataFile )( 
            IEyeLink __RPC_FAR * This,
            /* [in] */ BSTR src,
            /* [in] */ BSTR dest);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *userMenuSelection )( 
            IEyeLink __RPC_FAR * This,
            /* [retval][out] */ short __RPC_FAR *result);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *getButtonStates )( 
            IEyeLink __RPC_FAR * This,
            /* [retval][out] */ short __RPC_FAR *result);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *getDataCount )( 
            IEyeLink __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL samples,
            /* [in] */ VARIANT_BOOL events,
            /* [retval][out] */ short __RPC_FAR *count);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *isInDataBlock )( 
            IEyeLink __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL samples,
            /* [in] */ VARIANT_BOOL events,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *ret);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *waitForBlockStart )( 
            IEyeLink __RPC_FAR * This,
            /* [in] */ int max_wait,
            /* [in] */ VARIANT_BOOL samples,
            /* [in] */ VARIANT_BOOL events,
            /* [retval][out] */ short __RPC_FAR *result);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *waitForData )( 
            IEyeLink __RPC_FAR * This,
            /* [in] */ int max_wait,
            /* [in] */ VARIANT_BOOL samples,
            /* [in] */ VARIANT_BOOL events,
            /* [retval][out] */ short __RPC_FAR *result);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *sendKeybutton )( 
            IEyeLink __RPC_FAR * This,
            /* [in] */ int kcode,
            /* [in] */ short mod,
            /* [in] */ short state);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *getTargetPositionAndState )( 
            IEyeLink __RPC_FAR * This,
            /* [out] */ short __RPC_FAR *x,
            /* [out] */ short __RPC_FAR *y,
            /* [out] */ VARIANT_BOOL __RPC_FAR *visible);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *getModeData )( 
            IEyeLink __RPC_FAR * This,
            /* [out] */ short __RPC_FAR *sample_rate,
            /* [out] */ short __RPC_FAR *crmode,
            /* [out] */ short __RPC_FAR *file_filter,
            /* [out] */ short __RPC_FAR *link_filter);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *getSampleDataFlags )( 
            IEyeLink __RPC_FAR * This,
            /* [retval][out] */ short __RPC_FAR *result);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *echoKey )( 
            IEyeLink __RPC_FAR * This,
            /* [retval][out] */ short __RPC_FAR *result);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SendImageToTracker )( 
            IEyeLink __RPC_FAR * This,
            /* [in] */ IPicture __RPC_FAR *pImage,
            /* [in] */ FEROPTIONS xferoptions);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *BitmapToBackdrop )( 
            IEyeLink __RPC_FAR * This,
            /* [in] */ BSTR fname,
            /* [in] */ FEROPTIONS xferoptions);
        
        END_INTERFACE
    } IEyeLinkVtbl;

    interface IEyeLink
    {
        CONST_VTBL struct IEyeLinkVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEyeLink_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IEyeLink_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IEyeLink_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IEyeLink_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IEyeLink_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IEyeLink_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IEyeLink_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IEyeLink_open(This,hostAddress,busyTest)	\
    (This)->lpVtbl -> open(This,hostAddress,busyTest)

#define IEyeLink_dummyOpen(This)	\
    (This)->lpVtbl -> dummyOpen(This)

#define IEyeLink_getNextData(This,result)	\
    (This)->lpVtbl -> getNextData(This,result)

#define IEyeLink_close(This)	\
    (This)->lpVtbl -> close(This)

#define IEyeLink_reset(This)	\
    (This)->lpVtbl -> reset(This)

#define IEyeLink_stopRecording(This)	\
    (This)->lpVtbl -> stopRecording(This)

#define IEyeLink_doTrackerSetup(This)	\
    (This)->lpVtbl -> doTrackerSetup(This)

#define IEyeLink_startRecording(This,file_samples,file_events,link_samples,link_events)	\
    (This)->lpVtbl -> startRecording(This,file_samples,file_events,link_samples,link_events)

#define IEyeLink_doDriftCorrect(This,x,y,draw,allowSetup)	\
    (This)->lpVtbl -> doDriftCorrect(This,x,y,draw,allowSetup)

#define IEyeLink_doDriftCorrectEx(This,x,y,draw,allow_setup,ret)	\
    (This)->lpVtbl -> doDriftCorrectEx(This,x,y,draw,allow_setup,ret)

#define IEyeLink_isConnected(This,result)	\
    (This)->lpVtbl -> isConnected(This,result)

#define IEyeLink_getTrackerVersion(This,verNum)	\
    (This)->lpVtbl -> getTrackerVersion(This,verNum)

#define IEyeLink_setOfflineMode(This)	\
    (This)->lpVtbl -> setOfflineMode(This)

#define IEyeLink_sendCommand(This,cmd)	\
    (This)->lpVtbl -> sendCommand(This,cmd)

#define IEyeLink_sendTimedCommand(This,duration,command)	\
    (This)->lpVtbl -> sendTimedCommand(This,duration,command)

#define IEyeLink_sendMessage(This,msg)	\
    (This)->lpVtbl -> sendMessage(This,msg)

#define IEyeLink_getKey(This,result)	\
    (This)->lpVtbl -> getKey(This,result)

#define IEyeLink_abort(This)	\
    (This)->lpVtbl -> abort(This)

#define IEyeLink_commandResult(This,result)	\
    (This)->lpVtbl -> commandResult(This,result)

#define IEyeLink_inSetup(This,result)	\
    (This)->lpVtbl -> inSetup(This,result)

#define IEyeLink_getCalibrationResult(This,result)	\
    (This)->lpVtbl -> getCalibrationResult(This,result)

#define IEyeLink_applyDriftCorrect(This)	\
    (This)->lpVtbl -> applyDriftCorrect(This)

#define IEyeLink_startSetup(This)	\
    (This)->lpVtbl -> startSetup(This)

#define IEyeLink_getTrackerVersionString(This,verStr)	\
    (This)->lpVtbl -> getTrackerVersionString(This,verStr)

#define IEyeLink_getLastMessage(This,result)	\
    (This)->lpVtbl -> getLastMessage(This,result)

#define IEyeLink_readRequest(This,sys_var)	\
    (This)->lpVtbl -> readRequest(This,sys_var)

#define IEyeLink_readReply(This,result)	\
    (This)->lpVtbl -> readReply(This,result)

#define IEyeLink_getCalibrationMessage(This,result)	\
    (This)->lpVtbl -> getCalibrationMessage(This,result)

#define IEyeLink_getNewestSample(This,result)	\
    (This)->lpVtbl -> getNewestSample(This,result)

#define IEyeLink_trackerTime(This,result)	\
    (This)->lpVtbl -> trackerTime(This,result)

#define IEyeLink_trackerTimeOffset(This,result)	\
    (This)->lpVtbl -> trackerTimeOffset(This,result)

#define IEyeLink_trackerTimeUsec(This,result)	\
    (This)->lpVtbl -> trackerTimeUsec(This,result)

#define IEyeLink_trackerTimeUsecOffset(This,result)	\
    (This)->lpVtbl -> trackerTimeUsecOffset(This,result)

#define IEyeLink_eyeAvailable(This,result)	\
    (This)->lpVtbl -> eyeAvailable(This,result)

#define IEyeLink_getCurrentMode(This,result)	\
    (This)->lpVtbl -> getCurrentMode(This,result)

#define IEyeLink_getEventDataFlags(This,result)	\
    (This)->lpVtbl -> getEventDataFlags(This,result)

#define IEyeLink_getEventTypeFlags(This,result)	\
    (This)->lpVtbl -> getEventTypeFlags(This,result)

#define IEyeLink_flushKeybuttons(This,enable_button_queue)	\
    (This)->lpVtbl -> flushKeybuttons(This,enable_button_queue)

#define IEyeLink_waitForModeReady(This,max_wait,result)	\
    (This)->lpVtbl -> waitForModeReady(This,max_wait,result)

#define IEyeLink_exitCalibration(This)	\
    (This)->lpVtbl -> exitCalibration(This)

#define IEyeLink_resetData(This)	\
    (This)->lpVtbl -> resetData(This)

#define IEyeLink_getTrackerMode(This,result)	\
    (This)->lpVtbl -> getTrackerMode(This,result)

#define IEyeLink_readKeyQueue(This,result)	\
    (This)->lpVtbl -> readKeyQueue(This,result)

#define IEyeLink_acceptTrigger(This,result)	\
    (This)->lpVtbl -> acceptTrigger(This,result)

#define IEyeLink_startDriftCorrect(This,x,y)	\
    (This)->lpVtbl -> startDriftCorrect(This,x,y)

#define IEyeLink_setName(This,name)	\
    (This)->lpVtbl -> setName(This,name)

#define IEyeLink_stopData(This)	\
    (This)->lpVtbl -> stopData(This)

#define IEyeLink_startPlayBack(This)	\
    (This)->lpVtbl -> startPlayBack(This)

#define IEyeLink_stopPlayBack(This)	\
    (This)->lpVtbl -> stopPlayBack(This)

#define IEyeLink_isRecording(This,result)	\
    (This)->lpVtbl -> isRecording(This,result)

#define IEyeLink_getRecordingStatus(This,result)	\
    (This)->lpVtbl -> getRecordingStatus(This,result)

#define IEyeLink_startData(This,flags,lock)	\
    (This)->lpVtbl -> startData(This,flags,lock)

#define IEyeLink_openDataFile(This,fname)	\
    (This)->lpVtbl -> openDataFile(This,fname)

#define IEyeLink_closeDataFile(This)	\
    (This)->lpVtbl -> closeDataFile(This)

#define IEyeLink_escapePressed(This,result)	\
    (This)->lpVtbl -> escapePressed(This,result)

#define IEyeLink_breakPressed(This,result)	\
    (This)->lpVtbl -> breakPressed(This,result)

#define IEyeLink_terminalBreak(This,assert)	\
    (This)->lpVtbl -> terminalBreak(This,assert)

#define IEyeLink_getLastButtonPress(This,time,button)	\
    (This)->lpVtbl -> getLastButtonPress(This,time,button)

#define IEyeLink_pumpMessages(This)	\
    (This)->lpVtbl -> pumpMessages(This)

#define IEyeLink_readKeyButton(This,mods,state,kcode,time,scan)	\
    (This)->lpVtbl -> readKeyButton(This,mods,state,kcode,time,scan)

#define IEyeLink_receiveDataFile(This,src,dest)	\
    (This)->lpVtbl -> receiveDataFile(This,src,dest)

#define IEyeLink_userMenuSelection(This,result)	\
    (This)->lpVtbl -> userMenuSelection(This,result)

#define IEyeLink_getButtonStates(This,result)	\
    (This)->lpVtbl -> getButtonStates(This,result)

#define IEyeLink_getDataCount(This,samples,events,count)	\
    (This)->lpVtbl -> getDataCount(This,samples,events,count)

#define IEyeLink_isInDataBlock(This,samples,events,ret)	\
    (This)->lpVtbl -> isInDataBlock(This,samples,events,ret)

#define IEyeLink_waitForBlockStart(This,max_wait,samples,events,result)	\
    (This)->lpVtbl -> waitForBlockStart(This,max_wait,samples,events,result)

#define IEyeLink_waitForData(This,max_wait,samples,events,result)	\
    (This)->lpVtbl -> waitForData(This,max_wait,samples,events,result)

#define IEyeLink_sendKeybutton(This,kcode,mod,state)	\
    (This)->lpVtbl -> sendKeybutton(This,kcode,mod,state)

#define IEyeLink_getTargetPositionAndState(This,x,y,visible)	\
    (This)->lpVtbl -> getTargetPositionAndState(This,x,y,visible)

#define IEyeLink_getModeData(This,sample_rate,crmode,file_filter,link_filter)	\
    (This)->lpVtbl -> getModeData(This,sample_rate,crmode,file_filter,link_filter)

#define IEyeLink_getSampleDataFlags(This,result)	\
    (This)->lpVtbl -> getSampleDataFlags(This,result)

#define IEyeLink_echoKey(This,result)	\
    (This)->lpVtbl -> echoKey(This,result)

#define IEyeLink_SendImageToTracker(This,pImage,xferoptions)	\
    (This)->lpVtbl -> SendImageToTracker(This,pImage,xferoptions)

#define IEyeLink_BitmapToBackdrop(This,fname,xferoptions)	\
    (This)->lpVtbl -> BitmapToBackdrop(This,fname,xferoptions)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IEyeLink_open_Proxy( 
    IEyeLink __RPC_FAR * This,
    /* [optional][in] */ BSTR hostAddress,
    /* [optional][in] */ short busyTest);


void __RPC_STUB IEyeLink_open_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEyeLink_dummyOpen_Proxy( 
    IEyeLink __RPC_FAR * This);


void __RPC_STUB IEyeLink_dummyOpen_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEyeLink_getNextData_Proxy( 
    IEyeLink __RPC_FAR * This,
    /* [retval][out] */ IELData __RPC_FAR *__RPC_FAR *result);


void __RPC_STUB IEyeLink_getNextData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEyeLink_close_Proxy( 
    IEyeLink __RPC_FAR * This);


void __RPC_STUB IEyeLink_close_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEyeLink_reset_Proxy( 
    IEyeLink __RPC_FAR * This);


void __RPC_STUB IEyeLink_reset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEyeLink_stopRecording_Proxy( 
    IEyeLink __RPC_FAR * This);


void __RPC_STUB IEyeLink_stopRecording_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEyeLink_doTrackerSetup_Proxy( 
    IEyeLink __RPC_FAR * This);


void __RPC_STUB IEyeLink_doTrackerSetup_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEyeLink_startRecording_Proxy( 
    IEyeLink __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL file_samples,
    /* [in] */ VARIANT_BOOL file_events,
    /* [in] */ VARIANT_BOOL link_samples,
    /* [in] */ VARIANT_BOOL link_events);


void __RPC_STUB IEyeLink_startRecording_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEyeLink_doDriftCorrect_Proxy( 
    IEyeLink __RPC_FAR * This,
    /* [in] */ short x,
    /* [in] */ short y,
    /* [in] */ VARIANT_BOOL draw,
    /* [in] */ VARIANT_BOOL allowSetup);


void __RPC_STUB IEyeLink_doDriftCorrect_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEyeLink_doDriftCorrectEx_Proxy( 
    IEyeLink __RPC_FAR * This,
    /* [in] */ short x,
    /* [in] */ short y,
    /* [in] */ VARIANT_BOOL draw,
    /* [in] */ VARIANT_BOOL allow_setup,
    /* [retval][out] */ short __RPC_FAR *ret);


void __RPC_STUB IEyeLink_doDriftCorrectEx_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEyeLink_isConnected_Proxy( 
    IEyeLink __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *result);


void __RPC_STUB IEyeLink_isConnected_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEyeLink_getTrackerVersion_Proxy( 
    IEyeLink __RPC_FAR * This,
    /* [retval][out] */ short __RPC_FAR *verNum);


void __RPC_STUB IEyeLink_getTrackerVersion_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEyeLink_setOfflineMode_Proxy( 
    IEyeLink __RPC_FAR * This);


void __RPC_STUB IEyeLink_setOfflineMode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEyeLink_sendCommand_Proxy( 
    IEyeLink __RPC_FAR * This,
    /* [in] */ BSTR cmd);


void __RPC_STUB IEyeLink_sendCommand_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEyeLink_sendTimedCommand_Proxy( 
    IEyeLink __RPC_FAR * This,
    /* [in] */ int duration,
    /* [in] */ BSTR command);


void __RPC_STUB IEyeLink_sendTimedCommand_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEyeLink_sendMessage_Proxy( 
    IEyeLink __RPC_FAR * This,
    /* [in] */ BSTR msg);


void __RPC_STUB IEyeLink_sendMessage_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEyeLink_getKey_Proxy( 
    IEyeLink __RPC_FAR * This,
    /* [retval][out] */ short __RPC_FAR *result);


void __RPC_STUB IEyeLink_getKey_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEyeLink_abort_Proxy( 
    IEyeLink __RPC_FAR * This);


void __RPC_STUB IEyeLink_abort_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEyeLink_commandResult_Proxy( 
    IEyeLink __RPC_FAR * This,
    /* [retval][out] */ short __RPC_FAR *result);


void __RPC_STUB IEyeLink_commandResult_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEyeLink_inSetup_Proxy( 
    IEyeLink __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *result);


void __RPC_STUB IEyeLink_inSetup_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEyeLink_getCalibrationResult_Proxy( 
    IEyeLink __RPC_FAR * This,
    /* [retval][out] */ short __RPC_FAR *result);


void __RPC_STUB IEyeLink_getCalibrationResult_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEyeLink_applyDriftCorrect_Proxy( 
    IEyeLink __RPC_FAR * This);


void __RPC_STUB IEyeLink_applyDriftCorrect_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEyeLink_startSetup_Proxy( 
    IEyeLink __RPC_FAR * This);


void __RPC_STUB IEyeLink_startSetup_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEyeLink_getTrackerVersionString_Proxy( 
    IEyeLink __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *verStr);


void __RPC_STUB IEyeLink_getTrackerVersionString_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEyeLink_getLastMessage_Proxy( 
    IEyeLink __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *result);


void __RPC_STUB IEyeLink_getLastMessage_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEyeLink_readRequest_Proxy( 
    IEyeLink __RPC_FAR * This,
    /* [in] */ BSTR sys_var);


void __RPC_STUB IEyeLink_readRequest_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEyeLink_readReply_Proxy( 
    IEyeLink __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *result);


void __RPC_STUB IEyeLink_readReply_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEyeLink_getCalibrationMessage_Proxy( 
    IEyeLink __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *result);


void __RPC_STUB IEyeLink_getCalibrationMessage_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEyeLink_getNewestSample_Proxy( 
    IEyeLink __RPC_FAR * This,
    /* [retval][out] */ ISample __RPC_FAR *__RPC_FAR *result);


void __RPC_STUB IEyeLink_getNewestSample_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEyeLink_trackerTime_Proxy( 
    IEyeLink __RPC_FAR * This,
    /* [retval][out] */ double __RPC_FAR *result);


void __RPC_STUB IEyeLink_trackerTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEyeLink_trackerTimeOffset_Proxy( 
    IEyeLink __RPC_FAR * This,
    /* [retval][out] */ double __RPC_FAR *result);


void __RPC_STUB IEyeLink_trackerTimeOffset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEyeLink_trackerTimeUsec_Proxy( 
    IEyeLink __RPC_FAR * This,
    /* [retval][out] */ double __RPC_FAR *result);


void __RPC_STUB IEyeLink_trackerTimeUsec_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEyeLink_trackerTimeUsecOffset_Proxy( 
    IEyeLink __RPC_FAR * This,
    /* [retval][out] */ double __RPC_FAR *result);


void __RPC_STUB IEyeLink_trackerTimeUsecOffset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEyeLink_eyeAvailable_Proxy( 
    IEyeLink __RPC_FAR * This,
    /* [retval][out] */ short __RPC_FAR *result);


void __RPC_STUB IEyeLink_eyeAvailable_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEyeLink_getCurrentMode_Proxy( 
    IEyeLink __RPC_FAR * This,
    /* [retval][out] */ short __RPC_FAR *result);


void __RPC_STUB IEyeLink_getCurrentMode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEyeLink_getEventDataFlags_Proxy( 
    IEyeLink __RPC_FAR * This,
    /* [retval][out] */ short __RPC_FAR *result);


void __RPC_STUB IEyeLink_getEventDataFlags_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEyeLink_getEventTypeFlags_Proxy( 
    IEyeLink __RPC_FAR * This,
    /* [retval][out] */ short __RPC_FAR *result);


void __RPC_STUB IEyeLink_getEventTypeFlags_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEyeLink_flushKeybuttons_Proxy( 
    IEyeLink __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL enable_button_queue);


void __RPC_STUB IEyeLink_flushKeybuttons_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEyeLink_waitForModeReady_Proxy( 
    IEyeLink __RPC_FAR * This,
    /* [in] */ int max_wait,
    /* [retval][out] */ short __RPC_FAR *result);


void __RPC_STUB IEyeLink_waitForModeReady_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEyeLink_exitCalibration_Proxy( 
    IEyeLink __RPC_FAR * This);


void __RPC_STUB IEyeLink_exitCalibration_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEyeLink_resetData_Proxy( 
    IEyeLink __RPC_FAR * This);


void __RPC_STUB IEyeLink_resetData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEyeLink_getTrackerMode_Proxy( 
    IEyeLink __RPC_FAR * This,
    /* [retval][out] */ short __RPC_FAR *result);


void __RPC_STUB IEyeLink_getTrackerMode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEyeLink_readKeyQueue_Proxy( 
    IEyeLink __RPC_FAR * This,
    /* [retval][out] */ short __RPC_FAR *result);


void __RPC_STUB IEyeLink_readKeyQueue_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEyeLink_acceptTrigger_Proxy( 
    IEyeLink __RPC_FAR * This,
    /* [retval][out] */ short __RPC_FAR *result);


void __RPC_STUB IEyeLink_acceptTrigger_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEyeLink_startDriftCorrect_Proxy( 
    IEyeLink __RPC_FAR * This,
    /* [in] */ short x,
    /* [in] */ short y);


void __RPC_STUB IEyeLink_startDriftCorrect_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEyeLink_setName_Proxy( 
    IEyeLink __RPC_FAR * This,
    /* [in] */ BSTR name);


void __RPC_STUB IEyeLink_setName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEyeLink_stopData_Proxy( 
    IEyeLink __RPC_FAR * This);


void __RPC_STUB IEyeLink_stopData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEyeLink_startPlayBack_Proxy( 
    IEyeLink __RPC_FAR * This);


void __RPC_STUB IEyeLink_startPlayBack_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEyeLink_stopPlayBack_Proxy( 
    IEyeLink __RPC_FAR * This);


void __RPC_STUB IEyeLink_stopPlayBack_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEyeLink_isRecording_Proxy( 
    IEyeLink __RPC_FAR * This,
    /* [retval][out] */ EL_TRIAL_RESULT __RPC_FAR *result);


void __RPC_STUB IEyeLink_isRecording_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEyeLink_getRecordingStatus_Proxy( 
    IEyeLink __RPC_FAR * This,
    /* [retval][out] */ EL_TRIAL_RESULT __RPC_FAR *result);


void __RPC_STUB IEyeLink_getRecordingStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEyeLink_startData_Proxy( 
    IEyeLink __RPC_FAR * This,
    /* [in] */ short flags,
    /* [in] */ VARIANT_BOOL lock);


void __RPC_STUB IEyeLink_startData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEyeLink_openDataFile_Proxy( 
    IEyeLink __RPC_FAR * This,
    BSTR fname);


void __RPC_STUB IEyeLink_openDataFile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEyeLink_closeDataFile_Proxy( 
    IEyeLink __RPC_FAR * This);


void __RPC_STUB IEyeLink_closeDataFile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEyeLink_escapePressed_Proxy( 
    IEyeLink __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *result);


void __RPC_STUB IEyeLink_escapePressed_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEyeLink_breakPressed_Proxy( 
    IEyeLink __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *result);


void __RPC_STUB IEyeLink_breakPressed_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEyeLink_terminalBreak_Proxy( 
    IEyeLink __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL assert);


void __RPC_STUB IEyeLink_terminalBreak_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEyeLink_getLastButtonPress_Proxy( 
    IEyeLink __RPC_FAR * This,
    /* [optional][out] */ double __RPC_FAR *time,
    /* [retval][out] */ short __RPC_FAR *button);


void __RPC_STUB IEyeLink_getLastButtonPress_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEyeLink_pumpMessages_Proxy( 
    IEyeLink __RPC_FAR * This);


void __RPC_STUB IEyeLink_pumpMessages_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEyeLink_readKeyButton_Proxy( 
    IEyeLink __RPC_FAR * This,
    /* [out] */ short __RPC_FAR *mods,
    /* [out] */ short __RPC_FAR *state,
    /* [out] */ short __RPC_FAR *kcode,
    /* [out] */ double __RPC_FAR *time,
    /* [out] */ short __RPC_FAR *scan);


void __RPC_STUB IEyeLink_readKeyButton_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEyeLink_receiveDataFile_Proxy( 
    IEyeLink __RPC_FAR * This,
    /* [in] */ BSTR src,
    /* [in] */ BSTR dest);


void __RPC_STUB IEyeLink_receiveDataFile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEyeLink_userMenuSelection_Proxy( 
    IEyeLink __RPC_FAR * This,
    /* [retval][out] */ short __RPC_FAR *result);


void __RPC_STUB IEyeLink_userMenuSelection_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEyeLink_getButtonStates_Proxy( 
    IEyeLink __RPC_FAR * This,
    /* [retval][out] */ short __RPC_FAR *result);


void __RPC_STUB IEyeLink_getButtonStates_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEyeLink_getDataCount_Proxy( 
    IEyeLink __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL samples,
    /* [in] */ VARIANT_BOOL events,
    /* [retval][out] */ short __RPC_FAR *count);


void __RPC_STUB IEyeLink_getDataCount_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEyeLink_isInDataBlock_Proxy( 
    IEyeLink __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL samples,
    /* [in] */ VARIANT_BOOL events,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *ret);


void __RPC_STUB IEyeLink_isInDataBlock_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEyeLink_waitForBlockStart_Proxy( 
    IEyeLink __RPC_FAR * This,
    /* [in] */ int max_wait,
    /* [in] */ VARIANT_BOOL samples,
    /* [in] */ VARIANT_BOOL events,
    /* [retval][out] */ short __RPC_FAR *result);


void __RPC_STUB IEyeLink_waitForBlockStart_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEyeLink_waitForData_Proxy( 
    IEyeLink __RPC_FAR * This,
    /* [in] */ int max_wait,
    /* [in] */ VARIANT_BOOL samples,
    /* [in] */ VARIANT_BOOL events,
    /* [retval][out] */ short __RPC_FAR *result);


void __RPC_STUB IEyeLink_waitForData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEyeLink_sendKeybutton_Proxy( 
    IEyeLink __RPC_FAR * This,
    /* [in] */ int kcode,
    /* [in] */ short mod,
    /* [in] */ short state);


void __RPC_STUB IEyeLink_sendKeybutton_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEyeLink_getTargetPositionAndState_Proxy( 
    IEyeLink __RPC_FAR * This,
    /* [out] */ short __RPC_FAR *x,
    /* [out] */ short __RPC_FAR *y,
    /* [out] */ VARIANT_BOOL __RPC_FAR *visible);


void __RPC_STUB IEyeLink_getTargetPositionAndState_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEyeLink_getModeData_Proxy( 
    IEyeLink __RPC_FAR * This,
    /* [out] */ short __RPC_FAR *sample_rate,
    /* [out] */ short __RPC_FAR *crmode,
    /* [out] */ short __RPC_FAR *file_filter,
    /* [out] */ short __RPC_FAR *link_filter);


void __RPC_STUB IEyeLink_getModeData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEyeLink_getSampleDataFlags_Proxy( 
    IEyeLink __RPC_FAR * This,
    /* [retval][out] */ short __RPC_FAR *result);


void __RPC_STUB IEyeLink_getSampleDataFlags_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEyeLink_echoKey_Proxy( 
    IEyeLink __RPC_FAR * This,
    /* [retval][out] */ short __RPC_FAR *result);


void __RPC_STUB IEyeLink_echoKey_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEyeLink_SendImageToTracker_Proxy( 
    IEyeLink __RPC_FAR * This,
    /* [in] */ IPicture __RPC_FAR *pImage,
    /* [in] */ FEROPTIONS xferoptions);


void __RPC_STUB IEyeLink_SendImageToTracker_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEyeLink_BitmapToBackdrop_Proxy( 
    IEyeLink __RPC_FAR * This,
    /* [in] */ BSTR fname,
    /* [in] */ FEROPTIONS xferoptions);


void __RPC_STUB IEyeLink_BitmapToBackdrop_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IEyeLink_INTERFACE_DEFINED__ */



#ifndef __SREYELINKLib_LIBRARY_DEFINED__
#define __SREYELINKLib_LIBRARY_DEFINED__

/* library SREYELINKLib */
/* [helpstring][version][uuid] */ 







EXTERN_C const IID LIBID_SREYELINKLib;

EXTERN_C const CLSID CLSID_EyeLinkUtil;

#ifdef __cplusplus

class DECLSPEC_UUID("1A6E4DE4-35AA-444F-A5F7-94779D665399")
EyeLinkUtil;
#endif

EXTERN_C const CLSID CLSID_Sample;

#ifdef __cplusplus

class DECLSPEC_UUID("2DCBE197-E6D8-45C6-B2F7-477912EC3D7C")
Sample;
#endif

EXTERN_C const CLSID CLSID_ELData;

#ifdef __cplusplus

class DECLSPEC_UUID("C820D77B-A4BE-467D-9AE5-AA2615580804")
ELData;
#endif

EXTERN_C const CLSID CLSID_IOEvent;

#ifdef __cplusplus

class DECLSPEC_UUID("CB4AF70E-BA36-48EF-B123-179358E1DE3C")
IOEvent;
#endif

EXTERN_C const CLSID CLSID_Message;

#ifdef __cplusplus

class DECLSPEC_UUID("B070878B-A309-48FE-9032-5C248D800CAB")
Message;
#endif

EXTERN_C const CLSID CLSID_BusyCal;

#ifdef __cplusplus

class DECLSPEC_UUID("FC643CA1-AA4B-45CA-BEF3-A3B02DA0447F")
BusyCal;
#endif

EXTERN_C const CLSID CLSID_Calibration;

#ifdef __cplusplus

class DECLSPEC_UUID("467E1DE0-6BA9-4BAD-B9D7-48198FCB3E52")
Calibration;
#endif

EXTERN_C const CLSID CLSID_EyeEvent;

#ifdef __cplusplus

class DECLSPEC_UUID("55987768-41BC-4801-8846-8FB41D5BD55B")
EyeEvent;
#endif

EXTERN_C const CLSID CLSID_StartBlinkEvent;

#ifdef __cplusplus

class DECLSPEC_UUID("5C1814BF-9483-4274-9C35-67EF72869658")
StartBlinkEvent;
#endif

EXTERN_C const CLSID CLSID_EndBlinkEvent;

#ifdef __cplusplus

class DECLSPEC_UUID("AD78886C-A9B3-47B6-9CDB-F085130E180B")
EndBlinkEvent;
#endif

EXTERN_C const CLSID CLSID_StartSaccadeEvent;

#ifdef __cplusplus

class DECLSPEC_UUID("85679D73-DB1E-48F8-AD8E-F989A05439B6")
StartSaccadeEvent;
#endif

EXTERN_C const CLSID CLSID_StartFixationEvent;

#ifdef __cplusplus

class DECLSPEC_UUID("95C34A0D-799F-4329-90FB-361422F35297")
StartFixationEvent;
#endif

EXTERN_C const CLSID CLSID_EndSaccadeEvent;

#ifdef __cplusplus

class DECLSPEC_UUID("4D598D1C-9DBE-46E2-816F-8CABD3093C18")
EndSaccadeEvent;
#endif

EXTERN_C const CLSID CLSID_EndFixationEvent;

#ifdef __cplusplus

class DECLSPEC_UUID("FC90106A-B88F-49F9-AC83-4B8C6F96D198")
EndFixationEvent;
#endif

EXTERN_C const CLSID CLSID_FixUpdateEvent;

#ifdef __cplusplus

class DECLSPEC_UUID("9183948B-0E70-4AE0-8324-2A6A980C0160")
FixUpdateEvent;
#endif

EXTERN_C const CLSID CLSID_EyeLink;

#ifdef __cplusplus

class DECLSPEC_UUID("FF995595-3BF6-42CB-9A77-7041EB2F2FF2")
EyeLink;
#endif

EXTERN_C const CLSID CLSID_ELGDICal;

#ifdef __cplusplus

class DECLSPEC_UUID("60B09097-BCEC-4273-B5A3-3D4B96B9391F")
ELGDICal;
#endif
#endif /* __SREYELINKLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long __RPC_FAR *, unsigned long            , BSTR __RPC_FAR * ); 
unsigned char __RPC_FAR * __RPC_USER  BSTR_UserMarshal(  unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, BSTR __RPC_FAR * ); 
unsigned char __RPC_FAR * __RPC_USER  BSTR_UserUnmarshal(unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, BSTR __RPC_FAR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long __RPC_FAR *, BSTR __RPC_FAR * ); 

unsigned long             __RPC_USER  LPSAFEARRAY_UserSize(     unsigned long __RPC_FAR *, unsigned long            , LPSAFEARRAY __RPC_FAR * ); 
unsigned char __RPC_FAR * __RPC_USER  LPSAFEARRAY_UserMarshal(  unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, LPSAFEARRAY __RPC_FAR * ); 
unsigned char __RPC_FAR * __RPC_USER  LPSAFEARRAY_UserUnmarshal(unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, LPSAFEARRAY __RPC_FAR * ); 
void                      __RPC_USER  LPSAFEARRAY_UserFree(     unsigned long __RPC_FAR *, LPSAFEARRAY __RPC_FAR * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
