#include "config.h"
#include "pump.h"

WaterPump pump;

int _pumpState;
unsigned long _previousMillis;

long _onTime;     // milliseconds of on-time
long _offTime;    // milliseconds of off-time

void setup() {
  _pumpState = LOW;
  _previousMillis = 0;

  _onTime = _offTime = 5000;
  //_offTime = 2000;

  Serial.begin(BAUD_DEFAULT);

  pump.Init(2);
  pump.Update(LOW);

  Serial.println("Automatic irrigation system");
}

void loop() {
  unsigned long currentMillis = millis();

  if ((_pumpState == HIGH) && (currentMillis - _previousMillis >= _onTime))
  {
    Serial.println("PUMP OFF");
    _pumpState = LOW;  // Turn it off
    _previousMillis = currentMillis;
    pump.Update(_pumpState);
  }
  else if ((_pumpState == LOW) && (currentMillis - _previousMillis >= _offTime))
  {
    Serial.println("PUMP ON");
    _pumpState = HIGH;  // turn it on
    _previousMillis = currentMillis;
    pump.Update(_pumpState);
  }
}
