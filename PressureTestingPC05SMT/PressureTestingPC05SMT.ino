/*
    This code has been created by Electronics Tech Ha.Is Channel
    created: 02/06/2020

    This code is for reading the pressure values from the pressure sensor
    26PC SMT Series by Honeywell.
    Also this code should work with any pressure sensor that uses
    Wheatstone bridge configuration(Piezoresistive Technology).
    These sensor series need calibration in order to get accurate readings


*/
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define Pressure_pin        A5
#define Pressure_Readings   60     //Number of readings
#define Pressure_Offset     21     //Analog reading value
#define Pressure_Calib     208.33  //Calibration value depending on 100 mmHg readings from pressure sensor and the Arduino readings

LiquidCrystal_I2C lcd(0x3F, 16, 2);

float PressureR = 0;

void setup() {
  Serial.begin(115200);
  lcd.init();
  delay(1000);
  lcd.clear();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Pressure Testing");
  delay(3000);
}

void loop() {
  long PressureValue = 0;
  float VoltageP = 0;
  for (int i = 0; i < Pressure_Readings; i++) {
    PressureValue += analogRead(Pressure_pin);
    delay(2);
  }
  PressureValue = PressureValue / Pressure_Readings;
  Serial.print("Analog: ");
  Serial.println(PressureValue);
  Serial.println("------------");
  Serial.print("Voltage: ");
  PressureValue = PressureValue - Pressure_Offset;
  VoltageP = (PressureValue * 5.0) / 1023.0;
  Serial.println(VoltageP);
  Serial.println("------------");
  PressureR = VoltageP * Pressure_Calib;
  Serial.print("Pressure value: ");
  Serial.print(PressureR);
  Serial.println(" mmHg");
  Serial.println("------------");
  
  lcd.clear();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("P: ");
  lcd.print(PressureR);
  lcd.print(" mmHg");
  lcd.setCursor(0, 1);
  lcd.print("P: ");
  lcd.print(PressureR/750);
  lcd.print(" Bar");
  delay(300);
}
