
#include <Arduino.h>
#include "./v_server.h"

const long TIMEOUT = 500;

VServer::VServer(){}

VServer::VServer(String ssid, String password,int port) {
    this->ssid = ssid;
    this->password = password;
    this->server = WiFiServer(port);
}

void VServer::setup() {
    Serial.print("Connecting to ");
    Serial.println(ssid);
    WiFi.begin(this->ssid, this->password);
    while (WiFi.status() != WL_CONNECTED) {
      delay(500);
      Serial.print(".");
    }
    // Print local IP address and start web server
    Serial.println("");
    Serial.println("WiFi connected.");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
    this->server.begin();
}

void VServer::listenToNextClient() {
    WiFiClient client = server.available();
    if (!client) return;
    Serial.println("Accepted new connection");
    String req = "";

    uint8_t ch;
    unsigned long lastTime = millis();
    while (client.connected()) {
        if (millis() - lastTime > TIMEOUT) break;
        while(client.available()){
            char c = client.read();
            req+=String(c);
        }
    }
    if (req.length()==0) {
        client.stop();
        Serial.println("empty request body");
        return;
    }
    Serial.print("req=");
    Serial.println(req);
    Serial.println("Disconnected");
    client.println("HTTP/1.1 200 OK");
    client.println("Content-type:text/html");
    //client.println("Connection: close");
    client.println(); // The HTTP response starts with blank line
    client.println("{\"done\":true}");
    client.println(); // The HTTP response ends with another blank line
    client.stop();
}