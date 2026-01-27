#include <stdio.h>

int camera_open(void) {
    printf("camera opened\n");
    return 0;
}

int camera_capture(void) {
    printf("frame captured\n");
    return 0;
}

void camera_close(void) {
    printf("camera closed\n");
}