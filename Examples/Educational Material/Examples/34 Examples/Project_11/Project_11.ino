#include <LiquidCrystal_I2C.h>

#include <dht.h>
dht MYDHT;
int dhtPin=7;
void setup() {
  Serial.begin (9600);
  pinMode (dhtPin, INPUT);
 }
void loop() {
               MYDHT.read11(dhtPin);
               Serial.print ("Temperature: ");
               Serial.print (MYDHT.temperature, 1);
               Serial.print (char(176));
               Serial.print ("C");
               Serial.print ("     Humidity: ");
               Serial.print (MYDHT.humidity, 0);
               Serial.println ("%");
               delay (2000);
}
 

