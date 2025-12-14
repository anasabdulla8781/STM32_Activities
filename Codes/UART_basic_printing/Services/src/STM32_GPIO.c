/*
 * STM32_GPIO.c
 *
 *  Created on: Oct 20, 2025
 *      Author: ANAS
 */

#include <STM32_GPIO.h>



void pin_init(uint8_t pin , uint8_t mode , uint8_t port)
{
	rcc_ptr->AHB1ENR |= SET_GPTIO_CLOCK_ENABLE;					/// enabled the clock for GPIOs
	if( port == PORTD )
	{
		switch(mode)
		{
			case PIN_OUTPUT:
				gpiod_ptr->MODER &= ~(0X03<<(pin*2));		/// clearing the mode bits for the LED
				gpiod_ptr->MODER |= (0x01 << (pin*2));		/// setting the mode bits as output for the LED
				break;
			case PIN_ANALOG_INPUT:
				gpiod_ptr->MODER &= ~(0X03<<(pin*2));		/// clearing the mode bits for the input
				gpiod_ptr->MODER |= (0x03 << (pin*2));		/// setting the mode bits to analog input mode
				break;
			case PIN_ALTERNATE_FUNCTION:
				gpiod_ptr->MODER &= ~(0X03<<(pin*2));		/// clearing the mode bits for the LED
				gpiod_ptr->MODER |= (0x02 << (pin*2));		/// setting the mode bits as alternate function mode for the LED
				break;

			default:
				break;
		}
	}
	else if( port == PORTA )
	{
		switch(mode)
		{
			case PIN_OUTPUT:
				gpioa_ptr->MODER &= ~(0X03<<(pin*2));		/// clearing the mode bits for the LED
				gpioa_ptr->MODER |= (0x01 << (pin*2));		/// setting the mode bits as output for the LED
				break;
			case PIN_ANALOG_INPUT:
				gpioa_ptr->MODER &= ~(0X03<<(pin*2));		/// clearing the mode bits for the input
				gpioa_ptr->MODER |= (0x03 << (pin*2));		/// setting the mode bits to analog input mode
				break;
			case PIN_ALTERNATE_FUNCTION:
				gpioa_ptr->MODER &= ~(0X03<<(pin*2));		/// clearing the mode bits for the LED
				gpioa_ptr->MODER |= (0x02 << (pin*2));		/// setting the mode bits as alternate function mode for the LED
				break;

			default:
				break;
		}
	}
}


void pin_operations (uint8_t pin , uint8_t state)
{
	if(state == TOGGLE)
	{
		gpiod_ptr->ODR ^= (1<<pin);					/// toggling the LED
	}
	else if (state == ON)
	{
		gpiod_ptr->ODR |= (1<<pin);				/// Turn on the LED
	}
	else
	{
		gpiod_ptr->ODR &= ~(1<<pin);				/// Turn off the LED
	}
}

void set_alternate_function_portD ( uint8_t pin_number )
{
	if (pin_number > 7 && pin_number <16)
	{
		gpiod_ptr->AFRH &= ~ ( 0x0F <<((pin_number - 8)*4));				/// Clearing the alternate functions bits
		gpiod_ptr->AFRH |=   ( AF2 <<((pin_number - 8)*4));
	}
	else if (pin_number >= 0  && pin_number <8)
	{
		gpiod_ptr->AFRL &= ~ ( 0x0F <<(pin_number*4));						/// Clearing the alternate functions bits
		gpiod_ptr->AFRL |=   ( AF2  <<(pin_number*4));
	}
}

