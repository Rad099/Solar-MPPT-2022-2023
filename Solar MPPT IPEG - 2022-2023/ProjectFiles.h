/*
 * ProjectFiles.h
 *
 *  Created on: Jan 13, 2023
 *      Author: Ridwan Alrefai
 */

#ifndef PROJECTFILES_H_
#define PROJECTFILES_H_

#include "driverlib.h"
#include "adcConfig.h"
#include "adcPWM.h"
#include "mpptAlgorithms.h"
#include "DutyCyclePWM.h"
#include "device.h"
#include "adc.h"
#include "epwm.h"
#include <stdio.h>

//
// Globals
//
#define EX_ADC_RESOLUTION       12

// MPPT Variables

extern uint16_t adcAResults;
extern uint16_t adcBResults;
extern float current_in;
extern float voltage_in;
extern float power_in;
extern float power_out;
extern float prev_power_in;
extern float prev_power_out;




#endif /* PROJECTFILES_H_ */
