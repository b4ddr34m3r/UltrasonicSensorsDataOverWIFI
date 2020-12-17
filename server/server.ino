#include <ESP8266WebServer.h>    
#include <ESP8266WiFi.h>
#include <Ultrasonic.h>

 // the first ultrasonic sensor pins
Ultrasonic ulsc1(2,3); // trig, echo
// the second ultrasonic sensor pins
Ultrasonic ulsc2(5,6); // trig, echo

ESP8266WebServer server(80);   
// variables will hold the distance data from Sensors.
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
 // start WIFI Access Point
  Serial.println(WiFi.softAPIP());
  server.handleClient();
  
  delay(100);
   
 // reading the distance 
   dist1 = ulsc1.read();
   dist2 = ulsc2.read();
 // printing the distance to the serial monitor
  Serial.println(String(dist1)+ " This is the distance1.");
  Serial.println(String(dist2)+ " This is the distance2.");
  
 // 
  server.on("/", HTTP_GET, handleData);
}

void handleData(){
   server.send(200, "text/plain", String(dist1) + " " + String(dist2));
  }
