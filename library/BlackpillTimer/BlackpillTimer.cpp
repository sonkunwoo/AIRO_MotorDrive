#include "BlackpillTimer.h"

BlackpillTimer::BlackpillTimer(TIM_TypeDef *instance) {
  MyTim = new HardwareTimer(instance);
}

void BlackpillTimer::setIntervalMs(uint32_t intervalMs) {
  // 밀리세컨드를 헤르츠로 변환하여 setOverflow에 전달
  uint32_t hz = 1000 / intervalMs; // 밀리세컨드를 헤르츠로 변환
  MyTim->setOverflow(hz, HERTZ_FORMAT); // 헤르츠 단위로 설정
}

void BlackpillTimer::attachUpdateInterrupt(void (*isr)()) {
  MyTim->attachInterrupt(isr);
}

void BlackpillTimer::start() {
  MyTim->resume(); // 타이머 시작
}