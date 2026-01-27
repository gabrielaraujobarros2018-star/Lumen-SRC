#include <stdint.h>

static int fs_dirty = 0;

void fs_mark_dirty(void) {
    fs_dirty = 1;
}

void fs_clean(void) {
    fs_dirty = 0;
}

int fs_is_dirty(void) {
    return fs_dirty;
}

void fs_init(void) {
    fs_dirty = 0;
}