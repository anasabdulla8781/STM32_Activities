/*
 * APP_feature.h
 *
 *  Created on: Nov 16, 2025
 *      Author: ANAS
 */

#ifndef INC_APP_FEATURE_H_
#define INC_APP_FEATURE_H_

#include <stdint.h>

extern volatile uint8_t upcounter;

extern void fade_led_program(void);
extern void watchdog_blocking_program (void);

#endif /* INC_APP_FEATURE_H_ */
