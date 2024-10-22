
#include <Servo.h>

int sensorPin =A0;
Servo myServo;

void setup () {
  myServo.attach (9);
  myServo.write (0);
  delay (1000);
  myServo.write (90);
  delay (1000);
  myServo.write (180);
  delay (1000);
}

void loop () {
  int sensorValue = analogRead (sensorPin);
  int position = map (sensorValue, 0, 1023, 0, 180);
  myServo.write (position);
}

