
#include <Arduino.h>
#include "./v_server.h"
#include "../v_array_list/v_array_list.h"
#include "../v_hash_table/v_hash_table.h"
#include "../v_strings/v_strings.h"
#include "../v_json/v_json.h"
#include "v_server.h"

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

VArrayList<String> VServer::readLines(WiFiClient& client) {
    String currentLine = "";
    VArrayList<String> lines;
    unsigned long lastTime = millis();
    while (client.connected()) {
        if (millis() - lastTime > TIMEOUT) break;
        while(client.available()){
            char c = client.read();
            Serial.print(String(c));
            if (c=='\r') continue;
            if (c=='\n') {
                lines.add(currentLine);
                currentLine = "";
            }
            else {
                currentLine+=String(c);
            }
        }
    }
    if (currentLine.length()>0) {
        lines.add(currentLine);
    }
    return lines;
}

void VServer::parseFirstLine(String firstLine, String *method, String *url, VHashTable<String> *params) {
    VArrayList<String> parts = VStrings::splitBy(firstLine,' ');
    if (parts.size()>=2) {
        *method = parts.getAt(0);
        *url = parts.getAt(1);
        if (url->indexOf("?")>-1) {
            VArrayList<String> urlParts = VStrings::splitBy(*url,'?');
            *url = urlParts.getAt(0);
            String queryString = urlParts.getAt(1);
            VArrayList<String> queryParts = VStrings::splitBy(queryString,'&');
            for (size_t i = 0;i<queryParts.size();i++) {
                VArrayList<String> pair = VStrings::splitBy(queryParts.getAt(i),'=');
                params->put(pair.getAt(0),pair.getAt(1));
            }
        }
    }
}

void VServer::parseLines(VArrayList<String> &lines, String *method, String *url, VHashTable<String> *headers, VHashTable<String> *params)
{
    if (lines.size()>0) {
        this->parseFirstLine(lines.getAt(0), method, url, params);
    }

    boolean isBody = false;
    String bodyRaw = "";
    for (size_t i = 1;i<lines.size();i++) {
        String s = lines.getAt(i);
        if (s.length()==0) {
            isBody = true;
            continue;
        }
        if (isBody) {
            bodyRaw+=s;
        }
        else {
            VArrayList<String> pair = VStrings::splitBy(s,':');
            if (pair.size()>=2) {
                String val = pair.getAt(1);
                val.trim();
                headers->put(pair.getAt(0),val);
            }
        }
    }

    VHashTable<String> body = VJSon::parse(bodyRaw);
    body.forEach([&params](const String key, const String value) {
        params->put(key,value);
    });
}

void VServer::listenToNextClient() {
    WiFiClient client = server.available();
    if (!client) return;
    Serial.println("Accepted new connection");
    
    VArrayList<String> lines = readLines(client);

    String method = "";
    String url = "";
    VHashTable<String> headers;
    VHashTable<String> params;

    this->parseLines(lines, &method, &url, &headers, &params);

    Serial.println("Disconnected");
    
    client.println("HTTP/1.1 200 OK");
    client.println("Content-type:text/json");
    client.println("Connection: close");
    client.println(); // The HTTP response starts with blank line
    //client.println("{\"done\":true}");
    client.println(method);
    client.println(url);
    client.print(VJSon::stringify(params));
    client.println(VJSon::stringify(headers));
    client.println(); // The HTTP response ends with another blank line
    client.stop();
}