#ifndef LEG_H_
#define LEG_H_

#define SERVOMIN  150 // this is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX  600 // this is the 'maximum' pulse length count (out of 4096)
#define MID 
#define PWMFrequency 60 //Hz

class Leg {
  public:
  int j1, j2, j3;
  Adafruit_PWMServoDriver pwm;
  Leg(int joint1, int joint2, int joint3, Adafruit_PWMServoDriver pwm);
  void normal();
  void contract();
  void pushUp();
  void raise(); 
  void extend();
  void pushOff();
};
#endif // Leg
