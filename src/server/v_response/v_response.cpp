
#include <stdint.h>  // Додаємо цей заголовок для типів uint8_t, uint16_t тощо
#include <Arduino.h>
#include <WiFi.h>
#include "../v_hash_table/v_hash_table.h"
#include "../v_json/v_json.h"
#include "v_response.h"

VResponse::VResponse(WiFiClient *c) {
    this->client = c;
}

void VResponse::writeText(String mimetype, String resp) {
    this->client->println("HTTP/1.1 200 Ok");
    this->client->println("Content-type: " + mimetype);
    this->client->println("Connection: close");
    this->client->println(); // The HTTP response starts with blank line
    this->client->println(resp);// The HTTP response ends with another blank line
}

void VResponse::writeJson(VHashTable<String> &resp) {
    this->client->println("HTTP/1.1 200 Ok");
    this->client->println("Content-type: application/json");
    this->client->println("Connection: close");
    this->client->println(); // The HTTP response starts with blank line
    this->client->println(VJson::stringify(resp)); // The HTTP response ends with another blank line
}

void VResponse::writeBuffer(String mimetype, const uint8_t* buffer, size_t size) {
    this->client->println("HTTP/1.1 200 Ok");
    this->client->println("Content-type: " + mimetype);
    this->client->println("Connection: close");
    this->client->println(); // The HTTP response starts with blank line
    this->client->write(buffer, size); 
    this->client->flush();
    this->client->println(); // The HTTP response ends with another blank line
}
