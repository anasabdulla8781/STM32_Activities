/*
 * STM32_UART.c
 *
 *  Created on: Dec 7, 2025
 *      Author: ANAS
 */


#include "STM32_UART.h"

void uart2_init(void)
{
	// Step 1 - Enable the clocks
	usart2_clock_enable();
	// Step 2.1 - Set the GPIO Pins in alternalte fucntions mode for UART
	pin_init(2,PIN_ALTERNATE_FUNCTION,PORTA);
	pin_init(3,PIN_ALTERNATE_FUNCTION,PORTA);
	// Step 2.2 - Set the alternate function corresponding to UART for PA2 and PA3
	gpioa_ptr->AFRL	&= ~( 0x0F << 8  );	 /// Clearing the bits
	gpioa_ptr->AFRL |= ( 7 << 8 );		/// Setting into AF7 mode
	gpioa_ptr->AFRL &= ~( 0x0F << 12  );	 /// Clearing the bits
	gpioa_ptr->AFRL |= ( 7 << 12 );		/// Setting into AF7 mode
	// Step 3 - Set the baud rate
	uart2_set_baud_rate(9600,0);
	// Step 4 - Enable UART
	uart2_enable();
}

void uart2_set_baud_rate(uint32_t baud_rate , uint8_t oversampling)
{
	uint32_t internal_clock = 16000000;															// 16Mhz clock
	float usartdiv = (float)internal_clock / ((float)baud_rate * (8 * (2 - oversampling)));			// Finding the usartdiv using the equation
	uint32_t mantassa = (uint32_t)usartdiv;
	uint32_t fraction;
	if (oversampling == 1)		/// for oversampling of 8
	{
		fraction = (uint32_t)(( (float)(usartdiv - mantassa) * 8) + 0.5);
		fraction &= 0x07;      // keep only 3 bits
	}
	else if (oversampling == 0)/// for oversampling of 16
	{
		fraction = (uint32_t)(( (float)(usartdiv - mantassa) * 16) + 0.5);
		fraction &= 0x0F;      // keep only 4 bits
	}
	usart2_ptr->BRR = 0x0000;
	usart2_ptr->BRR |= (mantassa << 4);
	usart2_ptr->BRR |= fraction;
	usart2_ptr->CR1 &= ~(1 << 15);
	usart2_ptr->CR1 |= (oversampling << 15);

}

void uart2_enable(void)
{
	usart2_ptr->CR1 |=  1<<13;				/// Setting the uart enable bit
	usart2_ptr->CR1 |=  1<<3;				/// Setting the uart TX
	usart2_ptr->CR1 |=  1<<2;				/// Setting the uart RX
}

// Step 5 - Function for writing the data
void uart2_write_char(uint8_t charecter)
{
	while (!(usart2_ptr->SR & (1<<7)));
	usart2_ptr->DR = charecter;
}
