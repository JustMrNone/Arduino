#include <IRremote.h>

int redPin = 11;
int greenPin = 9;
int bluePin = 10;

int receiver = 5; // Corrected spelling: 'reciever' to 'receiver'
float brightnessFactor = 250;
IRrecv Receiver(receiver);
decode_results results;

unsigned long BrightnessUp = 0xF700FF;
unsigned long BrightnessDown = 0xF7807F;

void setup() {
  Serial.begin(9600); // Initialize serial communication
  Receiver.enableIRIn(); // Start the receiver
}

void loop() {
  if (Receiver.decode(&results)) { // Check for received IR signals
    unsigned long value = results.value; // Read the value from the results
    ChangeBrightness(value); // Change brightness based on the received value
    Serial.print("Brightness Factor: "); // Print a label for clarity
    Serial.println(brightnessFactor); // Print the current brightness factor
    Receiver.resume(); // Prepare to receive the next value
  }
}

void ChangeBrightness(unsigned long brightnessValue) {
  if (brightnessValue == BrightnessUp) {
    brightnessFactor += 25;
  } else if (brightnessValue == BrightnessDown) {
    brightnessFactor -= 25;
  }

  // Ensure brightnessFactor stays within bounds
  if (brightnessFactor < 0) {
    brightnessFactor = 0;
  } else if (brightnessFactor > 255) {
    brightnessFactor = 255;
  }
}

void ShowColor()
{
  digitalWrite(redPin, brightnessFactor);
}
