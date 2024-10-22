int redPin = 11;
int greenPin = 9;
int bluePin = 10;
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
  digitalWrite (redPin, LOW); 
  digitalWrite (greenPin, HIGH); 
  digitalWrite (bluePin, HIGH); 
}
void GREEN() {
  digitalWrite (redPin, HIGH); 
  digitalWrite (greenPin, LOW); 
  digitalWrite (bluePin, HIGH); 
}
void BLUE() {
  digitalWrite (redPin, HIGH); 
  digitalWrite (greenPin, HIGH); 
  digitalWrite (bluePin, LOW); 
}
 
void SPECTRUM() {
    int redIntensity=255;
    int blueIntensity=255;
    int greenIntensity=255;

    for (blueIntensity=255;  blueIntensity>0;  blueIntensity--)  {
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


    for (redIntensity=255; redIntensity>0; redIntensity--) {
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
    for (blueIntensity=0;  blueIntensity<255;  blueIntensity++) {
      analogWrite (redPin, redIntensity); 
      analogWrite (greenPin, greenIntensity); 
      analogWrite (bluePin, blueIntensity); 
      delay (10);
    }
}

