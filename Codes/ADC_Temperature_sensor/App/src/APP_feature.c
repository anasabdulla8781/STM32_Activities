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
