#include "Bot.h"

Bot::Bot(Adafruit_PWMServoDriver pwm) {
  this->pwm = pwm;
  l[0] = new Leg(16, 16, 16, pwm);

  l[1] = new Leg(13, 14, 15, pwm);
  l[2] = new Leg(10, 11, 12, pwm);
  l[3] = new Leg(2, 8, 9, pwm); //j1 unconnected
  l[4] = new Leg(2, 7, 3, pwm); //j1 unconnected
  l[5] = new Leg(4, 5, 6, pwm);
  l[6] = new Leg(0, 1, 2, pwm);
  
}
void Bot::normal() {
  for (int i = 1; i < legs; i++) { l[i]->normal(); delay(LEG_INTERVAL); }
}
void Bot::contract() {
  for (int i = 1; i < legs; i++) { l[i]->contract(); delay(LEG_INTERVAL); }
}
void Bot::raise() {
  for (int i = 1; i < legs; i++) { l[i]->raise(); delay(LEG_INTERVAL); }
}
void Bot::pushUp() {
  for (int i = 1; i < legs; i++) { l[i]->pushUp(); delay(LEG_INTERVAL); }
}

