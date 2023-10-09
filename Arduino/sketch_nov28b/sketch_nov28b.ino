void setup() {
  // put your setup code here, to run once:
pinMode(A0,INPUT);
pinMode(3,OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
int val,x;
val=analogRead(A0);
x=map(val,0,1023,0,255);
analogWrite(3,x);
Serial.print(val);
Serial.print("\t");
Serial.println(x);
delay(2500);
}
