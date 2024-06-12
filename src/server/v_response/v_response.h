#ifndef V_RESPONSE_H
#define V_RESPONSE_H

#include <stdint.h>  // Додаємо цей заголовок для типів uint8_t, uint16_t тощо
#include <Arduino.h>
#include <WiFi.h>
#include "../v_hash_table/v_hash_table.h"

class VResponse {
private:
    WiFiClient *client;

public:
    VResponse(WiFiClient *c);

    void writeText(String mimetype, String resp);
    void writeJson(VHashTable<String> &resp);
    void writeBuffer(String mimetype, const uint8_t* buffer, size_t size);
};

#endif