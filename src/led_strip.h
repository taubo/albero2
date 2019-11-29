#ifndef LED_STRIP_H
#define LED_STRIP_H

#include <stdint.h>
#include "Adafruit_NeoPixel.h"

// FIXME: compatibility layer omegalul
typedef struct rgb_color
{
    unsigned char red, green, blue;
    rgb_color() {};
    rgb_color(uint8_t r, uint8_t g, uint8_t b) : red(r), green(g), blue(b) {};
} rgb_color;

class LedStrip {
    public:
        LedStrip();
        void write(rgb_color *color, int len);
    private:
        void write_partial(int start_idx, int stop_idx, rgb_color *color);
        Adafruit_NeoPixel pixels;
        int index;
};

#endif