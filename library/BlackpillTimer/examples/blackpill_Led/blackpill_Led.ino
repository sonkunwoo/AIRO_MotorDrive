#include "BlackpillTimer.h"

BlackpillTimer myTimer(TIM1); // TIM1 사용

void myUpdateISR() {
  digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN)); // LED 상태 토글
}

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  myTimer.setIntervalMs(500); // 500ms 설정, 이는 2Hz와 동일
  myTimer.attachUpdateInterrupt(myUpdateISR); // 인터럽트 핸들러 연결
  myTimer.start(); // 타이머 시작
}

void loop() {
  // 메인 코드는 여기에 작성. 타이머 인터럽트는 자동으로 처리됨.
}
