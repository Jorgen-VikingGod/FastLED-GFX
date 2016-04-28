# FastLED-GFX
----------------
Simple FastLED port of ([Adafruit-GFX-Library](https://github.com/adafruit/Adafruit-GFX-Library))

## Available Methods
-----------------------

```c
void drawPixel(int16_t x, int16_t y, CRGB color)
void drawLine(int16_t x0, int16_t y0, int16_t x1, int16_t y1, CRGB color)
void drawFastVLine(int16_t x, int16_t y, int16_t h, CRGB color)
void drawFastHLine(int16_t x, int16_t y, int16_t w, CRGB color)
void drawRect(int16_t x, int16_t y, int16_t w, int16_t h, CRGB color)
void fillRect(int16_t x, int16_t y, int16_t w, int16_t h, CRGB color)
void fillScreen(CRGB color)
void invertDisplay(boolean i)

void drawCircle(int16_t x0, int16_t y0, int16_t r, CRGB color)
void drawCircleHelper(int16_t x0, int16_t y0, int16_t r, uint8_t cornername, CRGB color)
void fillCircle(int16_t x0, int16_t y0, int16_t r, CRGB color)
void fillCircleHelper(int16_t x0, int16_t y0, int16_t r, uint8_t cornername, int16_t delta, CRGB color)
void drawTriangle(int16_t x0, int16_t y0, int16_t x1, int16_t y1, int16_t x2, int16_t y2, CRGB color)
void fillTriangle(int16_t x0, int16_t y0, int16_t x1, int16_t y1, int16_t x2, int16_t y2, CRGB color)
void drawRoundRect(int16_t x0, int16_t y0, int16_t w, int16_t h, int16_t radius, CRGB color)
void fillRoundRect(int16_t x0, int16_t y0, int16_t w, int16_t h, int16_t radius, CRGB color)
void drawBitmap(int16_t x, int16_t y, const uint8_t *bitmap, int16_t w, int16_t h, CRGB color)
void drawBitmap(int16_t x, int16_t y, const uint8_t *bitmap, int16_t w, int16_t h, CRGB color, CRGB bg)
void drawBitmap(int16_t x, int16_t y, uint8_t *bitmap, int16_t w, int16_t h, CRGB color)
void drawBitmap(int16_t x, int16_t y, uint8_t *bitmap, int16_t w, int16_t h, CRGB color, CRGB bg)
void drawXBitmap(int16_t x, int16_t y, const uint8_t *bitmap, int16_t w, int16_t h, CRGB color)
void drawChar(int16_t x, int16_t y, unsigned char c, CRGB color, CRGB bg, uint8_t size)
void setCursor(int16_t x, int16_t y)
void setTextColor(CRGB c)
void setTextColor(CRGB c, CRGB bg)
void setTextSize(uint8_t s)
void setTextWrap(boolean w)
void setRotation(uint8_t r)
void cp437(boolean x=true)
void setFont(const GFXfont *f = NULL)
void getTextBounds(char *string, int16_t x, int16_t y, int16_t *x1, int16_t *y1, uint16_t *w, uint16_t *h)
void getTextBounds(const __FlashStringHelper *s, int16_t x, int16_t y, int16_t *x1, int16_t *y1, uint16_t *w, uint16_t *h)

size_t write(uint8_t)

int16_t height(void) const
int16_t width(void) const

uint8_t getRotation(void) const

int16_t getCursorX(void) const
int16_t getCursorY(void) const
```
