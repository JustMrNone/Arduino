#include <IRremote.h>
#include <avr/sleep.h>
#include <avr/interrupt.h>

const int recv_pin = 2; // Pin connected to the IR receiver
IRrecv irrecv(recv_pin);
decode_results results;

volatile bool sleepMode = false; // Flag to track sleep state

void setup() {
    Serial.begin(9600);
    irrecv.enableIRIn(); // Start the IR receiver
    Serial.println("Ready to receive IR signals...");
}

void loop() {
    // Check if an IR signal has been received
    if (irrecv.decode(&results)) {
        Serial.print("Received IR code: ");
        Serial.println(results.value, HEX); // Print the received code in HEX

        // Check if the received code matches the button to enter sleep mode
        // Replace 0x20DF10EF with the actual code for your sleep button
        if (results.value == 0x20DF10EF) { // Sleep button code
            Serial.println("Entering sleep mode...");
            enterSleep(); // Call the sleep function
            Serial.println("Woke up from sleep mode!");
        }
        
        // Check if the received code matches the button to wake up
        // Replace 0x20DF10FD with the actual code for your wake button
        if (results.value == 0x20DF10FD) { // Wake button code
            Serial.println("Waking up...");
            wakeUp(); // Handle wake-up logic
        }

        irrecv.resume(); // Receive the next value
    }

    // Your regular code here
    if (!sleepMode) {
        Serial.println("Looping...");
        delay(1000); // Simulate some work
    }
}

// Function to enter sleep mode
void enterSleep() {
    sleepMode = true; // Set sleep mode flag
    set_sleep_mode(SLEEP_MODE_PWR_DOWN); // Set sleep mode to power down
    sleep_enable(); // Enable sleep mode
    sleep_cpu(); // Enter sleep mode
    sleep_disable(); // Disable sleep mode after waking up
}

// Function to handle wake-up logic
void wakeUp() {
    sleepMode = false; // Clear sleep mode flag
    // Additional wake-up logic can be added here if needed
}
