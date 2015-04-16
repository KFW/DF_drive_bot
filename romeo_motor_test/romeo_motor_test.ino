// Romeo Motor Test
// based on sample code from: 
// http://www.dfrobot.com/wiki/index.php/Romeo_V2-All_in_one_Controller_(R3)_(SKU:DFR0225)
// 7.2 battery to power motors and board
// in practice may need to power board seperately from servos and motors
// fwd, back, turn test

// Standard PWM DC control
int E1 = 5;    // M1 Speed Control
int E2 = 6;    // M2 Speed Control
int M1 = 4;    // M1 Direction Control
int M2 = 7;    // M1 Direction Control


void halt(void)                    // Stop
{
  digitalWrite(E1,LOW);   
  digitalWrite(E2,LOW);      
}   
void fwd(char a,char b)          // Move forward
{
  analogWrite (E1,a);            // PWM Speed Control
  digitalWrite(M1,HIGH);    
  analogWrite (E2,b);    
  digitalWrite(M2,HIGH);
}  
void rev(char a,char b)          // Reverse
{
  analogWrite (E1,a);
  digitalWrite(M1,LOW);   
  analogWrite (E2,b);    
  digitalWrite(M2,LOW);
}
void turn_L (char a,char b)      // Turn Left
{
  analogWrite (E1,a);
  digitalWrite(M1,LOW);    
  analogWrite (E2,b);    
  digitalWrite(M2,HIGH);
}
void turn_R (char a,char b)     // Turn Right
{
  analogWrite (E1,a);
  digitalWrite(M1,HIGH);    
  analogWrite (E2,b);    
  digitalWrite(M2,LOW);
}

void setup(void) 
{ 
  int i;
  for(i=4;i<=7;i++) 
  {
    pinMode(i, OUTPUT);  
  } 
  delay(2000); // time to put robot down or whatever
} // end setup()

void loop() {
  fwd(255,255);
  delay(5000);
  halt();
  delay(500);
  rev(255,255);
  delay(5000);
  halt();
  delay(500);
  turn_R(128,128);
  delay(3000);
  halt();
  delay(500);
  turnL(128,128);
  delay(3000);
  halt();
  delay(5000);

} // end loop()
