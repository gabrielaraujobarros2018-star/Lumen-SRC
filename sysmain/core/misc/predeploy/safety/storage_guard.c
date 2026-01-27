#include <stdint.h>

static int layout_known;
static int allow_write;

void storage_detect_layout(int known) {
    layout_known = known;
    allow_write = 0;
}

int storage_request_write(void) {
    if (!layout_known)
        return -1;
    allow_write = 1;
    return 0;
}

int storage_is_readonly(void) {
    return !allow_write;
}