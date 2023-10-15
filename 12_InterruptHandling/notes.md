Interrupt Handling in Linux Kernel
===================================

1. Whenever an interrupt occurs, assembly instructions in linux kernel are executed, which
	locates relevant vector descriptor by multiplying reported vector number by size of vector number(8/16)
	and adding the result to the base address of IDT.

2. common_interrupt: arch/x86/entry/entry_64.S:
	a. saves the context of the running process
	b. This includes instruction pointer (IP), stack pointer and other registers needed to resume the process again
	c. This context is usually saved on the stack.
	d. Then the context is changed to interrupt stack. 

2. Finally it arrives at do_IRQ(). do_IRQ() is the common function for all hardware interrupts

	arch/x86/kernel/irq.c

3. Finds IRQ number in saved %EAX register

4. Calls handle_irq which will finally call our registered interrupt handler.

