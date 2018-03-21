/*
Source code is based on https://github.com/adafruit/Adafruit-GFX-Library
replace internal use of NeoPixel library with CRGB array to use with FastLED

modified:  Juergen Skrotzky (JorgenVikingGod@gmail.com)
date:      2016/04/27
*/

#ifndef _FASTLED_GFX_H
#define _FASTLED_GFX_H

#if ARDUINO >= 100
 #include "Arduino.h"
 #include "Print.h"
#else
 #include "WProgram.h"
#endif

#include "gfxfont.h"

#define adagfxswap(a, b) { int16_t t = a; a = b; b = t; }

#if !defined(ESP8266)
  #define swap(a, b) adagfxswap(a, b)
#endif

class FastLED_GFX : public Print {
public:
  FastLED_GFX(int16_t w, int16_t h); // Constructor

  // This MUST be defined by the subclass:
  virtual void drawPixel(int16_t x, int16_t y, CRGB color) = 0;

  // These MAY be overridden by the subclass to provide device-specific
  // optimized code.  Otherwise 'generic' versions are used.
  virtual void
    drawLine(int16_t x0, int16_t y0, int16_t x1, int16_t y1, CRGB color),
    drawFastVLine(int16_t x, int16_t y, int16_t h, CRGB color),
    drawFastHLine(int16_t x, int16_t y, int16_t w, CRGB color),
    drawRect(int16_t x, int16_t y, int16_t w, int16_t h, CRGB color),
    fillRect(int16_t x, int16_t y, int16_t w, int16_t h, CRGB color),
    fillScreen(CRGB color),
    invertDisplay(boolean i);

  // These exist only with FastLED_GFX (no subclass overrides)
  void
    drawCircle(int16_t x0, int16_t y0, int16_t r, CRGB color),
    drawCircleHelper(int16_t x0, int16_t y0, int16_t r, uint8_t cornername,
      CRGB color),
    fillCircle(int16_t x0, int16_t y0, int16_t r, CRGB color),
    fillCircleHelper(int16_t x0, int16_t y0, int16_t r, uint8_t cornername,
      int16_t delta, CRGB color),
    drawTriangle(int16_t x0, int16_t y0, int16_t x1, int16_t y1,
      int16_t x2, int16_t y2, CRGB color),
    fillTriangle(int16_t x0, int16_t y0, int16_t x1, int16_t y1,
      int16_t x2, int16_t y2, CRGB color),
    drawRoundRect(int16_t x0, int16_t y0, int16_t w, int16_t h,
      int16_t radius, CRGB color),
    fillRoundRect(int16_t x0, int16_t y0, int16_t w, int16_t h,
      int16_t radius, CRGB color),
    drawBitmap(int16_t x, int16_t y, const uint8_t *bitmap,
      int16_t w, int16_t h, CRGB color),
    drawBitmap(int16_t x, int16_t y, const uint8_t *bitmap,
      int16_t w, int16_t h, CRGB color, CRGB bg),
    drawBitmap(int16_t x, int16_t y, uint8_t *bitmap,
      int16_t w, int16_t h, CRGB color),
    drawBitmap(int16_t x, int16_t y, uint8_t *bitmap,
      int16_t w, int16_t h, CRGB color, CRGB bg),
    drawXBitmap(int16_t x, int16_t y, const uint8_t *bitmap,
      int16_t w, int16_t h, CRGB color),
    drawChar(int16_t x, int16_t y, unsigned char c, CRGB color,
      CRGB bg, uint8_t size),
    setCursor(int16_t x, int16_t y),
    setTextColor(CRGB c),
    setTextColor(CRGB c, CRGB bg),
    setTextSize(uint8_t s),
    setTextWrap(boolean w),
    setRotation(uint8_t r),
    cp437(boolean x=true),
    setFont(const GFXfont *f = NULL),
    getTextBounds(char *string, int16_t x, int16_t y,
      int16_t *x1, int16_t *y1, uint16_t *w, uint16_t *h),
    getTextBounds(const __FlashStringHelper *s, int16_t x, int16_t y,
      int16_t *x1, int16_t *y1, uint16_t *w, uint16_t *h);

#if ARDUINO >= 100
  virtual size_t write(uint8_t);
#else
  virtual void   write(uint8_t);
#endif

  int16_t height(void) const;
  int16_t width(void) const;

  uint8_t getRotation(void) const;

  // get current cursor position (get rotation safe maximum values, using: width() for x, height() for y)
  int16_t getCursorX(void) const;
  int16_t getCursorY(void) const;

protected:
  const int16_t
    WIDTH, HEIGHT;   // This is the 'raw' display w/h - never changes
  int16_t
    _width, _height, // Display w/h as modified by current rotation
    cursor_x, cursor_y;
  CRGB
    textcolor, textbgcolor;
  uint8_t
    textsize,
    rotation;
  boolean
    wrap,   // If set, 'wrap' text at right edge of display
    _cp437; // If set, use correct CP437 charset (default is off)
  GFXfont
    *gfxFont;
};

class FastLED_GFX_Button {
public:
  FastLED_GFX_Button(void);
  void initButton(FastLED_GFX *gfx, int16_t x, int16_t y,
   uint8_t w, uint8_t h, CRGB outline, CRGB fill,
   CRGB textcolor, char *label, uint8_t textsize);
  void drawButton(boolean inverted = false);
  boolean contains(int16_t x, int16_t y);

  void press(boolean p);
  boolean isPressed();
  boolean justPressed();
  boolean justReleased();

private:
  FastLED_GFX *_gfx;
  int16_t _x, _y;
  uint16_t _w, _h;
  uint8_t _textsize;
  CRGB _outlinecolor, _fillcolor, _textcolor;
  char _label[10];

  boolean currstate, laststate;
};

class GFXcanvas: public FastLED_GFX {
public:
  GFXcanvas(uint16_t w, uint16_t h);
  ~GFXcanvas(void);
  void drawPixel(int16_t x, int16_t y, CRGB color);
  void fillScreen(CRGB color);
  struct CRGB *getBuffer(void);
private:
  struct CRGB *m_LED;
};

#endif // _FASTLED_GFX_H
