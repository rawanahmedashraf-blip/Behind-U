#include <WiFi.h>
#include <esp_now.h>

typedef struct struct_message {
    int val_1;
    int val_2;
    float val_3;
} struct_message;

// Data to send
struct_message send_Data = {80, 95, 98.6}; // Example values

// Receiver's MAC address
uint8_t receiverMacAddress[] = {0xC8, 0xF0, 0x9E, 0xA4, 0x87, 0xBC};

void OnDataSent(const uint8_t *mac_addr, esp_now_send_status_t status) {
    if (status == ESP_NOW_SEND_SUCCESS) {
        Serial.println("Data sent successfully");
    } else {
        Serial.println("Data sending failed");
    }
}

void setup() {
    Serial.begin(115200);

    // Initialize ESP-NOW
    if (esp_now_init() != ESP_OK) {
        Serial.println("Error initializing ESP-NOW");
        return;
    }

    // Set up the peer (receiver) device
    esp_now_peer_info_t peerInfo;
    memcpy(peerInfo.peer_addr, receiverMacAddress, 6);
    esp_now_add_peer(&peerInfo);

    // Register the callback function for sent data
    esp_now_register_send_cb(OnDataSent);
}

void loop() {
    // Send data
    esp_err_t result = esp_now_send(receiverMacAddress, (uint8_t*)&send_Data, sizeof(send_Data));
    if (result == ESP_OK) {
        Serial.println("Sending data...");
    } else {
        Serial.println("Error sending data");
    }

    delay(5000); // Send data every 5 seconds
}
