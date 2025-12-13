#include "DigitalInput.h"

DigitalInput::DigitalInput(uint8_t pin, InputPull pull, bool activeHigh)
    : _pin(pin), _pull(pull), _activeHigh(activeHigh) {}

void DigitalInput::begin() {
    // TODO: Should throw error if assigned pin cannot be used as input/pull
    if (_pull == InputPull::UP) {
        pinMode(_pin, INPUT_PULLUP);
    } else if (_pull == InputPull::DOWN) {
        pinMode(_pin, INPUT_PULLDOWN);
    } else {
        pinMode(_pin, INPUT);
    }
}

bool DigitalInput::readRaw() const {
    return digitalRead(_pin) == HIGH;
}

bool DigitalInput::isActive() const {
    bool rawState = readRaw();
    return _activeHigh ? rawState : !rawState;
}