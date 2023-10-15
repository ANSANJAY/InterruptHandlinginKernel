#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/interrupt.h>
#include <linux/delay.h>

const unsigned char kbdus[128] =
{
    0,  27, '1', '2', '3', '4', '5', '6', '7', '8',	/* 9 */
  '9', '0', '-', '=', '\b',	/* Backspace */
  '\t',			/* Tab */
  'q', 'w', 'e', 'r',	/* 19 */
  't', 'y', 'u', 'i', 'o', 'p', '[', ']', '\n',	/* Enter key */
    0,			/* 29   - Control */
  'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';',	/* 39 */
 '\'', '`',   0,		/* Left shift */
 '\\', 'z', 'x', 'c', 'v', 'b', 'n',			/* 49 */
  'm', ',', '.', '/',   0,				/* Right shift */
  '*',
    0,	/* Alt */
  ' ',	/* Space bar */
    0,	/* Caps lock */
    0,	/* 59 - F1 key ... > */
    0,   0,   0,   0,   0,   0,   0,   0,
    0,	/* < ... F10 */
    0,	/* 69 - Num lock*/
    0,	/* Scroll Lock */
    0,	/* Home key */
    0,	/* Up Arrow */
    0,	/* Page Up */
  '-',
    0,	/* Left Arrow */
    0,
    0,	/* Right Arrow */
  '+',
    0,	/* 79 - End key*/
    0,	/* Down Arrow */
    0,	/* Page Down */
    0,	/* Insert Key */
    0,	/* Delete Key */
    0,   0,   0,
    0,	/* F11 Key */
    0,	/* F12 Key */
    0,	/* All other keys are undefined */
};

MODULE_LICENSE("GPL");
static int irq = 1,  dev = 0xaa;
#define KBD_DATA_REG        0x60    /* I/O port for keyboard data */
#define KBD_SCANCODE_MASK   0x7f
#define KBD_STATUS_MASK     0x80

static irqreturn_t keyboard_handler(int irq, void *dev)
{
	char scancode;
	scancode = inb(KBD_DATA_REG);
	pr_info("Character %c %s\n",
			kbdus[scancode & KBD_SCANCODE_MASK],
			scancode & KBD_STATUS_MASK ? "Released" : "Pressed");
        return IRQ_NONE;
}
/* registering irq */
static int test_interrupt_init(void)
{
        pr_info("%s: In init\n", __func__);
        return request_irq(irq, keyboard_handler, IRQF_SHARED,"my_keyboard_handler", &dev);
}

static void test_interrupt_exit(void)
{
        pr_info("%s: In exit\n", __func__);
        synchronize_irq(irq); /* synchronize interrupt */
        free_irq(irq, &dev);
}

module_init(test_interrupt_init);
module_exit(test_interrupt_exit);

