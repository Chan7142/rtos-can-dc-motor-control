#ifndef __SPI_H
#define __SPI_H
#include "stm32f4xx_it.h"
#include "stm32f4xx.h"

/* 2. uint32_t 등 표준 타입을 위해 포함 */
#include <stdint.h>

#define  SPI1_BASE	0x40013000UL



//offset
#define  SPI_CR1_OFFSET 0x00UL
#define SPI_CR2_OFFSET 0x04UL
#define SPI_SR_OFFSET 0x08UL
#define SPI_DR_OFFSET 0x0cUL
#define SPI_CRCPR_OFFSET 0x10UL
#define SPI_RXCRCR_OFFSET 0x14UL
#define SPI_TXCRCR_OFFSET 0x18UL
#define SPI_I2SCFGR_OFFSET 0x1CUL
#define SPI_I2SPR_OFFSET 0x20UL

//레지스터 주소 정의 (포인터로 캐스팅)

#define  SPI_CR1 (*((volatile uint32_t *)(SPI1_BASE + SPI_CR1_OFFSET)))
#define SPI_CR2	(*((volatile uint32_t *)(SPI1_BASE + SPI_CR2_OFFSET)))
#define SPI_SR	(*((volatile uint32_t *)(SPI1_BASE + SPI_SR_OFFSET)))
#define SPI_DR	(*((volatile uint32_t *)(SPI1_BASE + SPI_DR_OFFSET)))
#define SPI_CRCPR	(*((volatile uint32_t *)(SPI1_BASE + SPI_CRCPR_OFFSET)))
#define SPI_RXCRCR	(*((volatile uint32_t *)(SPI1_BASE + SPI_RXCRCR_OFFSET)))
#define SPI_TXCRCR	(*((volatile uint32_t *)(SPI1_BASE + SPI_TXCRCR_OFFSET)))
#define SPI_I2SCFGR	(*((volatile uint32_t *)(SPI1_BASE + SPI_I2SCFGR_OFFSET)))
#define SPI_I2SPR		(*((volatile uint32_t *)(SPI1_BASE + SPI_I2SPR_OFFSET)))
