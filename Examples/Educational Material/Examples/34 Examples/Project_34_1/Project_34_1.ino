#include <RFID.h>
RFID myRFID;

void setup(){
  Serial.begin(115200); 
  myRFID.begin(3, 6, 5, 4, 7, 2);  
  delay(100);
  myRFID.init(); 
}
void loop(){
  byte status;
  byte str[4];
  status = myRFID.request(PICC_REQIDL, str);
  if (status != MI_OK){
    return;
  }
  else{
    status = myRFID.anticoll(str);
    Serial.print("The card's number is: ");
    Serial.print (str[0],HEX);
    Serial.print (" ");
    Serial.print (str[1],HEX);
    Serial.print (" ");
    Serial.print (str[2], HEX);
    Serial.print (" ");
    Serial.print (str[3],HEX);
    Serial.print (" ");
    Serial.println();
    Serial.println();
  }
  delay(500);
}

