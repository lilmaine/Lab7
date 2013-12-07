#include "robot.h"
#include <msp430g2553.h>
/*
 * robot.c
 *
 *  Created on: Dec 6, 2013
 *      Author: C15Tramaine.Barnett
 */


void initiateSensors(){
	  ADC10CTL0 = ADC10SHT_3 + ADC10ON + ADC10IE; // ADC10ON, interrupt enabled
	  ADC10CTL1 |= ADC10DIV2;                // Select SMCLK

}

int leftSensorScan(){
	  ADC10CTL0 &= ~ENC;             // Sampling and conversion start
	  ADC10CTL1 = INCH_4;                       // input A4
	  ADC10AE0 |= BIT4;                         // PA.1 ADC option select
	  ADC10CTL0 |= ENC + ADC10SC;             // Sampling and conversion start
	  __bis_SR_register(CPUOFF + GIE);        // LPM0, ADC10_ISR will force exit
	  return ADC10MEM;
}

int rightSensorScan(){
	  ADC10CTL0 &= ~ENC;             // Sampling and conversion start
	  ADC10CTL1 = INCH_5;                       // input A4
	  ADC10AE0 |= BIT5;                         // PA.1 ADC option select
	  ADC10CTL0 |= ENC + ADC10SC;             // Sampling and conversion start
	  __bis_SR_register(CPUOFF + GIE);        // LPM0, ADC10_ISR will force exit
	  return ADC10MEM;
}

int centerSensorScan(){
	  ADC10CTL0 &= ~ENC;             // Sampling and conversion start
	  ADC10CTL1 = INCH_3;                       // input A4
	  ADC10AE0 |= BIT3;                         // PA.1 ADC option select
	  ADC10CTL0 |= ENC + ADC10SC;             // Sampling and conversion start
	  __bis_SR_register(CPUOFF + GIE);        // LPM0, ADC10_ISR will force exit
	  return ADC10MEM;
}
