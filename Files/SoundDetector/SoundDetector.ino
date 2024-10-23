#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C MYLCD (0x27, 16, 2);  //replace 0x3F with 0x27 if nothing shows up

int sensorPin=A0;
int digitalPin = 7;
int ledPin = 8;

void setup() {
      pinMode (digitalPin, INPUT_PULLUP);
      pinMode (ledPin, OUTPUT);
      MYLCD.init();
      MYLCD.backlight();
      MYLCD.setCursor(1, 0);
      MYLCD.print("Sound Detector");
      delay (3000);
}
 

void loop() {
               int sensorValue = analogRead (sensorPin);
               int digitalState = digitalRead (digitalPin);               
               MYLCD.clear ();
               MYLCD.setCursor(0, 0);
               MYLCD.print("A: ");
               MYLCD.setCursor(3, 0);
               MYLCD.print(sensorValue);   
               MYLCD.setCursor(8, 0);
               MYLCD.print("D: ");
               MYLCD.setCursor(11, 0);
               MYLCD.print (digitalState);   

               
               if (digitalState == 0) {
                 digitalWrite (ledPin, LOW);
               }
               else {
                 digitalWrite (ledPin, HIGH);
               }

               
               MYLCD.setCursor(2, 1);
               if (sensorValue <100) {
                    MYLCD.print("No Sound");
              }
              else {
                    MYLCD.print("Sound Detected");
              }
              delay (200);
}
