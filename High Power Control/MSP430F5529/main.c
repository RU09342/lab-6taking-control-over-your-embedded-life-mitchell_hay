#include <msp430.h>

int main(void)
{
  WDTCTL = WDTPW + WDTHOLD;                 // Stop WDT
  P1DIR |= BIT2+BIT3;                       // P1.2 and P1.3 output
  P1SEL |= BIT2+BIT3;                       // P1.2 and P1.3 options select
  TA0CCR0 = 64000;                          // PWM Period
  TA0CCTL1 = OUTMOD_7;                      // CCR1 reset/set
  TA0CCR1 = 32000;                            // CCR1 PWM duty cycle
  TA0CTL = TASSEL_1 + MC_1 + TACLR;         // ACLK, up mode, clear TAR

  __bis_SR_register(LPM0_bits);             // Enter LPM0
}
