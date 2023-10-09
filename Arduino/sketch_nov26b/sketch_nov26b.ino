int a=50,b=100,c;
void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  
  c=a+b;
  Serial.print(c);
  

}
