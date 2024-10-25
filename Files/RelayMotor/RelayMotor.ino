int Relaypin = 6;

void setup() {
  // put your setup code here, to run once:
  pinMode(Relaypin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(Relaypin, LOW);
  digitalWrite(Relaypin, HIGH);
}
