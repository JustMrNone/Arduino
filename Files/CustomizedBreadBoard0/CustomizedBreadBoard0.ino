#include <LiquidCrystal_I2C.h>
#include <IRremote.h>
void ModeOne();
int UltraSonic();
void HexaIRreciever();
void ModeThree();
void ChangeBrightness();
// UltraSonic Sensor 
int Trig = 3;
int Echo = 2;
int duration, distance; 
int reciever = 5;


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

unsigned long OFF = 0xF740BF;
unsigned long ON = 0xF7C03F;

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
  //LCD.print("Test.");
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  //IR
  Reciever.enableIRIn();

}

void loop() {
  //HexaIRreciever();
  //ModeOne();
  ModeThree();
  Serial.print(brightnessFactor);
  Serial.print("\n");
  delay(300);
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



void ModeThree() {
  if (Reciever.decode(&results)) {
    unsigned long value = results.value;

    // Check for brightness control first
    if (value == BrightnessUp || value == BrightnessDown) {
      ChangeBrightness(value);
    } 
    else {
      if(value == button1) {
        LCD.clear();
        LCD.setCursor(0, 1);
        LCD.print("Red Light.");
        Serial.println(brightnessFactor);
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
    }
    Reciever.resume();  // Prepare for the next signal
  }
}

void ChangeBrightness(unsigned long brightnessValue) {
  if (brightnessValue == BrightnessUp) {
    brightnessFactor += 0.1;
  } else if (brightnessValue == BrightnessDown) {
    brightnessFactor -= 0.1;
  }

  if (brightnessFactor < 0) {
    brightnessFactor = 0;
  } else if (brightnessFactor > 1) {
    brightnessFactor = 1;
  }
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
void R1() {  // Bright red
    setColor(255, 0, 0);  // Full red
}
void R2() {  // Orange-red
    setColor(255, 127, 0);  // Some green to create orange
}
void R3() {  // Yellow
    setColor(255, 255, 0);  // Full red and green to create yellow
}

// Green Variations
void GREEN() {
    setColor(0, 255, 0);  // Full intensity of green
}
void G1() {  // Bright green
    setColor(0, 255, 0);  // Full green
}
void G2() {  // Cyan-green
    setColor(0, 255, 127);  // Some blue
}
void G3() {  // Blue-green
    setColor(0, 255, 255);  // Full blue
}

// Blue Variations
void BLUE() {
    setColor(0, 0, 255);  // Full intensity of blue
}
void BL1() {  // Bright blue
    setColor(0, 0, 255);  // Full blue
}
void B2() {  // Purple-blue
    setColor(127, 0, 255);  // Some red
}
void B3() {  // Magenta-blue
    setColor(255, 0, 255);  // Full red and blue
}

// Primary Colors
void YELLOW() {
    setColor(255, 255, 0);  // Full intensity of red and green
}
void CYAN() {
    setColor(0, 255, 255);  // Full intensity of green and blue
}
void MAGENTA() {
    setColor(255, 0, 255);  // Full intensity of red and blue
}

// Warm Colors
void ORANGE() {
    setColor(255, 165, 0);  // Partial green for orange
}
void CORAL() {
    setColor(255, 127, 80);  // Less green and small blue
}
void PEACH() {
    setColor(255, 218, 185);  // Most green and some blue
}

// Cool Colors
void TURQUOISE() {
    setColor(64, 224, 208);  // Small red, most green, most blue
}
void SKYBLUE() {
    setColor(135, 206, 235);  // Some red, most green, full blue
}
void LAVENDER() {
    setColor(230, 230, 250);  // Most red and green, full blue
}

// Purple Variations
void VIOLET() {
    setColor(238, 130, 238);  // Most red, some green, most blue
}
void PLUM() {
    setColor(221, 160, 221);  // Most red and blue, some green
}

// Pastel Colors
void MINT() {
    setColor(189, 252, 201);  // Some red, full green, most blue
}
void SALMON() {
    setColor(250, 128, 114);  // Full red, some green and blue
}
void ROSE() {
    setColor(255, 192, 203);  // Full red, most green and blue
}

// Darker Shades
void BURGUNDY() {
    setColor(128, 0, 32);  // Half red, no green, small blue
}
void FOREST() {
    setColor(34, 139, 34);  // Small red, half green, small blue
}
void NAVY() {
    setColor(0, 0, 128);  // Half blue
}

// Special Effects
void GOLD() {
    setColor(255, 215, 0);  // Full red, most green, no blue
}
void SILVER() {
    setColor(192, 192, 192);  // Most red, green, and blue
}
void BRONZE() {
    setColor(205, 127, 50);  // Most red, half green, small blue
}

// Whites
void WHITE() {
    setColor(255, 255, 255);  // Full intensity of all colors
}
void BRIGHT_WHITE() {
    setColor(255, 255, 255);  // 100% intensity
}
void SOFT_WHITE() {
    setColor(200, 200, 200);  // ~78% intensity for all colors
}
void WARM_WHITE() {
    setColor(255, 240, 220);  // Full red, less green, even less blue
}
void COOL_WHITE() {
    setColor(220, 230, 255);  // Less red, slightly less green, full blue
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
}

void ENHANCED_SPECTRUM() {
    int redIntensity = 0;
    int greenIntensity = 0;
    int blueIntensity = 0;
    
    // Start with deep red (infrared transition)
    for (redIntensity = 0; redIntensity <= 255; redIntensity++) {
        analogWrite(redPin, redIntensity);
        analogWrite(greenPin, 0);
        analogWrite(bluePin, 0);
        delay(15);
    }

    // Red to Orange
    for (greenIntensity = 0; greenIntensity <= 165; greenIntensity++) {
        analogWrite(redPin, 255);
        analogWrite(greenPin, greenIntensity);
        analogWrite(bluePin, 0);
        delay(15);
    }

    // Orange to Yellow
    for (greenIntensity = 166; greenIntensity <= 255; greenIntensity++) {
        analogWrite(redPin, 255);
        analogWrite(greenPin, greenIntensity);
        analogWrite(bluePin, 0);
        delay(15);
    }

    // Yellow to Chartreuse
    for (redIntensity = 255; redIntensity >= 127; redIntensity--) {
        analogWrite(redPin, redIntensity);
        analogWrite(greenPin, 255);
        analogWrite(bluePin, 0);
        delay(15);
    }

    // Chartreuse to Green
    for (redIntensity = 127; redIntensity >= 0; redIntensity--) {
        analogWrite(redPin, redIntensity);
        analogWrite(greenPin, 255);
        analogWrite(bluePin, 0);
        delay(15);
    }

    // Green to Spring Green
    for (blueIntensity = 0; blueIntensity <= 127; blueIntensity++) {
        analogWrite(redPin, 0);
        analogWrite(greenPin, 255);
        analogWrite(bluePin, blueIntensity);
        delay(15);
    }

    // Spring Green to Cyan
    for (blueIntensity = 128; blueIntensity <= 255; blueIntensity++) {
        analogWrite(redPin, 0);
        analogWrite(greenPin, 255);
        analogWrite(bluePin, blueIntensity);
        delay(15);
    }

    // Cyan to Azure
    for (greenIntensity = 255; greenIntensity >= 127; greenIntensity--) {
        analogWrite(redPin, 0);
        analogWrite(greenPin, greenIntensity);
        analogWrite(bluePin, 255);
        delay(15);
    }

    // Azure to Blue
    for (greenIntensity = 127; greenIntensity >= 0; greenIntensity--) {
        analogWrite(redPin, 0);
        analogWrite(greenPin, greenIntensity);
        analogWrite(bluePin, 255);
        delay(15);
    }

    // Blue to Violet
    for (redIntensity = 0; redIntensity <= 127; redIntensity++) {
        analogWrite(redPin, redIntensity);
        analogWrite(greenPin, 0);
        analogWrite(bluePin, 255);
        delay(15);
    }

    // Violet to Purple
    for (redIntensity = 128; redIntensity <= 255; redIntensity++) {
        analogWrite(redPin, redIntensity);
        analogWrite(greenPin, 0);
        analogWrite(bluePin, 255);
        delay(15);
    }

    // Purple to Pink
    for (greenIntensity = 0; greenIntensity <= 192; greenIntensity++) {
        analogWrite(redPin, 255);
        analogWrite(greenPin, greenIntensity);
        analogWrite(bluePin, 255);
        delay(15);
    }

    // Pink to White
    for (greenIntensity = 193; greenIntensity <= 255; greenIntensity++) {
        analogWrite(redPin, 255);
        analogWrite(greenPin, greenIntensity);
        analogWrite(bluePin, 255);
        delay(15);
    }

    // Optional: Fade to Black (complete spectrum)
    for (int i = 255; i >= 0; i--) {
        analogWrite(redPin, i);
        analogWrite(greenPin, i);
        analogWrite(bluePin, i);
        delay(15);
    }

    // Optional: Rainbow Pulse Effect
    for (int i = 0; i < 2; i++) {
        // Quick pulse through primary and secondary colors
        int colors[][3] = {
            {255, 0, 0},    // Red
            {255, 127, 0},  // Orange
            {255, 255, 0},  // Yellow
            {0, 255, 0},    // Green
            {0, 255, 255},  // Cyan
            {0, 0, 255},    // Blue
            {127, 0, 255},  // Violet
            {255, 0, 255}   // Magenta
        };

        for (int j = 0; j < 8; j++) {
            // Fade in
            for (int k = 0; k <= 255; k++) {
                analogWrite(redPin, (colors[j][0] * k) / 255);
                analogWrite(greenPin, (colors[j][1] * k) / 255);
                analogWrite(bluePin, (colors[j][2] * k) / 255);
                delay(5);
            }
            // Fade out
            for (int k = 255; k >= 0; k--) {
                analogWrite(redPin, (colors[j][0] * k) / 255);
                analogWrite(greenPin, (colors[j][1] * k) / 255);
                analogWrite(bluePin, (colors[j][2] * k) / 255);
                delay(5);
            }
        }
    }

    LCD.clear();
}



















