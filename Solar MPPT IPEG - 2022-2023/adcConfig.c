/*
 * adcConfig.c
 *
 *  Created on: Dec 15, 2022
 *      Author: Ridwan Alrefai
 */

#include "adcConfig.h"

void configureADC(uint32_t base) {

    // sets ADCCLK
    ADC_setPrescaler(base, ADC_CLK_DIV_4_0);

    // sets mode to 12-bit single pin
    ADC_setMode(base, ADC_RESOLUTION_12BIT, ADC_MODE_SINGLE_ENDED);

    // sets end of conversion to pulse
    ADC_setInterruptPulseMode(base, ADC_PULSE_END_OF_CONV);

    // enable
    ADC_enableConverter(base);

    //DEVICE_DELAY_US(1000);

}

void initPWMTrigger(void) {

    EPWM_disableADCTrigger(EPWM1_BASE, EPWM_SOC_A);

    EPWM_setADCTriggerSource(EPWM1_BASE, EPWM_SOC_A, EPWM_SOC_TBCTR_U_CMPA);

    EPWM_setADCTriggerEventPrescale(EPWM1_BASE, EPWM_SOC_A, 1);

    // 10 Khz sampling rate
    EPWM_setCounterCompareValue(EPWM1_BASE, EPWM_COUNTER_COMPARE_A, 100);
    EPWM_setTimeBasePeriod(EPWM1_BASE, 1999);

    EPWM_setClockPrescaler(EPWM1_BASE, EPWM_CLOCK_DIVIDER_1, EPWM_HSCLOCK_DIVIDER_1);

    EPWM_setTimeBaseCounterMode(EPWM1_BASE, EPWM_COUNTER_MODE_STOP_FREEZE);

}

void configureSOCs(void) {

    // minimum acquisition window for 12-bit res
    //uint16_t min_acq_window = 14;


}
