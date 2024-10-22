int dataPin = 12;
int latchPin = 11;
int clockPin = 10;
int rowPins[8]={ 2, 3, 4, 5, 6, 7, 8, 9};
byte segments [12][8] = {
                        {60,102,66,66,66,66,102,60},
                        {24,24,24,24,24,24,24,24},
                        {60,102,66,32,16,8,4,126},
                        {60,98,96,60,96,64,98,60},
                        {32,48,40,36,126,32,32,32},
                        {126,2,62,98,64,64,102,60},
                        {60,66,2,62,66,66,66,60},
                        {126,64,64,32,16,8,4,2},
                        {60,66,66,60,66,66,66,60},
                        {60,66,66,66,124,64,66,60},
                        {60,66,165,129,165,90,60,0},
                        {0,68,238,254,254,124,56,16}
};

void setup() {
    pinMode(latchPin, OUTPUT);
    pinMode(dataPin, OUTPUT);  
    pinMode(clockPin, OUTPUT);
    for (int i=0 ; i<8; i++) {
        pinMode (rowPins[i], OUTPUT);
    }
}
void loop() {
      for(int k=0; k<12; k++) {
        for(int t=0; t<60; t++) {
          for (int j=0; j<8; j++) {
            digitalWrite(latchPin, LOW);
            shiftOut(dataPin, clockPin, LSBFIRST, segments[k][j]);
            digitalWrite(latchPin, HIGH);
            for (int r=0; r<8; r++){
              if (r==j){
                digitalWrite (rowPins[r], LOW);
              }
              else {
                digitalWrite (rowPins[r],HIGH);
              }
            }
            delay(2);
            digitalWrite (rowPins[j],HIGH);

          }   
        }
      }
}

