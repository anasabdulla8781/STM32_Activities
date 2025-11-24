/*
 * STM32_RCC.c
 *
 *  Created on: Oct 20, 2025
 *      Author: ANAS
 */


#include <STM32_RCC.h>


void rcc_init (void)
{
	rcc_ptr->AHB1ENR |= SET_GPTIO_CLOCK_ENABLE;					/// enabled the clock for GPIOs
//	rcc_ptr->APB1ENR |= SET_TIM2_CLOCK_ENABLE;					/// enabled the clock of TIMER2
//	rcc_ptr->APB1ENR |= SET_TIM4_CLOCK_ENABLE;					/// Enabled the clock of TIMER4
	rcc_ptr->APB2ENR |= (1 << 8);   							/// Enabled ADC1 clock
	rcc_ptr->APB2ENR |= (1 << 9);   							/// Enabled ADC2 clock
	rcc_ptr->APB2ENR |= (1 << 10);  							/// Enabled ADC3 clock

}

