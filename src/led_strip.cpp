#include "led_strip.h"

#define NUMPIXELS   100
#define PIN         6

int write_step = 0;

LedStrip::LedStrip() {
    pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ400);
    pixels.begin();
    index = 0;
}

/*
void write_partial(int start_idx, int stop_idx, rgb_color *color) {
    int i;

    for (i = start_idx; i < stop_idx; ++i) {
        pixels.setPixelColor(i, pixels.Color((int)color->red, (int)color->green, (int)color->blue));
    }
}
*/

void LedStrip::write(rgb_color *color, int len) {
    int i;

    for (i = 0; i < len; ++i) {
        pixels.setPixelColor(i, pixels.Color((int)color[i].red, (int)color[i].green, (int)color[i].blue));
    }
    // write_partial()
    pixels.show();
}