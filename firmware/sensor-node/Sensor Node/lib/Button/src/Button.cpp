#include "Button.h"

Button::Button(uint8_t pin) : _input(pin, InputPull::UP, false) {}

void Button::begin() {
    _input.begin();
    stablePressed = _input.isActive();
    lastRawPressed = stablePressed;
    lastChangeMs = millis();
}

ButtonEvent Button::update() {
    bool currentRawPressed = _input.isActive();
    uint32_t currentMs = millis();
    ButtonEvent event = ButtonEvent::NONE;

    // Check for raw state change
    if (currentRawPressed != lastRawPressed) {
        lastChangeMs = currentMs;
        lastRawPressed = currentRawPressed;
    }

    // Check if debounce time has passed
    if ((currentMs - lastChangeMs) >= debounceMs) {
        // Update stable state if it has changed
        if (stablePressed != currentRawPressed) {
            stablePressed = currentRawPressed;

            if (stablePressed) {
                // Button pressed
                pressStartMs = currentMs;
                longPressFired = false;
                event = ButtonEvent::PRESSED;
            } else {
                // Button released
                if (!longPressFired) {
                    event = ButtonEvent::RELEASED;
                }
            }
        }
    }

    // Check for long press
    if (stablePressed && !longPressFired) {
        if ((currentMs - pressStartMs) >= longPressMs) {
            longPressFired = true;
            event = ButtonEvent::LONG_PRESSED;
        }
    }

    return event;
}

void Button::setLongPressDuration(uint32_t durationMs) {
    longPressMs = durationMs;
}

void Button::setDebounceDuration(uint32_t durationMs) {
    debounceMs = durationMs;
}

bool Button::isPressed() const {
    return stablePressed;
}