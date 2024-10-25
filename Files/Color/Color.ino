#include <Wire.h>
#include <Adafruit_TCS34725.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);  // Initialize LCD at I2C address 0x27
Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_700MS, TCS34725_GAIN_4X);

void setup() {
  Serial.begin(9600);

  lcd.begin(16, 2);
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Color Detection");

  if (tcs.begin()) {
    Serial.println("Color sensor found.");
    lcd.setCursor(0, 1);
    lcd.print("Sensor Online");
  } else {
    Serial.println("No TCS34725 found.");
    while (1);
  }
  delay(2000);
  lcd.clear();
}

void loop() {
  uint16_t r, g, b, c;
  tcs.getRawData(&r, &g, &b, &c);

  // Calculate clear, red, green, and blue values
  float clearVal = c;
  float redVal = (float)r / clearVal;
  float greenVal = (float)g / clearVal;
  float blueVal = (float)b / clearVal;

  Serial.print("R: "); Serial.print(r);
  Serial.print(" G: "); Serial.print(g);
  Serial.print(" B: "); Serial.print(b);
  Serial.print(" C: "); Serial.println(c);

  lcd.setCursor(0, 0);
  lcd.print("R:");
  lcd.print(r);
  lcd.setCursor(8, 0);
  lcd.print("G:");
  lcd.print(g);
  lcd.setCursor(0, 1);
  lcd.print("B:");
  lcd.print(b);

  delay(1000);

  // Interpret color
  interpretColor(redVal, greenVal, blueVal);
}

void interpretColor(float r, float g, float b) {
  lcd.clear();
  lcd.setCursor(0, 0);

  if (r > 0.6 && g < 0.4 && b < 0.4) {
    lcd.print("Detected: RED");
  } else if (r < 0.4 && g > 0.6 && b < 0.4) {
    lcd.print("Detected: GREEN");
  } else if (r < 0.4 && g < 0.4 && b > 0.6) {
    lcd.print("Detected: BLUE");
  } else if (r > 0.5 && g > 0.5 && b < 0.4) {
    lcd.print("Detected: YELLOW");
  } else if (r > 0.5 && g > 0.5 && b > 0.5) {
    lcd.print("Detected: WHITE");
  } else {
    lcd.print("Detected: UNKNOWN");
  }
  delay(2000);
}
