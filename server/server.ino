#include <ESP8266WebServer.h>    
#include <ESP8266WiFi.h>
#include <Ultrasonic.h>

Ultrasonic ulsc1(2,3); // the first ultrasonic sensor
Ultrasonic ulsc2(5,6); // the second ultrasonic sensor

ESP8266WebServer server(80);   
 
int dist1 = 0, dist2 = 0;
const char* ssid = "communicate";    
const char* pass = "123456789";

void setup() {      
  Serial.begin(115200);    
  WiFi.softAP(ssid, pass);
  server.begin();
}

void loop() {
  Serial.print("The IP address is: ");
  Serial.println(WiFi.softAPIP());
  server.handleClient();
  
  delay(100);
    
   dist1 = ulsc1.read();
   dist2 = ulsc2.read();
  Serial.println(String(dist1)+ " This is the distance1.");
  Serial.println(String(dist2)+ " This is the distance2.");
  
  server.on("/", HTTP_GET, handleData);
}

void handleData(){
   server.send(200, "text/plain", String(dist1) + " " + String(dist2));
  }
