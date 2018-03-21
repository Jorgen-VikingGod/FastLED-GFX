#include <FastLED.h>
#include <FastLED_GFX.h>

#define LED_PIN         3
#define COLOR_ORDER     GRB
#define CHIPSET         WS2811
#define BRIGHTNESS      64

#define CANVAS_WIDTH    8
#define CANVAS_HEIGHT   8
#define NUM_LEDS        (CANVAS_WIDTH * CANVAS_HEIGHT)

GFXcanvas canvas(CANVAS_WIDTH, CANVAS_HEIGHT);

void setup() {
  FastLED.addLeds<CHIPSET, LED_PIN, COLOR_ORDER>(canvas.getBuffer(), NUM_LEDS).setCorrection(TypicalSMD5050);
  FastLED.setBrightness(BRIGHTNESS);
}

void loop() {
  EVERY_N_SECONDS(5) {
    canvas.fillScreen(CRGB::Red);
    canvas.drawLine(0, 0, CANVAS_WIDTH-1, CANVAS_HEIGHT-1, CRGB::White);
    canvas.drawCircle(4, 4, 2, CRGB(255,255,0));
    FastLED.show();
  }
}

