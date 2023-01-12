/*
 * DutyCyclePWM.h
 *
 *  Created on: Jan 12, 2023
 *      Author: radwanalrefai
 */

#ifndef DUTYCYCLEPWM_H_
#define DUTYCYCLEPWM_H_


#include "device.h"
#include "epwm.h"

typedef struct {
    uint16_t compA;
    uint16_t compB;
    uint16_t minCmpA;
    uint16_t maxCmpA;
    uint16_t minCmpB;
    uint16_t maxCmpB;

} epwm_data;

void init_dutyCycle_pwm(void);

__interrupt void epwm_duty_ISR(void);

void update_dutyCycle(epwm_data *data);






#endif /* DUTYCYCLEPWM_H_ */
