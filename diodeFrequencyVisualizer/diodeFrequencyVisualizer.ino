#include <SoftwareSerial.h>

class Diode
{
  public:
    Diode(int pin);
    void turnOn();
    void turnOff();
    void blink(int durationInMs);
  private:
    int _pin;
};

Diode::Diode(int pin)
{
  pinMode(pin, OUTPUT);
  digitalWrite(pin, LOW);
  _pin = pin;
}

void Diode::turnOn()
{
  if(digitalRead(_pin) == LOW) {
    digitalWrite(_pin, HIGH);
  }
}

void Diode::turnOff()
{
  if(digitalRead(_pin) == HIGH) {
    digitalWrite(_pin, LOW);
  }
}

void Diode::blink(int durationInMs)
{
  turnOff();
  delay(durationInMs);
  turnOn();
  delay(durationInMs);
  turnOff();
}

Diode redOne(6);

void setup() {
  
}

void loop() {
  redOne.blink(20);
}
