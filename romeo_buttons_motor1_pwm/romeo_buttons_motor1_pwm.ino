/*******************
motor extreme test

use buttons to test DFRobot Romeo v2 board for extremes of turning
since behavior in actual robot was flaky

*******************/

const int ButtonPin = 0;
int buttonVal = 0;

// Standard PWM DC control
int E1 = 5;    // M1 Speed Control
int E2 = 6;    // M2 Speed Control
int M1 = 4;    // M1 Direction Control
int M2 = 7;    // M1 Direction Control


void setup() 
{
  
}

void loop() 
{
  buttonVal = analogRead(ButtonPin);
  
  if (buttonVal < 30){       // button 1
    halt();                  
  }
  else if (buttonVal < 175){ // button 2 motors 1/4 power
    fwd(64,64);              // motors fwd 1/4 power
  }
  else if (buttonVal < 360){  // button 3 
    fwd(128,128);             // motors fwd 1/2
  }
  else if (buttonVal < 540){  // button 4
    fwd(192,192);             // motors fwd 3/4
  }
  else if (buttonVal < 800){  // button 5
    fwd(255,255);             // motors full power
  }
}


void halt(void)               // Stop
{
  digitalWrite(E1,LOW);   
  digitalWrite(E2,LOW);      
}   
void fwd(byte a,byte b)       // Move forward
{
  analogWrite (E1,a);         // PWM Speed Control
  digitalWrite(M1,HIGH);      // HIGH for fwd
  analogWrite (E2,b);    
  digitalWrite(M2,HIGH);
}  
void rev(byte a,byte b)       // Reverse
{
  analogWrite (E1,a);
  digitalWrite(M1,LOW);   
  analogWrite (E2,b);    
  digitalWrite(M2,LOW);
}  
