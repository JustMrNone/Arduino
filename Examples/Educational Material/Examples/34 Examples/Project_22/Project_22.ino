
int relayPin= 6;

void setup() {
    pinMode (relayPin, OUTPUT);
    digitalWrite (relayPin, HIGH);
    Serial.begin (9600);
}
void loop() {
    digitalWrite (relayPin, LOW);
    Serial.println("Relay Activated");
}

