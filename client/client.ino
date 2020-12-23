// Do not forget to install the libraries.
#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>

ESP8266WiFiMulti WiFiMulti;
// An Array that will hold the distances retrieved from the server page 
int* Ustates; 
// Buzzers pins, the client will react by making a buzz sound
int buzzer1 = 3, buzzer2 = 6;

// ---------------------------------------------------------- a function to split the data retrieved from the client
int *dataSplitter(String payload){
  char word = '';
  int data[2];
  for(char c: payload){
    if (c == ' '){
      data[0] = int(word) - '0';
      word = '';
      }
    word = c;
    }
     
    data[1] = int(word) - '0';
   return data;
}
// ---------------------------------------------------------

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
          
          Ustates = dataSplitter(payload);

          Serial.println(String(Ustates[0]) + " This is state1" );
          Serial.println(String(Ustates[1]) + " This is state2");
          
          digitalWrite(buzzer1, Ustates[0]);
          digitalWrite(buzzer2, Ustates[1]);
          
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
