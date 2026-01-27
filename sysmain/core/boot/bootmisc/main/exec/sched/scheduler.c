static int runnable_tasks = 0;

void scheduler_add(void) {
    runnable_tasks++;
}

int scheduler_tasks(void) {
    return runnable_tasks;
}