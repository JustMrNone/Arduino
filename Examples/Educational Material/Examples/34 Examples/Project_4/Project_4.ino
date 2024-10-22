int ledPin = 11;

void setup() {
                // put your setup code here, to run once
                pinMode (ledPin, OUTPUT);
 }

void loop() {
               int sensorValue= analogRead (A0);
               digitalWrite (ledPin, HIGH);
               delay (sensorValue);
               digitalWrite (ledPin, LOW);
               delay (sensorValue);
}

