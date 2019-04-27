#include <SoftwareSerial.h>

const byte diode_pin = 8;

void setup() {
  pinMode(6, OUTPUT);
  digitalWrite(6, HIGH);
  pinMode(diode_pin, OUTPUT);
  digitalWrite(diode_pin, HIGH);
  pinMode(9, OUTPUT);
  digitalWrite(9, HIGH);
}

void loop() {
}
