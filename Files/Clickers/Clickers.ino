int buttons[] = {13, 12};
int LEDs[] = {8, 9};

void setup() {
  // put your setup code here, to run once:
  for(int i = 0; i < 2; i++)
  {
    pinMode(buttons[i], INPUT);
    pinMode(LEDs[i], OUTPUT);

  }
}

void loop() {
  // put your main code here, to run repeatedly:
  int Button1 = digitalRead(buttons[0]);
  int Button2 = digitalRead(buttons[1]);

  if((Button1 == HIGH) && (Button2 == HIGH))
  {
    digitalWrite(LEDs[0], LOW);
    digitalWrite(LEDs[1], LOW);
  }
  else if((Button1 == HIGH) && (Button2 == LOW))
  {
    digitalWrite(LEDs[0], HIGH);
    digitalWrite(LEDs[1], LOW);
  }
  else if((Button1 == LOW) && (Button2 == HIGH))
  {
    digitalWrite(LEDs[0], LOW);
    digitalWrite(LEDs[1], HIGH);
  }
  else if((Button1 == LOW) && (Button2 == LOW))
  {

    digitalWrite(LEDs[0], HIGH);
    delay(300);
    digitalWrite(LEDs[0], LOW); 
    delay(300);   
    digitalWrite(LEDs[1], HIGH);
    delay(300);
    digitalWrite(LEDs[1], LOW);
    delay(300);

  }

        
}
