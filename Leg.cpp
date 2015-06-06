#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include "Leg.h"

#define debug 3

// leg number        0   -1    2   -3   -4    5
int j1normal[] =   {300, 300, 320, 450, 300, 300};
int j2normal[] =   {375, 400, 375, 375, 365, 280};
int j3normal[] =   {360, 400, 340, 340, 320, 420};

int j1ortho[] =    {300, 300, 320, 450, 300, 300};
int j2ortho[] =    {300, 450, 300, 440, 440, 230};
int j3ortho[] =    {300, 460, 250, 430, 370, 370};

int j2contract[] = {520, 220, 520, 210, 210, 445};
int j3contract[] = {500, 230, 480, 170, 160, 570};

int j2pushUp[]   = {200, 540, 200, 540, 540, 120};
int j3pushUp[]   = {200, 540, 170, 530, 490, 250};

int j1fwd[] =      {370, 250, 400, 350, 370, 230};
int j1back[] =     {230, 350, 270, 520, 250, 350};

int j2raise[] =    {375, 400, 375, 375, 365, 280};
int j3raise[] =    {360, 400, 340, 340, 320, 420};

//counting servo numbers from the body out
Leg::Leg(int servo1, int servo2, int servo3, Adafruit_PWMServoDriver pwm, int num) {
  this->j1 = servo1;
  this->j2 = servo2;
  this->j3 = servo3;
  this->pwm = pwm;
  this->num = num;
}
void Leg::generic(int j1array[], int j2array[], int j3array[], String moveName) {
  pwm.setPWM(j1, 0, j1array[this->num]);
  pwm.setPWM(j2, 0, j2array[this->num]);
  pwm.setPWM(j3, 0, j3array[this->num]);
  if (debug > 2) { String msg = "Leg " + String(this->num) + " " + moveName; Serial.println(msg); }
}
void Leg::normal() { this->generic(j1normal, j2normal, j3normal, "normal"); }
void Leg::ortho() { this->generic(j1ortho, j2ortho, j3ortho, "orto"); }
void Leg::contract() { this->generic(j1ortho, j2contract, j3contract, "contract"); }
void Leg::pushUp() { this->generic(j1ortho, j2pushUp, j3pushUp, "pushUp"); }
void Leg::raise() { this->generic(j1ortho, j2raise, j3raise, "raise"); }

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
  pwm.setPWM(j2, 0, j2raise[this->num]);
  pwm.setPWM(j3, 0, j3raise[this->num]); delay(100);
  pwm.setPWM(j1, 0, j1fwd[this->num]); delay(100);
  pwm.setPWM(j3, 0, j3ortho[this->num]); 
  pwm.setPWM(j2, 0, j2ortho[this->num]);
  if (debug > 2) { String msg = "Leg " + String(this->num) + " pivotRaiseFwd"; Serial.println(msg); }
}
void Leg::pivotBack() {
  pwm.setPWM(j1, 0, j1back[this->num]);
  if (debug > 2) { String msg = "Leg " + String(this->num) + " pivotBack"; Serial.println(msg); }
}
void Leg::bringIn() {
  pwm.setPWM(j3, 0, 450); delay(100);
  pwm.setPWM(j2, 0, 540); delay(100);
  pwm.setPWM(j3, 0, 510);
}
