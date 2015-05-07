#include "Bot.h"

#define STEP_DELAY 500

Bot::Bot(Adafruit_PWMServoDriver pwm[]) {

  l[5] = new Leg(0, 1, 2, pwm[0], 5);
  l[4] = new Leg(4, 5, 6, pwm[0], 4);
  l[3] = new Leg(0, 1, 2, pwm[1], 3);
  l[2] = new Leg(4, 5, 6, pwm[1], 2); 
  l[1] = new Leg(13, 14, 15, pwm[0], 1);
  l[0] = new Leg(10, 11, 12, pwm[0], 0);
  
}
void Bot::normal() {
  for (int i = 0; i < legs; i++) { l[i]->normal(); delay(LEG_INTERVAL); }
}
void Bot::contract() {
  for (int i = 0; i < legs; i++) { l[i]->contract(); delay(LEG_INTERVAL); }
}
void Bot::raise() {
  for (int i = 0; i < legs; i++) { l[i]->raise(); delay(LEG_INTERVAL); }
}
void Bot::pushUp() {
  for (int i = 0; i < legs; i++) { l[i]->pushUp(); delay(LEG_INTERVAL); }
}
void Bot::stepFwd() {
  l[0]->extend(); delay(STEP_DELAY);
  l[1]->extend(); delay(STEP_DELAY);
  l[2]->pivotRaiseFwd(); delay(STEP_DELAY);
  l[3]->pivotRaiseFwd(); delay(STEP_DELAY);
  l[4]->bringIn();
  l[5]->bringIn();
  l[2]->pivotBack();
  l[3]->pivotBack();
  l[4]->extend();
  l[5]->extend();
  l[0]->contract();
  l[1]->contract();

}

