int trig = 12;
int echo = 11;
int f1 = 2;
int r1 = 3;
int f2 = 4;
int r2 = 5;
void setup() {
  Serial.begin(9600);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(f1, OUTPUT);
  pinMode(r1, OUTPUT);
  pinMode(f2, OUTPUT);
  pinMode(r2, OUTPUT);
}

void loop() {
  digitalWrite(trig, HIGH);
  delayMicroseconds(16);
  digitalWrite(trig, LOW);
  int dist = pulseIn(echo, HIGH)/58;
  Serial.println(dist);
  if(dist > 10){
    forward();
    delay(100);
  }
  else{
    backward();
    delay(1500);
  }

}
void forward(){
  analogWrite(r1, 0);
  analogWrite(r2, 0);  
  delay(10);
  analogWrite(f1, 255);
  analogWrite(f2, 255);
}
void backward(){
  analogWrite(f1, 0);
  analogWrite(f2, 0);  
  delay(10);
  analogWrite(r1, 255);
  analogWrite(r2, 255);
}
