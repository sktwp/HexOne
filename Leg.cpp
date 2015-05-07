#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include "Leg.h"

#define debug 3

// leg number        0   -1    2   -3   -4    5
int j1normal[] =   {300, 300, 370, 450, 300, 300};
int j2normal[] =   {375, 375, 375, 375, 375, 375};
int j3normal[] =   {340, 340, 340, 340, 340, 340};

int j1ortho[] =    {300, 300, 370, 450, 300, 300};
int j2ortho[] =    {320, 420, 325, 420, 420, 320};
int j3ortho[] =    {300, 370, 280, 420, 420, 300};

int j1fwd[] =      {300, 300, 400, 350, 300, 300};
int j1back[] =     {300, 300, 270, 520, 300, 300};

int j2contract[] = {520, 220, 525, 220, 220, 520};
int j3contract[] = {500, 170, 480, 220, 220, 500};

int j2pushUp[]   = {200, 540, 200, 540, 540, 200};
int j3pushUp[]   = {170, 510, 170, 510, 510, 170};

int j2raise[] =    {450, 300, 450, 300, 300, 450};
int j3raise[] =    {300, 300, 300, 300, 300, 300};

//counting servo numbers from the body out
Leg::Leg(int servo1, int servo2, int servo3, Adafruit_PWMServoDriver pwm, int num) {
  this->j1 = servo1;
  this->j2 = servo2;
  this->j3 = servo3;
  this->pwm = pwm;
  this->num = num;
}
void Leg::normal() {
  pwm.setPWM(j1, 0, j1normal[this->num]);
  pwm.setPWM(j2, 0, j2normal[this->num]);
  pwm.setPWM(j3, 0, j3normal[this->num]);
  if (debug > 2) { String msg = "Leg " + String(this->num) + " normal"; Serial.println(msg); }
}
void Leg::contract() {
  pwm.setPWM(j1, 0, j1normal[this->num]);
  pwm.setPWM(j2, 0, j2contract[this->num]);
  pwm.setPWM(j3, 0, j3contract[this->num]);
  if (debug > 2) { String msg = "Leg " + String(this->num) + " contract"; Serial.println(msg); }
}
void Leg::pushUp() {
  pwm.setPWM(j1, 0, j1normal[this->num]);
  pwm.setPWM(j2, 0, j2pushUp[this->num]);
  pwm.setPWM(j3, 0, j3pushUp[this->num]);
  if (debug > 2) { String msg = "Leg " + String(this->num) + " pushUp"; Serial.println(msg); }
}
void Leg::raise() {
  pwm.setPWM(j1, 0, j1normal[this->num]);
  pwm.setPWM(j2, 0, j2raise[this->num]);
  pwm.setPWM(j3, 0, j3raise[this->num]);
  if (debug > 2) { String msg = "Leg " + String(this->num) + " raise"; Serial.println(msg); }
}
void Leg::extend() {
  pwm.setPWM(j1, 0, j1normal[this->num]);
  pwm.setPWM(j3, 0, 300); delay(100);
  pwm.setPWM(j2, 0, 420);
  if (debug > 2) { String msg = "Leg " + String(this->num) + " extend"; Serial.println(msg); }
}
void Leg::pushOff() {
  pwm.setPWM(j1, 0, j1normal[this->num]);
  pwm.setPWM(j3, 0, 300); delay(100);
  pwm.setPWM(j2, 0, 420);
  if (debug > 2) { String msg = "Leg " + String(this->num) + " pushOff"; Serial.println(msg); }
}
void Leg::pivotRaiseFwd() {
  pwm.setPWM(j2, 0, 540);
  pwm.setPWM(j3, 0, 450); delay(100);
  pwm.setPWM(j1, 0, j1fwd[this->num]); delay(100);
  pwm.setPWM(j3, 0, 510); 
  if (debug > 2) { String msg = "Leg " + String(this->num) + " pivotRaiseFwd"; Serial.println(msg); }
}
void Leg::pivotBack() {
  pwm.setPWM(j2, 0, 540);
  pwm.setPWM(j3, 0, 510); delay(100);
  pwm.setPWM(j1, 0, j1back[this->num]); delay(100);
  if (debug > 2) { String msg = "Leg " + String(this->num) + " pivotBack"; Serial.println(msg); }
}
void Leg::bringIn() {
  pwm.setPWM(j3, 0, 450); delay(100);
  pwm.setPWM(j2, 0, 540); delay(100);
  pwm.setPWM(j3, 0, 510);
}
