


/******************************************************************************
RC_signal_readings

Read RC signal pulse width by using interrupts 

DFRobot Romeo v2 controller board 
http://www.dfrobot.com/wiki/index.php/Romeo_V2-All_in_one_Controller_(R3)_(SKU:DFR0225)

Board has pin config like Leonardo - plan to take advantage of fact that 
Leonardo has 5 hardware interrupts for my 4 controller signals; 
see http://www.arduino.cc/en/Reference/AttachInterrupt 
won't use interrupt 2 since pin 0 - may want to use that for the buttons

                  
Helpful resources:
http://gammon.com.au/interrupts
http://rcarduino.blogspot.com/2012/04/how-to-read-multiple-rc-channels-draft.html
http://rcarduino.blogspot.com/2012/01/how-to-read-rc-receiver-with.html
https://beyondszine.wordpress.com/2013/10/31/part-ii-all-pin-interrupt-method-for-rc-in-arduino/

Using HobbyKing Turnigy 5X 5 channel mini transmitter and receiver
https://www.hobbyking.com/hobbyking/store/uh_viewItem.asp?idProduct=43854

want to read values - will test 1 control at a time


**/

/********************
*** DECLARATIONS ****
********************/

const int InterruptPin = 0;    // interrupt 2 is on pin 0
const int Interrupt = 2;


// variables
volatile unsigned long pw = 0;
volatile unsigned long timer = 0;
volatile boolean flag = false;
unsigned long pulse = 0;
unsigned long t1 = 0;


/********************
====== BODY =========
********************/

void setup() {
  Serial.begin(9600);
  attachInterrupt(Interrupt, readInterrupt, CHANGE);
  t1 = millis();  
} // end setup()


void loop() {
  // use flags to see if there is actually a new signal
  if (flag){
    noInterrupts();
    pulse = pw;
    flag = false;
    interrupts(); 
    if ((millis() - t1) > 500){  // print result approx twice a second (500 ms)
      t1 = millis();
      Serial.println(pulse);
    
    }
  }
} // end loop()


/********************
----- FUNCTIONS -----
********************/
  
void readInterrupt() {
  // interrupt occurs on CHANGE - need to determine if now high 
  // (start of pulse) or low (end of pulse)
  if(digitalRead(InterruptPin) == HIGH){
    timer = micros();  // get time stamp for initiation of pulse
  }
  else{   
    // pin must now be low - end of pulse; calculate pulse width
    pw = micros() - timer;
    flag = true;  //  flag true if control is moved either
  }
}
