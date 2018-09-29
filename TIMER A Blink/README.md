Author: Joseph DiBenedetto,
Last Edited: 09/28/2018

# TIMER A Blink
This second part of the lab implemented another simple skill from the first lab, blinking two LEDs, and instead performs this task using timers instead of just delays in the code. Timers have many purposes that shoewhat resemble what has been done here, and they can also be used in different counting modes. In these codes the UP mode was used. 

# MSP430G2553
To begin this part of the lab, the direction of both LED pins are set to be outputs and they are initialized to an off state. On this board these pins were P1.0 and 1.6. Next, numerical values were loaded onto the capture/compare registers of timer A0 and A1 (TAxCCR0). This part of the lab requests that the LEDs are to blink at different rates, so a different value was loaded into each timer's CCR0. The CTL of each timer was used to set the counting mode to up and ACLK was selected as the reference clock (TAxCCTL0). Interrupts had to be enabled on both timers using CCTL0 as well. An optional task of this lab was to enable low power mode, which was with the following line of code:

_BIS_SR(LPM0_bits + GIE);

Finally, a #pragma vector was used again to tick the interrupt so the timer triggers it when it reaches its value and toggles the LED.

# MSP430F5529
The only difference between the boards used for this part of this lab were the pins of the LEDS. The previous board used P1.0 and 1.6 while this board used 1.0 and 4.7.
