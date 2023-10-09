String readString, ON,OFF,a;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(13,OUTPUT);
  

}

void loop() {
  // put your main code here, to run repeatedly:
  
 a=Serial.readString();
{if (a==ON)
  digitalWrite(13,HIGH);
 else if(a==OFF)
  digitalWrite(13,LOW);
  
} 
}
