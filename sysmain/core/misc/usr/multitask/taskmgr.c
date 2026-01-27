#include <stdint.h>

#define MAX_TASKS 32

static uint32_t tasks = 0;

int task_spawn(void) {
    if (tasks >= MAX_TASKS) return -1;
    tasks++;
    return tasks;
}

int task_count(void) {
    return tasks;
}

void task_kill(void) {
    if (tasks > 0) tasks--;
}