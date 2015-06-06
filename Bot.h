#ifndef BOT_H_
#define BOT_H_

#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include "Leg.h"


#define LEGS 6
#define LEG_INTERVAL 10

class Bot {
  public:
  Leg *l[LEGS];
  Bot(Adafruit_PWMServoDriver pwm[]);
  void normal();
  void ortho();
  void raise();
  void pushUp();
  void contract();
  void stepFwd();
  void stepFwdOrtho();
  void pivotBack();
};

#endif // Bot

