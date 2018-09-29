Author: Joseph DiBenedetto,
Last Edit: 09/28/2018

# Button Interrupt
The first part of this lab required the use of interrupts to make a button blink an LED. By using an interrupt, the microcontroller does not constantly have to be searching for a value change from the button being pressed, and instead uses the board's peripherals to send a signal to the processor only when the button is pressed. This is a far more efficient method for the prcessor and is a big part of the reason these peripherals are on the board in the first place. 

# MSP430F5529
Just as one would blink an LED without using interrupts, the pin of the LED (P1.0) had to be set as an ouput, a pull-up resistor had to be enabled for the button (P1.1), and the button's state had to be initialized. New lines of code were added to enable the interrupt (P1IE) on the button's pin, and to also clear the interrupt so that the interrupt could be triggered when the button was actually pressed (P1IFG). The line of code that must be implemented to make interrupts tick on any board is as follows:

#pragma vector=PORT1_VECTOR
__interrupt void Port_1(void)

Inside of this crucial function, the state of the LED is toggled and the interrupt is once again cleared to wait on another button press.

# MSP430FR2311
The only difference when switching to this microcontroller from the previous in that this board's button pin is located at P1.3 instead of P1.1. These minor changes can be seen in the code.
