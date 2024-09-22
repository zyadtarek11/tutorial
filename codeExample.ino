#include <stdio.h>
#define IR1 2  // the sensor at the front of the robot
#define IR2 3   // the sensor at the back of the robot
#define IR3 13   // the sensor at the right side of the robot
#define IR4 5   // the sensor at the left side of the robot
#define right_motor1 6
#define right_motor2 1
#define left_motor1 4
#define left_motor2 9
int signalF =0;    // the signal recieved from the first IR (front) sensor
int signalB =0;    // the signal recieved from the secend IR (back) sensor
int signalR =0;    // the signal recieved from the third IR (right) sensor
int signalL =0;    // the signal recieved from the fourth IR (left) sensor
void right(){
  digitalWrite(right_motor1, LOW);
  digitalWrite(right_motor2, LOW);
  digitalWrite(left_motor1, HIGH);
  digitalWrite(left_motor2, LOW); // this block of code let the robot turn right
  delay(500);
}
void left(){
  digitalWrite(right_motor1, HIGH);
  digitalWrite(right_motor2, LOW);
  digitalWrite(left_motor1, LOW);
  digitalWrite(left_motor2, LOW); // this block of code let the robot turn left
  delay(500);
}
void forward(){
                  digitalWrite(right_motor1, HIGH);
                  digitalWrite(right_motor2, LOW);
                  digitalWrite(left_motor1, HIGH);
                  digitalWrite(left_motor2, LOW); // this block of code let the robot move forward
                  delay(500);
}
void stop(){
      digitalWrite(right_motor1, LOW);
      digitalWrite(right_motor2, LOW);
      digitalWrite(left_motor1, LOW);
      digitalWrite(left_motor2, LOW); // this block of code let the robot stop
      delay(500);
}
void setup() {
  pinMode(IR1, INPUT);
  pinMode(IR2, INPUT);
  pinMode(IR3, INPUT);
  pinMode(IR4, INPUT);
  pinMode(right_motor1, OUTPUT);
  pinMode(right_motor2, OUTPUT);
  pinMode(left_motor1, OUTPUT);
  pinMode(left_motor2, OUTPUT);
  pinMode(right_motor_EN, OUTPUT);
  pinMode(left_motor_EN, OUTPUT);
  Serial.begin(9600);
}
void loop() {
  signalF = digitalRead(IR1);   // read the signal of the first IR (front) sensor
  signalB = digitalRead(IR2);   // read the signal of the second IR (back) sensor      
  signalR = digitalRead(IR3);   // read the signal of the third IR (right) sensor
  signalL = digitalRead(IR4);   // read the signal of the fourth IR (left) sensor
  Serial.println(signal1);      // print the data from the first sensor on the serial monitornd algorithm)
  switch (signalF){
    case HIGH :
      switch (signalB){
        case HIGH :
          switch (signalR){
            case HIGH :
              right(); 
              break ;
            case LOW :
              switch (signalL){
                case HIGH :
                  left();
                  break ;
                case LOW :
                  forward();
                  break ;
              }
          }
        case LOW :
          forward();
      }
    case LOW :
      switch (signalB){
        case HIGH :
          switch (signalR){
            case HIGH :
              right();
              break ;
            case LOW :
              switch (signalL){
                case HIGH :
                  left(); 
                  break;
                case LOW :
                  
                 while(signalB==HIGH^signalF==LOW) {
                  forward();
                 }
                 while(signalF==LOW);
                 do {
                  right();
                 }
                   break ; //  this piece of code let the robot  turn around but Im not sure
              }  
          }
      }
    default :
      stop();
      break ;
  }
}