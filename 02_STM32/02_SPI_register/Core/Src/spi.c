#include "spi.h"

void spi_init(){
	SPI_CR1 |= SPI_CR1_BIDIMODE;
}
