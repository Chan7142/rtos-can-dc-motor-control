# STM32 Register-Level BLDC Motor Control

STM32 mcu를 사용한 BLDC FOC 위치제어 프로젝트 (전류제어루프X)


핵심 하드웨어 소개
<img width="1534" height="862" alt="하드웨어소개" src="https://github.com/user-attachments/assets/5cb7446f-2e83-46a2-b344-c0d9b262e71d" />

사용 툴 소프트웨어
matlab(simulink), python, vscode, stm32cudeide, stm32cubemx

MCU 펌웨어 : HAL 라이브러리 없이 직접 레지스터 조작하여 드라이버 함수 제작
(PWM, I2C, SPI, USART, TIM, ADC)

모터 전달 함수: Vq축 전압에 4.0V 스텝응답에 대한 전달함수 (파이썬 사용)
<img width="1181" height="728" alt="image" src="https://github.com/user-attachments/assets/c386da2c-c97b-40e0-be31-e1b6b149b87a" />
 추출된 전달함수 G(s)   = 24.6293 / (0.0120s + 1)

 적용된 제어 알고리즘
 1. P-PI cascade 위치제어
 2. 전차원 관측기(위치,속도,외란 추정)

전체 제어 모델링 (simulink)
<img width="916" height="429" alt="매틀랩제어선도" src="https://github.com/user-attachments/assets/9ffce95f-090e-4705-8f88-f94ae417c425" />
<img width="1028" height="792" alt="제어선도" src="https://github.com/user-attachments/assets/ea85f120-d808-4713-b6f6-1b701e588247" />

전차원 관측기 식

<img width="890" height="502" alt="Screenshot_20260705_180312_Google" src="https://github.com/user-attachments/assets/8e093b09-90ee-4f5f-b7fa-d25944b5b746" />




SIMULINK 자동 C코드 생성 기능 사용 -> MCU 제어알고리즘 적용 (이산화 적용 및 변수 연결) (Subsystem.c Subsystem.h 파일 각각 생성 후 적용)

CAN 통신 지령: 파이썬 코드에서 2초마다 0.0, 45.5, 90.0, -180.0 디그리 반복 지령
<img width="432" height="53" alt="image" src="https://github.com/user-attachments/assets/b500c179-a1bf-42eb-b0f7-3f6de456c070" />


실험결과
<img width="1487" height="777" alt="image" src="https://github.com/user-attachments/assets/c0d7ff12-0e51-4fcc-b241-cba283579d70" />
우수한 제어성능 확인
(구동영상 참조)
