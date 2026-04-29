////////////////////////////////////////////////////////////////
// concept of Arduino side bluetooth connection ////////////////
// current status not working //////////////////////////////////
////////////////////////////////////////////////////////////////

/* #include <ArduinoBLE.h>

int power_var = ina228.getPower_mW();
int current_var = ArduinoInput.getAverage();
int charge_time_var = 0.5 / ArduinoInput.getAverage();

//create service
BLEService powerMonitorService("100A"); //UUID = 100A
BLEByteCharacteristic switchCharacteristic("100A", BLERead); // readable by centeral device

void setup() {
  Serial.begin(9600);
  while (!Serial);

  // begin initialization
  if (!BLE.begin()) {
    Serial.println("starting Bluetooth® Low Energy module failed!");

    while (1);
  }

  Serial.println("Bluetooth® Low Energy Central - Peripheral Explorer");

  // set advertised name and service UUID
  BLE.setLocalName("<Power Pals>");
  BLE.setAdvertisedService(powerMonitorService);

  //add characteristics
  powerMonitorService.addCharacteristic(power);
  powerMonitorService.addCharacteristic(current);
  powerMonitorService.addCharacteristic(chargeTime);

  BLE.addService(powerMonitorService);

  power.writeValue(0); // set initial values
  curent.writeValue(0);
  chargeTime.writeValue(0);

  // start advertising
  BLE.advertise();
  Serial.println(" Bluetooth® device active, waiting for connections...");
}

void loop(){
  BLEDevice central = BLE.central();

  // if a central is connected to peripheral:
  if (central) {
    Serial.print("Connected to central: ");
    // print the central's MAC address:
    Serial.println(central.address());

    // while the central is still connected to peripheral:
    while (central.connected()) {

      //values to be sent to react app
      power.writeValue() = power_var;
      curent.writeValue() = current_var;
      chargeTime.writeValue() = charge_time_var;
    }

  // when the central disconnects, print it out:
    Serial.print(F("Disconnected from central: "));
    Serial.println(central.address());
  }
} */