// cmd+shift+p -> "PlatformIO: Rebuild IntelliSense Index" to update IntelliSense

#include <Arduino.h>
#include <RgbLed.h>
#include <MagneticSwitch.h>

constexpr uint8_t RED_PIN = 2;
constexpr uint8_t GREEN_PIN = 0;
constexpr uint8_t BLUE_PIN = 10;
constexpr uint8_t MAGNETIC_SWITCH_PIN = 9;

// Create a global rgb led instance
RgbLed statusLed(RED_PIN, GREEN_PIN, BLUE_PIN);
MagneticSwitch doorSwitch(MAGNETIC_SWITCH_PIN);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  
  statusLed.begin();
  doorSwitch.begin();
}

void loop() {
  if (doorSwitch.isClosed()) {
    Serial.println("Door is closed");
    statusLed.setColor(GREEN);
  } else {
    Serial.println("Door is open");
    statusLed.setColor(RED);
  }
}
