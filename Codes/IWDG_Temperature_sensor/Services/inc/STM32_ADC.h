/*
 * STM32_ADC.h
 *
 *  Created on: Nov 20, 2025
 *      Author: uie83604
 */

#ifndef INC_STM32_ADC_H_
#define INC_STM32_ADC_H_

#include <stdint.h>
#include <STM32_RCC.h>


typedef struct
{
    volatile uint32_t CSR;   // 0x00: Common status register
    volatile uint32_t CCR;   // 0x04: Common control register
    volatile uint32_t CDR;   // 0x08: Common regular data register
} ADC_Common_structure;

typedef struct
{
    volatile uint32_t SR;       // 0x00: Status register
    volatile uint32_t CR1;      // 0x04: Control register 1
    volatile uint32_t CR2;      // 0x08: Control register 2
    volatile uint32_t SMPR1;    // 0x0C: Sample time register 1 (channels 10–18)
    volatile uint32_t SMPR2;    // 0x10: Sample time register 2 (channels 0–9)

    volatile uint32_t JOFR1;    // 0x14: Injected channel data offset register 1
    volatile uint32_t JOFR2;    // 0x18: Injected channel data offset register 2
    volatile uint32_t JOFR3;    // 0x1C: Injected channel data offset register 3
    volatile uint32_t JOFR4;    // 0x20: Injected channel data offset register 4

    volatile uint32_t HTR;      // 0x24: Watchdog high threshold register
    volatile uint32_t LTR;      // 0x28: Watchdog low threshold register

    volatile uint32_t SQR1;     // 0x2C: Regular sequence register 1
    volatile uint32_t SQR2;     // 0x30: Regular sequence register 2
    volatile uint32_t SQR3;     // 0x34: Regular sequence register 3

    volatile uint32_t JSQR;     // 0x38: Injected sequence register

    volatile uint32_t JDR1;     // 0x3C: Injected data register 1
    volatile uint32_t JDR2;     // 0x40: Injected data register 2
    volatile uint32_t JDR3;     // 0x44: Injected data register 3
    volatile uint32_t JDR4;     // 0x48: Injected data register 4

    volatile uint32_t DR;       // 0x4C: Regular data register
} ADC_structure;

// ---------- ADC BASE ADDRESSES ----------
#define ADC1_BASEADDRESS         (0x40012000UL)
#define ADC2_BASEADDRESS         (0x40012100UL)
#define ADC3_BASEADDRESS         (0x40012200UL)
#define ADC_COMMON_BASEADDRESS   (0x40012300UL)


// ---------- POINTERS TO ADC STRUCTURES ----------
#define adc1_ptr      ((ADC_structure *) ADC1_BASEADDRESS)
#define adc2_ptr      ((ADC_structure *) ADC2_BASEADDRESS)
#define adc3_ptr      ((ADC_structure *) ADC3_BASEADDRESS)

// Pointer to ADC Common Block
#define adc_common_ptr   ((ADC_Common_structure *) ADC_COMMON_BASEADDRESS)


/// Macros

	// Modes
#define EXTERNAL_CHANNEL	0
#define INTERNAL_CHANNEL_TEMPERATURE_SENSOR	1
#define INTERNAL_CHANNEL_VBAT	2


#define ADC_INDEPENDENT_MODE	0
#define ADC_MAX_VALUE	4095.00
#define MAX_VOLTAGE		3.3

/// Temperature sensor specific macros
#define ADC_VOLTAGE_AT_25_DEGREE	0.760
#define TEMPERATURE_SENSOR_SLOPE	0.0025
#define INNER_TEMPERATURE_SENSOR	1
#define REFERANCE_TEMPERATURE	25.00


/// Global function declarations
void adc_init_common(uint8_t mode);
void adc_convert_value(volatile uint16_t adc_measured_value, float* converted_value ,uint8_t mode);
void adc_get_value(ADC_structure * adc_ptr , volatile uint16_t* adc_measured_value);
void adc_start_conversion(ADC_structure* adc_ptr);
void adc_init_module(ADC_structure * adc_ptr , uint8_t channel, uint8_t mode , uint8_t conversion_behaviour , uint8_t converion_order);

/// Global variable declarions

#endif /* INC_STM32_ADC_H_ */
