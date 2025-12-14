/*
 * STM32_rcc_ptr.c
 *
 *  Created on: Oct 20, 2025
 *      Author: ANAS
 */


#include <STM32_RCC.h>
#include <STM32_ADC.h>

void LSI_clock_enable (void)
{
	rcc_ptr->CSR |= 1<<0;					/// Set the LSI clock
	while (!(rcc_ptr->CSR & (1<<1)));
}


// Function to enable the clock for UART 2 module . We need to enable the clock of USART2 module and GPIOA module
void usart2_clock_enable(void)
{
	rcc_ptr->APB1ENR |= 1<<17;				/// Set the USART2 clock enable bit
	rcc_ptr->AHB1ENR |= 1<<0;				/// Set the GPIOA clock enable bit
}

void adc_clock_enable(ADC_structure* adc_ptr)
{

	if (adc_ptr == adc1_ptr)
	{
		rcc_ptr->APB2ENR |= (1 << 8);   							/// Enabled ADC1 clock
	}
	else if (adc_ptr == adc2_ptr)
	{
		rcc_ptr->APB2ENR |= (1 << 9);   							/// Enabled ADC2 clock
	}
	else if (adc_ptr == adc3_ptr)
	{
		rcc_ptr->APB2ENR |= (1 << 10);  							/// Enabled ADC3 clock
	}
	else
	{
		;
	}
}

void reset_reason_check(volatile uint8_t *reset_reason_ptr)
{
    uint32_t csr = rcc_ptr->CSR;  								/// Read the reset reason only once

    if (csr & (1 << 29))
        *reset_reason_ptr = INDEPENDENT_WATCHDOG_RESET;

    else if (csr & (1 << 30))
        *reset_reason_ptr = WINDOW_WATCHDOG_RESET;

    else if (csr & (1 << 26))
        *reset_reason_ptr = RESET_BUTTON_RESET;   					// NRST pin

    else if (csr & (1 << 27))
        *reset_reason_ptr = POWER_ON_RESET;       					// normal

    else if (csr & (1 << 25))
        *reset_reason_ptr = BROWN_OUT_RESET;      					// unstable power

    else if (csr & (1 << 28))
        *reset_reason_ptr = SOFTWARE_RESET;       					// NVIC_SystemReset

    else
        *reset_reason_ptr = UNKNOWN_RESET;

    rcc_ptr->CSR |= (1 << 23);									// Clear all reset flags
}

