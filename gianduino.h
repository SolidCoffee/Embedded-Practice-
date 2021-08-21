/*
 * gianduino.h
 *
 *  Created on: Jul 21, 2021
 *      Author: mmazzi
 */

#ifndef GIANDUINO_H_
#define GIANDUINO_H_

#define high 1
#define low 0

#define output 1
#define input 0
#define analog 3
#define alternate 2

#define LED_GREEN  12
#define LED_ORANGE 13
#define LED_RED    14
#define LED_BLUE   15

//void init_led_all(void);

void pinmode_A(uint32_t pin_num, uint32_t pin_mode);
void pinmode_B(uint32_t pin_num, uint32_t pin_mode);
void pinmode_C(uint32_t pin_num, uint32_t pin_mode);
void pinmode_D(uint32_t pin_num, uint32_t pin_mode);

void  digitalwrite_A(uint32_t pin_num, uint32_t high_low);
void  digitalwrite_B(uint32_t pin_num, uint32_t high_low);
void  digitalwrite_C(uint32_t pin_num, uint32_t high_low);
void  digitalwrite_D(uint32_t pin_num, uint32_t high_low);

#endif /* GIANDUINO_H_ */
