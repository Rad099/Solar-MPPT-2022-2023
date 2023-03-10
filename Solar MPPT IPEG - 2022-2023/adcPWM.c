/*
 * adcPWM.c
 *
 *  Created on: Jan 4, 2023
 *      Author: Ridwan Alrefai
 */

#include "adcPWM.h"


void initEPWM1(void) {

    // disable SOCA
    EPWM_disableADCTrigger(EPWM1_BASE, EPWM_SOC_A);

    // configure SOCA
    EPWM_setADCTriggerSource(EPWM1_BASE, EPWM_SOC_A, EPWM_SOC_TBCTR_U_CMPA);
    EPWM_setADCTriggerEventPrescale(EPWM1_BASE, EPWM_SOC_A, 1);

    //
    // 10Khz sampling rate TODO: confirm rate
    // logic: desired freq = 20Khz. period = 10k. to make duty-cycle of 50%
    // compare value should be period/2
    EPWM_setCounterCompareValue(EPWM1_BASE, EPWM_COUNTER_COMPARE_A, 5000);
    EPWM_setTimeBasePeriod(EPWM1_BASE, 10000);


    //
    // Set the local ePWM module clock divider to /1
    //
    EPWM_setClockPrescaler(EPWM1_BASE,EPWM_CLOCK_DIVIDER_1, EPWM_HSCLOCK_DIVIDER_1);

    //
    // Freeze the counter
    //
    EPWM_setTimeBaseCounterMode(EPWM1_BASE, EPWM_COUNTER_MODE_STOP_FREEZE);

}
