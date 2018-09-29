/*
 * created by: joseph dibenedetto
 * created: 9/20/18
 * updated: 9/28/18
 */

#include <msp430.h> 
/**
 * main.c
 */

int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;   // disables watchdog timer


    P1OUT &= BIT1; // initializes states of pins
    P4OUT &= ~BIT7;
    P1DIR |= BIT0; // sets P1.0 and 4.7 as outputs
    P4DIR |= BIT7;
    P1REN |= BIT1; // sets P1.1 to be a pull-up resistor
    P1IE |= BIT1; // enables interrupt on button
    P1IES |= BIT1; // // enables "high to low" behavior on interrupt

    TA0CCR0 = 100; // sets frequency
    TA0CCTL0 = CCIE; // interrupt at CCTL enabled
    TA0CTL = TASSEL_1 +MC_1 + ID_3; // SMCLK selected // continuous enabled divider = 4

__enable_interrupt(); // enables interrupts
    while (1) // continuously runs interrupt
    {
    }
}

#pragma vector = TIMER0_A0_VECTOR // timer0 A0 interrupt service routine
    __interrupt void Timer0_A0 ()
    {
        P1OUT ^= BIT0; // toggles states of both LEDs
        P4OUT ^= BIT7;
    }

#pragma vector=PORT1_VECTOR // makes interrupt tick
__interrupt void Port_1(void)
{
    if (P1IES & BIT1)
    {
        TA0CTL = TACLR;
        TA0CTL = TASSEL_1 + MC_2 + ID_3;  //changes to continuous

        P1IES &= ~BIT1;
    }
    else
    {
        TA0CCR0 = TA0R;
        TA0CTL = TASSEL_1 + MC_1 + ID_3;  // changes to continuous
        P1IES |= BIT1;
    }
        P1IFG &= ~BIT1;
}
