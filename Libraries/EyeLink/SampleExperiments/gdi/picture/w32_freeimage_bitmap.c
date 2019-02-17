/**********************************************************/
/* Windows 95/98/NT/2000/XP experiment C support          */
/* For use with Version 2.0 of EyeLink Windows API        */
/*                                                        */
/*      (c) 1997-2002 by SR Research Ltd.                 */
/* For non-commercial use by Eyelink licencees only       */
/*                                                        */
/* THIS FILE: w32_freeimage_bitmap.c                      */
/* CONTENTS:                                              */
/* - load many types of image files to memory bitmap      */
/*                                                        */
/* NOTE: loads bitmap as 24-bit color, and so will not    */
/*  properly display images in 256-color modes            */
/*                                                        */
/*                                                        */
/* CHANGES FOR Windows 2000/XP, EyeLink 2.0:  NEW         */
/**********************************************************/
 
#include <windows.h>
#include <windowsx.h>

#include "gdi_expt.h"
#include "w32_demo.h"

#include "freeimage.h"

/*********** LOAD IMAGE FILE, CREATE BITMAP ************/

           // Creates DDB bitmap from loaded image file
           // if <keepsize>, makes bitmap the same size as image file
           // otherwise, creates a full-screen sized bitmap
           // If <dx, dy> are not 0, will resize image to those dimensions
           // If resized image won't fill display, 
           // it clears the bitmap to <bgcolor> and centers the image in it
           // NOTE: intermediate bitmap is 24-bit color, 
           // so won't work well in 256-color display modes
HBITMAP image_file_bitmap(char *fname, int keepsize, int dx, int dy, COLORREF bgcolor)
{
  HDC hdc;
  HDC mdc, dmdc;
  HBITMAP hbm;      // fullscreen bitmap
  HBITMAP hdibm;    // source bitmap
  HBITMAP obm, odbm;
  FIBITMAP *dib = NULL;       // FreeImage bitmap
  FREE_IMAGE_FORMAT imgtype;  // FreeImage file type
  int x=0, y=0;               // top-left of resized image  
  
  imgtype = FreeImage_GetFileType(fname, 0);
  switch(imgtype)
    {
      case FIF_BMP:      // Windows or OS/2 Bitmap  
        dib = FreeImage_LoadBMP(fname, BMP_DEFAULT); 
        break;
      case FIF_ICO:      // Windows Icon  
        dib = FreeImage_LoadICO(fname, ICO_FIRST); 
        break;
      case FIF_JPEG:     // JPEG - JFIF Compliant  
      case FIF_JNG:      // JPEG Network Graphics  
        dib = FreeImage_LoadJPEG(fname, JPEG_ACCURATE);  // or JPEG_FAST
        break;
      case FIF_KOALA:    // C64 Koala Graphics  
        dib = FreeImage_LoadKOALA(fname, KOALA_DEFAULT); 
        break;
      case FIF_LBM:      // Deluxe Paint LBM  
        dib = FreeImage_LoadLBM(fname, LBM_DEFAULT); 
        break;
      case FIF_MNG:      // Multiple Network Graphics  
        dib = FreeImage_LoadMNG(fname, MNG_DEFAULT); 
        break;
      case FIF_PBM:      // Portable Bitmap  
      case FIF_PGM:      // Portable Greymap  
      case FIF_PPM:      // Portable Pixmap  
        dib = FreeImage_LoadPNM(fname, PNM_DEFAULT); 
        break;
      case FIF_PCD:      // Kodak PhotoCD  
           //  PCD_BASE 24-bit, 768 x 512 pixels 
           //  PCD_BASEDIV4 24-bit, 192 x 128 pixels 
           //  PCD_BASEDIV16 24-bit. 384 x 256 pixels 
        dib = FreeImage_LoadPCD(fname, PCD_BASE);
        break;
      case FIF_PCX:      // Zsoft Paintbrush  
        dib = FreeImage_LoadPCX(fname, PCX_DEFAULT); 
        break;
      case FIF_PNG:      // Portable Network Graphics  
        dib = FreeImage_LoadPNG(fname, PNG_DEFAULT); 
        break;
      case FIF_RAS:      // Sun Raster Image  
        dib = FreeImage_LoadRAS(fname, RAS_DEFAULT); 
        break;
      case FIF_TARGA:    // Truevision Targa  
        dib = FreeImage_LoadTARGA(fname, TARGA_DEFAULT); // or  TARGA_LOAD_RGB888 to convert to 24-bit. 
        break;
      case FIF_TIFF:     // Tagged Image File Format  
        dib = FreeImage_LoadTIFF(fname, TIFF_DEFAULT); 
        break;
      case FIF_WBMP:     // Wireless Bitmap  
        dib = FreeImage_LoadWBMP(fname, WBMP_DEFAULT); 
        break;
      case FIF_UNKNOWN:  // Unidentified bitmap type  
      default:
        return NULL;
    }

  if(!dib)
    {
      FreeImage_Free(dib);   
      return NULL;
    }

  hdc = GetDC(full_screen_window);               
  mdc = CreateCompatibleDC(hdc);    // Create a memory context for BITMAP
  dmdc = CreateCompatibleDC(hdc);    // Create a memory context for BITMAP
  hdibm = CreateDIBitmap(hdc, FreeImage_GetInfoHeader(dib),
                         CBM_INIT, FreeImage_GetBits(dib),
                         FreeImage_GetInfo(dib), DIB_RGB_COLORS);
  if(!hdibm)
    {
      ReleaseDC(full_screen_window, hdc);
      DeleteDC(mdc);
      DeleteDC(dmdc);
      FreeImage_Free(dib);   
      return NULL;
    }

  if(keepsize || ( FreeImage_GetWidth(dib)==(unsigned)SCRWIDTH && 
                   FreeImage_GetHeight(dib)==(unsigned)SCRHEIGHT) )   // no resizing, just return DDB
    {
      DeleteDC(mdc);
      DeleteDC(dmdc);
      ReleaseDC(full_screen_window, hdc);
	  FreeImage_Unload(dib);
      return hdibm;
    }
  
  if(dx==0 && dy==0)                           // set default size if required
    {
      dx = FreeImage_GetWidth(dib);
      if(dx > SCRWIDTH) dx = SCRWIDTH;
      dy = FreeImage_GetHeight(dib);
      if(dy > SCRHEIGHT) dy = SCRHEIGHT;
    }
  x = (SCRWIDTH-dx) / 2;      // compute top-left to center bitmap if too small
  y = (SCRHEIGHT-dy) / 2;

  hbm = CreateCompatibleBitmap(hdc, SCRWIDTH, SCRHEIGHT);  // Create fullscreen BITMAP
  if(!hbm) 
    {
      FreeImage_Free(dib);   
      DeleteDC(mdc);
      DeleteDC(dmdc);
      ReleaseDC(full_screen_window, hdc);
      return NULL;
    }

  obm = SelectObject(mdc, hbm);        // select dest BITMAP
  odbm = SelectBitmap(dmdc, hdibm);    // select sourcce BITMAP

  if(x>0 || y>0)              // do we need to clear background?
    {
      HBRUSH oBrush = SelectObject(mdc, CreateSolidBrush(bgcolor | 0x02000000L));  // brush to fill with 
      PatBlt(mdc, 0, 0, SCRWIDTH, SCRHEIGHT, PATCOPY);
      DeleteObject(SelectObject(mdc, oBrush));
    }

  StretchBlt(mdc, x, y, dx, dy, dmdc, 0, 0,  // Copy, convert and size DIBSECTION image
             FreeImage_GetWidth(dib), FreeImage_GetHeight(dib), SRCCOPY);

  SelectBitmap(dmdc, odbm);   // Release GDI resources for source context
  DeleteDC(dmdc);
  DeleteObject(hdibm);        // Delete source BITMAP
  
  SelectBitmap(mdc, obm);      // Release GDI resources for destination BITMAP context
  DeleteDC(mdc);

  ReleaseDC(full_screen_window, hdc);
  FreeImage_Unload(dib);
  return hbm;
}
 
