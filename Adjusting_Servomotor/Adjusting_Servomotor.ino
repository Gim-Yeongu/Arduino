/*
  180도 서보모터를 0도부터 180도까지 왕복으로 동작시키는 코드
*/

#include <Servo.h> //서보 헤더파일을 전처리(아두이노에게 서보모터를 사용할 것임을 알림)
 
#define angle_max 180 //서보모터의 가동 각도 설정
#define servoPin = 9 //서보 핀 설정

Servo servo; //Servo타입 servo변수 설정 만약 2개의 서보 사용 시 Servo servo1;
             //                                             Servo servo2;로 사용하며, 최대 8개까지 사용 가능

int angle = 0; // servo position in degrees 

void setup() 
{ 
    servo.attach(servoPin); //서보 변수에게 제어핀을 알림
} 


void loop() 
{ 
  // scan from 0 to angle_max degrees
  for(angle = 0; angle < angle_max; angle++) 
  { 
    servo.write(angle); 
    delay(15); 
  } 
  // now scan back from 180 to 0 degrees
  for(angle = angle_max; angle > 0; angle--) 
  { 
    servo.write(angle); 
    delay(15); 
  } 
} 
