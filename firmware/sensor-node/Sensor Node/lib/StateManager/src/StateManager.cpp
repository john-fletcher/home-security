#include "StateManager.h"

StateManager::StateManager(RgbLed& statusLed) : _statusLed(statusLed) {}

void StateManager::begin() {
    _statusLed.begin();
    _statusLed.setColor(LedColor::WHITE);
    _currentState = IDLE;
}

DeviceState StateManager::update(ButtonEvent buttonEvent, SwitchEvent switchEvent) {
    if (buttonEvent == ButtonEvent::NONE && switchEvent == SwitchEvent::NONE) {
        return _currentState; // No events to process
    } else if (buttonEvent != ButtonEvent::NONE) {
        Serial.print("Button Event: ");
        Serial.println(static_cast<int>(buttonEvent));
    } else if (switchEvent != SwitchEvent::NONE) {
        Serial.print("Switch Event: ");
        Serial.println(static_cast<int>(switchEvent));
    }

    switch (_currentState) {
        case IDLE:
            if (buttonEvent == ButtonEvent::LONG_PRESSED) {
                transitionToState(PAIRING);
            } else if (switchEvent == SwitchEvent::OPEN) {
                // Optionally handle door open in IDLE state
                _statusLed.setColor(LedColor::RED);
            } else if (switchEvent == SwitchEvent::CLOSED) {
                // Optionally handle door closed in IDLE state
                _statusLed.setColor(LedColor::GREEN);
            }
            break;
        case PAIRING:
            if (buttonEvent == ButtonEvent::LONG_PRESSED) {
                // TODO: Stop Pairing process
                transitionToState(IDLE);
            }
            break;
        case ARMED:
            if (switchEvent == SwitchEvent::OPEN) {
                // Trigger alert
            }
            break;
        case ERROR:
            _statusLed.setColor(LedColor::RED);
            break;
    }
    return _currentState;
}

void StateManager::transitionToState(DeviceState newState) {
    _currentState = newState;
    switch (newState) {
        case BOOTING:
            _statusLed.setColor(LedColor::WHITE);
            break;
        case IDLE:
            _statusLed.setColor(LedColor::GREEN);
            break;
        case PAIRING:
            _statusLed.setColor(LedColor::BLUE);
            break;
    }
}