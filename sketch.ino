#include <OneWire.h>
#include <DallasTemperature.h>

#define TEMP_PIN 15
#define HEATER 4
#define BUZZER 5

OneWire oneWire(TEMP_PIN);
DallasTemperature sensor(&oneWire);

void setup() {
  Serial.begin(115200);
  sensor.begin();
  pinMode(HEATER, OUTPUT);
  pinMode(BUZZER, OUTPUT);
}

void loop() {
  sensor.requestTemperatures();
  float t = sensor.getTempCByIndex(0);

  String state;
  if (t >= 55) {
    state = "OVERHEAT";
    digitalWrite(HEATER, LOW);
    digitalWrite(BUZZER, HIGH);
  } else if (t >= 48) {
    state = "TARGET";
    digitalWrite(HEATER, LOW);
    digitalWrite(BUZZER, LOW);
  } else if (t >= 45) {
    state = "STABILIZING";
    digitalWrite(HEATER, HIGH);
    digitalWrite(BUZZER, LOW);
  } else if (t >= 40) {
    state = "HEATING";
    digitalWrite(HEATER, HIGH);
    digitalWrite(BUZZER, LOW);
  } else {
    state = "IDLE";
    digitalWrite(HEATER, LOW);
    digitalWrite(BUZZER, LOW);
  }

  Serial.print("Temp: ");
  Serial.print(t);
  Serial.print(" °C | State: ");
  Serial.println(state);
  delay(1000);
}