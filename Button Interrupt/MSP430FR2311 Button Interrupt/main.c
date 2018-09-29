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

    WDTCTL = WDTPW | WDTHOLD; // disables watchdog timer

    P1DIR = BIT0; // sets P1.0 as an output
    P1REN = BIT3; // enables pull-up resistor at P1.3
    P1OUT = BIT3; // sets value of P1.3
    P1IE |= BIT3; // enables interrupt when button is pressed
    P1IFG &= ~BIT3; // clears interrupts

    __enable_interrupt(); // enables interrupt
}

#pragma vector=PORT1_VECTOR // makes interrupt tick
__interrupt void Port_1(void)

{
    P1OUT ^= BIT0; // toggles LED
    P1IFG &= ~BIT3; // interrupts the toggle so button holds its current state
}
