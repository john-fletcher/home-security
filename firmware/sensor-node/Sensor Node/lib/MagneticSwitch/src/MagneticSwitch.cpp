#include "MagneticSwitch.h"

MagneticSwitch::MagneticSwitch(uint8_t pin) : _input(pin, InputPull::UP, false) {}

void MagneticSwitch::begin() {
    _input.begin();
}

SwitchEvent MagneticSwitch::update() {
    SwitchEvent currentEvent = isClosed() ? SwitchEvent::CLOSED : SwitchEvent::OPEN;
    SwitchEvent returnEvent = SwitchEvent::NONE;

    // Only update last event if there is a change
    if (currentEvent != _lastEvent) {
        _lastEvent = currentEvent;
        returnEvent = currentEvent;
    }

    return returnEvent;
}

bool MagneticSwitch::isClosed() const {
    return _input.isActive();
}