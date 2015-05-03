#ifndef BOT_H_
#define BOT_H_

#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include "Leg.h"


#define legs 7
#define LEG_INTERVAL 10

class Bot {
  public:
  Adafruit_PWMServoDriver pwm;
  Leg *l[legs];
  Bot(Adafruit_PWMServoDriver pwm);
  void normal();
  void raise();
  void pushUp();
  void contract();
};

#endif // Bot

