//Variables
int redLight1 = 12;
int yellowLight = 11;
int greenLight1 = 10;

int redLight2 = 8;
int greenLight2 = 7;

int btnButton = 9;

int pedRed = 8;
int pedGreen = 7;
int crossTime = 5000;
long changeTime;

void setup() {
  // put your setup code here, to run once:
  pinMode(redLight1,OUTPUT);
  pinMode(redLight2,OUTPUT);
  pinMode(yellowLight, OUTPUT);
  pinMode(greenLight1,OUTPUT);

  pinMode(redLight2,OUTPUT);
  pinMode(greenLight2,OUTPUT);

  pinMode(btnButton,INPUT);

  digitalWrite(greenLight1,HIGH);
  digitalWrite(redLight1,LOW);
  digitalWrite(redLight2,HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  int state = digitalRead(btnButton);

  if(state == HIGH && (millis()-changeTime) > 5000){
    changeLights();
  }
}

void changeLights(){
  digitalWrite(greenLight1, LOW);
  digitalWrite(yellowLight, HIGH);
  delay(2000);
  digitalWrite(yellowLight, LOW);
  digitalWrite(redLight1, HIGH);
  delay(1000);
  digitalWrite(pedRed, LOW);
  digitalWrite(pedGreen, HIGH);
  delay(crossTime);
  //grünes Blinken fürs Warnen
  for (int x=0; x<10; x++) {
    digitalWrite(pedGreen, HIGH);
    delay(250);
    digitalWrite(pedGreen, LOW);
    delay(250);
  }
  digitalWrite(pedRed, HIGH);
  delay(500);
  digitalWrite(redLight1, LOW);
  digitalWrite(yellowLight, HIGH);
  delay(1000);
  delay(1000);
  digitalWrite(yellowLight, LOW);
  digitalWrite(greenLight1, HIGH);
  changeTime = millis();
}
