/*
  블루투스 모듈의 이름 또는 비밀번호를 변경하는 코드
  시리얼 모니터에 'line ending 없음'설정 후 'AT' 입력 시, 'OK'
                'AT+NAMEME' 입력 시, ME로 이름 변경
                'AT+PIN0000' 입력 시, 0000으로 패스워드 변경
 */
#include<SoftwareSerial.h> //시리얼통신 헤더파일 로드

#define BTtx 12 // tx핀 설정
#define BTrx 13 // rx핀 설정

SoftwareSerial BT(BTtx, BTrx); //시리얼통신 객체 설정

void setup(){
  Serial.begin(9600);
  BT.begin(9600);
}
void loop(){
  if(BT.available())
    Serial.write(BT.read());

  if(Serial.available())
    BT.write(Serial.read());
}
