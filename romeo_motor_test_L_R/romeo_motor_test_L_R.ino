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
}
void turn_L (byte a,byte b)      // Turn Left
{
  analogWrite (E1,a);
  digitalWrite(M1,LOW);    
  analogWrite (E2,b);    
  digitalWrite(M2,HIGH);
}
void turn_R (byte a,byte b)     // Turn Right
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
  analogWrite (E1,255);            // PWM Speed Control
  digitalWrite(M1,HIGH); 
  delay(2000); 
  digitalWrite(E1, LOW);
  delay(1000); 
  analogWrite (E2,255);    
  digitalWrite(M2,HIGH);
  delay(2000);
  digitalWrite(E2, LOW);
  delay(5000);


} // end loop()
