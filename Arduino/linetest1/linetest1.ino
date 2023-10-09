// First the line following (IR) sensors
const int irLeft = 0; //Left line sensor is on pin A0
const int irRight = 1; //Right line sensor is on pin A1

//Motor A (Right)
int enableA = 13;
int pinA1 = 9;
int pinA2 = 6;

//Motor B (Left)
int enableB = 12;
int pinB1 = 5;
int pinB2 = 3;
//Define Run variable
boolean run;
void setup() {
pinMode(enableA, OUTPUT);
pinMode(pinA1, OUTPUT);
pinMode(pinA2, OUTPUT);
pinMode(enableB, OUTPUT);
pinMode(pinB1, OUTPUT);
pinMode(pinB2, OUTPUT);
}
void loop(){
  int valleft= analogRead(irLeft);
   int leftsensor = analogRead(A0);  //in the side of motor B
  int rightsensor = analogRead(A1);  //in the side of motor A

   if ((leftsensor >= 700) && (rightsensor >= 700))
     forward();
        else if((leftsensor <= 150) && (rightsensor <= 150))
     backward();
     else if((leftsensor <= 150) && (rightsensor >= 700))
     turnright();
     else if((leftsensor >= 700) && (rightsensor <= 150))
     turnleft();
}
//Motors Foward
void forward(){
  digitalWrite(pinA1,HIGH);
  digitalWrite(pinA2,LOW);
  digitalWrite(pinB1,HIGH);
  digitalWrite(pinB2,LOW);
}
// Motors Backward
void backward(){
  digitalWrite(pinA1,LOW);
  digitalWrite(pinA2,HIGH);
  digitalWrite(pinB1,LOW);
  digitalWrite(pinB2,HIGH);
}
// turn left
void turnleft(){
  digitalWrite(pinA1,HIGH);
  digitalWrite(pinA2,LOW);
  digitalWrite(pinB1,LOW);
  digitalWrite(pinB2,HIGH);
}
// turn right 
void turnright(){
  digitalWrite(pinA1,LOW);
  digitalWrite(pinA2,HIGH);
  digitalWrite(pinB1,HIGH);
  digitalWrite(pinB2,LOW);
}
