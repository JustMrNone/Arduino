#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C LCD(0x27, 16, 2);
void initilize();
void RED();
void GREEN();
void BLUE();
void CYAN();
void OFF();

int buttons[] = {11, 12, 13, 4};

int redPin = 10;
int greenPin = 9;
int bluePin = 8;

void setup() {

  // Set up pins with internal pull-up resistors
  for (int i = 0; i < 4; i++) {
    pinMode(buttons[i], INPUT_PULLUP);  // Enable internal pull-up resistors
  }

  // Set up RGB LED pins as output
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  LCD.begin(16, 2);
  LCD.backlight();
  LCD.setCursor(0, 0);
  initilize();
}

void loop() {
  // Read buttons, using inverted logic due to pull-up (LOW when pressed)
  int button1 = digitalRead(buttons[0]);
  int button2 = digitalRead(buttons[1]);
  int button3 = digitalRead(buttons[2]);
  int button4 = digitalRead(buttons[3]);

  // Buttons are now active-low (pressed = LOW)
  if (button1 == LOW) {
    LCD.clear();
    LCD.print("RED is On");
    RED();
  } 
  else if (button2 == LOW) {
    LCD.clear();
    LCD.print("GREEN is On");
    GREEN();
  } 
  else if (button3 == LOW) {
    LCD.clear();
    LCD.print("BLUE is On");
    BLUE();
  } 
  else if (button4 == LOW) {
    LCD.clear();
    LCD.print("CYAN is On");
    CYAN();
  }

}
void initilize()
{
  LCD.print("Four Colors.");
}
// Color functions
void RED() {
  analogWrite(redPin, 255);
  analogWrite(greenPin, 0);
  analogWrite(bluePin, 0);
}

void BLUE() {
  analogWrite(redPin, 0);
  analogWrite(greenPin, 255);
  analogWrite(bluePin, 0);
}

void GREEN() {
  analogWrite(redPin, 0);
  analogWrite(greenPin, 0);
  analogWrite(bluePin, 255);
}

void CYAN() {
  analogWrite(redPin, 0);
  analogWrite(greenPin, 255);
  analogWrite(bluePin, 255);
}
void OFF(){
  analogWrite(redPin, 0);
  analogWrite(greenPin, 0);
  analogWrite(bluePin, 0);
}