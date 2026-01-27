#include <stdint.h>

static uint32_t key_state = 0;

void key_press(uint32_t k) {
    key_state |= k;
}

void key_release(uint32_t k) {
    key_state &= ~k;
}

int key_down(uint32_t k) {
    return (key_state & k) != 0;
}

void key_reset(void) {
    key_state = 0;
}