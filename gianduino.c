/*
 * gianduino.c
 *
 *  Created on: Jul 21, 2021
 *      Author: mmazzi
 */

#ifndef GIANDUINO_C_
#define GIANDUINO_C_

#include<stdint.h>
#include<stdio.h>
/*void init_led_all(void)
{
uint32_t *pModeAReg = (uint32_t*) 0x40020000;
uint32_t *pModeBReg = (uint32_t*) 0x40020400;
uint32_t *pModeCReg = (uint32_t*) 0x40020800;
uint32_t *pModeDReg = (uint32_t*) 0x40020C00;
uint32_t *pOutputAReg = (uint32_t*) 0x40020014;
uint32_t *pOutputBReg = (uint32_t*) 0x40020414;
uint32_t *pOutputCReg = (uint32_t*) 0x40020814;
uint32_t *pOutputDReg = (uint32_t*) 0x40020C14;
}*/


void pinmode_A(uint32_t pin_num, uint32_t pin_mode)
{
	uint32_t *pRccClbus = (uint32_t*) 0x40023830;
	*pRccClbus |= (1 << 0);
	uint32_t *pModeAReg = (uint32_t*) 0x40020000;
	*pModeAReg &= ~(3 << (2*pin_num));

	*pModeAReg |= (pin_mode << (2*pin_num));

	/*if(pin_mode == 1){
		*pModeAReg |= ( << (2*pin_num));
	}else if(pin_mode == 3){
		*pModeAReg |= (1 << (2*pin_num));
	}else if(pin_mode ==2)*/
}

void pinmode_B(uint32_t pin_num, uint32_t pin_mode)
{
	uint32_t *pRccClbus = (uint32_t*) 0x40023830;
	*pRccClbus |= (1 << 1);
	uint32_t *pModeBReg = (uint32_t*) 0x40020400;
	*pModeBReg &= ~(3 << (2*pin_num));

	*pModeBReg |= (pin_mode << (2*pin_num));
}

void pinmode_C(uint32_t pin_num, uint32_t pin_mode)
{
	uint32_t *pRccClbus = (uint32_t*) 0x40023830;
	*pRccClbus |= (1 << 2);
	uint32_t *pModeCReg = (uint32_t*) 0x40020800;
	*pModeCReg &= ~(3 << (2*pin_num));

	*pModeCReg |= (pin_mode << (2*pin_num));
}

void pinmode_D(uint32_t pin_num, uint32_t pin_mode)
{
	uint32_t *pRccClbus = (uint32_t*) 0x40023830;
	*pRccClbus |= (1 << 3);
	uint32_t *pModeDReg = (uint32_t*) 0x40020C00;
	*pModeDReg &= ~(3 << (2*pin_num));

	*pModeDReg |= (pin_mode << (2*pin_num));
}



void  digitalwrite_A(uint32_t pin_num, uint32_t high_low)
{

	uint32_t *pOutputAReg = (uint32_t*) 0x40020014;

	if(high_low){
		*pOutputAReg |=  (1 << pin_num);
	}else if(high_low == 0){
		*pOutputAReg &= ~(1 << pin_num);
	}else{
		printf("error, state  not recognized");
	}

}


void  digitalwrite_B(uint32_t pin_num, uint32_t high_low)
{
	uint32_t *pOutputBReg = (uint32_t*) 0x40020414;

	if(high_low){
		*pOutputBReg |=  (1 << pin_num);
	}else if(high_low == 0){
		*pOutputBReg &= ~(1 << pin_num);
	}else{
		printf("error, state  not recognized");
	}

}

void  digitalwrite_C(uint32_t pin_num, uint32_t high_low)
{
	uint32_t *pOutputCReg = (uint32_t*) 0x40020814;

	if(high_low){
		*pOutputCReg |=  (1 << pin_num);
	}else if(high_low == 0){
		*pOutputCReg &= ~(1 << pin_num);
	}else{
		printf("error, state  not recognized");
	}

}

void  digitalwrite_D(uint32_t pin_num, uint32_t high_low)
{
	uint32_t *pOutputDReg = (uint32_t*) 0x40020C14;

	if(high_low){
		*pOutputDReg |=  (1 << pin_num);
	}else if(high_low == 0){
		*pOutputDReg &= ~(1 << pin_num);
	}else{
		printf("error, state  not recognized");
	}

}


#endif /* GIANDUINO_C_ */
