/*******************
different PWM signals based on button press
http://www.dfrobot.com/wiki/index.php/Romeo_V2-All_in_one_Controller_(R3)_(SKU:DFR0225)

has PWM on pin 13 like Leonardo


*******************/

const int PWpin = 13;
const int ButtonPin = 0;
int buttonVal = 0;



void setup() {
  
} // end setup()


void loop() 
{
  buttonVal = analogRead(ButtonPin);
  
  if (buttonVal < 30){       // button 1
    analogWrite(PWpin, 0);
  }
  else if (buttonVal < 175){ // button 2
    analogWrite(PWpin, 64);   
  }
  else if (buttonVal < 360){  // button 3
    analogWrite(PWpin, 128);
  }
  else if (buttonVal < 540){  // button 4
    analogWrite(PWpin, 192);
  }
  else if (buttonVal < 800){  // button 5
    analogWrite(PWpin, 255); 
  }
}
