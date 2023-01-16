/*
 * DutyCyclePWM.h
 *
 *  Created on: Jan 12, 2023
 *      Author: radwanalrefai
 */

#ifndef DUTYCYCLEPWM_H_
#define DUTYCYCLEPWM_H_


#include "ProjectFiles.h"

// NOTE: Using EPWM 2 for outputting duty cycle.
// This will be outputted using DAC


void init_dutyCycle_pwm(void);

__interrupt void epwm_duty_ISR(void);

void update_dutyCycle(void);






#endif /* DUTYCYCLEPWM_H_ */
