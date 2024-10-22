int switchPin = 2;
int ledPin = 13;

void setup() {
  pinMode (switchPin, INPUT_PULLUP);
  pinMode (ledPin, OUTPUT);
 }
void loop() {
               int switchVal = digitalRead (switchPin);
               if (switchVal==HIGH) {
                    digitalWrite (ledPin, LOW);
               }
               else {
                    digitalWrite (ledPin, HIGH);
              }
}
 

