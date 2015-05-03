#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include "Leg.h"


Leg::Leg(int servo1, int servo2, int servo3, Adafruit_PWMServoDriver pwm) {
  this->j1 = servo1;
  this->j2 = servo2;
  this->j3 = servo3;
  this->pwm = pwm;
}
void Leg::normal() {
  pwm.setPWM(j1, 0, 300);
  pwm.setPWM(j2, 0, 375);
  pwm.setPWM(j3, 0, 340);
}
void Leg::contract() {
  pwm.setPWM(j1, 0, 300);
  pwm.setPWM(j2, 0, 540);
  pwm.setPWM(j3, 0, 510);
}
void Leg::pushUp() {
  pwm.setPWM(j1, 0, 300);
  pwm.setPWM(j2, 0, 200);
  pwm.setPWM(j3, 0, 170);
}
void Leg::raise() {
  pwm.setPWM(j1, 0, 300);
  pwm.setPWM(j2, 0, 450);
  pwm.setPWM(j3, 0, 300);
}
void Leg::extend() {
  pwm.setPWM(j1, 0, 300);
  pwm.setPWM(j3, 0, 300); delay(100);
  pwm.setPWM(j2, 0, 420);

}
void Leg::pushOff() {
  pwm.setPWM(j1, 0, 300);
  pwm.setPWM(j3, 0, 300); delay(20);
  pwm.setPWM(j2, 0, 420);
}
