int redPin = 10;
int greenPin = 9;
int bluePin = 8;

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  /*RED();
  delay(1000);
  GREEN();
  delay(1000);
  BLUE();
  delay(1000);
  YELLOW();
  delay(1000);
  CYAN();
  delay(1000);
  MAGENTA();
  delay(1000);
  WHITE();
  delay(1000);*/
  SPECTRUM(); // Add the full color spectrum cycle
  delay(1000);
}

void RED() {
  analogWrite(redPin, 255);
  analogWrite(greenPin, 0);
  analogWrite(bluePin, 0);
}

void GREEN() {
  analogWrite(redPin, 0);
  analogWrite(greenPin, 255);
  analogWrite(bluePin, 0);
}

void BLUE() {
  analogWrite(redPin, 0);
  analogWrite(greenPin, 0);
  analogWrite(bluePin, 255);
}

void YELLOW() {
  analogWrite(redPin, 255);
  analogWrite(greenPin, 255);
  analogWrite(bluePin, 0);
}

void CYAN() {
  analogWrite(redPin, 0);
  analogWrite(greenPin, 255);
  analogWrite(bluePin, 255);
}

void MAGENTA() {
  analogWrite(redPin, 255);
  analogWrite(greenPin, 0);
  analogWrite(bluePin, 255);
}

void WHITE() {
  analogWrite(redPin, 255);
  analogWrite(greenPin, 255);
  analogWrite(bluePin, 255);
}

void SPECTRUM() {
  int redIntensity = 0;
  int greenIntensity = 0;
  int blueIntensity = 0;

  // Fade from Red -> Yellow -> Green
  for (greenIntensity = 0; greenIntensity <= 255; greenIntensity++) {
    analogWrite(redPin, 255);
    analogWrite(greenPin, greenIntensity);
    analogWrite(bluePin, 0);
    delay(10);
  }

  // Fade from Green -> Cyan -> Blue
  for (redIntensity = 255; redIntensity >= 0; redIntensity--) {
    analogWrite(redPin, redIntensity);
    analogWrite(greenPin, 255);
    analogWrite(bluePin, 0);
    delay(10);
  }
  
  for (blueIntensity = 0; blueIntensity <= 255; blueIntensity++) {
    analogWrite(redPin, 0);
    analogWrite(greenPin, 255);
    analogWrite(bluePin, blueIntensity);
    delay(10);
  }

  // Fade from Blue -> Magenta -> Red
  for (greenIntensity = 255; greenIntensity >= 0; greenIntensity--) {
    analogWrite(redPin, 0);
    analogWrite(greenPin, greenIntensity);
    analogWrite(bluePin, 255);
    delay(10);
  }

  for (redIntensity = 0; redIntensity <= 255; redIntensity++) {
    analogWrite(redPin, redIntensity);
    analogWrite(greenPin, 0);
    analogWrite(bluePin, 255);
    delay(10);
  }

  // Fade from Magenta -> White -> Off
  for (greenIntensity = 0; greenIntensity <= 255; greenIntensity++) {
    analogWrite(redPin, 255);
    analogWrite(greenPin, greenIntensity);
    analogWrite(bluePin, 255);
    delay(10);
  }
  
  for (redIntensity = 255; redIntensity >= 0; redIntensity--) {
    analogWrite(redPin, redIntensity);
    analogWrite(greenPin, redIntensity);
    analogWrite(bluePin, redIntensity);
    delay(10);
  }
}
