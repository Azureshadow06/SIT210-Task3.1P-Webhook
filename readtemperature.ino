// This #include statement was automatically added by the Particle IDE.
#include "Grove_Temperature_And_Humidity_Sensor.h"

DHT dht(D4);
double temp, humidity;
double temp_dbl, humidity_dbl;

void setup() {
  Serial.begin(9600);
  dht.begin();
  Particle.variable("temp", temp_dbl);
  Particle.variable("humidity", humidity_dbl);
}

void loop() {
  temp = dht.getTempCelcius();
  humidity = dht.getHumidity();
  temp_dbl = temp;
  humidity_dbl = humidity;
  Serial.printlnf("Temp: %f", temp);
  Serial.printlnf("Humidity: %f", humidity);

  String temp_str = String(temp_dbl);
  Particle.publish("temp", temp_str, PRIVATE);

  delay(20000);
}
