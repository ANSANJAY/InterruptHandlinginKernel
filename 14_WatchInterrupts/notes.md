Watch Interrupts
================

To see the interrupts occurring on your system, run the command:

# watch -n1 "cat /proc/interrupts"

The watch command executes another command periodically, in this case "cat /proc/interrupts"

The -n1 option tells watch to execute the command every second

-d option of watch highlight  the  differences  between successive updates

# watch -n 0.1 -d 'cat /proc/interrupts'

--no-title / -t option of watch Turn off the header showing the interval, command, and current time at the top of the display, as well as the following blank line.

# watch -n 0.1 -d --no-title 'cat /proc/interrupts'



