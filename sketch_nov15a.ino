#include <ESP8266WiFi.h>
 int motorLpin1=15;
int motorLpin2=13;
int motorRpin1=2;
int motorRpin2=0;
int motorLpwm=14;
int motorRpwm=12;


const char* ssid = "WIFI NI NATH";
const char* password = "whatisthepassword";
 

WiFiServer server(80);
 
void setup() {
  Serial.begin(115200);
  delay(2000);
 analogWriteRange(100);
  analogWriteFreq(500);
pinMode(motorLpin1,OUTPUT);
  pinMode(motorLpin2,OUTPUT);
  pinMode(motorRpin1,OUTPUT);
  pinMode(motorRpin2,OUTPUT);
  pinMode(motorLpwm,OUTPUT);
  pinMode(motorRpwm,OUTPUT);
  
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  
  server.begin();
  Serial.println("Server started");
 
  Serial.println(WiFi.localIP());
}

void loop() {
  WiFiClient client = server.available();
  if (!client) {
    return;
  }
  
  Serial.println("new client");
  while(!client.available()){
    delay(1);
  }
  
  String req = client.readStringUntil('\r');
  Serial.println(req);
  client.flush();
  
  int val;
  String m;
  if (req.indexOf("/D1/0") != -1){
    stp();

  }
  else if (req.indexOf("/D1/1") != -1){
    m = "D1 is High";
    fwd();
  }
  else if (req.indexOf("/D2/0") != -1){
    m = "D2 is Low";

  }
  else if (req.indexOf("/D2/1") != -1){
    m = "D2 is High";
    rev();
  }
  else if (req.indexOf("/D3/0") != -1){
    m = "D3 is Low";
  rght();
  }
  else if (req.indexOf("/D3/1") != -1){
    m = "D3 is High";
    lft();
   
  }
  else {
    Serial.println("invalid request");
    client.stop();
    return;
  }
 
  
  
  client.flush();
 
  String s = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<!DOCTYPE HTML>\r\n<head><meta http-equiv=\"Access-Control-Allow-Origin\" content=\"*\"></head>\n<html>\r\n" +m;
  s += "</html>\n";
 
  client.print(s);
  delay(1);
  Serial.println("Client disonnected");
 
}

void fwd(){

  analogWrite(motorLpwm,80);
  analogWrite(motorRpwm,80);
  digitalWrite(motorLpin1,0);
  digitalWrite(motorLpin2,1);
  digitalWrite(motorRpin1,1);
  digitalWrite(motorRpin2,0);
      
}

void rev(){
  
  analogWrite(motorLpwm,80);
  analogWrite(motorRpwm,80);
  digitalWrite(motorLpin1,1);
  digitalWrite(motorLpin2,0);
  digitalWrite(motorRpin1,0);
  digitalWrite(motorRpin2,1);
}

void lft(){
  analogWrite(motorLpwm,0);
  analogWrite(motorRpwm,80);
  digitalWrite(motorLpin1,0);
  digitalWrite(motorLpin2,1);
  digitalWrite(motorRpin1,1);
  digitalWrite(motorRpin2,0);
}

void rght(){
  analogWrite(motorLpwm,80);
  analogWrite(motorRpwm,0);
  digitalWrite(motorLpin1,0);
  digitalWrite(motorLpin2,1);
  digitalWrite(motorRpin1,0);
  digitalWrite(motorRpin2,1);
}

void stp(){
  digitalWrite(motorLpwm,0);
  digitalWrite(motorRpwm,0);
  digitalWrite(motorLpin1,1);
  digitalWrite(motorLpin2,1);
  digitalWrite(motorRpin1,1);
  digitalWrite(motorRpin2,1);
}
