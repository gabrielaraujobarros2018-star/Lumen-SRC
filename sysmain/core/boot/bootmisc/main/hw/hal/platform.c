#include "platform.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>

static hal_platform_t detected_platform;

static int file_contains(const char *path, const char *needle) {
    FILE *f = fopen(path, "r");
    if (!f) return 0;
    char buf[256];
    while (fgets(buf, sizeof(buf), f)) {
        if (strstr(buf, needle)) {
            fclose(f);
            return 1;
        }
    }
    fclose(f);
    return 0;
}

void platform_detect(void) {
    if (access("/sys/class/android_usb", F_OK) == 0 ||
        file_contains("/proc/cpuinfo", "Qualcomm") ||
        file_contains("/proc/cpuinfo", "ARM")) {
        detected_platform = PLATFORM_PHONE;
    } else {
        detected_platform = PLATFORM_DESKTOP;
    }
}

hal_platform_t platform_get(void) {
    return detected_platform;
}