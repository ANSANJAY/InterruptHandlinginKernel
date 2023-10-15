Keyboard Interrupt
====================

When a key is pressed, the keyboard controller informs PIC  to cause an interrupt.

IRQ #1 is the keyboard interrupt, so when a key is pressed, IRQ 1 is sent to the PIC. 

PIC tells the CPU an interrupt occurred.

When the CPU acknowledges the "interrupt occurred" signal, the PIC chip sends the interrupt number (between 00h and FFh, or 0 and 255 decimal) to the CPU.

For each key pressed on the keyboard, it generates two interrupts (pressed and release).



