Interrupt Handlers
===================

Interrupt handlers are the responsibility of the driver managing the hardware.

If the device uses interrupts, then driver must register one interrupt handler.

Registering an interrupt handler
=================================

Header File: <linux/interrupt.h>

int request_irq(unsigned int irq,
        irq_handler_t handler,
        unsigned long flags,
        const char *name,
        void *dev);

Parameters:
============

irq     --> The interrupt number being requested
            For some devices,for example legacy PC devices such as the system timer or keyboard, this value is typically hard-coded.
            For most other devices, it is probed or otherwise determined programmatically and dynamically.

handler   --> function pointer to the actual interrupt handler that services this interrupt.
              invoked whenever the operating system receives the interrupt
              typedef irqreturn_t (*irq_handler_t)(int, void *);

flags     --> bitmask of options related to interrupt management.

name      --> Name to be displayed in /proc/interrupts

dev       --> Used for shared Interrupt Lines

Return Value:
=============

Success  -->    Returns Zero
Failure  -->    Non-Zero Value

               
void free_irq(unsigned int irq_no, void *dev);

When the interrupt is released, using the free_irq() function, you must send the same pointer value (dev) along with the same interrupt number (irq_no).
