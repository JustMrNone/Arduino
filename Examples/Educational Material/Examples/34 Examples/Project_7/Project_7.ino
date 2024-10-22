int redPin = 11;
int greenPin = 10;
int bluePin = 9;
void setup() {
        pinMode (redPin, OUTPUT);
        pinMode (greenPin, OUTPUT);
        pinMode (bluePin, OUTPUT);
 }
void loop() {
         RED();
        delay (1000);
         GREEN();
        delay (1000);
         BLUE();
         delay (1000);
         SPECTRUM();
        delay (1000);
}
 


void RED() {
  digitalWrite (redPin, HIGH); 
  digitalWrite (greenPin, LOW); 
  digitalWrite (bluePin, LOW); 
}
void GREEN() {
  digitalWrite (redPin, LOW); 
  digitalWrite (greenPin, HIGH); 
  digitalWrite (bluePin, LOW); 
}
void BLUE() {
  digitalWrite (redPin, LOW); 
  digitalWrite (greenPin, LOW); 
  digitalWrite (bluePin, HIGH); 
}
 
void SPECTRUM() {
    int redIntensity;
    int blueIntensity;
    int greenIntensity;

    for (blueIntensity=0;  blueIntensity<255;  blueIntensity++)  {
      analogWrite (redPin, redIntensity); 
      analogWrite (greenPin, greenIntensity); 
      analogWrite (bluePin, blueIntensity); 
            delay (10);

    }

    for (greenIntensity=0; greenIntensity<255; greenIntensity++) {
      analogWrite (redPin, redIntensity); 
      analogWrite (greenPin, greenIntensity); 
      analogWrite (bluePin, blueIntensity); 
            delay (10);

}


    for (redIntensity=0; redIntensity<255; redIntensity++) {
      analogWrite (redPin, redIntensity); 
      analogWrite (greenPin, greenIntensity); 
      analogWrite (bluePin, blueIntensity); 
            delay (10);

}
    for (greenIntensity=255; greenIntensity>0; greenIntensity--) {
      analogWrite (redPin, redIntensity); 
      analogWrite (greenPin, greenIntensity); 
      analogWrite (bluePin, blueIntensity); 
            delay (10);
    }
    for (blueIntensity=255;  blueIntensity>0;  blueIntensity--) {
      analogWrite (redPin, redIntensity); 
      analogWrite (greenPin, greenIntensity); 
      analogWrite (bluePin, blueIntensity); 
            delay (10);

    }
}

