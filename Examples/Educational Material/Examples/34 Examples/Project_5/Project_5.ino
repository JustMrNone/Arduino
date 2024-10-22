int ledPin = 11;

void setup() {
                // put your setup code here, to run once
                pinMode (ledPin, OUTPUT);
 }

void loop() {
               int sensorPin = A0;
               int sensorValue= analogRead (sensorPin);
               int intensity = map (sensorValue, 0, 1023, 0, 255);
//             int intensity= sensorValue/4;
               analogWrite (ledPin, intensity);
               delay(500);
               
}

