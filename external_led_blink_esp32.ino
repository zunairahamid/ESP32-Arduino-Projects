#define LED 23
//define LED which is at connected at GPIO pin 23
void setup() {
  // put your setup code here, to run once:
pinMode(LED,OUTPUT);
  //configure LED as output
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(LED,HIGH);
  //Turn on LED HIGH is for turning on and LOW is for turning off
delay(1000);
  //keep LED on for 1 second
digitalWrite(LED,LOW);
  //turn LED off 
delay(1000);
  //keep LED off for 1 second
}
