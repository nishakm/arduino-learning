const int LED=9;

void setup() {
  // put your setup code here, to run once:
  pinMode (LED, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  //fade in
  for (int i=0; i<256; i++)
  {
    analogWrite(LED, i); //write value from 0 - 255
    delay(10); //then delay by 10
  }

  //fade out
  for (int i=255; i>=0; i--)
  {
    analogWrite(LED, i); //now go the other way around
    delay(10);
  }

}
