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
  Device_init();


}

