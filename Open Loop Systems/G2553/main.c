/*
 * Mitchell Hay and Shani Thapa
 * RU 09342 - Lab 6
 * Open Loop System
 * MSP430G2553
 */

#include <msp430.h>

unsigned volatile int fan;
unsigned volatile int adcIn;

void Clock();
void GPIO();
void UART();
void ADC();

int main(void)
{
	WDTCTL = WDTPW + WDTHOLD; // Stop the Watch dog

	// Initialization
	Clock();
	GPIO();
	UART();
	ADC();

	while (1)
	{
	    	ADC10CTL0 |= ENC + ADC10SC;             // Sampling and conversion start
	    	__bis_SR_register(CPUOFF + GIE);        // LPM0, ADC10_ISR will force exit
		adcIn = ADC10MEM;
	}
}


// Transmit Interrupt
#pragma vector = USCIAB0TX_VECTOR
__interrupt void TransmitInterrupt(void) {
	# Send out data one digit at a time
	while(adcIn != 0)
	{
		while (!(UCA0IFG & UCTXIFG));
		UCA0TXBUF = adcIn % 10;
		adcIn /= 10;
	}
	# Send out newline character to indicate ADC reading is done
	while (!(UCA0IFG & UCTXIFG));
	UCA0TXBUF = '\n';
}

// Receive Interrupt
#pragma vector = USCIAB0RX_VECTOR
__interrupt void ReceiveInterrupt(void) {
	// Read in PWM, set it to CCR1
	fan = UCA0RXBUF;
	CCR1 = 10*fan;
	IFG2 &= ~UCA0RXIFG; // Clear RX flag
}


// ADC10 interrupt service routine
#if defined(__TI_COMPILER_VERSION__) || defined(__IAR_SYSTEMS_ICC__)
#pragma vector=ADC10_VECTOR
__interrupt void ADC10_ISR(void)
#elif defined(__GNUC__)
void __attribute__ ((interrupt(ADC10_VECTOR))) ADC10_ISR (void)
#else
#error Compiler not supported!
#endif
{
  __bic_SR_register_on_exit(CPUOFF);        // Clear CPUOFF bit from 0(SR)
}

// Clock init
void Clock()
{
	// Configure Clocks
	if (CALBC1_1MHZ == 0xFF)   // If calibration constant erased
	{
		while (1);          // do not load, trap CPU!!
	}
	DCOCTL = 0;             // Select lowest DCOx and MODx settings
	BCSCTL1 = CALBC1_1MHZ;   // Set range
	DCOCTL = CALDCO_1MHZ;   // Set DCO step + modulation
}

// GPIO init
void GPIO()
{
	P1SEL |= BIT1 + BIT2;  // P1.1 UCA0RXD input
	P1SEL2 |= BIT1 + BIT2;  // P1.2 UCA0TXD output
	P1DIR |= BIT2;         // P1.2 PWM Output
	P1SEL |= BIT2;         // P1.2 for TA0.1 output
	P1SEL2 = 0;			   //Select default function for P1.2
	CCR0 = 1000;        // PWM Period
	CCTL1 = OUTMOD_7;      // CCR1 reset/set
	CCR1 = 0;            // CCR1 PWM duty cycle
	TACTL = TASSEL_2 + MC_1;    // SMCLK, up mode
}

// UART init
void UART()
{
	UCA0CTL1 |= UCSSEL_2 + UCSWRST;  // USCI Clock = SMCLK,USCI_A0 disabled
	UCA0BR0 = 104;                 // 104 From datasheet table-
	UCA0BR1 = 0;                   // -selects baudrate =9600,clk = SMCLK
	UCA0MCTL = UCBRS_1;             // Modulation value = 1 from datasheet
	UCA0CTL1 &= ~UCSWRST;             // Clear UCSWRST to enable USCI_A0
	IE2 |= UCA0TXIE;                  // Enable the Transmit interrupt
	IE2 |= UCA0RXIE;                  // Enable the Receive  interrupt
}

// ADC init
void ADC()
{
	ADC10CTL0 = ADC10SHT_2 + ADC10ON + ADC10IE; // ADC10ON, interrupt enabled
	ADC10CTL1 = INCH_1;                       // input A1
	ADC10AE0 |= 0x02;                         // PA.1 ADC option select
}
