//Preprocessor directives
#include <IRremote.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

//Function Prototypes 
void RED();
void GREEN();
void BLUE();
void YELLOW();
void CYAN();
void MAGENTA();
void WHITE();
void SPECTRUM();
void initializeLCD();

//RGB Light Pins 
int redPin = 10;
int greenPin = 8;
int bluePin = 9;
//Infrared Receiver Pin
int reciever = 5;

// 'results' is a variable of type 'decode_results', used to store the decoded IR signal data
// from the IR receiver (e.g., button pressed on remote). It contains the value of the signal
// and other protocol information, which can be used to trigger specific actions.
decode_results results;

// Store the LCD Object in the LiquidCrystal_I2C class 
LiquidCrystal_I2C LCD(0x27, 16, 2);

IRrecv rec(reciever); // Creates an IRrecv object named 'rec' inside IRrecv Class that represents the IR receiver.
// 'rec' will interact with the IR receiver connected to the pin defined by the 'reciever' variable (in this case, pin 5).


//Save the hexadecimal values of the keys in variables 

unsigned long button1 = 0xFF30CF;
unsigned long button2 = 0xFF18E7;
unsigned long button3 = 0xFF7A85;
unsigned long button4 = 0xFF10EF;
unsigned long button5 = 0xFF38C7;
unsigned long button6 = 0xFF5AA5;
unsigned long button7 = 0xFF42BD;
unsigned long button8 = 0xFF4AB5;
unsigned long button9 = 0xFF52AD;
unsigned long button0 = 0xFF6897;



void setup() {
  Serial.begin(9600);
  rec.enableIRIn();
  LCD.begin(16, 2);
  LCD.backlight();
  LCD.setCursor(0, 0);
  
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  initializeLCD();
}

void loop() {
  //show initial text
  if(rec.decode(&results)) {
    unsigned long value = results.value;
    if(value == button1) {
      //clear screen
      LCD.clear();
      LCD.setCursor(0, 1);
      LCD.print("Red Light.");
      RED();
    }
    else if(value == button2) {
      LCD.clear();
      LCD.setCursor(0, 1);
      LCD.print("Green Light.");
      GREEN();
    }
    else if(value == button3) {
      LCD.clear();
      LCD.setCursor(0, 1);
      LCD.print("Blue Light.");
      BLUE();
    }
    else if(value == button4) {
      LCD.clear();
      LCD.setCursor(0, 1);
      LCD.print("Yellow Light.");
      YELLOW();
    }
    else if(value == button5) {
      LCD.clear();
      LCD.setCursor(0, 1);
      LCD.print("Cyan Light.");
      CYAN();
    }
    else if(value == button6) {
      LCD.clear();
      LCD.setCursor(0, 1);
      LCD.print("Magenta Light.");
      MAGENTA();
    }
    else if(value == button7) {
      LCD.clear();
      LCD.setCursor(0, 1);
      LCD.print("White Light.");
      WHITE();
    }
    else if(value == button8)
    {
      LCD.clear();
      LCD.setCursor(0, 1);
      LCD.print("Spectrum Playing.");
      SPECTRUM();
    }

    rec.resume();  // Prepare for the next signal
  }
}

// Logic For Colors

void RED() {
  analogWrite(redPin, 255);   // Full intensity of red
  analogWrite(greenPin, 0);   // No green
  analogWrite(bluePin, 0);    // No blue
}

void GREEN() {
  analogWrite(redPin, 0);     // No red
  analogWrite(greenPin, 255); // Full intensity of green
  analogWrite(bluePin, 0);    // No blue
}

void BLUE() {
  analogWrite(redPin, 0);     // No red
  analogWrite(greenPin, 0);   // No green
  analogWrite(bluePin, 255);  // Full intensity of blue
}

void YELLOW() {
  analogWrite(redPin, 255);   // Full intensity of red
  analogWrite(greenPin, 255); // Full intensity of green
  analogWrite(bluePin, 0);    // No blue
}

void CYAN() {
  analogWrite(redPin, 0);     // No red
  analogWrite(greenPin, 255); // Full intensity of green
  analogWrite(bluePin, 255);  // Full intensity of blue
}

void MAGENTA() {
  analogWrite(redPin, 255);   // Full intensity of red
  analogWrite(greenPin, 0);   // No green
  analogWrite(bluePin, 255);  // Full intensity of blue
}

void WHITE() {
  analogWrite(redPin, 255);   // Full intensity of red
  analogWrite(greenPin, 255); // Full intensity of green
  analogWrite(bluePin, 255);  // Full intensity of blue
}

void initializeLCD() {
  LCD.begin(16, 2);
  LCD.backlight();
  LCD.setCursor(0, 0);
  LCD.print("This is LCD IR.");
  LCD.setCursor(0, 1);
  LCD.print("Press 1 to 8.");
}

//Logic For Spectrum 
void SPECTRUM() {
  int redIntensity = 0;
  int greenIntensity = 0;
  int blueIntensity = 0;

  // Fade from Red -> Yellow -> Green
  for (greenIntensity = 0; greenIntensity <= 255; greenIntensity++) {
    analogWrite(redPin, 255);
    analogWrite(greenPin, greenIntensity);
    analogWrite(bluePin, 0);
    delay(20);
  }

  // Fade from Green -> Cyan -> Blue
  for (redIntensity = 255; redIntensity >= 0; redIntensity--) {
    analogWrite(redPin, redIntensity);
    analogWrite(greenPin, 255);
    analogWrite(bluePin, 0);
    delay(20);
  }
  
  for (blueIntensity = 0; blueIntensity <= 255; blueIntensity++) {
    analogWrite(redPin, 0);
    analogWrite(greenPin, 255);
    analogWrite(bluePin, blueIntensity);
    delay(20);
  }

  // Fade from Blue -> Magenta -> Red
  for (greenIntensity = 255; greenIntensity >= 0; greenIntensity--) {
    analogWrite(redPin, 0);
    analogWrite(greenPin, greenIntensity);
    analogWrite(bluePin, 255);
    delay(20);
  }

  for (redIntensity = 0; redIntensity <= 255; redIntensity++) {
    analogWrite(redPin, redIntensity);
    analogWrite(greenPin, 0);
    analogWrite(bluePin, 255);
    delay(20);
  }

  // Fade from Magenta -> White -> Off
  for (greenIntensity = 0; greenIntensity <= 255; greenIntensity++) {
    analogWrite(redPin, 255);
    analogWrite(greenPin, greenIntensity);
    analogWrite(bluePin, 255);
    delay(20);
  }
  
  for (redIntensity = 255; redIntensity >= 0; redIntensity--) {
    analogWrite(redPin, redIntensity);
    analogWrite(greenPin, redIntensity);
    analogWrite(bluePin, redIntensity);
    delay(20);
  }

  LCD.clear();
  initializeLCD();

}
