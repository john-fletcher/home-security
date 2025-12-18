#include "EspNowManager.h"

EspNowManager::EspNowManager() {}

void onDataSent(const uint8_t* macAddr, esp_now_send_status_t status) {
    // Handle data sent callback
    if (status == ESP_NOW_SEND_SUCCESS) {
        Serial.println("Data sent successfully");
    } else {
        Serial.println("Data send failed");
    }
}

bool EspNowManager::begin() {
    WiFi.mode(WIFI_STA);

    if (esp_now_init() != ESP_OK) {
        Serial.println("Error initializing ESP-NOW");
        return false;
    }

    //TODO: Register hub peer
    return true;
}

bool EspNowManager::isPaired() const {
    return _isPaired;
}
