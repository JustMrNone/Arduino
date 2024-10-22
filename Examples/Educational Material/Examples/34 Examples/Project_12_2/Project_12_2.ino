#include <LiquidCrystal_I2C.h>
#include <dht.h>

LiquidCrystal_I2C MYLCD (0x3F, 16, 2); //replace 0x3F with 0x27 if nothing shows up
dht MYDHT;
int dhtPin=7;

void setup() {
         pinMode (dhtPin, INPUT);
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
               MYDHT.read11(dhtPin);
               MYLCD.clear ();
               MYLCD.setCursor(0, 0);
               MYLCD.print("Tem: ");
               MYLCD.print(MYDHT.temperature, 1);   
               MYLCD.print(char(176)); 
               MYLCD.print("C");  
               MYLCD.setCursor(0, 1);
               MYLCD.print("Hum: ");
               MYLCD.print(MYDHT.humidity);   
               MYLCD.print("%"); 
               delay (2000);
}
 

