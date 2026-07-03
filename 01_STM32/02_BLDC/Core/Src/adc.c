#include "adc.h"


void ADC_Init(void) {
    RCC->AHB1ENR |= (1 << 0) | (1 << 2) | (1 << 5);   // GPIOA, GPIOC, GPIOF 클럭 활성화
    RCC->APB2ENR |= (1 << 9) | (1 << 8);   // ADC1, ADC2 클럭 활성화

    GPIOA->MODER &= ~(3 << 3*2);
    GPIOC->MODER &= ~(3 << 0*2);
    GPIOC->MODER &= ~(3 << 3*2);
    GPIOA->MODER |= (3 << 3*2);            // PA3 (채널 3) Analog 모드
    GPIOC->MODER |= (3 << 0*2);            // PC0 (채널 10) Analog 모드
    GPIOC->MODER |= (3 << 3*2);            // PC3 (채널 13) Analog 모드

    ADC_COMMON->CCR &= ~(3 << 16);
    ADC_COMMON->CCR |= (1 << 16);		   // ADCPRE 4분주

    ADC1->CR1 |= (1 << 8);                 // SCAN: 스캔 모드 켬 (여러 채널 순차 변환)
    ADC1->CR1 |= (1 << 7);                 // JEOCIE: Injected 변환 완료 인터럽트 켬

    ADC1->SMPR2 |= (4 << 9);               // CH3 (PA3) 샘플링 타임 (비트 11:9)
    ADC1->SMPR1 |= (4 << 0);               // CH10 (PC0) 샘플링 타임 (비트 2:0)
    ADC1->SMPR1 |= (4 << 9);			   // CH13

    ADC1->JSQR |= (2 << 20);               // JL[1:0] = 10 (총 3개 채널 변환)

    ADC1->JSQR |= (3 << 1*5);               // JSQ2: 첫 번째 변환 채널 = CH3  PA3
    ADC1->JSQR |= (10 << 2*5);              // JSQ3: 두 번째 변환 채널 = CH10 PC0
    ADC1->JSQR |= (13 << 3*5);              // JSQ4: 세 번째 변환 채널 = CH13 PC3

    ADC1->CR2 &= ~(0xF << 16);             // JEXTSEL 초기화 (0000 = TIM1 TRGO)
    ADC1->CR2 |= (1 << 20);                // JEXTEN: 01 (Rising Edge 하드웨어 트리거 켬)

    ADC1->CR2 |= (1 << 0);                 // ADON: ADC1 모듈 활성화
}

void ADC3_Init(void) {
    RCC->AHB1ENR |= (1 << 5);
    RCC->APB2ENR |= (1 << 10);

    GPIOF->MODER &= ~(3 << 6);
    GPIOF->MODER |= (3 << 6);

    ADC_COMMON->CCR &= ~(3 << 16);
    ADC_COMMON->CCR |= (1 << 16);

    // ADC3->CR1 |= (1 << 7);

    ADC3->SMPR2 |= (7 << 27);

    ADC3->JSQR &= ~(3 << 20);
    ADC3->JSQR &= ~(0x1F << 15);
    ADC3->JSQR |= (9 << 15);

    ADC3->CR2 &= ~(0xF << 16); // JEXTSEL 초기화
    ADC3->CR2 &= ~(3 << 20);   // JEXTEN 초기화

    ADC3->CR2 |= (1 << 0);
}

//float Get_Angle_Rad(void) {
//    ADC3->CR2 |= (1 << 22);
//    while (!(ADC3->SR & (1 << 2)));
//    return ADC3->JDR1 * 2.0f * 3.141592f / 4095.0f;
//}




