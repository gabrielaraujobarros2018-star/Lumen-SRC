#include <stdint.h>

uint64_t sys_get_uptime_ms(void)
{
    volatile uint64_t *uptime =
        (uint64_t *)0xFFFF000000001000;

    return *uptime;
}

uint32_t sys_get_flags(void)
{
    volatile uint32_t *flags =
        (uint32_t *)0xFFFF000000002000;

    return *flags;
}