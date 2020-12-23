// Do not forget to install the libraries.
#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>

ESP8266WiFiMulti WiFiMulti;
 
// Buzzers pins, the client will react by making a buzz sound
int buzzer1 = 3, buzzer2 = 6;

void setup() {
  Serial.begin(115200);

  for (uint8_t t = 4; t > 0; t--) {
    Serial.printf("[SETUP] WAIT %d...\n", t);
    Serial.flush();
    delay(1000);
  }
  // WIFI Access Station 
  WiFi.mode(WIFI_STA);
  WiFiMulti.addAP("communicate", "123456789");
  pinMode(buzzer1, OUTPUT);
  pinMode(buzzer2, OUTPUT);
}

void loop() {
  // wait for WiFi connection
  if ((WiFiMulti.run() == WL_CONNECTED)) {

    WiFiClient client;
    HTTPClient http;

    Serial.print("[HTTP] begin...\n");
    if (http.begin(client, "http://192.168.4.1")) {  // HTTP


      Serial.print("[HTTP] GET...\n");
      // start connection and send HTTP header
      int httpCode = http.GET();

      // httpCode will be negative on error
      if (httpCode > 0) {
        // HTTP header has been send and Server response header has been handled
        Serial.printf("[HTTP] GET... code: %d\n", httpCode);

        // file found at server
        if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY) {
          String payload = http.getString();
          Serial.println(payload);
          
          if(payload == "1 0"){
            digitalWrite(buzzer1, HIGH);
            digitalWrite(buzzer2, LOW);
          }
          
          if(payload == "1 1"){
            digitalWrite(buzzer1, HIGH);
            digitalWrite(buzzer2, HIGH);
          }
          
          if(payload == "0 1"){
            digitalWrite(buzzer1, LOW);
            digitalWrite(buzzer2, HIGH);
          }
          
          if(payload == "0 0"){
            digitalWrite(buzzer1, LOW);
            digitalWrite(buzzer2, LOW);
          }
          
         }
          
        }
      } else {
        Serial.println("[HTTP] GET... failed ");
      }
      http.end();
    } else {
      Serial.printf("[HTTP} Unable to connect\n");
    }
     delay(10);
  }
