#ifndef V_RESPONSE_H
#define V_RESPONSE_H

#include <Arduino.h>
#include <WiFi.h>
#include "../v_hash_table/v_hash_table.h"

class VResponse {
private:
    WiFiClient *client;

public:
    VResponse(WiFiClient *c);

    void writeText(String mimetype, String resp);
    void writeJson(VHashTable<String> resp);

};

#endif