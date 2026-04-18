/*
 * STM32_SPI.h
 *
 *  Created on: Feb 28, 2026
 *      Author: ANAS
 */

#ifndef INC_STM32_SPI_H_
#define INC_STM32_SPI_H_

#include <stdint.h>

/// Macros

/// Macros for different SPI modules
#define SPI1	0
#define SPI2	1
#define SPI3	2

/// Macros for SPI1 Pins
#define SPI1_NSS	4
#define SPI1_SCLK	5
#define SPI1_MISO	6
#define SPI1_MOSI	7

/// Macros - Common
#define NULL	0


typedef struct
{
	volatile uint32_t	CR1;
	volatile uint32_t	CR2;
	volatile uint32_t	SR;
	volatile uint32_t	DR;
	volatile uint32_t	CRCPR;
	volatile uint32_t	RXCRCR;
	volatile uint32_t	TXCRCR;
	volatile uint32_t	I2SCFGR;
	volatile uint32_t	I2SPR;
}spi_structure;


/// SPI Baseaddress
#define SPI1_BASEADDRESS	0x40013000


/// Macro for pointer to various SPI modules
#define spi1_ptr	((spi_structure*)SPI1_BASEADDRESS)


/// Function declarations
extern void spi_init_config(spi_structure* spi_ptr);
extern uint8_t spi_transfer(spi_structure* spi_ptr , uint8_t data);
extern void spi_transfer_buffer(spi_structure* spi_ptr, uint8_t *tx_buffer, uint8_t *rx_buffer, uint32_t length);

#endif /* INC_STM32_SPI_H_ */
