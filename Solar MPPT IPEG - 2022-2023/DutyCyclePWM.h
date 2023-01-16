/*
 * DutyCyclePWM.h
 *
 *  Created on: Jan 12, 2023
 *      Author: radwanalrefai
 */

#ifndef DUTYCYCLEPWM_H_
#define DUTYCYCLEPWM_H_


#include "ProjectFiles.h"

typedef struct
{
    uint16_t epwmCompADirection;
    uint16_t epwmCompBDirection;
    uint16_t epwmTimerIntCount;
    uint16_t epwmMaxCompA;
    uint16_t epwmMinCompA;
    uint16_t epwmMaxCompB;
    uint16_t epwmMinCompB;
} epwmInformation;



// NOTE: Using EPWM 2 for outputting duty cycle.
// This will be outputted using DAC


void init_dutyCycle_pwm(void);

__interrupt void epwm_duty_ISR(void);

// Direction values: 1 for increment, 0 for decrement
// Called from algorithm functions
void update_dutyCycle(uint16_t direction, epwmInformation *ewpmInfo);




#endif /* DUTYCYCLEPWM_H_ */
