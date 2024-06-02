#ifndef V_SERVER_H
#define V_SERVER_H

#include <Arduino.h>
#include <WiFi.h>
#include "../v_array_list/v_array_list.h"
#include "../v_hash_table/v_hash_table.h"

class VServer {
private:
  String ssid;
  String password;
  WiFiServer server;
  VArrayList<String> readLines(WiFiClient &client);
  void parseFirstLine(String firstLine, String *method, String *url, VHashTable<String> *params);
  void parseLines(VArrayList<String> &lines, String *method, String *url, VHashTable<String> *headers, VHashTable<String> *params);
public:
  VServer();
  VServer(String ssid, String password, int port);
  void setup();
  void listenToNextClient();
};

#endif;