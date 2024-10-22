void setup() {
  pinMode (13, OUTPUT);      // Set pin 13 to be an output
}
void loop() {
  digitalWrite(13, HIGH);    // Turn on the LED
  delay(1000);              // Wait for one second
  digitalWrite(13, LOW);    // Turn off the LED
  delay(1000);              // Wait for one second
}
