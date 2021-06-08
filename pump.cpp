#include <Arduino.h>
#include "pump.h"

WaterPump::WaterPump()
{
}

void WaterPump::Init(int pin)
{
  pumpPin = pin;
  pinMode(pumpPin, OUTPUT);
}

void WaterPump::Update(int state)
{
    digitalWrite(pumpPin, state);
}