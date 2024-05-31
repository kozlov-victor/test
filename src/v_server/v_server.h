#ifndef V_SERVER_H
#define V_SERVER_H

#include <Arduino.h>
#include <WiFi.h>

class VServer {
private:
  String ssid;
  String password;
  WiFiServer server;
public:
  VServer();
  VServer(String ssid, String password, int port);
  void setup();
  void listenToNextClient();

};

#endif;