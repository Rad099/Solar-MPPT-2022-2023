/**
 * main.c
 *
 * Ridwan Alrefai - 2022/2023
 * University of Illinois Chicago
 * Intelligent Power Electronics Laboratory - Chicago
 *
 */

#include "ProjectFiles.h"


//
// Globals
//
#define EX_ADC_RESOLUTION       12

// MPPT Variables

uint16_t adcAResults;
uint16_t adcBResults;
float current_in;
float voltage_in;
float power_in;
float power_out;
float prev_power_in;
float prev_power_out;


//
// Main
//
void main(void)
{

    //
    // Initialize device clock and peripherals
    //
    Device_init();

    //
    // Disable pin locks and enable internal pullups.
    //
    Device_initGPIO();

    //
    // Initialize PIE and clear PIE registers. Disables CPU interrupts.
    //
    Interrupt_initModule();

    //
    // Initialize the PIE vector table with pointers to the shell Interrupt
    // Service Routines (ISR).
    //
    Interrupt_initVectorTable();

    // initiliaze ADCs
    configureADC(ADCA_BASE); // voltage adc base
    configureADC(ADCB_BASE); // current adc base

    // initialize EPWM 1 for adc sampling
    initEPWM1();


    // initialize SOCs for adc conversions
    initSOCs();

    //
    // Enable Global Interrupt (INTM) and realtime interrupt (DBGM)
    //
    EINT;
    ERTM;

    //
    // Start ePWM1, enabling SOCA and putting the counter in up-count mode
    //
    EPWM_enableADCTrigger(EPWM1_BASE, EPWM_SOC_A);
    EPWM_setTimeBaseCounterMode(EPWM1_BASE, EPWM_COUNTER_MODE_UP);

    do {

        // Results
        adcAResults = ADC_readResult(ADCARESULT_BASE, ADC_SOC_NUMBER0); // voltage

        adcBResults = ADC_readResult(ADCBRESULT_BASE, ADC_SOC_NUMBER2); // current

        voltage_in = adcAResults * (3.3/4096);
        current_in = adcBResults * (3.3/4096);

        power_in = voltage_in * current_in;

        // clear interrupt flag
        ADC_clearInterruptStatus(ADCA_BASE, ADC_INT_NUMBER1);

        //
        // Acknowledge the interrupt
        //
        Interrupt_clearACKGroup(INTERRUPT_ACK_GROUP1);



    } while(1);

}




