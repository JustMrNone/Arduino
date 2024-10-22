int lmPin = A0;

void setup() {
  Serial.begin (9600);
 }
void loop() {
               float sensorValue = analogRead (lmPin);
               float temp = 0.488 * sensorValue;
               Serial.print ("Temperature: ");
               Serial.print (temp, 1);
               Serial.print (char(176));
               Serial.println ('C');
               delay (500);
}
 

