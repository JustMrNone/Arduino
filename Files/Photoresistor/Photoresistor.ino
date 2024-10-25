int sensorPin = A1;
int ledPin = 6;
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
 