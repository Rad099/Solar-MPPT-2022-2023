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

    DEVICE_DELAY_US(1000);

}

void continuousADCConfig(uint32_t adcBase, uint32_t channel) {

        uint16_t acqps = 14;

        //
        // Configure SOCs channel no. & acquisition window.
        //
        ADC_setupSOC(adcBase, ADC_SOC_NUMBER0, ADC_TRIGGER_SW_ONLY,
                     (ADC_Channel)channel, acqps);
        ADC_setupSOC(adcBase, ADC_SOC_NUMBER1, ADC_TRIGGER_SW_ONLY,
                     (ADC_Channel)channel, acqps);
        ADC_setupSOC(adcBase, ADC_SOC_NUMBER2, ADC_TRIGGER_SW_ONLY,
                     (ADC_Channel)channel, acqps);
        ADC_setupSOC(adcBase, ADC_SOC_NUMBER3, ADC_TRIGGER_SW_ONLY,
                     (ADC_Channel)channel, acqps);
        ADC_setupSOC(adcBase, ADC_SOC_NUMBER4, ADC_TRIGGER_SW_ONLY,
                     (ADC_Channel)channel, acqps);
        ADC_setupSOC(adcBase, ADC_SOC_NUMBER5, ADC_TRIGGER_SW_ONLY,
                     (ADC_Channel)channel, acqps);
        ADC_setupSOC(adcBase, ADC_SOC_NUMBER6, ADC_TRIGGER_SW_ONLY,
                     (ADC_Channel)channel, acqps);
        ADC_setupSOC(adcBase, ADC_SOC_NUMBER7, ADC_TRIGGER_SW_ONLY,
                     (ADC_Channel)channel, acqps);
        ADC_setupSOC(adcBase, ADC_SOC_NUMBER8, ADC_TRIGGER_SW_ONLY,
                     (ADC_Channel)channel, acqps);
        ADC_setupSOC(adcBase, ADC_SOC_NUMBER9, ADC_TRIGGER_SW_ONLY,
                     (ADC_Channel)channel, acqps);
        ADC_setupSOC(adcBase, ADC_SOC_NUMBER10, ADC_TRIGGER_SW_ONLY,
                     (ADC_Channel)channel, acqps);
        ADC_setupSOC(adcBase, ADC_SOC_NUMBER11, ADC_TRIGGER_SW_ONLY,
                     (ADC_Channel)channel, acqps);
        ADC_setupSOC(adcBase, ADC_SOC_NUMBER12, ADC_TRIGGER_SW_ONLY,
                     (ADC_Channel)channel, acqps);
        ADC_setupSOC(adcBase, ADC_SOC_NUMBER13, ADC_TRIGGER_SW_ONLY,
                     (ADC_Channel)channel, acqps);
        ADC_setupSOC(adcBase, ADC_SOC_NUMBER14, ADC_TRIGGER_SW_ONLY,
                     (ADC_Channel)channel, acqps);
        ADC_setupSOC(adcBase, ADC_SOC_NUMBER15, ADC_TRIGGER_SW_ONLY,
                     (ADC_Channel)channel, acqps);

        //
        // Setup interrupt trigger for SOCs. ADCINT2 will trigger first 8 SOCs.
        // ADCINT1 will trigger next 8 SOCs
        //

        //
        // ADCINT2 trigger for SOC0-SOC7
        //
        ADC_setInterruptSOCTrigger(adcBase, ADC_SOC_NUMBER0,
                                   ADC_INT_SOC_TRIGGER_ADCINT2);
        ADC_setInterruptSOCTrigger(adcBase, ADC_SOC_NUMBER1,
                                   ADC_INT_SOC_TRIGGER_ADCINT2);
        ADC_setInterruptSOCTrigger(adcBase, ADC_SOC_NUMBER2,
                                   ADC_INT_SOC_TRIGGER_ADCINT2);
        ADC_setInterruptSOCTrigger(adcBase, ADC_SOC_NUMBER3,
                                   ADC_INT_SOC_TRIGGER_ADCINT2);
        ADC_setInterruptSOCTrigger(adcBase, ADC_SOC_NUMBER4,
                                   ADC_INT_SOC_TRIGGER_ADCINT2);
        ADC_setInterruptSOCTrigger(adcBase, ADC_SOC_NUMBER5,
                                   ADC_INT_SOC_TRIGGER_ADCINT2);
        ADC_setInterruptSOCTrigger(adcBase, ADC_SOC_NUMBER6,
                                   ADC_INT_SOC_TRIGGER_ADCINT2);
        ADC_setInterruptSOCTrigger(adcBase, ADC_SOC_NUMBER7,
                                   ADC_INT_SOC_TRIGGER_ADCINT2);

        //
        // ADCINT1 trigger for SOC8-SOC15
        //
        ADC_setInterruptSOCTrigger(adcBase, ADC_SOC_NUMBER8,
                                   ADC_INT_SOC_TRIGGER_ADCINT1);
        ADC_setInterruptSOCTrigger(adcBase, ADC_SOC_NUMBER9,
                                   ADC_INT_SOC_TRIGGER_ADCINT1);
        ADC_setInterruptSOCTrigger(adcBase, ADC_SOC_NUMBER10,
                                   ADC_INT_SOC_TRIGGER_ADCINT1);
        ADC_setInterruptSOCTrigger(adcBase, ADC_SOC_NUMBER11,
                                   ADC_INT_SOC_TRIGGER_ADCINT1);
        ADC_setInterruptSOCTrigger(adcBase, ADC_SOC_NUMBER12,
                                   ADC_INT_SOC_TRIGGER_ADCINT1);
        ADC_setInterruptSOCTrigger(adcBase, ADC_SOC_NUMBER13,
                                   ADC_INT_SOC_TRIGGER_ADCINT1);
        ADC_setInterruptSOCTrigger(adcBase, ADC_SOC_NUMBER14,
                                   ADC_INT_SOC_TRIGGER_ADCINT1);
        ADC_setInterruptSOCTrigger(adcBase, ADC_SOC_NUMBER15,
                                   ADC_INT_SOC_TRIGGER_ADCINT1);

        //
        // Disable Interrupt flags
        //
        ADC_disableInterrupt(adcBase, ADC_INT_NUMBER1);
        ADC_disableInterrupt(adcBase, ADC_INT_NUMBER2);
        ADC_disableInterrupt(adcBase, ADC_INT_NUMBER3);
        ADC_disableInterrupt(adcBase, ADC_INT_NUMBER4);

        //
        // Enable continuous mode
        //
        ADC_enableContinuousMode(adcBase, ADC_INT_NUMBER1);
        ADC_enableContinuousMode(adcBase, ADC_INT_NUMBER2);
        ADC_enableContinuousMode(adcBase, ADC_INT_NUMBER3);
        ADC_enableContinuousMode(adcBase, ADC_INT_NUMBER4);

        //
        // Configure interrupt triggers
        //
        ADC_setInterruptSource(adcBase, ADC_INT_NUMBER1, ADC_SOC_NUMBER6);
        ADC_setInterruptSource(adcBase, ADC_INT_NUMBER2, ADC_SOC_NUMBER14);
        ADC_setInterruptSource(adcBase, ADC_INT_NUMBER3, ADC_SOC_NUMBER7);
        ADC_setInterruptSource(adcBase, ADC_INT_NUMBER4, ADC_SOC_NUMBER15);

}
