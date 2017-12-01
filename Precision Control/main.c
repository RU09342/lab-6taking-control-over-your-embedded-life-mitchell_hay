#include <msp430.h>

 /*
 * LSB - P8.2
 * P3.7
 * P4.0
 * P4.3
 * P1.2
 * P1.3
 * P1.4
 * MSB - P1.5
 * */

volatile unsigned int voltage;

void DAC(int v);

int main(void)
{
	WDTCTL = WDTPW + WDTHOLD;                 // Stop WDT
	P1DIR |= BIT0;                            // P1.0 output
	TA0CCTL0 = CCIE;                             // CCR0 interrupt enabled
	TA0CTL = TASSEL_1 + MC_1;           // ACLK/8, upmode
	TA0CCR0 = 80;                              // 1.25 Hz

	P8DIR |= BIT2;
	P3DIR |= BIT7;
	P4DIR |= BIT0;
	P4DIR |= BIT3;
	P1DIR |= BIT2;
	P1DIR |= BIT3;
	P1DIR |= BIT4;
	P1DIR |= BIT5;

	P8OUT &= ~BIT2;
	P3OUT &= ~BIT7;
	P4OUT &= ~BIT0;
	P4OUT &= ~BIT3;
	P1OUT &= ~BIT2;
	P1OUT &= ~BIT3;
	P1OUT &= ~BIT4;
	P1OUT &= ~BIT5;

	__bis_SR_register(LPM0_bits + GIE);       // Enter LPM0 w/ interrupt
}

// Timer A0 Interrupt Service Routine
#if defined(__TI_COMPILER_VERSION__) || defined(__IAR_SYSTEMS_ICC__)
#pragma vector=TIMER0_A0_VECTOR
__interrupt void Timer_A (void)
#elif defined(__GNUC__)
void __attribute__ ((interrupt(TIMER0_A0_VECTOR))) Timer_A (void)
#else
#error Compiler not supported!
#endif
{
  DAC(voltage);
  voltage++;
}

void DAC(int v)
{
	if (v & 0b00000001)
		P8OUT |= BIT2;
	if (v & 0b00000010)
		P3OUT |= BIT7;
	if (v & 0b00000100)
		P4OUT |= BIT0;
	if (v & 0b00001000)
		P4OUT |= BIT3;
	if (v & 0b00010000)
		P1OUT |= BIT2;
	if (v & 0b00100000)
		P1OUT |= BIT3;
	if (v & 0b01000000)
		P1OUT |= BIT4;
	if (v & 0b10000000)
		P1OUT |= BIT5;

	if (!(v & 0b00000001))
		P8OUT &= ~BIT2;
	if (!(v & 0b00000010))
		P3OUT &= ~BIT7;
	if (!(v & 0b00000100))
		P4OUT &= ~BIT0;
	if (!(v & 0b00001000))
		P4OUT &= ~BIT3;
	if (!(v & 0b00010000))
		P1OUT &= ~BIT2;
	if (!(v & 0b00100000))
		P1OUT &= ~BIT3;
	if (!(v & 0b01000000))
		P1OUT &= ~BIT4;
	if (!(v & 0b10000000))
		P1OUT &= ~BIT5;

}
