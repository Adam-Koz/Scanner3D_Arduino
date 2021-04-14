#define trigPin 12
#define echoPin 11
#include<Servo.h>

int LiczpomiarPoziom =3, stopienPoziom = 60;
int LiczpomiarPion = 5, stopienPion = 20;
Servo servoX, servoY;
String command;
float times , distance;
void czujnik();
void setup() {
  command = "";
  Serial.begin(115200);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  servoX.attach(5); // left-right servo
  servoY.attach(6); // forward-backward servo
  servoX.write(90); 
  servoY.write(25);
}

void loop() {
  command = Serial.readStringUntil('\n');
  delay(100);
  int x=0,y=0; // varible to while loop

  if(command == "start"){
    servoX.write(180);
    servoY.write(25);

   for(int i=0; i<LiczpomiarPion;i++){
    
    for(int j=0; j<LiczpomiarPoziom;j++){
      servoX.write(servoX.read()- stopienPoziom);
      czujnik();
      delay(100); 
    }
    
    servoX.write(180);
    servoY.write(servoY.read() + stopienPion);
   }
         
  }else if(command == "start1"){ 
    servoX.write(170);
    czujnik(); 
    delay(100);
    servoX.write(10);
    czujnik();    
  }
 servoX.write(90); 
 servoY.write(25); 
 command =""; 
}

void czujnik(){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
 
  times = pulseIn(echoPin, HIGH);
  
  distance = (times* .0343)/2;
  String d = String(distance);
  String x = String(servoX.read());
  String y = String(map(servoY.read(), 25, 115, 0, 115));
  String data = d + "#" + x + "#" + y; 
  delay(100);
  Serial.println(data);
}
