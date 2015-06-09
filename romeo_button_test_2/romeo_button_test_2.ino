/*******************
position servos with buttons  on DFRobot Romeo
to test ranges for setup

http://www.dfrobot.com/wiki/index.php/Romeo_V2-All_in_one_Controller_(R3)_(SKU:DFR0225)


*******************/

const int ButtonPin = 0;
int buttonVal = 0;



void setup() {
  Serial.begin(9600);
} // end setup()


void loop() 
{
  buttonVal = analogRead(ButtonPin);
  
  if (buttonVal < 30){       // button 1
    Serial.println("Button 1");   
  }
  else if (buttonVal < 175){ // button 2
    Serial.println("Button 2");     
  }
  else if (buttonVal < 360){  // button 3
    Serial.println("Button 2");  
  }
  else if (buttonVal < 540){  // button 4
    Serial.println("Button 4");  
  }
  else if (buttonVal < 800){  // button 5
    Serial.println("Button 5");  
  }
}
