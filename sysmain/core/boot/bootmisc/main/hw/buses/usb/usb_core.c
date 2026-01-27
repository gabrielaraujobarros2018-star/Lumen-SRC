#include <stdint.h>

static int usb_ready = 0;

void usb_init(void) {
    usb_ready = 1;
}

int usb_is_ready(void) {
    return usb_ready;
}