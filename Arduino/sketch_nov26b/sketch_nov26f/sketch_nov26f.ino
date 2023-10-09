void setup() {
  // put your setup code here, to run once:
pinMode(13,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
int a=Serial.read();
for(a=0;a<=10;a++)
{
  Serial.println(13,HIGH);
}
Serial.println(13,LOW);
}
