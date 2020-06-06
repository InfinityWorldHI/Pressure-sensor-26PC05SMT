/*
 *  This code has been created by Electronics Tech Ha.Is Channel
 *  created: 02/06/2020
 *  
 *  This code is for reading the pressure values from the pressure sensor
 *  26PC SMT Series by Honeywell.
 *  Also this code should work with any pressure sensor that uses 
 *  Wheatstone bridge configuration(Piezoresistive Technology).
 *  These sensor series need calibration in order to get accurate readings
 *  
 *  
 */
#define Pressure_pin        A5
#define Pressure_Readings   20     //Number of readings
#define Pressure_Offset     19     //Analog reading value
#define Pressure_Calib     208.33  //Calibration value depending on 100 mmHg readings from pressure sensor and the Arduino readings

float PressureR = 0;

void setup() {
  Serial.begin(115200);
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
  delay(300);
}
