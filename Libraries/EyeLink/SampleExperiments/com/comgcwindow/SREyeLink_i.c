/* this file contains the actual definitions of */
/* the IIDs and CLSIDs */

/* link this file in with the server and any clients */


/* File created by MIDL compiler version 5.01.0164 */
/* at Fri Jul 04 16:11:49 2014
 */
/* Compiler settings for .\SREyeLink.idl:
    Oicf (OptLev=i2), W1, Zp8, env=Win32, ms_ext, c_ext
    error checks: allocation ref bounds_check enum stub_data 
*/
//@@MIDL_FILE_HEADING(  )
#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

const IID IID_ICalibration = {0x5A47633B,0x0108,0x4F75,{0x83,0x5C,0xCE,0xE0,0x26,0x62,0x61,0x84}};


const IID IID_IELData = {0x280E4754,0x46DE,0x4592,{0x8A,0x69,0x04,0xA5,0x03,0x4C,0x0B,0x7C}};


const IID IID_ISample = {0xDB4DB2DA,0x2B04,0x4F5C,{0xA2,0x4C,0x95,0xAB,0xC3,0xEC,0x50,0x02}};


const IID IID_IIOEvent = {0xD21E803C,0x1F82,0x43DA,{0xB3,0x4B,0x73,0x6D,0x87,0x10,0x45,0xAC}};


const IID IID_IMessage = {0xD8B2919D,0xD78C,0x46E9,{0xB1,0xAC,0x26,0x21,0x6D,0x28,0x8C,0x3F}};


const IID IID_IBusyCal = {0x3F8A8D25,0x992D,0x4BA0,{0x87,0x07,0xA1,0x12,0xDC,0x75,0x42,0xC9}};


const IID IID_IELGDICal = {0x5A048516,0x843E,0x4A26,{0x9B,0x4C,0xB8,0x6D,0x4F,0x22,0x1A,0x26}};


const IID IID_IEyeLinkUtil = {0x3EBC7F4F,0x2333,0x4AEC,{0x98,0x47,0xEB,0x02,0x9E,0x5A,0x0C,0xDB}};


const IID IID_IEyeEvent = {0xFAF94525,0xE372,0x4B42,{0x99,0x03,0xF2,0x65,0xB2,0xE6,0xDA,0xA3}};


const IID IID_IStartBlinkEvent = {0x84C93301,0x94CB,0x4CA7,{0xA3,0x74,0x6F,0xC6,0x26,0xEB,0x00,0xD3}};


const IID IID_IEndBlinkEvent = {0x6D4B7642,0x9D28,0x49D5,{0xB5,0x2D,0x70,0x8A,0x56,0x39,0x23,0x6E}};


const IID IID_IStartSaccadeEvent = {0xE0C17079,0xEF6F,0x4CE7,{0xA8,0xB5,0x63,0xFA,0xD2,0x9D,0x47,0xFC}};


const IID IID_IStartFixationEvent = {0xC259A0BF,0x565A,0x410D,{0x8B,0x78,0xEA,0xC9,0x96,0x0D,0x96,0xCB}};


const IID IID_IEndSaccadeEvent = {0xB327CE59,0x87BB,0x4290,{0xA0,0x09,0x5F,0xB9,0x33,0x9F,0x73,0xF1}};


const IID IID_IEndFixationEvent = {0x70F1B032,0x1E56,0x4405,{0xBC,0x67,0xCD,0x93,0x61,0xC7,0x9E,0xF0}};


const IID IID_IFixUpdateEvent = {0xC4299AF5,0x74F3,0x4495,{0xB1,0x69,0xEB,0x79,0xE9,0x60,0xFC,0xAB}};


const IID IID_IEyeLink = {0x5A58A2E8,0x4BFD,0x46A4,{0xA1,0xFF,0xCA,0x5C,0xA7,0xCD,0xDF,0x62}};


const IID LIBID_SREYELINKLib = {0xF8FB49B9,0x9448,0x4045,{0xBB,0x1F,0x9D,0xEA,0x1F,0x98,0xB7,0xE6}};


const CLSID CLSID_EyeLinkUtil = {0x1A6E4DE4,0x35AA,0x444F,{0xA5,0xF7,0x94,0x77,0x9D,0x66,0x53,0x99}};


const CLSID CLSID_Sample = {0x2DCBE197,0xE6D8,0x45C6,{0xB2,0xF7,0x47,0x79,0x12,0xEC,0x3D,0x7C}};


const CLSID CLSID_ELData = {0xC820D77B,0xA4BE,0x467D,{0x9A,0xE5,0xAA,0x26,0x15,0x58,0x08,0x04}};


const CLSID CLSID_IOEvent = {0xCB4AF70E,0xBA36,0x48EF,{0xB1,0x23,0x17,0x93,0x58,0xE1,0xDE,0x3C}};


const CLSID CLSID_Message = {0xB070878B,0xA309,0x48FE,{0x90,0x32,0x5C,0x24,0x8D,0x80,0x0C,0xAB}};


const CLSID CLSID_BusyCal = {0xFC643CA1,0xAA4B,0x45CA,{0xBE,0xF3,0xA3,0xB0,0x2D,0xA0,0x44,0x7F}};


const CLSID CLSID_Calibration = {0x467E1DE0,0x6BA9,0x4BAD,{0xB9,0xD7,0x48,0x19,0x8F,0xCB,0x3E,0x52}};


const CLSID CLSID_EyeEvent = {0x55987768,0x41BC,0x4801,{0x88,0x46,0x8F,0xB4,0x1D,0x5B,0xD5,0x5B}};


const CLSID CLSID_StartBlinkEvent = {0x5C1814BF,0x9483,0x4274,{0x9C,0x35,0x67,0xEF,0x72,0x86,0x96,0x58}};


const CLSID CLSID_EndBlinkEvent = {0xAD78886C,0xA9B3,0x47B6,{0x9C,0xDB,0xF0,0x85,0x13,0x0E,0x18,0x0B}};


const CLSID CLSID_StartSaccadeEvent = {0x85679D73,0xDB1E,0x48F8,{0xAD,0x8E,0xF9,0x89,0xA0,0x54,0x39,0xB6}};


const CLSID CLSID_StartFixationEvent = {0x95C34A0D,0x799F,0x4329,{0x90,0xFB,0x36,0x14,0x22,0xF3,0x52,0x97}};


const CLSID CLSID_EndSaccadeEvent = {0x4D598D1C,0x9DBE,0x46E2,{0x81,0x6F,0x8C,0xAB,0xD3,0x09,0x3C,0x18}};


const CLSID CLSID_EndFixationEvent = {0xFC90106A,0xB88F,0x49F9,{0xAC,0x83,0x4B,0x8C,0x6F,0x96,0xD1,0x98}};


const CLSID CLSID_FixUpdateEvent = {0x9183948B,0x0E70,0x4AE0,{0x83,0x24,0x2A,0x6A,0x98,0x0C,0x01,0x60}};


const CLSID CLSID_EyeLink = {0xFF995595,0x3BF6,0x42CB,{0x9A,0x77,0x70,0x41,0xEB,0x2F,0x2F,0xF2}};


const CLSID CLSID_ELGDICal = {0x60B09097,0xBCEC,0x4273,{0xB5,0xA3,0x3D,0x4B,0x96,0xB9,0x39,0x1F}};


#ifdef __cplusplus
}
#endif

