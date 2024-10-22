int dataPin = 11;
int latchPin = 10;
int clockPin = 9;
byte segment = 0;
int i;
int data[]={ 63, 6, 91, 79, 102, 109, 125, 7, 127, 111, 119, 124, 88, 57, 94, 121, 113, 116, 118, 30, 56, 84, 92, 115, 103, 80, 28, 62};
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
