int Button1 = 12;
int Button2 = 13;
int LEDR = 9;
int LEDY = 8;

void setup() {
                // put your setup code here, to run once
                pinMode (Button1, INPUT);
                pinMode (Button2, INPUT);
                pinMode (LEDR, OUTPUT);
                pinMode (LEDY, OUTPUT);
}
               
void loop() {
               int state1= digitalRead(Button1);
               int state2= digitalRead(Button2);

               if ((state1==HIGH)&&(state2==HIGH)) {
                    digitalWrite (LEDR, LOW);
                    digitalWrite (LEDY, LOW);
              }

               if ((state1==HIGH)&&(state2==LOW)) {
                    digitalWrite (LEDR, HIGH);
                    digitalWrite (LEDY, LOW);
              }

                if ((state1==LOW)&&(state2==HIGH)) {
                    digitalWrite (LEDR, LOW);
                    digitalWrite (LEDY, HIGH);
              }
 

               if ((state1==LOW)&&(state2==LOW)) {
                    digitalWrite (LEDR, HIGH);
                    digitalWrite (LEDY, LOW);
                    delay (200) ;
                    digitalWrite (LEDR, LOW);
                    digitalWrite (LEDY, HIGH);
                    delay (200) ;
              }
}
 

