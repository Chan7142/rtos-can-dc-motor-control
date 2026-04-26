#include "rcc.h"
//uint32_t SystemCoreClock = 216000000;
void delay_ms(uint32_t ms) {
    if (ms == 0) return;

    // 1. SysTick 설정: 1ms 주기로 설정
    SysTick->LOAD = (SystemCoreClock / 1000) - 1;
    SysTick->VAL = 0; // 현재 값 초기화
    SysTick->CTRL = (1 << 2) | (1 << 0); // Processor Clock 사용, 타이머 활성화

    for (uint32_t i = 0; i < ms; i++) {
        while (!(SysTick->CTRL & (1 << 16)));
    }

    // 3. 종료 후 타이머 끄기
    SysTick->CTRL = 0;
}
