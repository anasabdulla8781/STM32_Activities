/*
 * app_main.h
 *
 *  Created on: Oct 17, 2025
 *      Author: ANAS
 */

#ifndef INC_APP_MAIN_H_
#define INC_APP_MAIN_H_

#include "stddef.h"



/// Macros

#define MAX_LOOP_TIME_MS	60

/// function declarations

extern void service_init(void);
extern void app_init(void);

extern volatile uint16_t adc_value;
extern float converted_value;
extern volatile uint8_t reset_reason;

/// variables for measuring the loop time
extern volatile uint32_t start_time_ms;
extern volatile uint32_t end_time_ms;
extern volatile uint32_t loop_time_ms;

#endif /* INC_APP_MAIN_H_ */
