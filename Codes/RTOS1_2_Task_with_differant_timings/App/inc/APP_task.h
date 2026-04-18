/*
 * APP_task.h
 *
 *  Created on: Mar 27, 2026
 *      Author: ANAS
 */

#ifndef INC_APP_TASK_H_
#define INC_APP_TASK_H_

#include "stdint.h"
#include "FreeRTOS_header.h"

extern void app_task_init(void);

/// Differant task declarations
extern void counting_task(void * data);
extern void led_blinking (void * data);

extern void vApplicationStackOverflowHook(TaskHandle_t xTask, char *pcTaskName);

#endif /* INC_APP_TASK_H_ */
