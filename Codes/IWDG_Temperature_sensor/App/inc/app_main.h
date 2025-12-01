/*
 * app_main.h
 *
 *  Created on: Oct 17, 2025
 *      Author: ANAS
 */

#ifndef INC_APP_MAIN_H_
#define INC_APP_MAIN_H_

#include "stddef.h"

/// function declarations

extern void service_init(void);
extern void app_init(void);

extern volatile uint16_t adc_value;
extern float converted_value;
extern volatile uint8_t reset_reason;

#endif /* INC_APP_MAIN_H_ */
