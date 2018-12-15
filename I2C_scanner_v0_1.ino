// I2C scanner v0.1
// www.hesta.pl
// Arduino Uno R3:  SCL-> A5  SDA-> A4

#include <Wire.h>

 byte error, address;
 int Devices = 0;
  
void setup()
{
  Wire.begin();
  Serial.begin(9600);
  Serial.println(" I2C Scanner v0.1");
}

void loop()
{
  Serial.println("Scanning...");
  
  for(address = 1; address < 127; address++) 
  {
    Wire.beginTransmission(address);
    error = Wire.endTransmission();

    if (error == 0)
    {
      Serial.print("I2C device found at address 0x");
       if (address<16) 
      Serial.print("0");
      Serial.print(address,HEX);
      Serial.print("  type:");
        if (address == 16){ Serial.print(" Sensor (example: VEML)"); };
        if (address == 19){ Serial.print(" Sensor (example: VCNL)"); };
        if (address == 30){ Serial.print(" Sensor (example: HMC)"); };
        if (address == 39){ Serial.print(" Converter (example: LCD)"); };
        if (address == 41){ Serial.print(" Sensor (example: TCS, TSL)"); };
        if (address == 57){ Serial.print(" Sensor (example: TSL)"); };
        if (address == 63){ Serial.print(" Converter (example: LCD)"); };
        if (address == 64){ Serial.print(" Sensor (example: INA, PCA)"); };
        if (address == 68){ Serial.print(" Sensor (example: SHT)"); };
        if (address == 69){ Serial.print(" Sensor (example: SHT)"); };
        if (address == 72){ Serial.print(" Sensor (example: ADS, RFID)"); };
        if (address == 83){ Serial.print(" Sensor (example: ADXL)"); };
        if (address == 96){ Serial.print(" Sensor (example: MPL)"); };
        if (address == 98){ Serial.print(" Sensor (example: MCP)"); };
        if (address == 104){ Serial.print(" Sensor (example: MPU)"); };
        if (address == 105){ Serial.print(" Sensor (example: L3G4)"); };
        if (address == 112){ Serial.print(" I2C Mux (example: TCA9548)"); };
        if (address == 118){ Serial.print(" Sensor (example: BMP)"); };
        if (address == 119){ Serial.print(" Sensor (example: BMP)"); };
      Serial.println(" ");
      Devices++;
    }
    else if (error==4) 
    {
      Serial.print("Unknown error at address 0x");
      if (address<16) 
       Serial.print("0");
       Serial.println(address,HEX);
    }    
  }
  if (Devices == 0)
    Serial.println("No I2C devices found");
  else
    Serial.println("done");

  delay(5000);          // wait 5 seconds for next scan
}
