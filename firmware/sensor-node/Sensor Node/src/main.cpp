// cmd+shift+p -> "PlatformIO: Rebuild IntelliSense Index" to update IntelliSense

#include <Arduino.h>
#include <RgbLed.h>
#include <MagneticSwitch.h>
#include <Button.h>
#include <StateManager.h>

constexpr uint8_t RED_PIN = 2;
constexpr uint8_t GREEN_PIN = 0;
constexpr uint8_t BLUE_PIN = 10;
constexpr uint8_t MAGNETIC_SWITCH_PIN = 9;
constexpr uint8_t BUTTON_PIN = 4;

// Create a global rgb led instance
RgbLed statusLed(RED_PIN, GREEN_PIN, BLUE_PIN);
MagneticSwitch doorSwitch(MAGNETIC_SWITCH_PIN);
Button controlButton(BUTTON_PIN);

StateManager stateManager(statusLed);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  
  statusLed.begin();
  doorSwitch.begin();
  controlButton.begin();
  stateManager.begin();
}

void loop() {
  ButtonEvent buttonEvent = controlButton.update();
  SwitchEvent switchEvent = doorSwitch.update();
  stateManager.update(buttonEvent, switchEvent);
}
