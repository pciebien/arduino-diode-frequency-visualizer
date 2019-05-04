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

Diode *redDiode;
Diode *yellowDiode;
Diode *greenDiode;
String soundPath; 
int offset = 0;

void setup() 
{
  redDiode = new Diode(6);
  yellowDiode = new Diode(8);
  greenDiode = new Diode(9);
  soundPath = "112358132134558914423337761098715972584418167651094617711286574636875025121393196418317811514229832040134626921783093524578570288792274651493035224157817390881696324598610233415516558014126791429643349443770140873311349031701836311903";
}

void loop() 
{
  int currentSample = (int)soundPath[offset] - 48;
  
  if(currentSample > 0 && currentSample < 4)
  {
      greenDiode->blink(currentSample * 100);
  } 
  else if(currentSample > 3 && currentSample < 7)
  {
      yellowDiode->blink(currentSample * 100);
  }
  else redDiode->blink(currentSample * 100);
    
  ++offset;
}
