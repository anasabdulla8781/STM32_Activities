/*
 * STM32_IWDG.c
 *
 *  Created on: Nov 26, 2025
 *      Author: uie83604
 */

/// ***************************************** HISTORY ******************************************

/// Version 1.1	 ---------------------------   26-11-25 - Creating new file

#include <STM32_IWDG.h>


void init_independent_watchdog(void)
{
	/// Step 1 - Setting up the clock
	LSI_clock_enable();
	/// Step 2 - Freezing independent watchdog once we add the breakpoint
	init_dbgmcu();
	/// Step 3 - Unlocking prescalar and relaod register access
	iwdg_ptr->KR = PRESCALAR_AND_RELOAD_ACCESS;			// Getting the access to prescalar and reload register
	/// Step 4 - Setting the prescalar and reload register
	iwdg_ptr->PR = 6;   								// Setting the prescalar to 256
	iwdg_ptr->RLR = 1240;								// Setting the timing for 1 second ( reset time )
//	while(iwdg_ptr->SR != 0);							// Waiting till the bit fillings are completed in the PR and RLR
	/// Step 5 - Reset and start the watchdog
	iwdg_ptr->KR = RESET_WATCHDOG;						// Before starting , lets reset the reload register
	iwdg_ptr->KR = IWDG_START;							// Starting the watchdog , counter ( RLR ) decrement is started now

}

/// Step 6 - Feeding the watchdog continously
void feed_watchdog(void)
{
	iwdg_ptr->KR = RESET_WATCHDOG;
}

