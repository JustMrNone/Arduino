int red = A2;  // GPIO Pin 4 connected to the LED

void setup() {
  pinMode(red, OUTPUT);  // Set pin 4 as an output
}

void loop() {
  digitalWrite(red, LOW);  // Turn the LED on (5V to pin 4)
}
