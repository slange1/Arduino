#define tx 2
#define data 3
#define t1 20

void setup() {
  Serial.begin(9600);
  pinMode(tx, OUTPUT);
  pinMode(data,OUTPUT);
  digitalWrite(data,HIGH);
  delay(100);
  Serial.println("Start");
}

void loop() {
  if(Serial.available()>0){
    digitalWrite(data,HIGH);
    String text = Serial.readString();
    int i;
    for(i=0; text[i]!='\0'; i+=1);
    Serial.println(i);
    short t;
    for(t=0; t<i; t+=1){
    fsk(text[t]);
    }
  }
}

void fsk(char c){
  tone(tx, 1275);
  digitalWrite(data, LOW);
  delay(t1);
  int i;
  for (i=0; i<=7; i+=1){
    if((c>>i) & 1){
        tone(tx, 2125);
        digitalWrite(data,HIGH);
        delay(t1);
      }
      else{
        tone(tx, 1275);
        digitalWrite(data,LOW);
        delay(t1);
     }  
  }
  tone(tx, 2125);
  digitalWrite(data,HIGH);
  delay(2*t1);
  //digitalWrite(data,LOW);
  noTone(tx);
}
