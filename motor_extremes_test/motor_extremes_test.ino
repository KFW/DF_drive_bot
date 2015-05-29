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
  
  if (buttonVal > ##){       // button # - fwd hard L
    fwd(16,255);             // L motor barely fwd, R motor hard fwd
    delay(5000);             // 5 sec for readings
    halt();
  }
  else if (buttonVal > ##){  // button # - fwd hard R
    fwd(255,16);
    delay(5000);
    halt();
  }
  else if (buttonVal > ##){  // button # - rev hard L
    rev(16,255);
    delay(5000);
    halt();
  }
  else if (buttonVal > ##){  // button # - rev hard R
    rev(255,16);
    delay(5000);
    halt();
  }
}


void halt(void)                    // Stop
{
  digitalWrite(E1,LOW);   
  digitalWrite(E2,LOW);      
}   
void fwd(byte a,byte b)          // Move forward
{
  analogWrite (E1,a);            // PWM Speed Control
  digitalWrite(M1,HIGH);    
  analogWrite (E2,b);    
  digitalWrite(M2,HIGH);
}  
void rev(byte a,byte b)          // Reverse
{
  analogWrite (E1,a);
  digitalWrite(M1,LOW);   
  analogWrite (E2,b);    
  digitalWrite(M2,LOW);
