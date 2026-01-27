#include <stdint.h>

static int sel_start = -1;
static int sel_end = -1;

void text_select_start(int p) {
    sel_start = p;
}

void text_select_end(int p) {
    sel_end = p;
}

int text_has_selection(void) {
    return sel_start >= 0 && sel_end >= 0;
}