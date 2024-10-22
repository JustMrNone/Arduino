#include <TimerOne.h>
int latchPin = 10;
int dataPin = 11;
int clockPin = 9;
int d4 = 7;
int d3 = 6;
int d2 = 5;
int d1 = 4;
byte segment = 0;
int n = 0; 
void setup() {
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);  
  pinMode(clockPin, OUTPUT);
  pinMode(d1, OUTPUT);
  pinMode(d2, OUTPUT);
  pinMode(d3, OUTPUT);
  pinMode(d4, OUTPUT);
  Timer1.initialize();
  Timer1.attachInterrupt( add );
}
void loop() {
  clearLEDs();
  pickDigit(0);
  pickNumber((n/1000));
  clearLEDs();
  pickDigit(1);
  pickNumber((n%1000)/100);
  clearLEDs();
  pickDigit(2);
  pickNumber(n%100/10);
  clearLEDs();
  pickDigit(3);
  pickNumber(n%10);
}
void clearLEDs()  {
  segment=0;
   digitalWrite(latchPin, LOW);
   shiftOut(dataPin, clockPin, LSBFIRST, segment);
   digitalWrite(latchPin, HIGH);
}
void pickDigit(int x) {
  int digit[]={d1,d2,d3,d4};
  for (int j=0; j<4; j++){
    if (j==x){
      digitalWrite(digit[j], LOW);
    }
    else {
      digitalWrite(digit[j], HIGH);
    }
  }
}

void pickNumber(int x){
    int data[]={63, 6, 91, 79,102,109,125,7,127,111};
    segment=data[x];
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, segment);
    digitalWrite(latchPin, HIGH);
} 
void add(){
    n++;
    if(n == 10000){
        n = 0;
    }
}

