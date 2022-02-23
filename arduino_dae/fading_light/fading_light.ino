//Variablen
int ledPin = 10;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin,OUTPUT); 
}

void loop() {
  // put your main code here, to run repeatedly:
  fadeOn(1000, 10);
  fadeOff(1000, 10);
}

void fadeOn(unsigned int time,int increment){
  for(byte value = 0; value < 255; value+=increment){
    analogWrite(ledPin, value);
    delay(time/(255/5));
  }
}

void fadeOff(unsigned int time,int decrement){
  for(byte value=255; value>0; value-=decrement){
    analogWrite(ledPin, value);
    delay(time/(255/5));
  }
}
