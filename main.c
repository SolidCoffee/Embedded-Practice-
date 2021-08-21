/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */

#include <stdint.h>
#include<stdio.h>

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

#define RCC_CRFG_REG 0x40023808
#define AHB1_ENR 0x40023830
#define GPIOA_BASE 0x40020000

int main(void)
{
	uint32_t *pRccCrgfReg = (uint32_t*)RCC_CRFG_REG;
	uint32_t *pRCCAhb1Reg = (uint32_t*)AHB1_ENR;
	uint32_t *pGpioAMode = (uint32_t*)GPIOA_BASE;
	uint32_t *pPortAAFHR = (uint32_t*)(GPIOA_BASE + 0x24);

	//Select hsi as clock mode
	*pRccCrgfReg &= ~(3 << 21);
	*pRccCrgfReg &= ~(7 << 24);

	//prescaller
	*pRccCrgfReg |= (3 << 25);

	//setting gpio A port
	*pRCCAhb1Reg |= (1 << 0);

	//set GPIO A to alternate funciton mode
	*pGpioAMode &= ~(3 << 16);
	*pGpioAMode |= (2 << 16);

	//configure the alternation function register
	*pPortAAFHR &= ~(0xf << 0);

	for(;;);
}
