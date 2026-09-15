/*
 * TimerControl.h
 *
 *  Created on: Sep 15, 2026
 *      Author: alexandermartinez
 */

#ifndef INC_TIMERCONTROL_H_
#define INC_TIMERCONTROL_H_

#include <stdint.h>

void startTimerB();
void stopTimerB();
void enableTimerInterupt();
void disableTimerInterupt();
void clearTimerInterupt();
void configureATimer();
void configureBTimer();
uint16_t getCount();
void resetTimerCount();


#endif /* INC_TIMERCONTROL_H_ */
