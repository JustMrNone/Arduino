#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 for a 16 chars and 2-line display
LiquidCrystal_I2C MYLCD(0x27, 16, 2);

void setup() {
  // Initialize the LCD with the number of columns and rows
  MYLCD.begin(16, 2);
  
  // Turn on the backlight (optional, depending on your module)
  MYLCD.backlight();
  
  // Print "Hello" to the LCD
  MYLCD.setCursor(0, 0);  // Set the cursor to column 0, line 0
  MYLCD.print("Hello There I am \n here");
}

void loop() {
  // The loop is left empty as we only need to print once
}
