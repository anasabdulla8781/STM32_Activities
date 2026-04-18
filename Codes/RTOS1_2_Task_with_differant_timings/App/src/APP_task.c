/*
 * APP_task.c
 *
 *  Created on: Mar 27, 2026
 *      Author: ANAS
 */


#include "APP_task.h"
#include "service.h"

uint16_t counter_task;

void app_task_init(void)
{
	/// 1 . Set the clock to HSE
	clock_enable_HSE();
	/// 2. Make the tasks
	xTaskCreate(task1s , "LED_TASK1" , 128, NULL , 1 , NULL);
	xTaskCreate(task500ms , "LED_TASK2" , 128, NULL , 1 , NULL);
	// 3. Start the scheduler
	vTaskStartScheduler();
}



void task1s(void * data)
{
	TickType_t lastWakeTime = xTaskGetTickCount();
	while(1)
	{
		vTaskDelayUntil(&lastWakeTime, pdMS_TO_TICKS(1000));
	}
}


void led_blinking (void * data)
{
	TickType_t lastWakeTime = xTaskGetTickCount();
	while (1)
	{
		gpio_output_operations (gpiod_ptr , PORTD_BLUE_LED_PIN , SET_TOGGLE);
		vTaskDelayUntil(&lastWakeTime, pdMS_TO_TICKS(1000));
	}
}

void vApplicationStackOverflowHook(TaskHandle_t xTask, char *pcTaskName)
{
    // You can debug here
    while(1);
}
