int buzzerPin = 9;

void setup() {
    pinMode(buzzerPin,OUTPUT);
}

void loop() {
    int i=0;
    for(i=0;i<80;i++) {
    digitalWrite(buzzerPin,HIGH);
          delay(1);
    digitalWrite(buzzerPin,LOW);
          delay(1);
  }
  
  for(i=0;i<100;i++) {
    digitalWrite(buzzerPin,HIGH);
    delay(2);
    digitalWrite(buzzerPin,LOW);
    delay(2);
  }
} 
