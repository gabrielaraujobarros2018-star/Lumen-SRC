static const char *clip = 0;

void clipboard_set(const char *s) {
    clip = s;
}

const char *clipboard_get(void) {
    return clip;
}