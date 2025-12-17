#pragma once
#include <Arduino.h>
#include <DigitalInput.h>

enum class ButtonEvent {
    NONE,
    PRESSED,
    RELEASED,
    LONG_PRESSED
};

class Button {
    public:
        Button(uint8_t pin);
        void begin();

        // Call every loop(). Returns one event at most each call
        ButtonEvent update();

        void setLongPressDuration(uint32_t durationMs);
        void setDebounceDuration(uint32_t durationMs);
        bool isPressed() const;
    private:
        DigitalInput _input;

        uint32_t debounceMs = 30;     // typical debounce 30ms
        uint32_t longPressMs = 5000;  // default 5 seconds

        bool stablePressed = false;   // debounced state
        bool lastRawPressed = false;  // raw read last loop

        uint32_t lastChangeMs = 0;    // when raw changed
        uint32_t pressStartMs = 0;    // when stable press started

        bool longPressFired = false;
};