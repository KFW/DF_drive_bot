// Romeo Button Test
// http://www.dfrobot.com/wiki/index.php/Romeo_V2-All_in_one_Controller_(R3)_(SKU:DFR0225)
// Romeo has 5 buttons all read on pin 0
// uses value to determine which button
// this will simply print value to help visualize

const int ButtonPin = 0;
int val = 0;

void setup() 
{
  Serial.begin(9600);
}

void loop() 
{
  val = analogRead(ButtonPin);
  Serial.println(val);
  delay(500);  
}
