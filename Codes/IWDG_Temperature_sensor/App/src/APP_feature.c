/*
 * APP_feature.c
 *
 *  Created on: Nov 16, 2025
 *      Author: ANAS
 */


#include <APP_feature.h>
#include <service.h>


volatile uint8_t upcounter = 1;

void fade_led_program(void)
{
    if (upcounter == 1)    // increasing brightness
    {
        gpt4_ptr->TIMx_CCR1++;
        gpt4_ptr->TIMx_CCR2++;
        gpt4_ptr->TIMx_CCR3++;
        gpt4_ptr->TIMx_CCR4++;

        if (gpt4_ptr->TIMx_CCR1 >= gpt4_ptr->TIMx_ARR)
        {
            upcounter = 0; // switch direction at MAX
        }
    }
    else                   // decreasing brightness
    {
        gpt4_ptr->TIMx_CCR1--;
        gpt4_ptr->TIMx_CCR2--;
        gpt4_ptr->TIMx_CCR3--;
        gpt4_ptr->TIMx_CCR4--;

        if (gpt4_ptr->TIMx_CCR1 == 0)
        {
            upcounter = 1; // switch direction at MIN
        }
    }
}

void watchdog_blocking_program (void)
{
	uint8_t button_flag = 0;
	if (pin_state_check(PIN_0,gpioa_ptr))
	{
		button_flag = 1;
	}

	while (button_flag)
	{
		pin_operations(PIN_12 , ON);
		for (uint32_t i = 0; i<100; i++);
		pin_operations(PIN_12 , OFF);
		for (uint32_t i = 0; i<100; i++);
	}
}
