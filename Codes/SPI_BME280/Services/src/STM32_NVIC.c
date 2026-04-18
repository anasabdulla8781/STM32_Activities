/*
 * STM32_NVIC.c
 *
 *  Created on: Nov 10, 2025
 *      Author: ANAS
 */


#include <STM32_NVIC.h>
#include <STM32_GPT.h>
#include <STM32_GPIO.h>
#include <APP_feature.h>


uint8_t four_s_delay;
uint8_t eight_s_delay;
uint8_t twelve_s_delay;


void nvic_init(uint8_t interrupt_number)
{
	switch(interrupt_number)
	{
		case 28:
			nvic_ptr->ISER[0] |= ENABLE_TIMER2_INTERRUPT;
			break;

		case 30:
			nvic_ptr->ISER[0] |= ENABLE_TIMER4_INTERRUPT;
			break;

		default:
			break;

	}
}

void TIM2_IRQHandler(void)
{
	if (gpt2_ptr->TIMx_SR & 1U) 			/// Last bit in the SR is 1 indicating there is an interrupt happened
	{
		gpt2_ptr->TIMx_SR &= ~(1U << 0);
		gpio_output_operations(gpiod_ptr,GREEN_LED_PIN,SET_TOGGLE);

		four_s_delay++;
		eight_s_delay++;
		twelve_s_delay++;

		if(four_s_delay == 4)
		{
			gpio_output_operations(gpiod_ptr,BLUE_LED_PIN,SET_HIGH);
			four_s_delay = 0 ;
		}

		if(eight_s_delay == 8)
		{
			gpio_output_operations(gpiod_ptr,RED_LED_PIN,SET_TOGGLE);
			eight_s_delay = 0 ;
		}

		if(twelve_s_delay == 12)
		{
			gpio_output_operations(gpiod_ptr,ORANGE_LED_PIN,SET_TOGGLE);
			twelve_s_delay = 0 ;
		}
	}
}

void TIM4_IRQHandler(void)
{
	if(gpt4_ptr->TIMx_SR &1u)
	{
		gpt4_ptr->TIMx_SR &= ~(1U << 0);

		fade_led_program();
	}
}
