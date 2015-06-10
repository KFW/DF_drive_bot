/*******************
position servos with buttons  on DFRobot Romeo
to test ranges for setup

http://www.dfrobot.com/wiki/index.php/Romeo_V2-All_in_one_Controller_(R3)_(SKU:DFR0225)


*******************/



#include <Servo.h>

Servo wrist;
Servo claw; 
const int ButtonPin = 0;
int buttonVal = 0;

const int WristPin = 13;
const int ClawPin = 12;



void setup() {
  Serial.begin(9600);
  wrist.attach(WristPin);
  claw.attach(ClawPin);
  wrist.write(90);
  delay(1000);
  claw.write(90);
  delay(1000);
} // end setup()


void loop() 
{
  buttonVal = analogRead(ButtonPin);
  delay(10);
  buttonVal = analogRead(ButtonPin); // for stable value??
  
  if (buttonVal < 30){       // button 1
    wrist.write(90);
    claw.write(90);
    Serial.println("button 1");
    delay(1000);    
  }
  else if (buttonVal < 200){ // button 2
    claw.write(0);
    Serial.println("button 2");
    delay(1000);    
  }
  else if (buttonVal < 350){  // button 3
    claw.write(180);
    Serial.println("button 3");
    delay(1000);
  }
  else if (buttonVal < 600){  // button 4
    wrist.write(0);
    Serial.println("button 4");
    delay(1000);
  }
  else if (buttonVal < 850){  // button 5
    wrist.write(180);
    delay(1000);
  }
}
