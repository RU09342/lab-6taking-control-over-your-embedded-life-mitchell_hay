/*
 * Mitchell Hay and Shani Thapa
 * RU09342 - 4
 * Lab 6 - Precision Control PWM
 */

#include <msp430.h>
volatile unsigned int rx;

void main(void)
{
	// Clock Setup
	WDTCTL = WDTPW + WDTHOLD;                 	// Stop WDT
	TA0CCR0 = 255;                        		// PWM Period
	TA0CTL = TASSEL_2 + MC_1 + TACLR;         	// SMCLK, up mode, clear TAR

	// PWM Setup
	P1DIR |= BIT2;					// Set up Pin 1.2 as output
	P1SEL |= BIT2;					// Set Pin 1.2 to CCR1
	TA0CCTL1 = OUTMOD_7;                      	// CCR1 reset/set
	TA0CCR1 = 127;                            	// CCR1 PWM duty cycle

	// UART Setup
	P3SEL |= BIT3 + BIT4;                       	// P3.3,4 = USCI_A0 TXD/RXD
	UCA0CTL1 |= UCSWRST;                      	// **Put state machine in reset**
	UCA0CTL1 |= UCSSEL_1;                     	// ACLK
	UCA0BR0 = 3;                        		// 32726 MHz/3 = 9600 (see User's Guide)
	UCA0BR1 = 0;                              	// 1MHz 3
	UCA0MCTL |= UCBRS_3 + UCBRF_0;            	// Modulation UCBRSx=1, UCBRFx=0
	UCA0CTL1 &= ~UCSWRST;                   	// **Initialize USCI state machine**
	UCA0IE |= UCRXIE;                         	// Enable USCI_A0 RX interrupt

	__enable_interrupt();				// Enable Interrupts
	__bis_SR_register(LPM0 + GIE);       		// Enter LPM0, interrupts enabled
}


// Transmit and Receive Interrupts
#if defined(__TI_COMPILER_VERSION__) || defined(__IAR_SYSTEMS_ICC__)
#pragma vector=USCI_A0_VECTOR
__interrupt void USCI_A0_ISR(void)
#elif defined(__GNUC__)
void __attribute__ ((interrupt(USCI_A0_VECTOR))) USCI_A0_ISR (void)
#else
#error Compiler not supported!
#endif
{
	switch (__even_in_range(UCA0IV, 4)) {
	case 0:
		break;                             	// Vector 0 - no interrupt
	case 2:                                   	// Vector 2 - RXIFG
		while (!(UCA0IFG & UCTXIFG));
		rx = UCA0RXBUF;				// Hold received character
		TA0CCR1 = rx;
		break;
	case 4:
		break;
	default:
		break;
	}
}
