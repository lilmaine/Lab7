#include <msp430g2553.h>

int main(void)
{
  WDTCTL = WDTPW + WDTHOLD;                 // Stop WDT
  P1DIR |= 0x41;                            // Set P1.0 to output direction
  initiateSensors();

  for (;;)
  {

	leftSensorScan();
    if (ADC10MEM < 0x2ff)
      P1OUT &= ~0x01;                       // Clear P1.0 LED off
    else
      P1OUT |= 0x01;                        // Set P1.0 LED on
    _delay_cycles(300000);
	rightSensorScan();
    if (ADC10MEM < 0x1ff)
      P1OUT &= ~0x40;                       // Clear P1.0 LED off
    else
      P1OUT |= 0x40;                        // Set P1.0 LED on
    _delay_cycles(300000);

  }

    return 0;
}

// ADC10 interrupt service routine
#pragma vector=ADC10_VECTOR
__interrupt void ADC10_ISR(void)
{
  __bic_SR_register_on_exit(CPUOFF);        // Clear CPUOFF bit from 0(SR)
}
