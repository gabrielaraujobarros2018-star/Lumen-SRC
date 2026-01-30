#include <stdint.h>

static char clipboard[256];
static int clip_len = 0;

void clipboard_copy(const char *src, int len) {
    for (int i = 0; i < len && i < 255; i++)
        clipboard[i] = src[i];
    clip_len = len;
}

int clipboard_size(void) {
    return clip_len;
}