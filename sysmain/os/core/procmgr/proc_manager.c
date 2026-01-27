#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <sys/wait.h>
#include "proc_control.h"

#define MAX_PROCS 32

static proc_entry_t proc_table[MAX_PROCS];
static int proc_count = 0;

static void die_if_not_root() {
    if (getuid() != 0) {
        fprintf(stderr, "procManager: root required\n");
        exit(1);
    }
}

int proc_register(pid_t pid, const char *name, int flags) {
    if (proc_count >= MAX_PROCS) return -1;

    proc_table[proc_count].pid = pid;
    strncpy(proc_table[proc_count].name, name, 63);
    proc_table[proc_count].flags = flags;
    proc_count++;
    return 0;
}

int proc_spawn(const char *path, char *const argv[], int flags) {
    pid_t pid = fork();

    if (pid == 0) {
        setsid();
        execv(path, argv);
        _exit(1);
    }

    if (pid > 0) {
        proc_register(pid, path, flags);
        return pid;
    }

    return -1;
}

static void respawn(int index) {
    char *args[] = { proc_table[index].name, NULL };
    proc_table[index].pid = proc_spawn(
        proc_table[index].name,
        args,
        proc_table[index].flags
    );
}

void proc_watchdog_loop() {
    while (1) {
        for (int i = 0; i < proc_count; i++) {
            if (kill(proc_table[i].pid, 0) != 0) {
                if (proc_table[i].flags & PROC_FLAG_IMMORTAL) {
                    respawn(i);
                }
            }
        }
        sleep(1);
    }
}

int main() {
    die_if_not_root();
    signal(SIGCHLD, SIG_IGN);
    proc_watchdog_loop();
    return 0;
}