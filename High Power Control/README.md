# Lab 6: "High Power" Control
## Shani Thapa, Mitchell Hay
* Populated README on 11/21

### Software Dependencies
The code was extremely simple. We set the a timer's CCR0 to a period, then simply have CCR1 to have half that value to get a PWM on one of the GPIO pins. Then that can be output to the circuit for switching.  
```
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
```

### Relay Switching 
The Relay used for this lab was the MAD-12V-C, automotive relay. It required 12V to operate. The relay drew around 9.6-9.8V and went down as the frequency was increased. The current draw increased when the frequency went down ranging from 90mA-130mA from 2Hz-0.6Hz. Once the frequency was over 100Hz the switching became unstable and eventually stops working. 

### Mosfet Switching 
We had to build Low Side and a High Side using an NMOS and a PMOS. The circuit is very simple for both with some minor differences. The LSS uses an NMOS with the load connected to the Drain of the mosfet. Meanwhile, the HSS uses a PMOS with the load also connected to Drain. The gate on both are connected to the micro-contorller. Then the source is connected to ground, and some resisters are placed to limit current. The schematics are below. 

![Alt text](https://user-images.githubusercontent.com/31711430/33403750-9410471c-d52f-11e7-9760-08b14539a200.PNG)

#### Examples
Below are the gifs of the mosfet swiching actuated through LEDs.

![Alt text](https://user-images.githubusercontent.com/31711430/33402326-34781f8c-d52a-11e7-8809-f35d6e29d003.gif)

## Tasks
* [x] Write a program for the MSP430 to generate a square wave
* [x] Implement a switching circuit using a relay
* [x] Implement a switching circuit using MOSFETs
