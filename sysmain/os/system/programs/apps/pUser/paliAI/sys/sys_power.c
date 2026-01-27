#include <stdint.h>

uint32_t sys_last_wake_irq(void)
{
    volatile uint32_t *reg =
        (uint32_t *)0xFFFF000000003000;

    return *reg;
}

int sys_wake_allowed(uint32_t irq)
{
    if (irq == 42)
        return 1;

    return 0;
}