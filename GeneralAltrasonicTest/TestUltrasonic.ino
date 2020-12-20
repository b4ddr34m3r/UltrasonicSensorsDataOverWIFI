#include <Ultrasonic>

int U1T = 1, U1E = 2;
int U2T = 3, U2E = 4;

void setup(){
  Serial.begin(115200);
  Ultrasonic ultrasoinc1(U1T, U1E);
  Ultrasonic ultrasoinc2(U2T, U2E);
}


void loop(){
  int distanceU1 = ultrasonic1.read();
  int distanceU2 = ultrasonic2.read();
  
  Serial.print("Distance of Ultrasonic sensor 1: "); Serial.println(distanceU1);
  Serial.print("Distance of Ultrasonic sensor 2: "); Serial.println(distanceU2);
}