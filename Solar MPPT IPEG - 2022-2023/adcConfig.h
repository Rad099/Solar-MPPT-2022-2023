/*
 * adcConfig.h
 *
 *  Created on: Dec 16, 2022
 *      Author: Ridwan Alrefai
 */

#include "adc.h"
#include "epwm.h"
#include "device.h"

#ifndef ADCCONFIG_H_
#define ADCCONFIG_H_

void configureADC(uint32_t base);


void continuousADCConfig(uint32_t base, uint32_t channel);



#endif /* ADCCONFIG_H_ */
