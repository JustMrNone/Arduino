int sensorPin=A0;
int relayPin= 2;

void setup() {
    pinMode (relayPin, OUTPUT);
    digitalWrite (relayPin, HIGH);
    Serial.begin (9600);
}
void loop() {
    int sensorValue=analogRead(sensorPin);
    if (sensorValue<400) {
        digitalWrite (relayPin, LOW);
        Serial.println("Relay Activated");
    }
    else {
        digitalWrite (relayPin, HIGH);
    }
    Serial.println(sensorValue);
    delay(200);
}

