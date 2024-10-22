int PINS[] = {13, 12, 11};

void setup() {
  // Set each pin as OUTPUT
  for (int i = 0; i < 3; i++) {
    pinMode(PINS[i], OUTPUT);
  }
}

void loop() {
  // Light up each LED in sequence
  for (int index = 0; index < 3; index++) {
    digitalWrite(PINS[index], HIGH);  // Turn the current LED on
    delay(500);                       // Wait for half a second
    digitalWrite(PINS[index], LOW);   // Turn the current LED off
  }
}