#pragma once
#include <Arduino.h>
#include <RgbLed.h>
#include <Button.h>
#include <MagneticSwitch.h>

enum DeviceState {
    BOOTING,
    IDLE,
    PAIRING,
    ARMED, // This can probably be removed as ARMED
    ERROR
};

class StateManager {
    public:
        StateManager(RgbLed& statusLed);
        void begin();

        DeviceState update(ButtonEvent buttonEvent, SwitchEvent switchEvent);

    private:
        void transitionToState(DeviceState newState);

        DeviceState _currentState = IDLE;
        RgbLed& _statusLed;
};