#include <IRremote.h>

const int recv_pin = 2; // Pin connected to the IR receiver
IRrecv irrecv(recv_pin);
decode_results results;

void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
  Serial.println("Ready to receive IR signals...");
}

void loop() {
  // Check if an IR signal has been received
  if (irrecv.decode(&results)) {
    Serial.print("Received IR code: ");
    Serial.println(results.value, HEX); // Print the received code in HEX

    // Check if the received code matches the button we want to use (e.g., 0x20DF10EF)
    // Replace 0x20DF10EF with your remote's button code
    if (results.value == 0x20DF10EF) {
      Serial.println("Resetting Arduino...");
      resetArduino(); // Call the reset function
    }
    
    irrecv.resume(); // Receive the next value
  }
}

// Function to reset the Arduino
void resetArduino() {
  // Trigger a reset
  asm volatile ("  jmp 0");
}