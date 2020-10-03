/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */

/*
 *
/*
#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif
*/

#include <stdint.h>
#define SPI1_BASE_ADDR				0x40013000UL
#define SPI1_CR1_REG_OFFSET			0x00UL
#define SPI1_CR1_REG_ADDR			(SPI1_BASE_ADDR + SPI1_CR1_REG_OFFSET)
#define RCC_BASE_ADDR				0x40023800UL
#define RCC_APB2ENR_OFFSET			0x44UL
#define RCC_APB2ENR_ADDR			(RCC_BASE_ADDR + RCC_APB2ENR_OFFSET)

int main(void)
{
	uint32_t *pSpi1Cr1RegSSI	=	(uint32_t)SPI1_CR1_REG_ADDR;
	uint32_t *pRccApb2enrReg	 = 	(uint32_t)RCC_APB2ENR_ADDR;

	*pRccApb2enrReg |= (1<<6);
	*pSpi1Cr1RegSSI |= (1<<8);
    /* Loop forever */
	for(;;);
}