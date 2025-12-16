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

/// ********************** System Timer - Global variables ********************* ///
volatile uint32_t system_timer_1ms = 0;
volatile uint32_t	counter_for_system_timer = 0;
volatile uint32_t system_timer_1s = 0;



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
		pin_operations(GREEN_LED_PIN, TOGGLE);

		four_s_delay++;
		eight_s_delay++;
		twelve_s_delay++;

		if(four_s_delay == 4)
		{
			pin_operations(BLUE_LED_PIN, ON);
			four_s_delay = 0 ;
		}

		if(eight_s_delay == 8)
		{
			pin_operations(RED_LED_PIN, TOGGLE);
			eight_s_delay = 0 ;
		}

		if(twelve_s_delay == 12)
		{
			pin_operations(ORANGE_LED_PIN, TOGGLE);
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

void SysTick_Handler(void)
{
	system_timer_1ms++;
	counter_for_system_timer++;
	if(counter_for_system_timer == 1000)
	{
		counter_for_system_timer = 0;
		system_timer_1s++;
	}
}
