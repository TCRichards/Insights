#include <SDL/SDL.h>
#include <windows.h>

// coppied from http://www.libsdl.org/pipermail/sdl/2003-February/052238.html
struct GDI_FontInfo {
     HBITMAP bitmap;
     int bmpWidth;
     int bmpHeight;
     LPSTR bmpBits;
};

#define WIDTHBYTES(i)       ((i+31)/32*4)
#define PALETTE_SIZE        2

SDL_Surface * RenderText_GDI(HFONT font, SDL_Color * color,
                              const char * str)
{
     GDI_FontInfo                fontInfo;
     HDC                         hdc;
     HDC                         m_hdc;
     LPBITMAPINFO                pbmi;
     SIZE                        size;

     if (font == NULL) {
         return NULL;
     }

     // Create a memory DC for rendering our text into
     hdc = GetDC(HWND_DESKTOP);
     m_hdc = CreateCompatibleDC(hdc);
     ReleaseDC(NULL, hdc);
     if (m_hdc == NULL) {
         return NULL;
     }

     // Select font, and get the text dimensions
     SelectObject(m_hdc, font);
     GetTextExtentPoint32(m_hdc, str, (int) ::strlen(str), &size);
     fontInfo.bmpWidth = size.cx + 2;
     fontInfo.bmpHeight = size.cy + 2;

     // Create a dib section for containing the bits
     pbmi = (LPBITMAPINFO) LocalAlloc(LPTR, sizeof(BITMAPINFO) +
             PALETTE_SIZE * sizeof(RGBQUAD));
     if (pbmi == NULL)
     {
         DeleteDC(m_hdc);
         return NULL;
     }
     pbmi->bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
     pbmi->bmiHeader.biWidth = fontInfo.bmpWidth;
     // negative height = top-down
     pbmi->bmiHeader.biHeight = -1 * fontInfo.bmpHeight;
     pbmi->bmiHeader.biPlanes = 1;
     pbmi->bmiHeader.biBitCount = 8; // 8bpp makes it easy to get data

     pbmi->bmiHeader.biCompression = BI_RGB;
     pbmi->bmiHeader.biXPelsPerMeter = 0;
     pbmi->bmiHeader.biYPelsPerMeter = 0;
     pbmi->bmiHeader.biClrUsed = PALETTE_SIZE;
     pbmi->bmiHeader.biClrImportant = PALETTE_SIZE;

     pbmi->bmiHeader.biSizeImage = WIDTHBYTES(fontInfo.bmpWidth * 8) *
             fontInfo.bmpHeight;

     // Just a plain monochrome palette
     pbmi->bmiColors[0].rgbRed = 0;
     pbmi->bmiColors[0].rgbGreen = 0;
     pbmi->bmiColors[0].rgbBlue = 0;
     pbmi->bmiColors[1].rgbRed = 255;
     pbmi->bmiColors[1].rgbGreen = 255;
     pbmi->bmiColors[1].rgbBlue = 255;

     // Create a DIB section that we can use to read the font bits out of
     fontInfo.bitmap = CreateDIBSection(m_hdc, pbmi,
                   DIB_RGB_COLORS, (void **) &fontInfo.bmpBits, NULL, 0);
     LocalFree(pbmi);
     if (fontInfo.bitmap == NULL)
     {
         DeleteDC(m_hdc);
         return NULL;
     }

     // Set up our memory DC with the font and bitmap
     SelectObject(m_hdc, fontInfo.bitmap);
     SetBkColor(m_hdc, RGB(0, 0, 0));
     SetTextColor(m_hdc, RGB(255, 255, 255));

     // Output text to our memory DC (the bits end up in our DIB section)
     PatBlt(m_hdc, 0, 0, fontInfo.bmpWidth, fontInfo.bmpHeight,
            BLACKNESS);
     TextOut(m_hdc, 1, 1, str, lstrlen(str));

     SDL_Surface * surface = SDL_CreateRGBSurface(SDL_SWSURFACE,
               fontInfo.bmpWidth, fontInfo.bmpHeight, 32,
               0, 0, 0, 0);
     if (SDL_MUSTLOCK(surface)) {
         SDL_LockSurface(surface);
     }
     Uint32 * destPixels = (Uint32 *) surface->pixels;

     LPSTR lpsrc = fontInfo.bmpBits;
     for (int ii = 0; ii < fontInfo.bmpHeight; ii++) {
         for (int jj = 0; jj < fontInfo.bmpWidth; jj++) {
             // If lpsrc[j] is 0, then it's a black pixel (opaque)
             // otherwise it's white (transparent)
             if (lpsrc[jj]) {
                 destPixels[jj] = ::SDL_MapRGBA(surface->format,
                         color->r, color->g, color->b, 0xff);
             } else {
                 destPixels[jj] = ::SDL_MapRGBA(surface->format,
                                                0, 0, 0, 0);
             }
         }
         lpsrc += WIDTHBYTES(fontInfo.bmpWidth * 8);
         destPixels += fontInfo.bmpWidth;
     }

     if (SDL_MUSTLOCK(surface)) {
         SDL_UnlockSurface(surface);
     }

     DeleteDC(m_hdc);
     DeleteObject(fontInfo.bitmap);

     return surface;
}
