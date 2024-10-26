int butt = 13;
int led = 6;
void setup() {
  // put your setup code here, to run once:
  pinMode(butt, INPUT);
  pinMode(led, OUTPUT);
}

void loop() {
    // put your main code here, to run repeatedly:
  digitalWrite(led, LOW);
  int value = digitalRead(butt);
  if(value == LOW)
  {
    digitalWrite(led, HIGH);
  }
  
}
