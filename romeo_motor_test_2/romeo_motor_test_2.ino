/*
romeo_motor_test_2

simple test of motors, based on sample code from
http://www.dfrobot.com/wiki/index.php/Romeo_V2-All_in_one_Controller_(R3)_(SKU:DFR0225)

*/


//Standard PWM DC control
int E1 = 5;     //M1 Speed Control
int E2 = 6;     //M2 Speed Control
int M1 = 4;     //M1 Direction Control
int M2 = 7;     //M1 Direction Control

void stop()                   //Stop
{
  digitalWrite(E1,LOW);   
  digitalWrite(E2,LOW);      
}   
void advance(char a,char b)   //Move forward
{
  analogWrite (E1,a);         //PWM Speed Control
  digitalWrite(M1,HIGH);    
  analogWrite (E2,b);    
  digitalWrite(M2,HIGH);
}  
void back_off (char a,char b) //Move backward
{
  analogWrite (E1,a);
  digitalWrite(M1,LOW);   
  analogWrite (E2,b);    
  digitalWrite(M2,LOW);
}
void turn_L (char a,char b)   //Turn Left
{
  analogWrite (E1,a);
  digitalWrite(M1,LOW);    
  analogWrite (E2,b);    
  digitalWrite(M2,HIGH);
}
void turn_R (char a,char b)   //Turn Right
{
  analogWrite (E1,a);
  digitalWrite(M1,HIGH);    
  analogWrite (E2,b);    
  digitalWrite(M2,LOW);
}
void setup() 
{ 
  int i;
  for(i=4;i<=7;i++)
  {
    pinMode(i, OUTPUT);  
  } 
}

void loop() {
  advance(255,255);
  delay(1000);
  stop();
  delay(100);
  back_off(255,255);
  delay(1000);
  stop();
  delay(100);
  turn_L(128,128);
  delay(1000);
  stop();
  delay(100);
  turn_R(128, 128);
  delay(1000);
  stop();
  delay(3000);

}
