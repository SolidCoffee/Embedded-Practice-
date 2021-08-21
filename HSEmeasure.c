

#include <stdint.h>
#include<stdio.h>

#define RCC_CRFG_REG 0x40023808
#define RCC_CR 0x40023800
#define AHB1_ENR 0x40023830
#define GPIOA_BASE 0x40020000


int main(void)
{
	uint32_t *pRccCr = (uint32_t*)0x40023800;
	uint32_t *pRccCrgfReg = (uint32_t*)RCC_CRFG_REG;
	uint32_t *pRCCAhb1Reg = (uint32_t*)AHB1_ENR;
	uint32_t *pGpioAMode = (uint32_t*)GPIOA_BASE;
	uint32_t *pPortAAFHR = (uint32_t*)(GPIOA_BASE + 0x24);

	//enable HSE
	*pRccCr |= (1 << 16);

	//wait until it is ready
	while(!(*pRccCr & (1 << 17)));

	//switch the system clock to HSE
	*pRccCrgfReg |= (1 << 0);

	//do MC01 settings to measrue it

	//Select hse as clock mode
	*pRccCrgfReg &= ~(3 << 21);
	*pRccCrgfReg |= (1 << 22);

	//prescaller divisor as 4
	*pRccCrgfReg &= ~(7 << 24);
	*pRccCrgfReg |= (3 << 25);

	//setting gpio A port
	*pRCCAhb1Reg |= (1 << 0);

	//set GPIO A to alternate function mode
	*pGpioAMode &= ~(3 << 16);
	*pGpioAMode |= (2 << 16);

	//configure the alternation function register
	*pPortAAFHR &= ~(0xf << 0);

	for(;;);
}
