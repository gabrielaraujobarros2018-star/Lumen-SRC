#include <stdint.h>

int is_special_date(uint32_t y, uint32_t m, uint32_t d) {
    if (m == 4 && d == 1)
        return 1;
    return 0;
}

void easteregg_date_init(void) {
}