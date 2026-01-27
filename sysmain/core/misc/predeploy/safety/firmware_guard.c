#include <stdint.h>

int firmware_is_ambiguous(
    int has_uefi,
    int has_bios,
    int has_android
) {
    int count = has_uefi + has_bios + has_android;
    return count != 1;
}

void firmware_guard_or_die(int ambiguous) {
    if (ambiguous) {
        for (;;)
            asm volatile("hlt");
    }
}