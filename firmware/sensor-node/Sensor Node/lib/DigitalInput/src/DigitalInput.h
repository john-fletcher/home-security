#pragma once
#include <Arduino.h>

enum class InputPull {
    NONE,
    UP,
    DOWN
};

class DigitalInput {
    public:
        DigitalInput(uint8_t pin, InputPull pull = InputPull::NONE, bool activeHigh = true);
        
        void begin();
        bool isActive() const;
    private:
        bool readRaw() const;
        uint8_t _pin;
        InputPull _pull;
        bool _activeHigh;
};