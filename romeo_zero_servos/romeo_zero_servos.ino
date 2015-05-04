// Romeo Servo Test
// using 7.2V HiTec servos powered by the servo power input. 
// http://www.dfrobot.com/wiki/index.php/Romeo_V2-All_in_one_Controller_(R3)_(SKU:DFR0225)
// for test will also use same battery to power board
// with motor may need to power board seperately from servos and motors
// simple sweep test

#include <Servo.h>

Servo wrist;
Servo claw;

const int WristPin = 13;
const int ClawPin = 12;


void setup() {
  wrist.attach(WristPin);
  claw.attach(ClawPin);

} // end setup()


void loop() {
  delay(100);
  claw.write(0);
  delay(3000); // time for servo to move
  wrist.write(0);
  delay(3000);
  
} // end loop()
