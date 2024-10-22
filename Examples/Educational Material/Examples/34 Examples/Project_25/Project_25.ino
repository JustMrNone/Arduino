#include <Stepper.h>

int stepsPerRevolution = 2048;  

Stepper myStepper(stepsPerRevolution, 12, 10, 11, 9);

void setup() {
    myStepper.setSpeed(16);
    Serial.begin(9600);
}

void loop() {
    Serial.println("clockwise");
    myStepper.step(stepsPerRevolution);
    delay(1000);

    Serial.println("counterclockwise");
    myStepper.step(-stepsPerRevolution);
    delay(500);
}

