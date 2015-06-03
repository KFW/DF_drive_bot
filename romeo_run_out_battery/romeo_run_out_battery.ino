/******************************************************************************
Romeo_run_out_battery

tests time I can get on a 2S Li ion battery

DFRobot Romeo Drive Bot
Robot for MakerFaire Kansas City Arch Reactor booth


SparkFun robot arm (https://www.sparkfun.com/products/11524 and  
https://www.sparkfun.com/products/11674 )


DFRobot Romeo v2 controller board 
http://www.dfrobot.com/wiki/index.php/Romeo_V2-All_in_one_Controller_(R3)_(SKU:DFR0225)


Will assume full range of signal (1000 - 2000), simplifies programming
Extreme values outside range only occur with extremes of trim, which 
should be a rare outlier - will avoid the overhead of a constrain() operation


M1 is R wheel (pointing forward)
M2 is L wheel


**/

/********************
*** DECLARATIONS ****
********************/
#include <Servo.h>

Servo wrist;
Servo claw;

const int WristPin = 12;
const int ClawPin = 13;

// motor control pins - internally wired on Romeo
const int Rdir   = 4;
const int Rspeed = 5;
const int Ldir   = 7;
const int Lspeed = 6;



/********************
====== BODY =========
********************/

void setup() {
  wrist.attach(WristPin);
  claw.attach(ClawPin);
  wrist.write(120); // starting position
  claw.write(120);   
  
} // end setup()


void loop() {
  forward(256,256);
  delay(3000);
  stop();
  for (int i= 120; i > 60; i -= 1){
    claw.write(i);
  }
  for (int i= 120; i > 60; i -= 1){
    wrist.write(i);
  }
  for (int i= 60; i < 120; i += 1){
    claw.write(i);
  }
  for (int i= 60; i < 120; i += 1){
    wrist.write(i);
  }
  reverse(256,256);
  delay(3000);
  stop();
  
} // end loop()


/********************
----- FUNCTIONS -----
********************/
           
void stop()                  
{
  digitalWrite(Rspeed,LOW);   
  digitalWrite(Lspeed,LOW);      
}   

void forward(int l,int r)   // technically only need 'char" for speeds
{
  digitalWrite(Ldir,LOW);
  analogWrite (Lspeed,l);         //PWM Speed Control   
  digitalWrite(Rdir,LOW);
  analogWrite (Rspeed,r);
}  

void reverse(int l,int r) //Move backward
{
  digitalWrite(Ldir,HIGH);  
  analogWrite (Lspeed,l);    
  digitalWrite(Rdir,HIGH); 
  analogWrite (Rspeed,l);
}

