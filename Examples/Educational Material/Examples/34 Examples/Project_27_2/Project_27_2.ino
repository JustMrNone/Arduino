int dataPin = 11;
int latchPin = 10;
int clockPin = 9;
byte segment = 0;
int i;
int data[] = {192, 249, 164, 176, 153, 146, 130, 248, 128, 144, 136, 131, 167, 198, 161, 134, 142, 139, 137, 225, 199, 171, 163, 140, 152, 175, 227, 193};
void setup() {
    pinMode(latchPin, OUTPUT);
    pinMode(dataPin, OUTPUT);  
    pinMode(clockPin, OUTPUT);
}
void loop() {
  for (i=0; i<28; i++) {
      segment=data[i];
      digitalWrite(latchPin, LOW);
      shiftOut(dataPin, clockPin, LSBFIRST, segment);
      digitalWrite(latchPin, HIGH);
      delay(1000);
  }
 
}
