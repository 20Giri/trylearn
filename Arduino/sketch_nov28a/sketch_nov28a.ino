long duration;
int distance;
void setup() {
  // put your setup code here, to run once:
pinMode(10,INPUT);
pinMode(9,OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
 digitalWrite(9,HIGH);
 delayMicroseconds(2);
 digitalWrite(9,LOW);
 delayMicroseconds(10);
 digitalWrite(9,HIGH);
 duration=pulseIn(10,HIGH);
 distance=(duration*0.034)/2;
 Serial.println("Distance:");
 Serial.println("distance");    
}
