#include <WiFi.h>
#include "src/v_server/v_server.h"
#include "src/v_array_list/v_array_list.h"
#include "src/v_strings/v_strings.h"
#include "src/v_hash_table/v_hash_table.h"
#include "src/v_json/v_json.h"

VServer vServer("Lanet_200","Oracle_db12",80);

void setup() {
    Serial.begin(115200);
    vServer.setup();
    VArrayList<String> list;
    list.add("test1");
    list.add("test2");
    list.add("test3");
    list.add("test4");
    list.add("test5");
    list.add("test6");
    list.add("test7");
    list.add("test8");
    list.add("test9");
    list.add("test10");
    list.add("test11");
    list.add("test12");
    list.add("test13");
    list.add("test14");
    list.addAt("inserted",1);
    list.removeAt(0);
    Serial.println(list.size());
    Serial.println(list.indexOf("test9"));
    Serial.println(list.has("test9"));
    Serial.println(list.has("test91"));
    Serial.println(list.empty());
    for (size_t i = 0;i<list.size();i++) {
        Serial.println(list.getAt(i));
    }
    VArrayList<String> parts = VStrings::splitBy("test1+test2,,,,test3,last,WWW,123",',');
    for (size_t i = 0;i<parts.size();i++) {
        Serial.println(parts.getAt(i));
    }
    VHashTable<String> table;
    table["key1"] = "value1";
    table["key1"] = "value1_new";
    table.put("key2","value2");
    table.put("key2","value2_new");
    table.put("key3","value3");
    table.put("key3","value3_new");
    table.remove("key2");
    table.remove("key2_____");
    Serial.println(table.has("key2"));
    table.forEach([](const String key, const String value) {
        Serial.print("Key: ");
        Serial.print(key);
        Serial.print(", Value: ");
        Serial.println(value);
    });
    Serial.println(VJSon::stringify(table));

    VHashTable<String> json = VJSon::parse("{\"key1\":\"value1\",\"key2\":\"value2\",\"key3\":{\"value3\"}}");
    Serial.println("---json---");
    Serial.println(json.size());
    json.forEach([](const String key, const String value) {
        Serial.print("Key: ");
        Serial.print(key);
        Serial.print(", Value: ");
        Serial.println(value);
    });
    Serial.println(VJSon::stringify(json));
}

void loop(){
    vServer.listenToNextClient();
//   WiFiClient client = server.available();   // Listen for incoming clients
//
//   if (client) {                             // If a new client connects,
//     currentTime = millis();
//     previousTime = currentTime;
//     Serial.println("New Client.");          // print a message out in the serial port
//     String currentLine = "";                // make a String to hold incoming data from the client
//     while (client.connected() && currentTime - previousTime <= timeoutTime) {  // loop while the client's connected
//       currentTime = millis();
//       if (client.available()) {             // if there's bytes to read from the client,
//         char c = client.read();             // read a byte, then
//         Serial.write(c);                    // print it out the serial monitor
//         header += c;
//         if (c == '\n') {                    // if the byte is a newline character
//           // if the current line is blank, you got two newline characters in a row.
//           // that's the end of the client HTTP request, so send a response:
//           if (currentLine.length() == 0) {
//             // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
//             // and a content-type so the client knows what's coming, then a blank line:
//             client.println("HTTP/1.1 200 OK");
//             client.println("Content-type:text/html");
//             client.println("Connection: close");
//             client.println();
//
//             // turns the GPIOs on and off
//             if (header.indexOf("GET /26/on") >= 0) {
//               Serial.println("GPIO 26 on");
//               output26State = "on";
//               digitalWrite(output26, HIGH);
//             } else if (header.indexOf("GET /26/off") >= 0) {
//               Serial.println("GPIO 26 off");
//               output26State = "off";
//               digitalWrite(output26, LOW);
//             } else if (header.indexOf("GET /27/on") >= 0) {
//               Serial.println("GPIO 27 on");
//               output27State = "on";
//               digitalWrite(output27, HIGH);
//             } else if (header.indexOf("GET /27/off") >= 0) {
//               Serial.println("GPIO 27 off");
//               output27State = "off";
//               digitalWrite(output27, LOW);
//             }
//
//             // Display the HTML web page
//             client.println("<!DOCTYPE html><html>");
//             client.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
//             client.println("<link rel=\"icon\" href=\"data:,\">");
//             // CSS to style the on/off buttons
//             // Feel free to change the background-color and font-size attributes to fit your preferences
//             client.println("<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}");
//             client.println(".button { background-color: #4CAF50; border: none; color: white; padding: 16px 40px;");
//             client.println("text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}");
//             client.println(".button2 {background-color: #555555;}</style></head>");
//
//             // Web Page Heading
//             client.println("<body><h1>ESP32 Web Server</h1>");
//
//             // Display current state, and ON/OFF buttons for GPIO 26
//             client.println("<p>GPIO 26 - State " + output26State + "</p>");
//             // If the output26State is off, it displays the ON button
//             if (output26State=="off") {
//               client.println("<p><a href=\"/26/on\"><button class=\"button\">ON</button></a></p>");
//             } else {
//               client.println("<p><a href=\"/26/off\"><button class=\"button button2\">OFF</button></a></p>");
//             }
//
//             // Display current state, and ON/OFF buttons for GPIO 27
//             client.println("<p>GPIO 27 - State " + output27State + "</p>");
//             // If the output27State is off, it displays the ON button
//             if (output27State=="off") {
//               client.println("<p><a href=\"/27/on\"><button class=\"button\">ON</button></a></p>");
//             } else {
//               client.println("<p><a href=\"/27/off\"><button class=\"button button2\">OFF</button></a></p>");
//             }
//             client.println("</body></html>");
//
//             // The HTTP response ends with another blank line
//             client.println();
//             // Break out of the while loop
//             break;
//           } else { // if you got a newline, then clear currentLine
//             currentLine = "";
//           }
//         } else if (c != '\r') {  // if you got anything else but a carriage return character,
//           currentLine += c;      // add it to the end of the currentLine
//         }
//       }
//     }
//     // Clear the header variable
//     header = "";
//     // Close the connection
//     client.stop();
//     Serial.println("Client disconnected.");
//     Serial.println("");
//  }
}