#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C MYLCD (0x3F, 16, 2);  //replace 0x3F with 0x27 if nothing shows up

int pirPin=7;
int ledPin=8;

void setup() {
               pinMode (pirPin, INPUT);
               pinMode (ledPin, OUTPUT);
               MYLCD.init ();
               MYLCD.backlight();
               MYLCD.setCursor(1, 0);
               MYLCD.print("KankashTech.com");
               delay (3000);
               
}
void loop() {
               int pirState = digitalRead (pirPin);
               if (pirState==LOW) {               
                      MYLCD.clear ();
                      MYLCD.setCursor(4, 0);
                      MYLCD.print("No Motion");
                      digitalWrite (ledPin, LOW);
                }
                else {
                      MYLCD.clear ();
                      MYLCD.setCursor(0, 0);
                      MYLCD.print("Motion Detected");
                      digitalWrite (ledPin, HIGH);
                }
                delay (200);
}
 

