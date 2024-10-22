int switchPin = 12;
int enablePin = 11;
int in1Pin = 10;
int in2Pin = 9;
int potPin = A0;
void setup() {
  pinMode (in1Pin, OUTPUT);
  pinMode (in2Pin, OUTPUT);
  pinMode (enablePin, OUTPUT);
  pinMode (switchPin, INPUT_PULLUP);
}
void loop() {
  int speed = analogRead(potPin) / 4;
  int state = digitalRead (switchPin);
  if (state == HIGH) {
      analogWrite (enablePin, speed);
      digitalWrite  (in1Pin, HIGH);
      digitalWrite  (in2Pin, LOW);
  }
  else {
      analogWrite (enablePin, speed);
      digitalWrite  (in1Pin, LOW);
      digitalWrite  (in2Pin, HIGH);
  }
}
