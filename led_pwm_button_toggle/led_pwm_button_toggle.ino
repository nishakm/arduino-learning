const int LED=9; //pin 9 is LED
const int BUTTON=2; //pin 2 is button

boolean lastButton = LOW; //the last state of the button - now LOW
boolean currentButton = LOW; //the current state of the button - now LOW
boolean ledOn = false; //is the led on? no...

void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT); //the pin mode for LED (9) is output
  pinMode(BUTTON, INPUT); //the pin mode for the BUTTON (2) is input

}

/*
 * Debounce - when the button is pressed the state doesn't change
 * immediately. You need to wait for the voltage to stop
 * oscillating
 * 
 * So give it the last button state
 * it will catch the current button state
 * if it is different from the previous button state
 * then wait 5ms and read it again
 * then return the value
 */
boolean debounce(boolean last){
  boolean current = digitalRead(BUTTON); //read the state of the button now
  if (last != current){
    //state has changed!
    delay(5); //delay for 5ms
    current = digitalRead(BUTTON); //read it again
  }
  return current;
}

void loop() {
  // put your main code here, to run repeatedly:
  currentButton = debounce(lastButton);
  if(lastButton == LOW && currentButton == HIGH){
    ledOn = !ledOn; //toggle!
  }

  lastButton = currentButton; //the last button state is now the current button state
  digitalWrite(LED, ledOn);
}
