#ifndef BlackpillTimer_h
#define BlackpillTimer_h

#include "Arduino.h"
#include "HardwareTimer.h"

class BlackpillTimer {
  public:
    BlackpillTimer(TIM_TypeDef *instance);
    void setIntervalMs(uint32_t intervalMs); // 인터럽트 시간을 ms로 설정
    void attachUpdateInterrupt(void (*isr)());
    void start(); // 타이머 시작
  private:
    HardwareTimer *MyTim;
};

#endif