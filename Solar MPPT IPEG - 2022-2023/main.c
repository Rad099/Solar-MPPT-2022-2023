/**
 * main.c
 *
 * Ridwan Alrefai - 2022
 * University of Illinois Chicago
 * Intelligent Power Electronics Laboratory - Chicago
 *
 */

#include "driverlib.h"
#include "device.h"
#include "adcConfig.h"


// MPPT Variables
float current_in;
float current_out;
float voltage_in;
float voltage_out;
float power_in;
float power_out;
float prev_power_in;
float prev_power_out;


int main(void)
{


    //
    // Initialize device clock and peripherals
    //
    Device_init();

    //
    // Initialize GPIO and configure the GPIO pin as a push-pull output
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

    //
    // Initialize ADC configurations for ADCA and ADCB
    //
    configureADC(ADCA_BASE);
    configureADC(ADCD_BASE);

    //
    // Setup continuous ADC
    //
    continuousADCConfig(ADCA_BASE, 0U);
    continuousADCConfig(ADCA_BASE, 1U);









    //
    // Loop Forever
    //


}

