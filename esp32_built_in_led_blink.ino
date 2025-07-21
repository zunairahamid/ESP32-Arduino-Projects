#define LED 2 
// built-in LED is at GPIO PIN 2, hence it is defined as such
void setup() {
  // put your setup code here, to run once:
pinMode(LED,OUTPUT);
  //LED is configured as output
}

void loop() {
  // put your main code here, to run repeatedly:
delay(1000);
  //keep LED off for 1 second
digitalWrite(LED,HIGH);
  //turn on the LED HIGH is for on and LOW is for OFF
delay(1000);
  //keep LED on for for 1 second
digitalWrite(LED,LOW);
  //turn LED off
}
