#include <TM1637Display.h>
int CLK= 8;
int DIO= 9;
TM1637Display myTM(CLK, DIO);
byte data[] = { 63, 63, 63 , 63 };
int n1 = 0;
int n2 = 0;
int n3 = 0;
int n4 = 0;

void setup() {
    myTM.setBrightness(7);
    myTM.showNumberDec(0 , true, 4, 0);  
    delay (2000);
    myTM.showNumberDec(10, false, 4, 0);    
    delay (2000);
    myTM.showNumberDec(100, false, 4, 0);    
    delay (2000);
    myTM.showNumberDec(1000, false, 4, 0);    
    delay (2000);
}

void loop() {
    myTM.setBrightness(7);
    int number[]={63, 6, 91, 79,102,109,125,7,127,111};
    for(n4=0; n4<10; n4++) {
        data[3]=number[n4];
        int mod=n4%2;
        if (mod==0) {
            data[1]=number[n2];
        }
        else {
            data[1]=number[n2]+128;
        }
        myTM.setSegments(data);
        delay(1000);
    }
        if (n4==10){
          n4=0;
          n3++;
          if (n3==6) {
            n3=0;
            n2++;
            if (n2==10){
              n2=0;
              n1++;
              if (n1==6) {
                n1=0;
              }
            }
           }
          }
  data[2]=number[n3];
  data[1]=number[n2];
  data[0]=number[n1];
  myTM.setSegments(data);
}
