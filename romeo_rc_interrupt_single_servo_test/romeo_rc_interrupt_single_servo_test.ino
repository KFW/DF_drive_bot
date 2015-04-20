/*
Romeo RC Interrupt Single Servo Test
Read RC signal pulse width by using interrupt then control servo


DFRobot Romeo v2 has pin config like Leonardo - plan to take advantage of fact that Leonardo
  has 4 hardware interrupts for my 4 controller signals
For this test will use  pin 0 (interrupt 3 - see http://www.arduino.cc/en/Reference/AttachInterrupt )

Helpful resources:
http://gammon.com.au/interrupts
http://rcarduino.blogspot.com/2012/04/how-to-read-multiple-rc-channels-draft.html
http://rcarduino.blogspot.com/2012/01/how-to-read-rc-receiver-with.html
https://beyondszine.wordpress.com/2013/10/31/part-ii-all-pin-interrupt-method-for-rc-in-arduino/


*/

#include <Servo.h>

Servo myServo;

const int int0pin = 3; // interrupt 0 is on pin 3
const int servo1pin = 8;

volatile unsigned long pw0 = 0;   // volatilse since will be in interrupt function
volatile unsigned long start0 = 0;
unsigned long pulse = 0;
unsigned long timestamp = 0;

void setup() {
  attachInterrupt(0, readint0, CHANGE);  // pin 3 on Romeo
  myServo.attach(servo1pin, 1000, 2000); // set min and max parameters
  // Serial.begin(9600);
  timestamp = micros();
} // end setup()

void loop() {
  noInterrupts(); // pause interrupts so pw0 is read faithfully and not changed part way during assignment
  pulse = pw0;
  interrupts();   // there is a safer way to do this by saving and resorting settings register, but since I'm not using libraries should be OK
  // want to print ~ 5x/second, so see if now - timestamp is > 200K microseconds
  // if so reset timestamp and print whatever value pulse is, recognizing that pw0 may have changed in meanwhile
  if ((micros() - timestamp) > 200000){
    timestamp = micros(); // reset for next comparison
    // Serial.println(pulse);
    myServo.writeMicroseconds(pulse);
  }
} // end loop()

void readint0() {
  // interrupt occurs on CHANGE - need to determine if now high (start of pulse) or low (end of pulse
  if(digitalRead(int0pin) == HIGH){
    start0 = micros();  // get time stamp for initiation of pulse
  }
  else{   
    // pin must now be low - end of pulse; calculate pulse width
    pw0 = micros() - start0;
  }
} // end readint0()
