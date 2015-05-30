#ifndef LEG_H_
#define LEG_H_

#define SERVOMIN  150 // this is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX  600 // this is the 'maximum' pulse length count (out of 4096)
#define MID 
#define PWMFrequency 60 //Hz

class Leg {
  public:
  int j1, j2, j3, num;
  Adafruit_PWMServoDriver pwm;
  Leg(int joint1, int joint2, int joint3, Adafruit_PWMServoDriver pwm, int num);
  void generic(int j1array[], int j2array[], int j3array[], String moveName);
  void normal();
  void contract();
  void pushUp();
  void raise(); 
  void extend();
  void pushOff();
  void pivotRaiseFwd();
  void pivotBack();
  void bringIn();
  void ortho();
};
#endif // Leg
