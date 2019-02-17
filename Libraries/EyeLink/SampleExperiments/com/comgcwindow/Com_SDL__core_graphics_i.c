/* this file contains the actual definitions of */
/* the IIDs and CLSIDs */

/* link this file in with the server and any clients */


/* File created by MIDL compiler version 5.01.0164 */
/* at Fri Jul 04 16:12:26 2014
 */
/* Compiler settings for .\Com_SDL__core_graphics.idl:
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

const IID IID_ISDLCoreGraphics = {0x3B2F0EB0,0xADEF,0x40BA,{0xB2,0xA2,0xBD,0x7E,0x90,0x4A,0xE7,0x22}};


const IID LIBID_COM_SDL__CORE_GRAPHICSLib = {0x0E0C52FB,0xE1FE,0x4F69,{0x8C,0xB4,0x6A,0x87,0x3A,0x0E,0x5F,0x2C}};


const CLSID CLSID_SDLCoreGraphics = {0x5A01E0D6,0xA278,0x4C47,{0x82,0x18,0xD1,0xCD,0x24,0x6D,0x28,0xC0}};


#ifdef __cplusplus
}
#endif

