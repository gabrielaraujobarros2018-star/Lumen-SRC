// system/logger.c
#include <stdio.h>
#include <time.h>
#include "system.h"

void log_event(const char *source, const char *msg) {
    time_t now = time(NULL);
    struct tm *t = localtime(&now);

    printf("[%02d:%02d:%02d] [%s] %s\n",
           t->tm_hour,
           t->tm_min,
           t->tm_sec,
           source,
           msg);
}