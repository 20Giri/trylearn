char t;
 int vSpeed = 200;        // MAX 255
  int turn_speed = 100;    // MAX 255 

  const int motorA1           = 12;    
  const int motorA2           = 11; 
  const int motorAspeed  = 13;
  const int motorB1           = 9; 
  const int motorB2           = 10; 
  const int motorBspeed  = 8;
 
  const int motorC1           = 3;    
  const int motorC2           = 4; 
  const int motorCspeed  = 2;
  const int motorD1           = 5; 
  const int motorD2           = 6; 
  const int motorDspeed  = 7;

void setup() {
pinMode(motorA1,OUTPUT);   //left motors forward
pinMode(motorA2,OUTPUT);   //left motors reverse
pinMode(motorB1,OUTPUT);   //right motors forward
pinMode(motorB2,OUTPUT);   //right motors reverse
pinMode(motorC1,OUTPUT);
pinMode(motorC2,OUTPUT);
pinMode(motorD1,OUTPUT);
pinMode(motorD2,OUTPUT);
pinMode(0,INPUT);
pinMode(1,INPUT);
Serial.begin(9600);
 
}
 
void loop() {
if(Serial.available()){
  t = Serial.read();
  Serial.println(t);
}
 
if(t == 'F'){            //move forward(all motors rotate in forward direction)
   digitalWrite (motorA2,HIGH);
  digitalWrite(motorA1,LOW);                       
  digitalWrite (motorB2,LOW);
  digitalWrite(motorB1,HIGH);
  digitalWrite (motorAspeed, vSpeed);
  digitalWrite (motorBspeed, vSpeed);

}
 
else if(t == 'B'){      //move reverse (all motors rotate in reverse direction)
   digitalWrite (motorA1,HIGH);
  digitalWrite(motorA2,LOW);                       
  digitalWrite (motorB1,LOW);
  digitalWrite(motorB2,HIGH);
  digitalWrite (motorAspeed, vSpeed);
  digitalWrite (motorBspeed, vSpeed);
}
 
else if(t == 'R'){      //turn right (left side motors rotate in forward direction, right side motors doesn't rotate)
  digitalWrite (motorA1,LOW);
  digitalWrite(motorA2,HIGH);                       
  digitalWrite (motorB1,LOW);
  digitalWrite(motorB2,HIGH);
  digitalWrite (motorAspeed, vSpeed);
  digitalWrite (motorBspeed, turn_speed);
}
 
else if(t == 'L'){      //turn left (right side motors rotate in forward direction, left side motors doesn't rotate)
  digitalWrite (motorA1,HIGH);
  digitalWrite(motorA2,LOW);                       
  digitalWrite (motorB1,HIGH);
  digitalWrite(motorB2,LOW);
  digitalWrite (motorAspeed, turn_speed);
  digitalWrite (motorBspeed, vSpeed);
}
else if(t == 'W'){      
  digitalWrite (motorC1,HIGH);
  digitalWrite(motorC2,LOW);                       
}
else if(t == 'w'){      
  digitalWrite (motorC1,LOW);
  digitalWrite(motorC2,LOW);                       
}
else if(t == 'B'){      
  digitalWrite (motorD1,HIGH);
  digitalWrite(motorD2,LOW);                       
}
else if(t == 'b'){      
  digitalWrite (motorD1,LOW);
  digitalWrite(motorD2,LOW);                       
}
 
else if(t == 'S'){      //STOP (all motors stop)
  digitalWrite(motorA1,LOW);
  digitalWrite(motorA2,LOW);
  digitalWrite(motorB1,LOW);
  digitalWrite(motorB2,LOW);
  digitalWrite (motorAspeed, LOW);
  digitalWrite (motorBspeed, LOW);
  digitalWrite(motorC1,LOW);
  digitalWrite(motorC2,LOW);
  digitalWrite(motorD1,LOW);
  digitalWrite(motorD2,LOW);
  
}
delay(100);
}
