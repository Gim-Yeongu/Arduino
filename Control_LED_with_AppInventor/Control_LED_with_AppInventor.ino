/*
  앱 인벤터로부터 숫자를 전송받아 LED를 ON/OFF 하는 코드
  전송받은 숫자가 1일 경우, LED ON
                0일 경우, LED OFF
  LED의 상태를 시리얼 모니터에 출력
*/
#include <SoftwareSerial.h>

#define LED_PIN 4  // LED핀 번호
#define BTtx    12 // 블루투스 tx핀이 연결된 아두이노 핀 번호
#define BTrx    13 // 블루투스 rx핀이 연결된 아두이노 핀 번호

SoftwareSerial BT(BTtx, BTrx); // 소프트웨어 시리얼 객체

int data = 0;  //모바일 앱으로 부터 입력받은 값을 저장할 변수

void setup(){
  BT.begin(9600);                // 소프트웨어 시리얼 통신 준비
  Serial.begin(9600);            // 하드웨어 시리얼 통신 준비
  pinMode(LED_PIN, OUTPUT);      // 4번핀 출력모드
}

void loop(){
  if(BT.available()>0){          // 블루투스 통신으로 입력된 데이터가 있으면
    data = BT.read();            // 입력된 데이터를 읽어서 변수에 저장하기
  }
  if(data==0){                   // data가 숫자 0이면
    digitalWrite(LED_PIN, LOW);  // LED를 끄고
    Serial.println("LED OFF");   // 시리얼모니터에 LED OFF 문구 출력
  }
  else if(data==1){              // data가 숫자 1이면
    digitalWrite(LED_PIN, HIGH); // LED를 키고
    Serial.println("LED ON");    // 시리얼모니터에 LED ON 문구 출력
  }
}
