/*
 * adcConfig.h
 *
 *  Created on: Dec 16, 2022
 *      Author: Ridwan Alrefai
 */

#include "adc.h"
#include "epwm.h"

#ifndef ADCCONFIG_H_
#define ADCCONFIG_H_

void configureADC(uint32_t base);


void initPWMTrigger(void);


void configureSOCs(void);




#endif /* ADCCONFIG_H_ */
