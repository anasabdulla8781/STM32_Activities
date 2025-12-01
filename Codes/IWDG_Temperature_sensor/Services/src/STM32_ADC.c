/*
 * STM32_ADC.c
 *
 *  Created on: Nov 20, 2025
 *      Author: uie83604
 */


/// Version 1.1

#include <STM32_ADC.h>
#include "STM32_GPIO.h"
#include "STM32_RCC.h"



void adc_init_module(ADC_structure * adc_ptr , uint8_t channel, uint8_t mode , uint8_t conversion_behaviour , uint8_t converion_order)
{
    uint8_t shift = (converion_order-1)*5;
	/// Step 1 - perform the clock enable for the ADC
	adc_clock_enable(adc_ptr);
	/// Step 2 - Perfrom the pin init for the external channel ( Not needed for the internal channel )
	if (mode == EXTERNAL_CHANNEL)
	{
		/// Implement the pin init here
	}
	else
	{
		if (mode == INTERNAL_CHANNEL_TEMPERATURE_SENSOR)				/// Step 3 - Perform the internal sensor init / measurement init
		{
			adc_common_ptr->CCR |= (0X01 << 23);						/// Enabling the temperature sensing
			for (volatile int i = 0; i < 3000; i++);   					// ~15–20 µs delay
		}
		else if (mode == INTERNAL_CHANNEL_VBAT)
		{
			adc_common_ptr->CCR |= (0X01 << 22);						/// Enabling the adc from VBAT
			for (volatile int i = 0; i < 3000; i++);   					// ~15–20 µs delay
		}
		else
		{
				;
		}
	}

	/// Step 4 - Set the sample time

	if (channel >= 0 && channel < 10)
	{
		adc_ptr->SMPR2 &= ~(0x07 << ( channel *3)) ;
		adc_ptr->SMPR2 |= (0x07 << ( channel *3)) ;						/// Clearing and setting the Sample time to 480 cycle
	}
	else if (channel >9 && channel <= 18)
	{
		adc_ptr->SMPR1 &= ~(0x07 << (( channel - 10 )*3)) ;
		adc_ptr->SMPR1 |= (0x07 << ((channel - 10 )*3)) ;				/// Clearing and settting the sample time to 480 cycle
	}

	/// Step 5 - Enable the ADC Module

	adc_ptr->CR2 |= 1<<0;												/// Turn on the ADC
	for (volatile int i=0; i<100; i++);									/// Added a small delay

	/// Step 6 - Setting up the conversion mode . single or continours

	adc_ptr->CR2 |= 1<<1;												/// Set in the continous mode

	/// Step 7 - Setting the EOC as convertion after every convertion

	if (conversion_behaviour == ALL_CYCLE_CONVERSION)
	{
		adc_ptr->CR2 |= (1 << 10);  										// EOCS = 1 → EOC flag set after each conversion
	}
	else if (conversion_behaviour == SEQUENCE_CONVERSION)
	{
		adc_ptr->CR2 &= ~(1 << 10);  										// EOCS = 0 → EOC flag set after the full conversion only
	}

	/// Step 8 - Setting the sequence and length in the SQR register
    if (converion_order >=1 && converion_order <= 6)
    {
        adc_ptr->SQR3 &= ~(0x1F << shift);
        adc_ptr->SQR3 |= (channel << shift);
    }
    else if (converion_order >=7 && converion_order <= 12)
    {
        shift = (converion_order-7)*5;
        adc_ptr->SQR2 &= ~(0x1F << shift);
        adc_ptr->SQR2 |= (channel << shift);
    }
    else if (converion_order >=13 && converion_order <=16)
    {
        shift = (converion_order-13)*5;
        adc_ptr->SQR1 &= ~(0x1F << shift);
        adc_ptr->SQR1 |= (channel << shift);
    }

    // Update sequence length
    adc_ptr->SQR1 &= ~(0xF << 20);
    adc_ptr->SQR1 |= ((converion_order-1) << 20);
}

/// Step 9 - Start the conversion
void adc_start_conversion(ADC_structure* adc_ptr)
{
	adc_ptr->CR2 |= (1 << 30); 											// SWSTART
	for (volatile int i=0; i<100; i++);									/// Added a small delay
}

/// Step 10 - Reading the ADC Values based on Polling method
void adc_get_value(ADC_structure * adc_ptr , volatile uint16_t* adc_measured_value)
{
	while (!(adc_ptr->SR & (0x01<<1)));											/// holding till the converions is getting completed
	*adc_measured_value = adc_ptr->DR;											/// storing the converted value into the variable
}
/// Step 11 - Perform the converions from the ADC value
void adc_convert_value(volatile uint16_t adc_measured_value, float* converted_value ,uint8_t mode)
{
	float v_sense = 0.0;
	v_sense = (adc_measured_value / ADC_MAX_VALUE) * MAX_VOLTAGE;				/// Curresponding voltage value from the sensor

	if ( mode == INNER_TEMPERATURE_SENSOR )
	{
		*converted_value = ((v_sense - ADC_VOLTAGE_AT_25_DEGREE)/TEMPERATURE_SENSOR_SLOPE)+ REFERANCE_TEMPERATURE;		/// Doing the ADC convertion
	}
	else
	{
		*converted_value = v_sense;
	}

}
/// Step 12 - Add the configurations for the common module in independent mode
void adc_init_common(uint8_t mode)
{
	if (mode == ADC_INDEPENDENT_MODE)
	{
		adc_common_ptr->CCR &= ~( 0x1F);								/// Clearing the multimode
		adc_common_ptr->CCR &= ~( 0x03 << 16);							/// Clearing the prescalar AND Setting prescalar to 8
		adc_common_ptr->CCR |= (0x03 << 16);
	}
}
