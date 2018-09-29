Author: Joseph DiBenedetto,
Last Edited: 09/28/2018

# Button Based Delay
This part of the lab combined our understanding of the previous parts of this lab as well as the previous lab and made things slightly more challenging. The task was to initialize a blink on the LED of the microcontroller, and then by pressing a button down for a certain period of time, the LED's blinking rate was to match the duration of this button hold. Interrupts from the timer module and from the button were enabled to make this possible. 

# MSP430G2553
Once again the LED pins on the boards were set to the output direction, they were intialized to be off, and a pull-up resistor was enabled for the button. Interrupts also had to be enabled on the button pin once again, and hi/lo behavior had to be enabled with the PXIES register. This had to be enabled for detection of the button's hold being released and therefore changing states. A timer was loaded with a frequency with CCR once again and CCTL was used to choose UP mode. For this part a while loop had to be implemented to make the interrupt continuous during the button's hold. #pragma vectors once again were used, but this time for both the interrupts on the button and timer peripheral. An if/else statemnent timed the button press, determining what to set the LED's rate at. 

# MSP430F5529
The difference between the boards used were slightly greater here than in the previous two parts of the lab. Not only did the pin of the button change from 1.3 on the previous board to 1.1 on this board, but the registers of the timer on the G2553 were CCR0, CCR0, and TACTL, while this board used TA0CCR0, TA0CCTL0, and TA0CTL. One final difference is that the G2 used SMCLK while this board used ACLK.
