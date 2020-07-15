/*
  초음파센서로 읽은 거리값을 앱 인벤터로 전송하는 코드
  pulsIn(pin, value)함수 설명
    pin:펄스신호를 받아들이는 핀 번호
    value: HIGH 또는 LOW
    결과값:펄스의 지속시간(us, 마이크로세컨드 단위)
    주의점: pin은 펄스를 읽어오는 핀이므로 pinMode()에서 INPUT으로 설정되어 있어야 함.
        e.g)pulsIn(1,HIGH)면, 1번 핀이 0[V]에서 5[V]가 되는 시점부터 다시 0[V]가 되는 시점까지의 시간을 마이크로세컨드 단위로 계산
*/

#include <SoftwareSerial.h>  //소프트웨어 시리얼 헤더파일 전처리

#define BTtx 12 //블루투스 tx핀이 연결된 아두이노 핀 번호
#define BTrx 13 //블루투스 rx핀이 연결된 아두이노 핀 번호
#define TRIG 3  //초음파센서 trig핀이 연결된 아두이노 핀 번호
#define ECHO 4  //초음파센서 echo핀이 연결된 아두이노 핀 번호

SoftwareSerial BT(BTtx, BTrx); //소프트웨어 시리얼 객체 설정

int Duration = 0; //에코값을 받을 변수 선언

void setup()
{
  BT.begin(9600);         //소프트웨어 시리얼 통신 준비
  Serial.begin(9600);     //하드웨어 시리얼 통신 준비
  pinMode(TRIG, OUTPUT);  //TRIG핀 출력 모드 설정
  pinMode(ECHO, INPUT);   //ECHO핀 입력 모드 설정
}

void loop()
{
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);        //TRIG 핀 ON
  delayMicroseconds(10);           //10마이크로초 동안 신호 전송
  digitalWrite(TRIG, LOW);         //TRIG 핀 OFF 

  Duration = pulseIn(ECHO, HIGH);  //해당 함수에 대한 자세한 설명은 위의 주석에 표시

  int Distance_mm = Distance(Duration);

  Serial.print("Distance = ");
  Serial.print(Distance_mm);
  Serial.println("mm");

  BT.write(Distance_mm);
  delay(1000);
}

long Distance(long time) //거리 구하기 함수
{
  long DistanceCalc;
  DistanceCalc = (((time*340)/1000)/2);
  return DistanceCalc;
}
