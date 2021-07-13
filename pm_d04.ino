#include <dustSensor_kocoa.h>

dustSensor_kocoa dust;

int pm10;
int pm25;
int pm1;
void setup() {
  Serial.begin(9600);
  dust.begin(2, 3);
}

void loop() {
  pm10 = dust.pm10Value();
  pm25 = dust.pm25Value();
  pm1 = dust.pm1Value();

  Serial.print("PM10 Dust : ");
  Serial.println(pm10);
  Serial.print("PM2.5 Dust : ");
  Serial.println(pm25);
  Serial.print("PM1 Dust : ");
  Serial.println(pm1);

}
