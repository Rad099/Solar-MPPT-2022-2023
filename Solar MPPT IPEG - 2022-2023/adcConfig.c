/*
 * adcConfig.c
 *
 *  Created on: Dec 15, 2022
 *      Author: Ridwan Alrefai
 */

#include "adcConfig.h"

void configureADC(uint32_t adcBase) {

    //
    // Set ADCDLK divider to /4
    //
    ADC_setPrescaler(adcBase, ADC_CLK_DIV_4_0);

    // set Vref to internal
    //ADC_setVREF(ADCA_BASE, ADC_REFERENCE_INTERNAL, ADC_REFERENCE_3_3V);

    //
    // Set resolution and signal mode (see #defines above) and load
    // corresponding trims.
    //

    ADC_setMode(adcBase, ADC_RESOLUTION_12BIT, ADC_MODE_SINGLE_ENDED);


    //
    // Set pulse positions to late
    //
    ADC_setInterruptPulseMode(adcBase, ADC_PULSE_END_OF_CONV);

    //
    // Power up the ADCs and then delay for 1 ms
    //
    ADC_enableConverter(adcBase);

    //
    // Delay for 1ms to allow ADC time to power up
    //
    DEVICE_DELAY_US(1000);

}

void initSOCs(void) {

        uint16_t acqps;


        //
        // Determine minimum acquisition window (in SYSCLKS) based on resolution
        // TODO: confirm acquisition window
        acqps = 14; // 75ns

        // Vin adc setup
        ADC_setupSOC(ADCA_BASE, ADC_SOC_NUMBER0, ADC_TRIGGER_EPWM1_SOCA, ADC_CH_ADCIN0, acqps);

        // configure interrupt for ADCA
        //ADC_setInterruptSource(ADCA_BASE, ADC_INT_NUMBER1, ADC_SOC_NUMBER0);
        //ADC_enableInterrupt(ADCA_BASE, ADC_INT_NUMBER1);
       // ADC_clearInterruptStatus(ADCA_BASE, ADC_INT_NUMBER1);

        // Iin adc setup
        ADC_setupSOC(ADCA_BASE, ADC_SOC_NUMBER2, ADC_TRIGGER_EPWM1_SOCA, ADC_CH_ADCIN2, acqps);

        // configure interrupt for ADCB
        ADC_setInterruptSource(ADCA_BASE, ADC_INT_NUMBER1, ADC_SOC_NUMBER0);
        ADC_setInterruptSource(ADCA_BASE, ADC_INT_NUMBER1, ADC_SOC_NUMBER2);
        ADC_enableInterrupt(ADCA_BASE, ADC_INT_NUMBER1);
        ADC_clearInterruptStatus(ADCA_BASE, ADC_INT_NUMBER1);

}
