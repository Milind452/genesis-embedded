/*
 * 001_LedToggle.c
 *
 *  Created on: Sep 30, 2020
 *      Author: milind
 */
#include "STM32F407xx.h"
#include "STM32F407xx_gpio_driver.h"

void delay(void);

void delay(void)
{
	for(uint32_t i = 0; i <= 0xFFFF; i += 1);
}

int main(void)
{
	//LED1
	GPIO_Handle_t gpioLed1;
	gpioLed1.pGPIOx = GPIOD;
	gpioLed1.GPIO_PinConfig.PinNumber = GPIO_PIN_NO_12;
	gpioLed1.GPIO_PinConfig.PinMode = GPIO_MODE_OUT;
	gpioLed1.GPIO_PinConfig.PinOpType = GPIO_OP_TYPE_PP;
	gpioLed1.GPIO_PinConfig.PinSpeed = GPIO_SPEED_HIGH;
	gpioLed1.GPIO_PinConfig.PinPuPdCtrl = GPIO_NO_PUPD;

	GPIO_PeriphClkCtrl(GPIOD, ENABLE);	//gpioLed.pGPIOx = GPIOD
	GPIO_Init(&gpioLed1);

	//LED2
	GPIO_Handle_t gpioLed2;
	gpioLed2.pGPIOx = GPIOD;
	gpioLed2.GPIO_PinConfig.PinNumber = GPIO_PIN_NO_13;
	gpioLed2.GPIO_PinConfig.PinMode = GPIO_MODE_OUT;
	gpioLed2.GPIO_PinConfig.PinOpType = GPIO_OP_TYPE_PP;
	gpioLed2.GPIO_PinConfig.PinSpeed = GPIO_SPEED_HIGH;
	gpioLed2.GPIO_PinConfig.PinPuPdCtrl = GPIO_NO_PUPD;

	GPIO_PeriphClkCtrl(GPIOD, ENABLE);	//gpioLed.pGPIOx = GPIOD
	GPIO_Init(&gpioLed2);

	//Push button
	GPIO_Handle_t gpioButton;
	gpioButton.pGPIOx = GPIOA;
	gpioButton.GPIO_PinConfig.PinNumber = GPIO_PIN_NO_0;
	gpioButton.GPIO_PinConfig.PinMode = GPIO_MODE_IN;
	gpioButton.GPIO_PinConfig.PinOpType = GPIO_OP_TYPE_PP;
	gpioButton.GPIO_PinConfig.PinSpeed = GPIO_SPEED_HIGH;
	gpioButton.GPIO_PinConfig.PinPuPdCtrl = GPIO_NO_PUPD;

	GPIO_PeriphClkCtrl(GPIOA, ENABLE);
	GPIO_Init(&gpioButton);

	while(1)
	{
//		GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_12);
//		delay();
		uint8_t buttonStatus = GPIO_ReadFromInputPin(GPIOA, GPIO_PIN_NO_0);

		if(buttonStatus){
			GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_12, RESET);
			GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_13, SET);
		}
		else{
			GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_12, SET);
			GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_13, RESET);
		}
	}

	return 0;
}