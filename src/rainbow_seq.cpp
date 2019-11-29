#include <Arduino.h>

#include "rainbow_seq.h"

// seq rainbow
rgb_color hsvToRgb(uint16_t h, uint8_t s, uint8_t v)
{
	uint8_t f = (h % 60) * 255 / 60;
	uint8_t p = (255 - s) * (uint16_t)v / 255;
	uint8_t q = (255 - f * (uint16_t)s / 255) * (uint16_t)v / 255;
	uint8_t t = (255 - (255 - f) * (uint16_t)s / 255) * (uint16_t)v / 255;
	uint8_t r = 0, g = 0, b = 0;
	switch ((h / 60) % 6) {
		case 0: r = v; g = t; b = p; break;
		case 1: r = q; g = v; b = p; break;
		case 2: r = p; g = v; b = t; break;
		case 3: r = p; g = q; b = v; break;
		case 4: r = t; g = p; b = v; break;
		case 5: r = v; g = p; b = q; break;
	}

	return rgb_color(r / 6, g / 6, b / 6);
}

void rainbow_update(struct color_seq *col, void *data)
{
	if (!col)
		return;

	uint16_t time = millis() >> 2;

	for (uint16_t i = 0; i < col->len; i++) {
		byte x = (time >> 2) - (i << 3);
		col->colors[i] = hsvToRgb((uint32_t)x * 359 / 256, 255, 255);
	}
}
