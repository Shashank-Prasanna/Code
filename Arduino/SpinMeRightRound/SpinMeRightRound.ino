/************************************************
 Written by Cruz Monrreal II
 Created on 06-26-2012
 Modified on 10-20-2012
 
 Updates can be found here:
  https://github.com/cmonr/Arduino-Sphero-Library
************************************************/

#include <ArduinoBLE.h>
#include <Sphero.h>
Sphero sphero;

void Action(BLEDevice peripheral){
  Serial.println("connected to the Sphero Mini!"); 
  // Turn on Back LED
  sphero.setBackLED(0xFF);
  
  // Turn off Stabilization
  sphero.setStabilization(0);
    
  // ??? You Spin Me Right Round ???
  sphero.setMotorPowers(-80, 80);
}

void setup() {
  Serial.begin(115200);
  Serial.println("Start scanning for sphero!"); 
  BLE.begin();
  BLE.scanForUuid("00010001-574f-4f20-5370-6865726f2121"); 
  

}

void loop(){
  BLEDevice peripheral = BLE.available(); 
  if (peripheral.localName() != "SM-38FA") {
    return; 
  }
  if (peripheral.localName() == "SM-38FA") {
    Serial.println(peripheral.localName()); 
  }
  
  BLE.stopScan(); 

  Action(peripheral); 
  BLE.scanForUuid("00010001-574f-4f20-5370-6865726f2121");

  
}
