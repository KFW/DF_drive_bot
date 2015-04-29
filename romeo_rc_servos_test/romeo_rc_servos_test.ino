/*
Romeo RC Servos Test
Read RC signal pulse width by using interrupt then control servos of
SparkFun robot arm (https://www.sparkfun.com/products/11524 and  https://www.sparkfun.com/products/11674 )


DFRobot Romeo v2 has pin config like Leonardo - plan to take advantage of fact that Leonardo
  has 4 hardware interrupts for my 4 controller signals
For this test will use pin 3 (interrupt 0 - see http://www.arduino.cc/en/Reference/AttachInterrupt )
                   and pin 2 (interrupt 1)
                   


Helpful resources:
http://gammon.com.au/interrupts
http://rcarduino.blogspot.com/2012/04/how-to-read-multiple-rc-channels-draft.html
http://rcarduino.blogspot.com/2012/01/how-to-read-rc-receiver-with.html
https://beyondszine.wordpress.com/2013/10/31/part-ii-all-pin-interrupt-method-for-rc-in-arduino/


*/

#include <Servo.h>

Servo wrist;
Servo claw;

const int int0pin = 3; // interrupt 0 is on pin 3 for wrist (throttle on receiver)
const int int1pin = 2; // interrupt 1 is on pin 2 for claw (rudder on receiver)
const int wristpin = 12;
const int clawpin = 13;

volatile unsigned long wrist_pw0 = 0;   // volatile since will be in interrupt function
volatile unsigned long claw_pw1 = 0;
volatile unsigned long start0 = 0;
volatile unsigned long start1 = 0;
unsigned long wristpulse = 0;
unsigned long clawpulse = 0;

int clawangle = 85;
int clawminthresh = 1300; // threshold for closing claw; want dead zone in center
int clawmaxthresh = 1700; // threshold for opening claw
const int minclawangle = 35; // limit travel to protect servo
const int maxclawangle = 135;

void setup() {
  attachInterrupt(0, readint0, CHANGE);  // pin 3 on Romeo  __ signal for wrist
  attachInterrupt(1, readint1, CHANGE);  // pin 2            __ signal for claw
  wrist.attach(wristpin);
  claw.attach(clawpin);
  wrist.write(90); // starting position
  wrist.write(clawangle);
} // end setup()

void loop() {
  // ==========================================================================
  // will want to set flag(s) to see if there has actualy been a signal change
  // ==========================================================================  
  if (FLAG){
    noInterrupts(); // pause interrupts so pw signals are read faithfully and not changed part way during assignment
    wristpulse = wrist_pw0;
    clawpulse = claw_pw1;
    interrupts();   // there is a safer way to do this by saving and resorting settings register, but since I'm not using libraries should be OK
    
    wrist.writeMicroseconds(wristpulse);
    
    // for claw want to open/close base on stick, but then hold position
    if (clawpulse < clawminthresh){
      clawangle -= 2; // decrement by 2 degrees at a time 
    }
    else if (clawpulse > clawmaxthresh){
      clawangle +=2;
    }
    clawangle = constrain(clawangle, minclawangle, maxclawngle);
    claw.write(clawangle);
  }
} // end loop()

void readint0() {
  // interrupt occurs on CHANGE - need to determine if now high (start of pulse) or low (end of pulse
  if(digitalRead(int0pin) == HIGH){
    start0 = micros();  // get time stamp for initiation of pulse
  }
  else{   
    // pin must now be low - end of pulse; calculate pulse width
    wrist_pw0 = micros() - start0;
  }
} // end readint0()

void readint1() {
  // interrupt occurs on CHANGE - need to determine if now high (start of pulse) or low (end of pulse
  if(digitalRead(int1pin) == HIGH){
    start1 = micros();  // get time stamp for initiation of pulse
  }
  else{   
    // pin must now be low - end of pulse; calculate pulse width
    claw_pw1 = micros() - start1;
  }
} // end readint1()
