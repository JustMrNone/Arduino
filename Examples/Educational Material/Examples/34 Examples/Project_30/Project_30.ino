#include <DS1302RTC.h>                                                                              
#include <LiquidCrystal_I2C.h>
int clkPin = 8;
int datPin = 7;
int rstPin = 6;
DS1302RTC myRTC(clkPin, datPin, rstPin);
LiquidCrystal_I2C myLCD(0x3F,16,2);
void setup()  {      
      myRTC.setDS1302Time(8, 30, 10, 6, 22, 9, 2017);
      myLCD.init();
      myLCD.backlight();
      myLCD.setCursor(1, 0);
      myLCD.print("KankashTech.com");
      delay (3000);
      myLCD.clear();
}                                                                                                     
void loop()  {                                                                                            
    String weekDay[]={"SAT", "SUN", "MON", "TUE", "WED", "THU", "FRI"};
    myRTC.updateTime();                                                                                     
    myLCD.setCursor(1,0);
    myLCD.print (weekDay[myRTC.dayofweek-1]);
    myLCD.print(" ");                                                                                     
    myLCD.print(myRTC.dayofmonth);                                                                         
    myLCD.print("-");                                                                                     
    myLCD.print(myRTC.month);                                                                  
    myLCD.print("-");                                                                                     
    myLCD.print(myRTC.year);                                                                    
    myLCD.setCursor(2,1);
    myLCD.print(myRTC.hours);                                                                 
    myLCD.print(":");                                                                                   
    myLCD.print(myRTC.minutes);                                                            
    myLCD.print(":");                                                                                  
    myLCD.print(myRTC.seconds);                                                        
    delay( 1000);
                                                                              
    
}                                                                                                       

