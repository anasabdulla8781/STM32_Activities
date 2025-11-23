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
		rcc_ptr->APB2ENR |= (0x700);									/// Clock init of ADC for all 3 ADCs
		adc_common_ptr->CCR &= ~( 0x1F);								/// Clearing the multimode
		adc_common_ptr->CCR &= ~( 0x03 << 16);							/// Clearing the prescalar AND Setting prescalar to 8
		adc_common_ptr->CCR |= (0x03 << 16);
		adc_common_ptr->CCR |= (0X01 << 23);							/// Enabling the temperature sensing
		for (volatile int i = 0; i < 3000; i++);   // ~15–20 µs delay
		__asm("nop");
		__asm("nop");
		__asm("nop");
	}
}

void adc1_init(void)
{
	adc1_ptr->CR1 &= ~(0x03 << 24);										/// clearing the resolution ( default 12bit resolution )
	adc1_ptr->CR2 |=  (1 << 0);    										/// ADON = 1 (ADC ON)
	adc1_ptr->CR2 |=  (1 << 1);    										/// CONT = 1 (continuous conversion)
	adc1_ptr->CR2 &= ~(1 << 11);   										/// ALIGN = right alignment
	adc1_ptr->CR2 |= (0x01 << 10);   									/// EOCS after every conversion
	adc1_ptr->SMPR1 &= ~(0x07 << 18);     								/// Clear CH16 sampling bits
	adc1_ptr->SMPR1 |=  (0x07 << 18);     								/// Set 112 cycle sampling time
	adc1_ptr->SQR3 &= ~(0x1F << 0);    									/// Clear SQ1 bits
	adc1_ptr->SQR3 |=  (16  << 0);     									/// Put channel 16 in SQ1
	__asm("nop");
	__asm("nop");
	adc1_ptr->CR2 |= (0x01 << 30);										/// Start the conversion
	__asm("nop");
	__asm("nop");
}


void get_adc_value(volatile uint16_t* adc_measured_value)
{
	while (!(adc1_ptr->SR & (0x01<<1)));							/// holding till the converions is getting completed
	*adc_measured_value = adc1_ptr->DR;								/// storing the converted value into the variable
}

void adc_convert_value(volatile uint16_t adc_measured_value, float* converted_value ,uint8_t mode)
{
	float v_sense = 0.0;
	v_sense = (adc_measured_value / ADC_MAX_VALUE) * MAX_VOLTAGE;				/// Curresponding voltage value from the sensor

	if ( mode == TEMPERATURE_DETECTION_MODE )
	{
		*converted_value = ((v_sense - ADC_VOLTAGE_AT_25_DEGREE)/TEMPERATURE_SENSOR_SLOPE)+ REFERANCE_TEMPERATURE;		/// Doing the ADC convertion
	}

}
