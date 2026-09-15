#include "TimerControl.h"
#include "stm32f4xx_hal.h"

static TIM_HandleTypeDef TIM6EnableStruct = {0};

void configureBTimer(){
    __HAL_RCC_TIM6_CLK_ENABLE();

    TIM6EnableStruct.Instance = TIM6;
    TIM6EnableStruct.Init.Prescaler = 11363;
    TIM6EnableStruct.Init.CounterMode = TIM_COUNTERMODE_UP;
    TIM6EnableStruct.Init.Period = 65535;
    TIM6EnableStruct.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
    TIM6EnableStruct.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;

    HAL_TIM_Base_Init(&TIM6EnableStruct);

    //disable all interrupts for this timer
    NVIC_DisableIRQ(TIM6_DAC_IRQn);
    NVIC_ClearPendingIRQ(TIM6_DAC_IRQn);
}

void startTimerB(){
    __HAL_TIM_SET_COUNTER(&TIM6EnableStruct, 0);
    __HAL_TIM_ENABLE(&TIM6EnableStruct);
}
void stopTimerB(){
	__HAL_TIM_DISABLE(&TIM6EnableStruct);
}

void enableTimerInterupt(){
	HAL_NVIC_EnableIRQ(TIM6_DAC_IRQn);
}
void disableTimerInterupt(){
	HAL_NVIC_DisableIRQ(TIM6_DAC_IRQn);
}
void clearTimerInterupt(){
	__HAL_TIM_CLEAR_FLAG(&TIM6EnableStruct, TIM_FLAG_UPDATE);
	HAL_NVIC_ClearPendingIRQ(TIM6_DAC_IRQn);
}

uint16_t getCount(){
	return __HAL_TIM_GET_COUNTER(&TIM6EnableStruct);
}

void resetTimerCount(){
	__HAL_TIM_SET_COUNTER(&TIM6EnableStruct, 0);
}
