/*******************
position servos with buttons  on DFRobot Romeo
to test ranges for setup

http://www.dfrobot.com/wiki/index.php/Romeo_V2-All_in_one_Controller_(R3)_(SKU:DFR0225)

*******************/

#include <Servo.h>

Servo wrist;
Servo claw; 
const int WristPin = 13;
const int ClawPin = 12;

const int ButtonPin = 0;
int buttonVal = 0;
int wristPos = 90;
int clawPos = 90;

void setup() {
//  Serial.begin(9600);
  wrist.attach(WristPin);
  claw.attach(ClawPin);
  wrist.write(wristPos);
  claw.write(clawPos);
  delay(1000);
} // end setup()


void loop() 
{

  buttonVal = analogRead(ButtonPin);
  delay(10);
  buttonVal = analogRead(ButtonPin); // for stable value??
  
  if (buttonVal < 30){       // button 1
    wristPos = 90;
    clawPos = 90;
    wrist.write(wristPos);
    claw.write(clawPos);
    delay(1000);    
  }
  else if (buttonVal < 200){ // button 2
    // close claw
    clawPos--;    
  }
  else if (buttonVal < 350){  // button 3
    //open claw
    clawPos++;
  }
  else if (buttonVal < 600){  // button 4
    // lower wrist
    wristPos--;
  }
  else if (buttonVal < 850){  // button 5
    // raise wrist
    wristPos++;
  }
  claw.write(clawPos);
  wrist.write(wristPos);
  delay(100);
}
