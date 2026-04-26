#include "fonts.h"
#include "main.h"
#include "string.h"
#include "gpwm.h"
void SystemClock_Config_Max(void);
uint32_t current_cnt = 0;
uint32_t gCount = 0;
int main(void)
{
	SystemClock_Config_Max();
	SystemCoreClock = 216000000;
	SPI_GPIO_Init();
	DMA_Init();
	uint8_t test_data[4] = {0xAA, 0xBB, 0xCC, 0xDD};
	DMA2_config_SPI1_TX((uint32_t)test_data, 4);

	ST7735_Init();              // 1. 초기화 (이전 단계에서 만든 함수)
	ST7735_FillScreen(0x0000);  // 2. 검정색으로 배경 채우기
	ST7735_WriteString(10, 50, "Hello World", Font_7x10, 0xFFFF, 0x0000);
	PWM_TIM5_CH1_Init(1000);
	PWM_TIM5_CH1_Setduty(80); //80% pwm duty
  while (1)
  {

  }

}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure LSE Drive Capability
  */
  HAL_PWR_EnableBkUpAccess();

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE3);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_BYPASS;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 4;
  RCC_OscInitStruct.PLL.PLLN = 96;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  RCC_OscInitStruct.PLL.PLLR = 2;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Activate the Over-Drive mode
  */
  if (HAL_PWREx_EnableOverDrive() != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_3) != HAL_OK)
  {
    Error_Handler();
  }
}
void SystemClock_Config_Max(void) {
    /* 1. 레지스터 주소 정의 (STM32F767ZI 기준) */
    volatile uint32_t *const RCC_CR      = (uint32_t *)0x40023800UL;
    volatile uint32_t *const RCC_PLLCFGR = (uint32_t *)0x40023804UL;
    volatile uint32_t *const RCC_CFGR    = (uint32_t *)0x40023808UL;
    volatile uint32_t *const RCC_APB1ENR = (uint32_t *)0x40023840UL;
    volatile uint32_t *const PWR_CR1     = (uint32_t *)0x40007000UL;
    volatile uint32_t *const PWR_CSR1    = (uint32_t *)0x40007004UL;
    volatile uint32_t *const FLASH_ACR   = (uint32_t *)0x40023C00UL;

    /* 2. HSE (External Crystal) 활성화 */
    *RCC_CR |= (1 << 16); // HSEON
    while (!(*RCC_CR & (1 << 17))); // HSERDY 대기

    /* 3. 전원 인터페이스 클럭 활성화 및 VOS 설정 */
    *RCC_APB1ENR |= (1 << 28); // PWREN
    (void)*RCC_APB1ENR; // 클럭 안정화를 위한 더미 읽기

    // VOS Scale 1 설정 (비트 14:15를 11로)
    *PWR_CR1 |= (3 << 14);

    // VOSRDY 대기 (멈춤 방지를 위한 타이아웃 처리)
    uint32_t timeout = 0xFFFF;
    while (!(*PWR_CSR1 & (1 << 14)) && timeout--);

    /* 4. Over-drive 모드 활성화 (216MHz 필수 시퀀스) */
    *PWR_CR1 |= (1 << 16); // ODEN (Over-drive Enable)
    while (!(*PWR_CSR1 & (1 << 16))); // ODRDY 대기

    *PWR_CR1 |= (1 << 17); // ODSWEN (Over-drive Switching Enable)
    while (!(*PWR_CSR1 & (1 << 17))); // ODSWRDY 대기

    /* 5. Flash ACR 설정 (216MHz에서는 반드시 7 Wait States 필요) */
    // ART Accelerator 활성화 (ICEN, DCEN, PRFTEN) + Latency 7WS
    *FLASH_ACR = (1 << 9) | (1 << 10) | (1 << 8) | (7 << 0);

    /* 6. PLL 설정 (HSE 8MHz 기준)
     * 목표: SYSCLK = 216MHz
     * PLL_M = 4   => 8MHz / 4 = 2MHz (PLL 입력은 1~2MHz 권장)
     * PLL_N = 216 => 2MHz * 216 = 432MHz (VCO 출력)
     * PLL_P = 2   => 432MHz / 2 = 216MHz (최종 SYSCLK)
     * SRC = HSE (1 << 22)
     */
    *RCC_PLLCFGR = (4 << 0) | (216 << 6) | (0 << 16) | (1 << 22);

    /* 7. PLL 활성화 */
    *RCC_CR |= (1 << 24); // PLLON
    while (!(*RCC_CR & (1 << 25))); // PLLRDY 대기

    /* 8. 버스 분주비(Prescaler) 설정
     * AHB  = SYSCLK / 1 = 216MHz (HPRE = 0xxx)
     * APB1 = SYSCLK / 4 = 54MHz  (PPRE1 = 101, Max 54MHz)
     * APB2 = SYSCLK / 2 = 108MHz (PPRE2 = 100, Max 108MHz)
     */
    *RCC_CFGR = (0 << 4) | (5 << 10) | (4 << 13);

    /* 9. 시스템 클럭 전환 (SYSCLK Source = PLL) */
    *RCC_CFGR |= (2 << 0); // SW = PLL
    while ((*RCC_CFGR & (0x0C)) != (0x08)); // SWS가 PLL(10)인지 확인
}
