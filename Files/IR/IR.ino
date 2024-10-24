#include <IRremote.h>

int receiverPin = 5;  // Connect the output pin of the IR receiver to digital pin 2
IRrecv irrecv(receiverPin);
decode_results results;

void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn();  // Start the IR receiver
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);  // Print the value in HEX format
    irrecv.resume();  // Receive the next value
  }
}
