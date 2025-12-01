/*
 * STM32_ADC.c
 *
 *  Created on: Nov 20, 2025
 *      Author: uie83604
 */


#include <STM32_ADC.h>


void adc_init_common(uint8_t mode)
{
	if (mode == ADC_INDEPENDENT_MODE)
	{
		adc_common_ptr->CCR &= ~( 0x1F);								/// Clearing the multimode
		adc_common_ptr->CCR &= ~( 0x03 << 16);							/// Clearing the prescalar AND Setting prescalar to 8
		adc_common_ptr->CCR |= (0x03 << 16);
	}
}
void adc_init_internal_channels(uint8_t internal_channel)
{
	switch(internal_channel)
	{
		case(INNER_TEMPERATURE_SENSOR):
			adc_common_ptr->CCR |= (0X01 << 23);						/// Enabling the temperature sensing
			for (volatile int i = 0; i < 3000; i++);   					// ~15–20 µs delay
			__asm("nop");
			__asm("nop");
			__asm("nop");
			break;
		default:
			break;
	}
}

void adc_init_individual_modules(ADC_structure * adc_ptr , uint8_t channel)
{
	adc_ptr->CR1 &= ~(0x03 << 24);										/// clearing the resolution ( default 12bit resolution )
	adc_ptr->CR2 |=  (1 << 0);    										/// ADON = 1 (ADC ON)
	for (volatile int i = 0; i < 10000; i++); 							// give ADC time to power up
	adc_ptr->CR2 |=  (1 << 1);    										/// CONT = 1 (continuous conversion)
	adc_ptr->CR2 |= (0x01 << 10);   									/// EOCS after every conversion
	adc_ptr->CR2 &= ~(1 << 11);   										/// ALIGN = right alignment
	if (channel > 9 && channel < 19)
	{
		adc_ptr->SMPR1 &= ~(0x07 << (3*(channel - 10)));     								/// Clear the sampling time bits for the channel selected
		adc_ptr->SMPR1 |=  (0x07 << (3*(channel - 10)));     								/// Set desired sampling time ( 480 cycles here )
	}
	else if (channel >=0 && channel <10)
	{
		adc_ptr->SMPR2 &= ~(0x07 << (3*channel));     										/// Clear the sampling time bits for the channel selected
		adc_ptr->SMPR2 |=  (0x07 << (3*channel));     										/// Set desired sampling time ( 480 cycles here )
	}
	adc_ptr->SQR1 = 0;													/// Clearing the SQR1
	adc_ptr->SQR2 = 0;													/// Clearing the SQR2
	adc_ptr->SQR3 = 0;													/// Clearing the SQR3
	adc_ptr->SR = 0;													/// Clearing the flags initially


}

void adc_set_sequnce (ADC_structure * adc_ptr , uint8_t channel , uint8_t order)
{
	if ( order < 7 )
	{
		adc_ptr->SQR3 &= ~ (0x1F << 5* (order - 1));							/// cleared the specidic order in SQR register
		adc_ptr->SQR3 |= (channel << 5* (order-1));							/// Set the channel we want in that SQR bits
	}
	else if (order < 13)
	{
		adc_ptr->SQR2 &= ~ (0x1F << 5* (order - 7));							/// cleared the specidic order in SQR register
		adc_ptr->SQR2 |= (channel << 5* (order - 7));							/// Set the channel we want in that SQR bits
	}
	else if (order < 17)
	{
		adc_ptr->SQR1 &= ~ (0x1F << 5* (order - 13));							/// cleared the specidic order in SQR register
		adc_ptr->SQR1 |= (channel << 5* (order - 13));							/// Set the channel we want in that SQR bits
	}

	adc_ptr->SQR1 &= ~(0x0F << 20);   											/// incrementing the length for the new channel added
	adc_ptr->SQR1 |= ((order - 1) << 20);
}

void adc_start_conversion(ADC_structure * adc_ptr)
{
	adc_ptr->CR2 |= (0x01 << 30);												/// Start the conversion
	__asm("nop");
}

void adc_get_value(ADC_structure * adc_ptr , volatile uint16_t* adc_measured_value)
{
    if (adc_ptr->SR & (1 << 1))     // EOC
    {
        *adc_measured_value = adc_ptr->DR;
    }
}
void adc_convert_value(volatile uint16_t adc_measured_value, float* converted_value ,uint8_t mode)
{
	float v_sense = 0.0;
	v_sense = (adc_measured_value / ADC_MAX_VALUE) * MAX_VOLTAGE;		/// Curresponding voltage value from the sensor

	if ( mode == INNER_TEMPERATURE_SENSOR )
	{
		*converted_value = ((v_sense - ADC_VOLTAGE_AT_25_DEGREE)/TEMPERATURE_SENSOR_SLOPE)+ REFERANCE_TEMPERATURE;		/// Doing the ADC convertion
	}
	else
	{
		*converted_value = v_sense;
	}

}
