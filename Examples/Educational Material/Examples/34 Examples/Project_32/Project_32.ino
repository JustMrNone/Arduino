#include <IRremote.h>
int irPin =5;  
IRrecv myIR(irPin); 
int ledPin[] ={13, 12, 11, 10, 9, 8, 7, 6};
long  controlKey[2][8] ={
                      {0xFF30CF, 0xFF18E7, 0xFF7A85, 0xFF10EF, 0xFF38C7, 0xFF5AA5, 0xFF42BD, 0xFF4AB5},
                      {0x9716BE3F, 0x3D9AE3F7, 0x6182021B, 0x8C22657B, 0x488F3CBB, 0x449E79F, 0x32C6FDF7, 0x1BC0157B} 
};
decode_results irInput;

void setup()  {      
      Serial.begin(9600);
      for (int i=0; i<8; i++) {
          pinMode(ledPin[i],OUTPUT);
          digitalWrite(ledPin[i], LOW);
      }
      myIR.enableIRIn(); 
}

void loop() {
  if (myIR.decode(&irInput)) { 
    Serial.println(irInput.value, HEX);
    myIR.resume(); 
  }
  delay(600);
  for (int k=0; k<2; k++){
    for (int j=0; j<8; j++) {  
      if (irInput.value == controlKey[k][j]) {
          digitalWrite(ledPin[j],HIGH);
          Serial.print("LED no.");
          Serial.print(j+1);
          Serial.println(" is on.");
      }
      else {
          digitalWrite(ledPin[j],LOW);
      }
    }
  }
}
