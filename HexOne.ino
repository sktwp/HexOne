  #include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include <Servo.h>
#include "Leg.h"
#include "Bot.h"

//=========================================== GLOBALS ===================================

#define SERIAL_BAUD 57600

/* foreach macro viewing an array of int values as a collection of int values */
#define foreach( intpvar, intary ) int* intpvar; for( intpvar=intary; intpvar < (intary + (sizeof(intary)/sizeof(intary[0]))) ; intpvar++)

// called this way, it uses the default address 0x40
Adafruit_PWMServoDriver pwm[2] = { Adafruit_PWMServoDriver(0x40), Adafruit_PWMServoDriver(0x41) };

  
//======================================== INITIALIZATION ============================================
Bot *bot;
uint8_t j = 2;

//======================================== SETUP() ============================================
void setup() {
  bot = new Bot(pwm);

  Serial.begin(SERIAL_BAUD);
  pwm[0].begin();
  pwm[0].setPWMFreq(PWMFrequency);
  pwm[1].begin();
  pwm[1].setPWMFreq(PWMFrequency);

  delay(1000);

}
//======================================== LOOP() ============================================
void loop() {
  int d = 3000;
  int d1 = 1000;
  //bot->normal();
  
  //bot->stepFwd();
  //delay(10000);
  
  //delay(d);
  //bot->pushUp();
  //delay(d);
  

  //Bot test routine  
  //bot->normal(); Serial.println("normal"); delay(d);
  bot->ortho(); Serial.println("ortho"); delay(d);
  bot->stepFwdOrtho(); Serial.println("stepFwdOrtho"); delay(d);
  //bot->pivotBack(); Serial.println("pivotBack"); delay(d);
  /*
  bot->contract(); Serial.println("contract"); delay(d);
  bot->normal(); Serial.println("normal"); delay(d);
  bot->pushUp(); Serial.println("pushUp"); delay(d);
  bot->normal(); Serial.println("normal"); delay(d);
*/
/*
  // Leg test routine
  Serial.print("Leg # ");
  while (!Serial.available()) {
    delay(100);
  }
  int n = Serial.parseInt();
  Serial.println(n);
  bot->l[n]->normal(); Serial.println("normal"); delay(d);
  bot->l[n]->ortho();  Serial.println("ortho"); delay(d);
  //bot->l[n]->pushUp(); Serial.println("pushUp"); delay(d);
  //bot->l[n]->contract(); Serial.println("contract"); delay(d);
  bot->l[n]->normal(); Serial.println("normal"); delay(d);
  delay(1000);

*/

 /* 
  // Joint position modeling routine
  //int joints[] = {0, 1, 2, 4, 5, 6, 10, 11, 12, 13, 14, 15, 20, 21, 22, 24, 25, 26};
  int joints1[] = {10, 13, 24, 20, 4, 0};
  int joints2[] = {1, 5, 11, 14, 21, 25};
  int joints3[] = {2, 6, 12, 15, 22, 26};
  int leg5[] = {0, 1, 2};
  int leg4[] = {4, 5, 6};
  int leg3[] = {20, 21, 22};
  int leg2[] = {24, 25, 26};
  int leg1[] = {13, 14, 15};
  int leg0[] = {10, 11, 12};
  int test[] = {};
  
  foreach (j,  joints1) {
    Serial.print("Joint # "); Serial.println(*j);
    while (!Serial.available()) {
      delay(100);
    }
    int n = Serial.parseInt();
    if (*j < 20) pwm[0].setPWM(*j, 0, n);
    else pwm[1].setPWM(*j -20, 0, n);
    delay(500);
  }
  delay(1000);
*/
  
} //loop()

//======================================== END END END ========================================



/*
void setServoPulse(uint8_t n, double pulse) {
  double pulseLength = 100000;
  pulseLength /= PWMFrequency;
  pulseLength /= 4096; //12 bits of resolution
  pulse *= 1000; 
  pulse /= pulseLength;
  pwm.setPWM(n, 0, pulse);
}
*/
