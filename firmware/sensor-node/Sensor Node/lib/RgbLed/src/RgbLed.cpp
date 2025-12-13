#include "RgbLed.h"

RgbLed::RgbLed(uint8_t redPin, uint8_t greenPin, uint8_t bluePin)
    : _redPin(redPin), _greenPin(greenPin), _bluePin(bluePin) {}

void RgbLed::begin() {
    pinMode(_redPin, OUTPUT);
    pinMode(_greenPin, OUTPUT);
    pinMode(_bluePin, OUTPUT);
    setColor(OFF);
}

void RgbLed::apply(uint8_t redValue, uint8_t greenValue, uint8_t blueValue) {
    analogWrite(_redPin, redValue);
    analogWrite(_greenPin, greenValue);
    analogWrite(_bluePin, blueValue);
}

void RgbLed::setColor(LedColor color) {
    switch (color) {
        case LedColor::OFF:     apply(0,   0,   0);   break;
        case LedColor::RED:     apply(255, 0,   0);   break;
        case LedColor::GREEN:   apply(0,   255, 0);   break;
        case LedColor::BLUE:    apply(0,   0,   255); break;
        case LedColor::YELLOW:  apply(255, 255, 0);   break;
        case LedColor::CYAN:    apply(0,   255, 255); break;
        case LedColor::MAGENTA: apply(255, 0,   255); break;
        case LedColor::WHITE:   apply(255, 255, 255); break;
    }
}