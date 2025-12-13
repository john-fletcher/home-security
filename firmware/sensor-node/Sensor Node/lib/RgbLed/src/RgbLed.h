#pragma once
#include <Arduino.h>

enum LedColor {
    OFF,
    RED,
    GREEN,
    BLUE,
    YELLOW,
    CYAN,
    MAGENTA,
    WHITE
};

class RgbLed {
    public:
        RgbLed(uint8_t redPin, uint8_t greenPin, uint8_t bluePin);
        void begin();
        void setColor(LedColor color);
    private:
        uint8_t _redPin, _greenPin, _bluePin;
        void apply(uint8_t redValue, uint8_t greenValue, uint8_t blueValue);
};