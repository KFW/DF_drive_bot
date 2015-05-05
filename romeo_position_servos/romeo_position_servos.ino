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
boolean flag = true;


void setup() {
  wrist.attach(WristPin);
  claw.attach(ClawPin);
  wrist.write(90);
  delay(500);
  claw.write(90);
  delay(500);
} // end setup()


void loop() {
  if (flag){
//    for(int pos = 90; pos>=0; pos-=1){                                
//      wrist.write(pos);               
//      delay(15); 
//    } 
    for(int pos = 90; pos<=180; pos+=1) {     // 180 is closed position                           
      claw.write(pos);               
      delay(15);                      
    }
    flag = false;
  }
}
