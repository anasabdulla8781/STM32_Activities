/*
 * STM32_GPIO.h
 *
 *  Created on: Oct 20, 2025
 *      Author: ANAS
 */

#ifndef INC_STM32_GPIO_H_
#define INC_STM32_GPIO_H_

#include <stdint.h>
#include <STM32_RCC.h>

/// GPIO Structure

typedef struct
{
    volatile uint32_t MODER;     // 0x00: GPIO port mode register
    volatile uint32_t OTYPER;    // 0x04: GPIO port output type register
    volatile uint32_t OSPEEDR;   // 0x08: GPIO port output speed register
    volatile uint32_t PUPDR;     // 0x0C: GPIO port pull-up/pull-down register
    volatile uint32_t IDR;       // 0x10: GPIO port input data register
    volatile uint32_t ODR;       // 0x14: GPIO port output data register
    volatile uint32_t BSRR;      // 0x18: GPIO port bit set/reset register
    volatile uint32_t LCKR;      // 0x1C: GPIO port configuration lock register
    volatile uint32_t AFRL;      // 0x20: GPIO alternate function low register (pins 0–7)
    volatile uint32_t AFRH;      // 0x24: GPIO alternate function high register (pins 8–15)
} GPIO_structure;


/// GPIO BASE ADDRESS

#define GPIOA_BASEADDRESS  (0x40020000UL)
#define GPIOB_BASEADDRESS  (0x40020400UL)
#define GPIOC_BASEADDRESS  (0x40020800UL)
#define GPIOD_BASEADDRESS  (0x40020C00UL)
#define GPIOE_BASEADDRESS  (0x40021000UL)
#define GPIOF_BASEADDRESS  (0x40021400UL)
#define GPIOG_BASEADDRESS  (0x40021800UL)
#define GPIOH_BASEADDRESS  (0x40021C00UL)
#define GPIOI_BASEADDRESS  (0x40022000UL)


/// POINTERS TO GPIO Structures

#define gpioa_ptr ((GPIO_structure *) GPIOA_BASEADDRESS)
#define gpiob_ptr ((GPIO_structure *) GPIOB_BASEADDRESS)
#define gpioc_ptr ((GPIO_structure *) GPIOC_BASEADDRESS)
#define gpiod_ptr ((GPIO_structure *) GPIOD_BASEADDRESS)
#define gpioe_ptr ((GPIO_structure *) GPIOE_BASEADDRESS)
#define gpiof_ptr ((GPIO_structure *) GPIOF_BASEADDRESS)
#define gpiog_ptr ((GPIO_structure *) GPIOG_BASEADDRESS)
#define gpioh_ptr ((GPIO_structure *) GPIOH_BASEADDRESS)
#define gpioi_ptr ((GPIO_structure *) GPIOI_BASEADDRESS)


/// MACROS

#define BLUE_LED_PIN	15
#define GREEN_LED_PIN	12
#define ORANGE_LED_PIN	13
#define RED_LED_PIN		14

#define ON		1
#define OFF		0
#define TOGGLE	2

#define PIN_OUTPUT 	1
#define PIN_ANALOG_INPUT	2
#define PIN_ALTERNATE_FUNCTION	3
#define PIN_GENERAL_INPUT	4

#define AF2	2

#define PORTA	1
#define PORTB	2
#define PORTC	3
#define PORTD	4

#define PIN_0      0
#define PIN_1      1
#define PIN_2      2
#define PIN_3      3
#define PIN_4      4
#define PIN_5      5
#define PIN_6      6
#define PIN_7      7
#define PIN_8      8
#define PIN_9      9
#define PIN_10     10
#define PIN_11     11
#define PIN_12     12
#define PIN_13     13
#define PIN_14     14
#define PIN_15     15



/// FUNCTION DEFINITIONS
extern void pin_init(uint8_t pin,uint8_t mode , uint8_t port);
extern void pin_operations(uint8_t pin , uint8_t state);
extern void set_alternate_function_portD ( uint8_t pin_number );
extern uint8_t pin_state_check(uint8_t pin , GPIO_structure * gpio_ptr);


#endif /* INC_STM32_GPIO_H_ */
