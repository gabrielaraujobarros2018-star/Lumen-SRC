#include <stdint.h>

static int last_status = 0;

void fetch_file(const char *p) {
    (void)p;
    last_status = 1;
}

int fetch_file_status(void) {
    return last_status;
}

void fetch_file_reset(void) {
    last_status = 0;
}