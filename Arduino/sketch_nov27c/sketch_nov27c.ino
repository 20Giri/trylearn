int sensor_Reading,sensor=10;
void setup() {
 
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(13,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
sensor_Reading = digitalRead(sensor);
Serial.println(sensor_Reading);
if(sensor_Reading==1)
digitalWrite(13,HIGH);
else
digitalWrite(13,LOW);
}
