#include <Arduino.h>

class dustSensor_kocoa {
  public:
    dustSensor_kocoa ();
    
    void
      begin(int txPin, int rxPin),
      settingData();

    int
      pm1Value(),
      pm25Value(),
      pm10Value();
      
    boolean checkingData();
      
  private:
    int
      valueData[32],
      _txPin,
      _rxPin;

    unsigned long prevTime;
};
