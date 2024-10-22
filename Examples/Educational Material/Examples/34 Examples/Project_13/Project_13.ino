#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C MYLCD (0x3F, 16, 2);  //replace 0x3F with 0x27 if nothing shows up
int sensorPin=A0;

void setup() {
               MYLCD.init ();
               MYLCD.backlight();
               MYLCD.setCursor(1, 0);
               MYLCD.print("KankashTech.com");
               delay (3000);
               for (int cursor=0; cursor<16; cursor++) {
                    MYLCD.scrollDisplayLeft();
                    delay (500);  
               }
}
 
void loop() {
               int sensorValue = analogRead (sensorPin);
               MYLCD.clear ();
               MYLCD.setCursor(2, 0);
               MYLCD.print("Water Value: ");
               MYLCD.setCursor(6, 1);
               MYLCD.print(sensorValue);   
               delay (200);
}
 

