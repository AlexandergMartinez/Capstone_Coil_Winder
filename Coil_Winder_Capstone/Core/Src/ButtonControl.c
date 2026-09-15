#include "ButtonControl.h"
#include "stm32f4xx_hal.h"

void buttConfig(){
	__HAL_RCC_GPIOA_CLK_ENABLE();
	GPIO_InitTypeDef GPIO_StructInit = {0};

	GPIO_StructInit.Pin = GPIO_PIN_0;
	GPIO_StructInit.Mode = GPIO_MODE_IT_RISING_FALLING;
	GPIO_StructInit.Pull = GPIO_NOPULL;
	GPIO_StructInit.Speed = GPIO_SPEED_FREQ_HIGH;


	HAL_GPIO_Init(GPIOA, &GPIO_StructInit);
	enableButtInterrupt();
}

void clearButtPending(){
	NVIC_ClearPendingIRQ(EXTI0_IRQn);
}

void enableButtInterrupt(){
	NVIC_EnableIRQ(EXTI0_IRQn);
}

void clearButtInterrupt(){
	__HAL_GPIO_EXTI_CLEAR_IT(GPIO_PIN_0);
}

void disableButtInterrupt(){
	NVIC_DisableIRQ(EXTI0_IRQn);
}

int readPin(){
	return HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0);
}

