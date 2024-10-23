int xPin= A0;
int yPin= A1;
int btnPin= 2;
int topLED= 13;
int leftLED= 12;
int downLED= 11;
int rightLED= 10;

void setup() {
    pinMode(btnPin, INPUT_PULLUP);
    pinMode(leftLED, OUTPUT);
    pinMode(downLED, OUTPUT);
    pinMode(rightLED, OUTPUT);
    pinMode(topLED, OUTPUT);
}
void loop() {
    int btnState = digitalRead(btnPin); 
    int yState = analogRead(yPin); 
    int xState = analogRead(xPin); 
    if  (btnState == LOW) {
      digitalWrite (leftLED, HIGH);
      digitalWrite (downLED, HIGH);
      digitalWrite (rightLED, HIGH);
      digitalWrite (topLED, HIGH);
    }      
  else {
    digitalWrite (leftLED, LOW);
    digitalWrite (downLED, LOW);
    digitalWrite (rightLED, LOW);
    digitalWrite (topLED, LOW);
    }   
  if (yState > 550) {
    digitalWrite (downLED, LOW);
    digitalWrite (topLED, HIGH);
  }
  if (yState < 450) {
    digitalWrite (topLED, LOW);
    digitalWrite (downLED, HIGH);
  }
  if (xState > 550) {
    digitalWrite (rightLED, LOW);
    digitalWrite (leftLED, HIGH);
  }
  if (xState < 450) {
    digitalWrite (leftLED, LOW);
    digitalWrite (rightLED, HIGH);
  }
 

}
