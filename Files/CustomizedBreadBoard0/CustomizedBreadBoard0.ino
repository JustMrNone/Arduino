#include <LiquidCrystal_I2C.h>
#include <IRremote.h>

void initializeLCD();
void ModeOne();
int UltraSonic();
void HexaIRreciever();
void MainMode();
void ChangeBrightness();
void lightSensor();
void ClickerButton();
void startlcd();
void OFF();
void Flash(int dur);
void NextPrev(int Value);


// Red Variations
void RED();
void R1();
void R2();
void R3();
void YELLOW();
// Green Variations
void GREEN();
void G1();
void G2();
void G3();
void G4();

// Blue Variations
void BLUE();
void BL1();
void B2();
void B3();
void B4();

// Whites
void WHITE();


void SPECTRUM();
void ENHANCED_SPECTRUM();

// UltraSonic Sensor 
int Trig = 3;
int Echo = 2;
int duration, distance; 
int reciever = 5;

//clickers 

int clickbutton  = 4;
int clickbutton1 = 12;
int clickbutton2 = 13;
int clickbutton3 = 8;

//light sensor 
int sensorPin = A0;
int digitalPin = 7;
int ledPin = 6;

//RGB Light Pins 
int redPin = 11;
int greenPin = 9;
int bluePin = 10;

//LCD config
LiquidCrystal_I2C LCD(0x27, 16, 2);

//Infrared Reciever Config 
IRrecv Reciever(reciever);
decode_results results;

//main controller buttons mapping
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
unsigned long button100 = 0xFF9867;
unsigned long button200 = 0xFFB04F;
unsigned long minus = 0xFFE01F; 
unsigned long plus = 0xFFA857;
unsigned long eq = 0xFF906F;
unsigned long prevv = 0xFF22DD; 
unsigned long nextt = 0xFF02FD;
unsigned long PlayPause = 0xFFC23D;
unsigned long chpluse = 0xFFE21D;
unsigned long chminus = 0xFFA25D;
unsigned long chhh = 0xFF629D;

//other controller 

unsigned long REDB = 0xF720DF;
unsigned long GREENB = 0xF7A05F;
unsigned long BLUEB = 0xF7609F;
unsigned long WHITEB = 0xF7E01F;
unsigned long R1B = 0xF710EF;
unsigned long R2B= 0xF730CF;
unsigned long R3B= 0xF708F7;
unsigned long G1B =  0xF7906F;
unsigned long G2B = 0xF7B04F;
unsigned long G3B = 0xF78877;
unsigned long B1B = 0xF750AF;
unsigned long B2B = 0xF7708F;
unsigned long B3B = 0xF748B7;
unsigned long BrightnessUp = 0xF700FF;
unsigned long BrightnessDown = 0xF7807F;
unsigned long OFFbtn = 0xF740BF;
unsigned long ON = 0xF7C03F;
unsigned long Play = 0xF7A857;
unsigned long Next = 0xF76897;
unsigned long Prev = 0xF728D7;
unsigned long Smooth = 0xF7E817;
unsigned long Fade = 0xF7C837;
unsigned long strobe = 0xF7F00F;
unsigned long Flashbtn = 0xF7D02F;
float brightnessFactor = 1.0;
// Variables for brightness levels



void setup() {
  // Setup for UltraSonic Sensor
  Serial.begin(9600);
  pinMode(Trig, OUTPUT);
  pinMode(Echo, INPUT);
  // Setup for LCD
  LCD.begin(16, 2);
  LCD.backlight();
  LCD.setCursor(0, 0);
  //light
  pinMode (digitalPin, INPUT_PULLUP);
  pinMode (ledPin, OUTPUT);
  //LCD.print("Test.");
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

    // Enable internal pull-ups for button pins
  pinMode(clickbutton, INPUT_PULLUP);
  pinMode(clickbutton1, INPUT_PULLUP);
  pinMode(clickbutton2, INPUT_PULLUP);
  pinMode(clickbutton3, INPUT_PULLUP);
  //IR
  Reciever.enableIRIn();
  initializeLCD();
  delay(300);

}

void loop() {
  //HexaIRreciever();

  MainMode();
  //Serial.print(brightnessFactor);
 // Serial.print("\n");
 // delay(300);
 //lightSensor();
 //ClickerButton();
 //ENHANCED_SPECTRUM();

}

//Mode One
void ModeOne()
{
  // Get distance from UltraSonic sensor

  int UltraSonicRes = UltraSonic();
  
  // Clear the LCD screen before displaying the new result
  LCD.clear();
  LCD.setCursor(0, 0);
  
  // Print the distance result
  LCD.print("Distance:");
  LCD.print(UltraSonicRes);
  LCD.print(" cm"); // Assuming the distance is in cm
  
  // Add a small delay so the display doesn't flicker too much
  delay(500);
}
int UltraSonic() {
  // Trigger the UltraSonic sensor
  digitalWrite(Trig, LOW);
  delayMicroseconds(2);
  digitalWrite(Trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trig, LOW); 
  
  // Read the echo duration
  duration = pulseIn(Echo, HIGH);
  
  // Calculate distance based on the speed of sound
  distance = duration * 0.034 / 2;

  return distance;
}

//Mode Two
void HexaIRreciever()
{
  if (Reciever.decode(&results)) {
    LCD.clear();
    LCD.print("Value: ");
    LCD.print(results.value, HEX);
    
    Reciever.resume();  // Receive the next value
  }
}

//Mode three
void MainMode() {
  if (Reciever.decode(&results)) {
    unsigned long value = results.value;
    if(value == REDB) {
      startlcd();
      LCD.print("Red Light.");
      RED();
    }
    else if(value == GREENB) {
      startlcd();
      LCD.print("Green Light.");
      GREEN();
    }
    else if(value == BLUEB) {
      startlcd();
      LCD.print("Blue Light.");
      BLUE();
    }
    else if(value == OFFbtn)
    {
      OFF();
      startlcd();
      LCD.print("OFF.");
    }
    else if(value == WHITEB) {
      startlcd();
      LCD.print("White Light.");
      WHITE();
    }
    else if(value == R1B) {
      startlcd();
      LCD.print("Orange Light.");
      R2();
    }
    else if(value == R2B) {
      startlcd();
      LCD.print("Amber light.");
      R3();
    }
    else if(value == R3B) {
      startlcd();
      LCD.print("Yellow Light.");
      YELLOW();
    }
    else if(value == G1B) {
      startlcd();
      LCD.print("Teal Light.");
      G2();
    }
    else if(value == G2B) {
      startlcd();
      LCD.print("Turquoise Light.");
      G3();
    }
    else if(value == G3B) {
      startlcd();
      LCD.print("Cyan Light.");
      G4();
    }
    else if(value == B1B) {
      startlcd();
      LCD.print("Purple Light.");
      B2();
    }
    else if(value == B2B) {
      startlcd();
      LCD.print("Violet Light.");        
      B3();
    }
    else if(value == B3B) {
      startlcd();
      LCD.print("Pink light.");
      B4();
    }
    else if (value == Next || value == Prev || value == Play) {
      NextPrev(value);
    }
    else if (value == Flashbtn) {
      int duration = 200;
      startlcd();
      LCD.print("Flashing Mode.");

      // Flashing mode loop, break if another button is pressed
      while (true) {
        Flash(duration);  // Flash the light for a specified duration

        // Check if any other button is pressed while flashing
        if (Reciever.decode(&results)) {
            unsigned long newValue = results.value;

            // If any valid button is pressed, break the loop and handle the new value
            if (newValue != Flashbtn) {

                Reciever.resume(); // Resume the receiver for future inputs
                value = newValue;  // Update the value to handle it outside the loop
                break;
            }
            // Reset the receiver to listen for new signals
            Reciever.resume();
        }
      }
    }
    Reciever.resume();  // Prepare for the next signal
  }
}

void startlcd()
{
  LCD.clear();
  LCD.setCursor(0, 1);
}

//Colors 
void setColor(int redValue, int greenValue, int blueValue) {
    analogWrite(redPin, redValue);
    analogWrite(greenPin, greenValue);
    analogWrite(bluePin, blueValue);
}

// Red Variations
void RED() {
    setColor(255, 0, 0);  // Full intensity of red
}
void R2() {  // Orange-red
    setColor(255, 10, 0);  // Some green to create orange
}
void R3() {  // Yellow
    setColor(255, 20, 0);  // Full red and green to create yellow
}
void YELLOW() {
    setColor(255, 40, 0);  // Full intensity of red and some green
}

// Green Variations
void GREEN() {
    setColor(0, 255, 0);  // Full intensity of green
}
void G2() {  // Cyan-green
    setColor(0, 255, 100);  // Some blue
}
void G3() {  // Blue-green
    setColor(0, 255, 255);  // Full blue
}
void G4() {
    setColor(0, 50, 255); 
}
// Blue Variations
void BLUE() {
    setColor(0, 0, 255);  // Full intensity of blue
}
void B2() {  // Purple-blue
    setColor(255, 100, 200);  // Some red
}
void B3() {  // Magenta-blue
    setColor(255, 50, 150);  
}
void B4() {
    setColor(255, 25, 50);  
}

void OFF() {
    setColor(0, 0, 0);
}
// White

void WHITE() {
    setColor(255, 100, 100);  // Full intensity of all colors
}

void initializeLCD() {
  LCD.begin(16, 2);
  LCD.backlight();
  LCD.setCursor(0, 0);
  LCD.print("This Some LCD");
  LCD.setCursor(0, 1);
  LCD.print("Enter Mode.");
}

//ModeFour 
void lightSensor()
{
  int sensorValue = analogRead(sensorPin);
  int digitalState = digitalRead(digitalPin);
  LCD.clear();
  LCD.setCursor(0, 0);
  LCD.print("A: ");
  LCD.setCursor(3, 0);
  LCD.print(sensorValue);
  LCD.setCursor(8, 0);
  LCD.print("D: ");
  LCD.setCursor(11, 0);
  LCD.print(digitalState);

  if (digitalState == 0) {
      digitalWrite(ledPin, LOW);
  } else {
      digitalWrite(ledPin, HIGH);
  }

  LCD.setCursor(2, 1);
  if (sensorValue < 100) {
      LCD.print("DARK");
  } else {
      LCD.print("LIGHT");
  }
  delay(200);

}
//Flashing
void Flash(int dur)
{
  setColor(255, 100, 100);
  delay(dur);
  OFF();
  delay(dur);
}

void NextPrev(unsigned long value) {
    // Declare an array of function pointers for the colors
    startlcd();

    void (*colorFunctions[])(void) = {
        RED, R2, R3, YELLOW,        // Red Variations
        GREEN, G2, G3, G4,          // Green Variations
        BLUE, B2, B3, B4, 
        WHITE,          // Blue Variations
        OFF                        // Off state
    };


    static int n = 0; // Use static to retain value across function calls
    int totalColors = sizeof(colorFunctions) / sizeof(colorFunctions[0]);

    // Check if we need to go to the next or previous color
    if (value == Next) {
        n = (n + 1) % totalColors; // Increment and wrap around using modulo
    } else if (value == Prev) {
        n = (n - 1 + totalColors) % totalColors; // Decrement and wrap around (avoid negative index)
    }
    if(n == 0)
      LCD.print("Red Light.");
    else if(n == 1)
      LCD.print("Orange Light.");
    else if(n == 2)
      LCD.print("Amber Light.");
    else if(n == 3)
      LCD.print("Yellow Light.");
    else if(n == 4)
    //Green
      LCD.print("Green Light.");
    else if(n == 5)
      LCD.print("Teal  light.");
    else if(n == 6)
      LCD.print("Turquoise Light.");
    else if(n == 7)
      LCD.print("Cyan Light.");
    else if(n == 8)
    //Blue
      LCD.print("Blue Light.");
    else if(n == 9)
      LCD.print("Purple Light.");
    else if(n == 10)
      LCD.print("Violet Light.");
    else if(n == 11)
      LCD.print("Pink Light.");
    else if(n == 12)
      LCD.print("White Light.");
    else if(n == 13)
      LCD.print("OFF.");
    
    
    // Call the current function in the array
    colorFunctions[n](); // Execute the function at index n
}





















