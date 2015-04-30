/*
DF_drive_bot
robot for Maker Faire Kansas City for kids to earn their "Robot Driver's License"
robot built from Vex parts, including motors

SparkFun robot claw (https://www.sparkfun.com/products/11524/ ) 
and and pan/tilt bracket (https://www.sparkfun.com/products/11674 )

Use DF Robot Romeo V2 board for servos and motors 
(http://www.dfrobot.com/index.php?route=product/product&product_id=844&search=romeo&description=true)
board has pin config like Leonardo - plan to take advantage of fact that Leonardo
  has 4 hardware interrupts for my 4 controller signals
For robot arm will use pin 3 (interrupt 0 - see http://www.arduino.cc/en/Reference/AttachInterrupt )
                   and pin 2 (interrupt 1)

use regular hobby RC for control                   
Helpful resources:
http://gammon.com.au/interrupts
http://rcarduino.blogspot.com/2012/04/how-to-read-multiple-rc-channels-draft.html
http://rcarduino.blogspot.com/2012/01/how-to-read-rc-receiver-with.html
https://beyondszine.wordpress.com/2013/10/31/part-ii-all-pin-interrupt-method-for-rc-in-arduino/


*/

#include <Servo.h>

Servo wrist;
Servo claw;

const int int0pin = 3; // interrupt 0 is on pin 3
const int int1pin = 2;
const int wristpin = 12;
const int clawpin = 13;

volatile unsigned long wrist_pw0 = 0;   // volatile since will be in interrupt function
volatile unsigned long claw_pw1 = 0;
volatile unsigned long start0 = 0;
volatile unsigned long start1 = 0;
volatile boolean flag = 0;
unsigned long wristpulse = 0;
unsigned long clawpulse = 0;



void setup() {
  attachInterrupt(0, readint0, CHANGE);  // pin 3 on Romeo  __ signal for wrist
  attachInterrupt(1, readint1, CHANGE);  // pin 2            __ signal for claw
  wrist.attach(wristpin);
  claw.attach(clawpin);
} // end setup()

void loop() {
  // ==========================================================================
  // Will set generic flag to see if signal change. In future may want to 
  // check more specific flags by signal
  // ==========================================================================  
  if (flag){
    noInterrupts(); 
    // pause interrupts so pw signals are read faithfully and not changed part way during assignment
    // copy to values that will be used this time through loop even if later changed by interrupt
    // if value unchanged will just read old value
    wristpulse = wrist_pw0;
    clawpulse = claw_pw1;
    flag = false;
    interrupts();   // turn interrupts back on; 
                    // there is a safer way to do this by saving and resorting settings register, 
                    // but since I'm not using external libraries should be OK
    
    wrist.writeMicroseconds(wristpulse);
    claw.writeMicroseconds(clawpulse);
    
    
  }
} // end loop()

void readint0() {
  // interrupt occurs on CHANGE - need to determine if now high (start of pulse) or low (end of pulse)
  if(digitalRead(int0pin) == HIGH){
    start0 = micros();  // get time stamp for initiation of pulse
  }
  else{   
    // pin must now be low - end of pulse; calculate pulse width
    wrist_pw0 = micros() - start0;
    flag = true; // know signal occured; ok if multiple signals set flag in this version
  }
} // end readint0()

void readint1() {
  // interrupt occurs on CHANGE - need to determine if now high (start of pulse) or low (end of pulse)
  if(digitalRead(int1pin) == HIGH){
    start1 = micros();  // get time stamp for initiation of pulse
  }
  else{   
    // pin must now be low - end of pulse; calculate pulse width
    claw_pw1 = micros() - start1;
    flag = true;
  }
} // end readint1()
