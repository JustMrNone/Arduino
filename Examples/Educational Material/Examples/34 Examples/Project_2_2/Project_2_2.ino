int ledPin[] = {13, 12, 11, 10, 9, 8, 7, 6};
int index = 0;

void setup() {
    for (index=0; index<8; index++) {
      pinMode (ledPin[index], OUTPUT);
    }
}

void loop() {
               for (index=0; index<8; index++) {
                  digitalWrite (ledPin[index], HIGH);
                  delay (1000);
                  digitalWrite (ledPin[index], LOW);
                  delay (1000);
               }
}


