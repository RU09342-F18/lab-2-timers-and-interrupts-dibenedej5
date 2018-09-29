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
    BCSCTL3 = LFXT1S_2; // makes ACLK use an internal oscillator instead of external

    P1DIR |= 0X41; // sets P1.0 and 1.6 as outputs
    P1REN |= BIT3; // sets P1.3 to be a pull-up resistor
    P1OUT |= BIT3; // initializes states of pins
    P1OUT |= 0X01;

    P1IE |= BIT3;  // enables interrupt on the button
    P1IES |= BIT3; // enables "high to low" behavior on interrupt

    CCTL0 = CCIE; // CCR0 interrupt enabled
    CCR0 =  100; // sets frequency

    TACTL = TASSEL_1 + MC_1+ID_3; // SMCLK selected // continuous enabled divider = 4

__enable_interrupt(); //enables interrupts
    while (1) // continuously runs interrupt
    {
    }
}

#pragma vector = TIMER0_A0_VECTOR // timer0 A0 interrupt service routine
    __interrupt void Timer_A ()
    {
        P1OUT ^= 0X41; // toggles state

    }

#pragma vector=PORT1_VECTOR // makes interrupt tick
__interrupt void Port_1(void)
{
    if (P1IES & BIT3)
    {
        TACTL = TACLR;
        TACTL = TASSEL_1 + MC_2 + ID_3;  // change to continuous

        P1IES &= ~BIT3;
    }
    else
    {
        CCR0 = TA0R;
        TACTL = TASSEL_1 + MC_1 + ID_3;  // change to continuous
        P1IES |= BIT3;
    }
        P1IFG &= ~BIT3;
}
