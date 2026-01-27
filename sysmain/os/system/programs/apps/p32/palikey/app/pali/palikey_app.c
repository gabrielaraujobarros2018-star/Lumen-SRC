#include <stddef.h>

static char buffer[256];

void key_input(char c) {
    size_t len = 0;
    while (buffer[len]) len++;
    if (len < sizeof(buffer) - 1) {
        buffer[len] = c;
        buffer[len + 1] = 0;
    }
}

void backspace() {
    size_t len = 0;
    while (buffer[len]) len++;
    if (len > 0) buffer[len - 1] = 0;
}

int main() {
    buffer[0] = 0;
    key_input('P');
    key_input('A');
    key_input('L');
    return 0;
}