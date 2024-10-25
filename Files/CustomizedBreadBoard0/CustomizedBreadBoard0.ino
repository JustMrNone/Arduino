#include <LiquidCrystal_I2C.h>
#include <IRremote.h>
void ModeOne();
int UltraSonic();
void HexaIRreciever();


// UltraSonic Sensor 
int Trig = 3;
int Echo = 2;


int duration, distance; 
int reciever = 5;

//LCD config
LiquidCrystal_I2C LCD(0x27, 16, 2);

//Infrared Reciever Config 
IRrecv Reciever(reciever);
decode_results results;

//buttons mapping
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
  // Setup for UltraSonic Sensor
  Serial.begin(9600);
  pinMode(Trig, OUTPUT);
  pinMode(Echo, INPUT);

  // Setup for LCD
  LCD.begin(16, 2);
  LCD.backlight();
  LCD.setCursor(0, 0);
  //LCD.print("Test.");
  

  //IR
  Reciever.enableIRIn();

}

void loop() {
  //HexaIRreciever();
  //ModeOne();
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
































