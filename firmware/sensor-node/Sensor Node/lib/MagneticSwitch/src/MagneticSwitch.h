#pragma once
#include <Arduino.h>
#include <DigitalInput.h>

enum class SwitchEvent {
    NONE,
    OPEN,
    CLOSED
};

class MagneticSwitch {
    public:
        MagneticSwitch(uint8_t pin);
        void begin();
        SwitchEvent update();
        bool isClosed() const;
    private:
        DigitalInput _input;
        SwitchEvent _lastEvent = SwitchEvent::NONE; // Track state of last loop
};