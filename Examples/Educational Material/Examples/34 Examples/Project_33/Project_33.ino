#include <LiquidCrystal_I2C.h> 
#include <Keypad.h> 

const byte rows = 4; 
const byte cols = 4;
byte rowPins [rows] = {2, 3, 4, 5}; 
byte colPins [cols] = {6, 7, 8, 9};

int redLED = 12; 
int greenLED = 11;
int password =1234; 

char keyNames [rows] [cols] = { 
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

Keypad myKeypad (makeKeymap(keyNames), rowPins, colPins, rows, cols);
LiquidCrystal_I2C myLCD(0x3F, 16, 2);

void setup(){
  myLCD.init();
  myLCD.backlight();
  myLCD.clear();
  pinMode(redLED, OUTPUT); 
  pinMode(greenLED, OUTPUT);
  myLCD.setCursor(4, 0);
  myLCD.print("Welcome");
  delay (2000);
  myLCD.setCursor(1, 1);
  myLCD.print("Enter Password");
  Serial.begin(9600);
    
  }

void loop(){
long pass= getNumber();
  
    if (pass==password){
          myLCD.clear ();
          myLCD.setCursor(0, 0);
          myLCD.print("*** Verified ***");
          myLCD.setCursor(0, 1);
          myLCD.print("Door  Unlocked");
          digitalWrite (greenLED , HIGH);
          digitalWrite (redLED, LOW);
        }
        else {
          myLCD.clear ();
          myLCD.setCursor(0, 0);
          myLCD.print("Wrong Password");
          myLCD.setCursor(3, 1);
          myLCD.print("Try Again");
          digitalWrite (greenLED , LOW);
          digitalWrite (redLED, HIGH);
       }
}
long getNumber() {
   long num = 0;
   char key = myKeypad.getKey();
   while(key != '#' ) {
           switch (key) {
         case NO_KEY:
            break;

         case '0': case '1': case '2': case '3': case '4':
         case '5': case '6': case '7': case '8': case '9':
            myLCD.clear();
            num = num * 10 + (key - '0');
            myLCD.setCursor(5,0);
            myLCD.print(num);
            Serial.println(key);
            break;

         case '*':
            num = 0;
            myLCD.clear();
            break;

        case 'A': case 'B' : case 'C': case 'D':
          myLCD.clear();
          myLCD.print ("Invalid Input");
          break;
      }
      
      key = myKeypad.getKey();
      
   }
   return num;
}
