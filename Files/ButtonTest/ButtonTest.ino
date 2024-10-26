#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C LCD(0x27, 16, 2);

int ledpin = 6;
int button  = 4;
int button1 = 12;
int button2 = 13;
int button3 = 8;

int redPin = 11;
int greenPin = 9;
int bluePin = 10;

void setup() {
  pinMode(ledpin, OUTPUT);

  // Enable internal pull-ups for button pins
  pinMode(button, INPUT_PULLUP);
  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
  pinMode(button3, INPUT_PULLUP);

  // Set RGB LED pins as outputs and ensure off at startup
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  setColor(0, 0, 0); // Ensure RGB LED is off at startup

  // Initialize LCD
  LCD.begin(16, 2);
  LCD.backlight();
  LCD.setCursor(0, 0);
}

void loop() {
  int buttonOne = digitalRead(button);
  int buttonTwo = digitalRead(button1);
  int buttonThree = digitalRead(button2);
  int buttonFour = digitalRead(button3);

  if (buttonOne == LOW) {  // Button 1 pressed
    LCD.clear();
    RED();
    LCD.print("RED is ON");
    delay(300);
  }
  else if (buttonTwo == LOW) {
    LCD.clear();
    GREEN();
    LCD.print("GREEN is ON");
    delay(300);
  }
  else if (buttonThree == LOW)
  {
    LCD.clear();
    BLUE();
    LCD.print("BLUE is ON");
    delay(300);
  }
  else if (buttonFour == LOW)
  {
    LCD.clear();
    OFF();
    LCD.print("OFF");
    delay(300);
  }

  // Add additional button checks if needed
}

void setColor(int red, int green, int blue) {
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
}

void RED() {
  setColor(255, 0, 0);
}

void GREEN() {
  setColor(0, 255, 0);
}

void BLUE() {
  setColor(0, 0, 255);
}

void OFF() {
  setColor(0, 0, 0);
}