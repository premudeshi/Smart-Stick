


#define trigPin 11

#define echoPin 12

int buzzer = 5;

void setup() {

  Serial.begin (9600);

  pinMode(trigPin, OUTPUT);

  pinMode(echoPin, INPUT);

  pinMode(buzzer, OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);  



}

void redColor(){  
  digitalWrite(10, HIGH);
  digitalWrite(9, LOW);
  digitalWrite(8, LOW);
}
void blueColor(){  
  digitalWrite(10, LOW);
  digitalWrite(9, HIGH);
  digitalWrite(8, LOW);
}
void greenColor(){
  digitalWrite(10, LOW);
  digitalWrite(9, LOW);
  digitalWrite(8, HIGH);  
}
void off(){
  digitalWrite(10, LOW);
  digitalWrite(9, LOW);
  digitalWrite(8, LOW); 
}

void magenta(){
  digitalWrite(10, HIGH);
  digitalWrite(9, HIGH);
  digitalWrite(8, LOW);
  
}
void loop() {

  int DelayTime;
  char colorChange;
  long duration, distance;

  digitalWrite(trigPin, LOW); 

  delayMicroseconds(2); 

  digitalWrite(trigPin, HIGH);


  delayMicroseconds(10); 

  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  distance = (duration/2) / 29.1;  
  
    DelayTime = distance * 20;
    
  if(distance > 100){
    //safe side
    
        analogWrite(buzzer, 0);
        greenColor();
        colorChange = 'G';
  }else if((distance <= 60) && (distance > 20)){
    //close
    analogWrite(buzzer, 30);
    blueColor();
        colorChange = 'B';
    //delay(500);
    
    delay(DelayTime);
    off();
    analogWrite(buzzer, 0);
  }else if((distance <= 20) && (distance > 10)){
    //warning
      
    analogWrite(buzzer, 30);
    magenta();
        colorChange = 'M';
    //delay(300);
    delay(DelayTime);
    off();
    analogWrite(buzzer, 0);    
    }else if((distance < 10) && (distance > 5)){
      //danger
      analogWrite(buzzer, 60);
      redColor();
        colorChange = 'R';
    //delay(50);
    delay(DelayTime);
    off();
    analogWrite(buzzer, 0); 
    }
    if (distance <= 5) {
      //dead
      redColor();
        colorChange = 'X';
      analogWrite(buzzer, 60);
    }
  
  if (distance >= 500 || distance <= 0){

    Serial.println("Out of range");

  } else {

    Serial.print(distance);
    Serial.println(" cm");
    Serial.println(colorChange);
  }

  delay(80);

}
