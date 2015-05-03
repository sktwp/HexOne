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
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();


void setServoPulse(uint8_t n, double pulse) {
  double pulseLength = 100000;
  pulseLength /= PWMFrequency;
  pulseLength /= 4096; //12 bits of resolution
  pulse *= 1000; 
  pulse /= pulseLength;
  pwm.setPWM(n, 0, pulse);
}
  
//======================================== INITIALIZATION ============================================
Bot *bot;
uint8_t j = 2;

//======================================== SETUP() ============================================
void setup() {
  bot = new Bot(pwm);

  Serial.begin(SERIAL_BAUD);
  pwm.begin();
  pwm.setPWMFreq(PWMFrequency);
  delay(500);

  bot->contract();
  delay(1000);
  bot->normal();
  delay(1000);
  bot->contract();
  delay(1000);
}
//======================================== LOOP() ============================================
void loop() {
  int d = 3000;
  int d1 = 1000;
  


  //Bot test routine  
  bot->normal(); Serial.println("normal"); delay(d);
  bot->pushUp(); Serial.println("pushUp"); delay(d);
  bot->contract(); Serial.println("contract"); delay(d);
  bot->normal(); Serial.println("normal"); delay(d);
  delay(10000);

  /*
  // Leg test routine
  Serial.print("Leg # ");
  while (!Serial.available()) {
    delay(100);
  }
  int n = Serial.parseInt();
  Serial.println(n);
  bot->l[n]->normal(); Serial.println("normal"); delay(d);
  bot->l[n]->raise();  Serial.println("raise"); delay(d);
  bot->l[n]->pushUp(); Serial.println("pushUp"); delay(d);
  bot->l[n]->contract(); Serial.println("contract"); delay(d);
  bot->l[n]->normal(); Serial.println("normal"); delay(d);
  delay(1000);
  */
  /*
  // Joint position modeling routine
  int joints[] = {3, 7, 8, 9};
  foreach (j,  joints) {
    Serial.print("Joint # "); Serial.println(*j);
    while (!Serial.available()) {
      delay(100);
    }
    int n = Serial.parseInt();
    pwm.setPWM(*j, 0, n);
    delay(500);
  }
  delay(1000);
  */
}

//======================================== END END END ========================================

