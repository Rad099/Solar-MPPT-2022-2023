/*
 * DutyCyclePWM.c
 *
 *  Created on: Jan 13, 2023
 *      Author: Ridwan Alrefai
 */

#include "DutyCyclePWM.h"


epwmInformation epwmInfo;


void init_dutyCycle_pwm(void) {

    EPWM_setTimeBasePeriod(EPWM2_BASE, 2000U);
    EPWM_setPhaseShift(EPWM2_BASE, 0U);
    EPWM_setTimeBaseCounter(EPWM2_BASE, 0U);


    EPWM_setCounterCompareValue(EPWM2_BASE,
                                EPWM_COUNTER_COMPARE_A,
                                50U);

    // Set-up counter mode
    //
    //EPWM_setTimeBaseCounterMode(EPWM2_BASE, EPWM_COUNTER_MODE_UP_DOWN);
    //EPwm2Regs.TBCTL.bit.CTRMODE = TB_COUNT_UPDOWN;
    EPWM_disablePhaseShiftLoad(EPWM2_BASE);
    EPWM_setClockPrescaler(EPWM2_BASE, EPWM_CLOCK_DIVIDER_1, EPWM_HSCLOCK_DIVIDER_1);


    //
    // Set-up shadowing
    //
    EPWM_setCounterCompareShadowLoadMode(EPWM2_BASE,
                                         EPWM_COUNTER_COMPARE_A,
                                         EPWM_COMP_LOAD_ON_CNTR_ZERO);

    //
    // Set-up action-qualifier module
    //
    EPWM_setActionQualifierAction(EPWM2_BASE,
                                  EPWM_AQ_OUTPUT_A,
                                  EPWM_AQ_OUTPUT_HIGH,
                                  EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);



    EPWM_setActionQualifierAction(EPWM2_BASE,
                                      EPWM_AQ_OUTPUT_B,
                                      EPWM_AQ_OUTPUT_LOW,
                                      EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);
    EPWM_setActionQualifierAction(EPWM2_BASE,
                                      EPWM_AQ_OUTPUT_B,
                                      EPWM_AQ_OUTPUT_HIGH,
                                      EPWM_AQ_OUTPUT_ON_TIMEBASE_PERIOD);

    //
    // Interrupt where we will change the Compare Values
    // Select INT on Time base counter zero event,
    // Enable INT, generate INT on 3rd event
    //
    EPWM_setInterruptSource(EPWM2_BASE, EPWM_INT_TBCTR_ZERO);
    EPWM_enableInterrupt(EPWM2_BASE);
    EPWM_setInterruptEventCount(EPWM2_BASE, 3U);

    epwmInfo.epwmCompADirection = 1U;
    epwmInfo.epwmCompBDirection = 0U;
    epwmInfo.epwmTimerIntCount = 0U;
    epwmInfo.epwmMaxCompA = 1950U;
    epwmInfo.epwmMinCompA = 50U;
    epwmInfo.epwmMaxCompB = 1950U;
    epwmInfo.epwmMinCompB = 50U;

}


// IN TEST MODE ---- NOT FINALIZED

__interrupt void epwm_duty_ISR(void) {

}


// IN TEST MODE ---- NOT FINALIZED

void update_dutyCycle(uint16_t direction, epwmInformation *epwmInfo) {

    uint16_t compAValue;

    compAValue = EPWM_getCounterCompareValue(EPWM2_BASE, EPWM_COUNTER_COMPARE_A);


    //
    //  Change the CMPA values every 10th interrupt.
    //
    if(epwmInfo->epwmTimerIntCount == 10U) {
         epwmInfo->epwmTimerIntCount = 0U;

         // increasing CMPA
         if (direction == 1U) {

             if (compAValue < epwmInfo->epwmMaxCompA) {
                 EPWM_setCounterCompareValue(EPWM2_BASE, EPWM_COUNTER_COMPARE_A, ++compAValue);
             }

             // TODO: Else Options
             // Could stop entire program for safety, or automatically decrease duty
             // Could keep duty the same and ignore increase request

         }

         // decreasing CMPA
         else {

             if (compAValue > epwmInfo->epwmMinCompA) {
                 EPWM_setCounterCompareValue(EPWM2_BASE, EPWM_COUNTER_COMPARE_A, --compAValue);
             }

             // TODO: Else Options
             // Could stop entire program for safety, or automatically increase duty
             // Could keep duty the same and ignore increase request
         }



    }



}
