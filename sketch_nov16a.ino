int motorLpin1=22;
int motorLpin2=24;
int motorRpin1=26;
int motorRpin2=31;
int motorLpwm=2;
int motorRpwm=3;
int trig_pin=32;
int echo_pin=30;
char val=0;
long duration,cm,inches;
int safeDistance=40;
int x=1;
#define LS A0
#define RS A8

int motorSpeed=80;
int turn=20;
void setup() {
  pinMode(LS, INPUT);
  pinMode(RS, INPUT);
  Serial.begin(9600);
  Serial.flush();
  pinMode(motorLpin1,OUTPUT);
  pinMode(motorLpin2,OUTPUT);
  pinMode(motorRpin1,OUTPUT);
  pinMode(motorRpin2,OUTPUT);
  pinMode(motorLpwm,OUTPUT);
  pinMode(motorRpwm,OUTPUT);
  pinMode(trig_pin,OUTPUT);
  pinMode(echo_pin,INPUT);
}

void loop() {
  sonar();
  bluetooth();
}
void sonar()
{
    //sonar sensor  
    digitalWrite(trig_pin, LOW);
    delayMicroseconds(1);
    digitalWrite(trig_pin, HIGH);
    delayMicroseconds(1);
    digitalWrite(trig_pin, LOW);
 
    pinMode(echo_pin, INPUT);
    duration = pulseIn(echo_pin, HIGH);
 
  // convert the time into a distance
  cm = (duration/2) / 29.1;
  inches = (duration/2) / 74; 
  
  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  
  delay(1);

  }
void bluetooth()
{
  if(Serial.available()){
    val=Serial.read();
    delay(5);
  } 
  if(val=='0'){
    stp();
  }
 else if(val=='1' && cm>safeDistance){
            sonar();
      if(cm<safeDistance)
      {
        stp();
        sonar();
      }
      else
      {
         fwd();
      }

  }
  else if(val=='2'){
    rev();
  }
  else if(val=='3'){
    lft();
  }
  else if(val=='4'){
    rght();
  }
  
 /* else if(val=='6')
  {
  if(digitalRead(LS) && digitalRead(RS))     // Move Forward
  {
      analogWrite(motorLpwm,70);
  analogWrite(motorRpwm,70);
  digitalWrite(motorLpin1,0);
  digitalWrite(motorLpin2,1);
  digitalWrite(motorRpin1,1);
  digitalWrite(motorRpin2,0);
  delay(200);
  stp();
  x=1;
  }
  
  if(!(digitalRead(LS)) && digitalRead(RS))     // Turn right
  {
      analogWrite(motorLpwm,70);
  analogWrite(motorRpwm,0);
  digitalWrite(motorLpin1,0);
  digitalWrite(motorLpin2,1);
  digitalWrite(motorRpin1,0);
  digitalWrite(motorRpin2,1);
   delay(200);
  stp();
    x=1;
  }
  
  if(digitalRead(LS) && !(digitalRead(RS)))     // turn left
  {
      analogWrite(motorLpwm,0);
  analogWrite(motorRpwm,70);
  digitalWrite(motorLpin1,0);
  digitalWrite(motorLpin2,1);
  digitalWrite(motorRpin1,1);
  digitalWrite(motorRpin2,0);
  delay(200);
  stp();
  x=1;
     
  }
  
  if(!(digitalRead(LS)) && !(digitalRead(RS)))     // stop
  {
    if(x==1)
    {
          analogWrite(motorLpwm,motorSpeed);
  analogWrite(motorRpwm,motorSpeed);
  digitalWrite(motorLpin1,1);
  digitalWrite(motorLpin2,0);
  digitalWrite(motorRpin1,0);
  digitalWrite(motorRpin2,1);
  delay(600);
  analogWrite(motorLpwm,0);
  analogWrite(motorRpwm,0);
  delay(400);
  analogWrite(motorLpwm,70);
  analogWrite(motorRpwm,0);
  digitalWrite(motorLpin1,0);
  digitalWrite(motorLpin2,1);
  digitalWrite(motorRpin1,1);
  digitalWrite(motorRpin2,0);
  delay(1200);
  stp();
  x++;
  }
  
  }
  }
  else if(val=='5')
  {
  if(digitalRead(LS) && digitalRead(RS))     // Move Forward
  {
      analogWrite(motorLpwm,70);
  analogWrite(motorRpwm,70);
  digitalWrite(motorLpin1,0);
  digitalWrite(motorLpin2,1);
  digitalWrite(motorRpin1,1);
  digitalWrite(motorRpin2,0);
  delay(200);
  stp();
  x=1;
  }
  
  if(!(digitalRead(LS)) && digitalRead(RS))     // Turn right
  {
      analogWrite(motorLpwm,70);
  analogWrite(motorRpwm,0);
  digitalWrite(motorLpin1,0);
  digitalWrite(motorLpin2,1);
  digitalWrite(motorRpin1,0);
  digitalWrite(motorRpin2,1);
   delay(200);
  stp();
    x=1;
  }
  
  if(digitalRead(LS) && !(digitalRead(RS)))     // turn left
  {
      analogWrite(motorLpwm,0);
  analogWrite(motorRpwm,70);
  digitalWrite(motorLpin1,0);
  digitalWrite(motorLpin2,1);
  digitalWrite(motorRpin1,1);
  digitalWrite(motorRpin2,0);
  delay(200);
  stp();
  x=1;
     
  }
  
  if(!(digitalRead(LS)) && !(digitalRead(RS)))     // stop
  {
    if(x==1)
    {
      analogWrite(motorLpwm,motorSpeed);
  analogWrite(motorRpwm,motorSpeed);
  digitalWrite(motorLpin1,1);
  digitalWrite(motorLpin2,0);
  digitalWrite(motorRpin1,0);
  digitalWrite(motorRpin2,1);
  delay(600);
  analogWrite(motorLpwm,0);
  analogWrite(motorRpwm,0);
  delay(400);
  analogWrite(motorLpwm,0);
  analogWrite(motorRpwm,70);
  digitalWrite(motorLpin1,0);
  digitalWrite(motorLpin2,1);
  digitalWrite(motorRpin1,1);
  digitalWrite(motorRpin2,0);
  delay(1200);
  stp();
  x++;
  }
  
  }
  }
}
*/
}
void fwd(){
Serial.print("goinh forward  with ");
      Serial.print(cm);
      Serial.print(" cm  and going");
      Serial.println();
                  sonar();
      if(cm<safeDistance)
      {
        stp();
        sonar();
      }
      else
      {
  analogWrite(motorLpwm,motorSpeed);
  analogWrite(motorRpwm,motorSpeed);
  digitalWrite(motorLpin1,0);
  digitalWrite(motorLpin2,1);
  digitalWrite(motorRpin1,1);
  digitalWrite(motorRpin2,0);
      }
}

void rev(){
  
  analogWrite(motorLpwm,motorSpeed);
  analogWrite(motorRpwm,motorSpeed);
  digitalWrite(motorLpin1,1);
  digitalWrite(motorLpin2,0);
  digitalWrite(motorRpin1,0);
  digitalWrite(motorRpin2,1);
}

void lft(){
  analogWrite(motorLpwm,0);
  analogWrite(motorRpwm,motorSpeed);
  digitalWrite(motorLpin1,0);
  digitalWrite(motorLpin2,1);
  digitalWrite(motorRpin1,1);
  digitalWrite(motorRpin2,0);
}

void rght(){
  analogWrite(motorLpwm,motorSpeed);
  analogWrite(motorRpwm,0);
  digitalWrite(motorLpin1,0);
  digitalWrite(motorLpin2,1);
  digitalWrite(motorRpin1,0);
  digitalWrite(motorRpin2,1);
}

void stp(){
  analogWrite(motorLpwm,0);
  analogWrite(motorRpwm,0);
  digitalWrite(motorLpin1,1);
  digitalWrite(motorLpin2,1);
  digitalWrite(motorRpin1,1);
  digitalWrite(motorRpin2,1);
}

