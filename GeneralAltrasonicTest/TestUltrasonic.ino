#include <Ultrasonic.h>

// The T in these variables means Trigger
// and E in these varaibles means Echo
int U1T = 1, U1E = 2;
int U2T = 3, U2E = 4;

Ultrasonic ultrasoinc1(U1T, U1E);
Ultrasonic ultrasoinc2(U2T, U2E);

void setup(){
  Serial.begin(115200);
}


void loop(){
  // Reading distances in centimeters
  int distanceU1 = ultrasoinc1.read();
  int distanceU2 = ultrasoinc2.read();

  // printing out the distances to the  serial monitors
  Serial.print("Distance of Ultrasonic sensor 1: "); Serial.println(distanceU1);
  Serial.print("Distance of Ultrasonic sensor 2: "); Serial.println(distanceU2);
}
