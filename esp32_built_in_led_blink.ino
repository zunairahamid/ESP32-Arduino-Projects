#define LED 2
void setup() {
  // put your setup code here, to run once:
pinMode(LED,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
delay(1000);
digitalWrite(LED,HIGH);
delay(1000);
digitalWrite(LED,LOW);
}
