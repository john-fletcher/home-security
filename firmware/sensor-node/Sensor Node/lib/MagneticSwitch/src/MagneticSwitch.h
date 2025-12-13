#pragma once
#include <Arduino.h>
#include <DigitalInput.h>

class MagneticSwitch {
    public:
        MagneticSwitch(uint8_t pin);
        void begin();
        bool isClosed() const;
    private:
        DigitalInput _input;
};