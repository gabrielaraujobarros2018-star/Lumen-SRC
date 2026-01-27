#include <stdio.h>
#include <time.h>

static time_t last_run = 0;

void weekly_tasks_run(void) {
    time_t now = time(NULL);
    if (now - last_run < 604800) return;

    printf("[automation] running weekly tests\n");
    printf("[automation] restarting drivers\n");

    last_run = now;
}