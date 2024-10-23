#include <DS1302RTC.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

// Pins for DS1302
int clkPin = 8;
int datPin = 7;
int rstPin = 6;

// Initialize RTC and LCD
DS1302RTC myRTC(clkPin, datPin, rstPin);
LiquidCrystal_I2C myLCD(0x27, 16, 2); // Set I2C address to 0x27 for a 16x2 LCD

void setup() {
    // Set the time only once, to avoid resetting every time the Arduino starts.
    // Set format: hour, minute, second, dayOfWeek (1=Sunday), day, month, year
    myRTC.setDS1302Time(15, 10, 12, 3, 23, 10, 2024);  // Example: Set to 15:30:00, Wed, 23-Oct-2024

    // Initialize LCD
    myLCD.init();
    myLCD.backlight();
    myLCD.setCursor(1, 0);
    myLCD.print("Clock Module");
    delay(3000);
    myLCD.clear();
}

void loop() {
    // Array for days of the week
    String weekDay[] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};

    // Update RTC time
    myRTC.updateTime();

    // Display day of the week, date, and year
    myLCD.setCursor(1, 0);
    myLCD.print(weekDay[myRTC.dayofweek - 1]);
    myLCD.print(" ");
    myLCD.print(myRTC.dayofmonth);
    myLCD.print("-");
    myLCD.print(myRTC.month);
    myLCD.print("-");
    myLCD.print(myRTC.year);

    // Display time (hours, minutes, seconds)
    myLCD.setCursor(2, 1);
    myLCD.print(myRTC.hours);
    myLCD.print(":");
    myLCD.print(myRTC.minutes);
    myLCD.print(":");
    myLCD.print(myRTC.seconds);

    // Delay 1 second before updating the display
    delay(1000);
}
