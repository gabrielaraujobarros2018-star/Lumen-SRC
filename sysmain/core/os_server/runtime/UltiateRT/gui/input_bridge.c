#include <stdio.h>

void input_event(const char *evt) {
    printf("Input event: %s\n", evt);
}

void input_bridge_init(void) {
    printf("Input bridge ready\n");
}