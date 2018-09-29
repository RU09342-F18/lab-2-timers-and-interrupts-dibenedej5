/*
 * created by: joseph dibenedetto
 * created: 9/20/18
 * updated: 9/28/18
 */

#include <msp430.h>
/**
 * main.c
 */

void main(void)
{
  WDTCTL = WDTPW + WDTHOLD; // disables watchdog timer

  P1DIR |= BIT0; // sets P1.0 to an output
  P1OUT &= ~BIT0; // initializes red LED as off
  P4DIR |= BIT7; // sets P1.6 to an output
  P4OUT &= ~BIT7; // initializes green LED as off

  TA0CCR0 = 12000; // 16 bit count limits
  TA1CCR0 = 24000;
  TA0CCTL0 = 0x10; // enables timer A0 and A1 interrupts
  TA1CCTL0 = 0x10;
  TA0CTL = TASSEL_1 + MC_1; // timer A0 with ACLK, count UP
  TA1CTL = TASSEL_1 + MC_1; // timer A1 with ACLK, count UP

  _BIS_SR(LPM0_bits + GIE); // enables LPM0 (low power mode) interrupts
}

#pragma vector=TIMER0_A0_VECTOR // timer0 A0 interrupt service routine
__interrupt void Timer0_A0 (void)
{
   P4OUT ^= BIT7; // toggles green LED
}


#pragma vector=TIMER1_A0_VECTOR  // timer1 A0 interrupt service routine
__interrupt void Timer1_A0 (void)
{
      P1OUT ^= BIT0; // toggles red LED
}
