/proc/interrupts
==================

Contains statistics related to interrupts on the system

           CPU0       CPU1       CPU2       CPU3       CPU4       CPU5       
   0:          2          0          0          0          0          0   IO-APIC    2-edge      timer
   1:        458          0          0          0       6154          0   IO-APIC    1-edge      i8042
   8:          0          0          0          0          0          1   IO-APIC    8-edge      rtc0
   9:          0          0          0          0          0          0   IO-APIC    9-fasteoi   acpi
  12:          0          0          0      22185          0          0   IO-APIC   12-edge      i8042
  14:          0          0          0          0          0          0   IO-APIC   14-edge      ata_piix
  15:          0          0          0          0          0          0   IO-APIC   15-edge      ata_piix
  16:          0      19541          0          0          0          0   IO-APIC   16-fasteoi   vmwgfx, snd_ens1371
  17:       9825          0      47519          0          0          0   IO-APIC   17-fasteoi   ehci_hcd:usb1, i

Column 1:  IRQ number
            the file shows only interrupts corresponding to installed handlers

Column 2:  counter of the number of interrupts received.
           A column is present for each processor on the system

Column 3/4: Type of the interrupt and device that handles the interrupt.
            For x86.
            XT-PIC — This is the old AT computer interrupts. 8259
            IO-APIC 

Column 5:  device associated with this interrupt
            This name is supplied by the devname parameter to request_irq(),
            


Difference between  IO-APIC-fasteoi and IO-APIC-edge?
----------------------------------------------------

The difference lies in the way the interrupts are triggered.

The -edge interrupt are edge triggered.
The -fasteoi interrupts are level interrupts that are triggered until the interrupt event is acknowledged in the programmable interrupt controller (PIC). 
The EOI stands for End Of Interrupt.
