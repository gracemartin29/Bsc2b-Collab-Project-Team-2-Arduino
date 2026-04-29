#include <Adafruit_INA228.h>
#include "Queue.h"

Adafruit_INA228 ina228 = Adafruit_INA228();

Queue ArduinoInput;


void setup() {
  // put your setup code here, to run once:

  //S2 monitoring status of battery from battery charger
  // pinMode(A2, OUTPUT);

  Serial.begin(115200);
  // Wait until serial port is opened
  while (!Serial) {
    delay(10);
  }

  Serial.println("Adafruit INA228 Test");

  if (!ina228.begin()) {
    Serial.println("Couldn't find INA228 chip");
    while (1)
      ;
  }
  Serial.println("Found INA228 chip");
  // set shunt resistance and max current
  ina228.setShunt(0.015, 10.0);

  ina228.setAveragingCount(INA228_COUNT_16);
  uint16_t counts[] = {1, 4, 16, 64, 128, 256, 512, 1024};
  Serial.print("Averaging counts: ");
  Serial.println(counts[ina228.getAveragingCount()]);

  // set the time over which to measure the current and bus voltage
  ina228.setVoltageConversionTime(INA228_TIME_150_us);
  Serial.print("Voltage conversion time: ");
  switch (ina228.getVoltageConversionTime()) {
  case INA228_TIME_50_us:
    Serial.print("50");
    break;
  case INA228_TIME_84_us:
    Serial.print("84");
    break;
  case INA228_TIME_150_us:
    Serial.print("150");
    break;
  case INA228_TIME_280_us:
    Serial.print("280");
    break;
  case INA228_TIME_540_us:
    Serial.print("540");
    break;
  case INA228_TIME_1052_us:
    Serial.print("1052");
    break;
  case INA228_TIME_2074_us:
    Serial.print("2074");
    break;
  case INA228_TIME_4120_us:
    Serial.print("4120");
    break;
  }
  Serial.println(" uS");

  ina228.setCurrentConversionTime(INA228_TIME_280_us);
  Serial.print("Current conversion time: ");
  switch (ina228.getCurrentConversionTime()) {
  case INA228_TIME_50_us:
    Serial.print("50");
    break;
  case INA228_TIME_84_us:
    Serial.print("84");
    break;
  case INA228_TIME_150_us:
    Serial.print("150");
    break;
  case INA228_TIME_280_us:
    Serial.print("280");
    break;
  case INA228_TIME_540_us:
    Serial.print("540");
    break;
  case INA228_TIME_1052_us:
    Serial.print("1052");
    break;
  case INA228_TIME_2074_us:
    Serial.print("2074");
    break;
  case INA228_TIME_4120_us:
    Serial.print("4120");
    break;
  }
  Serial.println(" uS");

  // default polarity for the alert is low on ready, but
  // it can be inverted!
  // ina228.setAlertPolarity(1);

}

void loop() {
  // put your main code here, to run repeatedly:

  // Print reading of battery
  // Serial.print("Battery S2: ");
  // Serial.println(analogRead(A2));

  // by default the sensor does continuous reading, but
  // we can set to triggered mode. to do that, we have to set
  // the mode to trigger a new reading, then wait for a conversion
  // either by checking the ALERT pin or reading the ready register
  // ina228.setMode(INA228_MODE_TRIGGERED);
  // while (!ina228.conversionReady())
  //  delay(1);

  // Serial.print("Current: ");
  // Serial.print(ina228.getCurrent_mA());
  // Serial.println(" mA");

  //Averaging of current values

  //Calculating time left to charge the battery fully -- send to app

  // Serial.print("Bus Voltage: ");
  // Serial.print(ina228.getBusVoltage_V());
  // Serial.println(" V");

  // Serial.print("Shunt Voltage: ");
  // Serial.print(ina228.getShuntVoltage_mV());
  // Serial.println(" mV");

  //Send to App as Watts 
  Serial.print("Power: ");
  Serial.print(ina228.getPower_mW());
  Serial.println(" mW");

  // Serial.print("Energy: ");
  // Serial.print(ina228.readEnergy());
  // Serial.println(" J");
  
  // Serial.print("Charge: ");
  // Serial.print(ina228.readCharge());
  // Serial.println(" C");

  // Serial.print("Temperature: ");
  // Serial.print(ina228.readDieTemp());
  // Serial.println(" *C");
 

  ArduinoInput.pushAndPop(ina228.getCurrent_mA());

  Serial.print("Current: ");
  Serial.print(ArduinoInput.getAverage());
  Serial.println(" mA");

  Serial.print("Time to fully charge: ");

  if(ArduinoInput.getAverage() > 0.0){
    Serial.print(0.5 / ArduinoInput.getAverage());
    Serial.println(" hours");
  }

  if(ArduinoInput.getAverage() <= 0.0){
    Serial.print("not charging");
    Serial.println();
  }
  
  Serial.println();
  delay(1000);




}
