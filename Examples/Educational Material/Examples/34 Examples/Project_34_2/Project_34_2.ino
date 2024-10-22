#include<RFID.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C myLCD(0x3F,16,2);
RFID myRFID; 

int redLED = 12; 
int greenLED = 11;

void setup(){
  myLCD.init(); 
  myLCD.backlight(); 
  myRFID.begin(3, 6, 5, 4, 7, 2);     //rfid.begin(IRQ_PIN,SCK_PIN,MOSI_PIN,MISO_PIN,SDA_PIN,RST_PIN)
  delay(100);
  myRFID.init(); 
  pinMode(greenLED, OUTPUT); 
  pinMode(redLED, OUTPUT); 
  digitalWrite(redLED,HIGH); 
  digitalWrite(greenLED,LOW); 
}
void loop(){
  byte status;
  byte str[4];
  status = myRFID.request(PICC_REQIDL, str);
  status = myRFID.anticoll(str);
  
  myLCD.setCursor(3,0);
  myLCD.print(" WELCOME! ");
  digitalWrite(redLED,HIGH);
  digitalWrite(greenLED,LOW);
  
  if (status != MI_OK) {
    return;
  }
  else {
     if( str[0]==0xC0 && str[1]==0xEC && str[2]==0xB4 && str[3]==0x4B ) {
      digitalWrite(greenLED,HIGH);
      digitalWrite(redLED,LOW);
      myLCD.clear();
      myLCD.setCursor(0,0);
      myLCD.print("Hi KankashTech!");
      myLCD.setCursor(0,1);
      myLCD.print("Door is Unlocked");
      delay(5000);
      myLCD.clear();
    } 
    else{
      myLCD.clear();
      myLCD.setCursor(1,1);
      myLCD.print("Unknown Card!");
      digitalWrite(redLED,HIGH);
      digitalWrite(greenLED,LOW);
      delay(5000);
      myLCD.clear();
    }
  }
}
