#pragma once
#include <Arduino.h>
#include <esp_now.h>
#include <WiFi.h>

enum MessageType {
    PAIRING,
    DATA
};

typedef struct structMessage {
    uint8_t type;
    uint8_t id;
    bool isOpen;
} structMessage;

typedef struct structPairing {
    uint8_t msgType;
    uint8_t id;
    uint8_t macAddr[6];
    uint8_t channel;
} struct_pairing;

class EspNowManager {
    public:
        EspNowManager();
        bool begin(); // Returns true if initializes successful
        void startPairing();
        void stopPairing();
        bool sendData(const uint8_t* peerAddr, const uint8_t* data, size_t len);
        bool isPaired() const;
    private:
        void onDataSent(const uint8_t* macAddr, esp_now_send_status_t status);

        bool _isPaired = false;
};