#include "MagneticSwitch.h"

MagneticSwitch::MagneticSwitch(uint8_t pin) : _input(pin, InputPull::UP, false) {}

void MagneticSwitch::begin() {
    _input.begin();
}

bool MagneticSwitch::isClosed() const {
    return _input.isActive();
}