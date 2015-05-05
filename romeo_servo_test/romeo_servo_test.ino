// Romeo Servo Test
// using 7.2V HiTec servos powered by the servo power input. 
// http://www.dfrobot.com/wiki/index.php/Romeo_V2-All_in_one_Controller_(R3)_(SKU:DFR0225)
// for test will also use same battery to power board
// with motor may need to power board seperately from servos and motors
// simple sweep test

# include <Servo.h>

Servo wrist;
Servo claw;

const int WristPin = 13;
const int ClawPin = 12;
int pos = 0;


void setup() {
  wrist.attach(WristPin);
  claw.attach(ClawPin);
} // end setup()


void loop() {
  for(pos = 0; pos <= 180; pos += 1) {                                  
    wrist.write(pos);               
    delay(15);                      
  } 
  for(pos = 180; pos>=0; pos-=1) {                                
    wrist.write(pos);               
    delay(15);                      
  } 
  
  for(pos = 10; pos <= 170; pos += 1) {    // don't go full way for claw                                
    claw.write(pos);               
    delay(15);                      
  } 
  for(pos = 170; pos>=10; pos-=1) {                                
    claw.write(pos);               
    delay(15);                      
  } 
  
} // end loop()
