int sensorPin = A0;
int ledPin = 13;
void setup() {
                pinMode (ledPin, OUTPUT);
                Serial.begin (9600);
 }
void loop() {
               int sensorValue = analogRead (sensorPin);
              if (sensorValue > 100 ) {
                    digitalWrite (ledPin, LOW);
              }
               else {
                    digitalWrite (ledPin, HIGH);
               }
               Serial.println (sensorValue);
               delay (200);
}
 