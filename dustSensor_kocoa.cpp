#include "dustSensor_kocoa.h"
#include <SoftwareSerial.h>

dustSensor_kocoa::dustSensor_kocoa() {
}


void dustSensor_kocoa::begin(int txPin, int rxPin) {
  _txPin = txPin;
  _rxPin = rxPin;
}


void dustSensor_kocoa::settingData() {
  SoftwareSerial dustSerial(_txPin, _rxPin);
  dustSerial.begin(9600);
  dustSerial.listen();
  prevTime = millis();

  for (int i = 0; i < 32; i++) {
    valueData[i] = 0;
    delay(1);
  }
  
  while ((millis() - prevTime) < 5000) {
    if (dustSerial.available()) {
      for (int i = 0; i < 32; i++) {
        valueData[i] = (int)dustSerial.read();
        delay(1);
      }
      return;
    }
  }
}


boolean dustSensor_kocoa::checkingData() {
  int totalData = 0;
  for (int i = 0; i < 30; i++) {
    totalData += valueData[i];
  }

  if (totalData != ((valueData[30] * 256) + valueData[31]) || valueData[0] != 0x42 || valueData[1] != 0x4D) {
    return false;
  }

  return true;
}


int dustSensor_kocoa::pm1Value() {
  settingData();
  if (checkingData()) {
    return (valueData[4] * 256) + valueData[5];
  }
  else {
    return -1;
  }
}


int dustSensor_kocoa::pm25Value() {
  settingData();
  if (checkingData()) {
    return (valueData[6] * 256) + valueData[7];
  }
  else {
    return -1;
  }

}


int dustSensor_kocoa::pm10Value() {
  settingData();
  if (checkingData()) {
    return (valueData[8] * 256) + valueData[9];
  }
  else {
	return -1;
  }
}
