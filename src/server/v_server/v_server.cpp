
#include <Arduino.h>
#include <WiFi.h>
#include "./v_server.h"
#include "../v_array_list/v_array_list.h"
#include "../v_hash_table/v_hash_table.h"
#include "../v_strings/v_strings.h"
#include "../v_json/v_json.h"
#include "../v_route_registry/v_route_registry.h"
#include "../v_request/v_request.h"
#include "../v_response/v_response.h"
#include "v_server.h"

#include "../static/static.h"

const unsigned long TIMEOUT = 2000;


VServer::VServer(String ssid, String password,int port,boolean accessPointMode) {
    this->ssid = ssid;
    this->password = password;
    this->accessPointMode = accessPointMode;
    this->server = WiFiServer(port);
}

void VServer::setup() {
    if (this->accessPointMode) {
        WiFi.softAP("esp32", "12345678");
        Serial.println("Access point activated");
        Serial.print("IP address: ");
        Serial.println(WiFi.softAPIP());
    }
    else {
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
    }
    this->server.begin();
}

void VServer::readRequest(WiFiClient &client, String *method, String *url, VHashTable<String> *headers, VHashTable<String> *params) {
    String currentLine = "";
    boolean isFirstLine = true;
    boolean isBody = false;
    String bodyRaw;
    int contentLengthCnt = 0;
    unsigned long lastTime = millis();
    unsigned long currTime = lastTime;
    
    while (client.connected()) {
        currTime = millis();
        unsigned long delta = currTime - lastTime;
        if (delta > TIMEOUT) {
            Serial.printf("currTime=%d\n",currTime);
            Serial.printf("lastTime=%d\n",lastTime);
            Serial.printf("delta=%d\n",delta);
            Serial.println("Connection timeout");
            break;
        }
        if(client.available()) {
            char c = client.read();
            lastTime = millis();
            Serial.println(String(c) + " " + int(c));
            if (isBody) { // is body, accumulate raw body untill contentLengthCnt is lt contentLength
                Serial.println("--------------------is body-----------------------------");
                bodyRaw+=String(c);
                contentLengthCnt++;
                String contentLength = headers->get("Content-Length");
                if (contentLength.length()>0) {
                    if (contentLengthCnt==contentLength.toInt()) {
                        break;
                    }
                }
            }
            if (c=='\r') continue;
            if (c=='\n') { // is new line
                if (currentLine.length()==0) {
                    if (*method=="GET") {
                        break;
                    }
                    if (headers->get("Content-Length")=="0") { // if body is empty
                        break;
                    }
                    isBody = true;
                }
                if (isFirstLine) { // first line (ie GET /index HTTP 1.1)
                    isFirstLine = false;
                    this->parseFirstLine(currentLine, method, url, params);
                }
                else if (!isBody) { // headers
                    this->parseHeaderLine(currentLine,headers);
                }
                currentLine = "";
            }
            else { // accumulate line
                if (!isBody) currentLine+=String(c);
            }
        }
    }
    //Serial.println("bodyRaw = "  + bodyRaw);
    this->parseBody(bodyRaw,params);
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

void VServer::parseHeaderLine(String line,VHashTable<String> *headers) {
    VArrayList<String> pair = VStrings::splitBy(line,':');
    if (pair.size()>=2) {
        String val = pair.getAt(1);
        val.trim();
        headers->put(pair.getAt(0),val);
    }
}

void VServer::parseBody(String bodyRaw, VHashTable<String> *params) {
    VHashTable<String> body = VJson::parse(bodyRaw);
    body.forEach([&params](const String key, const String value) {
        params->put(key,value);
    });
}

void VServer::listenToNextClient() {
    WiFiClient client = server.available();
    if (!client) return;
    Serial.println("Accepted new connection");
    
    String method = "";
    String url = "";
    VHashTable<String> headers;
    VHashTable<String> params;

    this->readRequest(client, &method, &url, &headers, &params);

    VRequest req(method, &headers, &params);
    VResponse resp(&client);
    if (!VRouteRegistry::handleRequest(url,method,&req,&resp)) {
        Serial.println("Not handled");
        client.println("HTTP/1.1 404 Not Found");
        client.println("Connection: close");
        client.println("Content-type: text/html");
        client.println();
        client.println("<h1>404</h1>");
    }
    client.flush();  // Ensure all data is sent
    client.stop();
    Serial.println("Client connection closed");
}