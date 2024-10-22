int LED= 11;
int Switch = 12;
void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);
  pinMode(Switch, INPUT);
}

void loop() {
  int button = digitalRead(Switch);// put your main code here, to run repeatedly:
  if(button == LOW)
  {
    int val = 1;
    while(val)
    {
    int val = analogRead(A0);
    digitalWrite(LED, HIGH);
    delay(val);
    digitalWrite(LED, LOW);
    delay(val);
    }
  }

}
