#ifndef PROC_CONTROL_H
#define PROC_CONTROL_H

#include <sys/types.h>

#define PROC_FLAG_CRITICAL  0x01
#define PROC_FLAG_IMMORTAL  0x02
#define PROC_FLAG_HIDDEN    0x04

typedef struct {
    pid_t pid;
    char  name[64];
    int   flags;
} proc_entry_t;

int proc_spawn(const char *path, char *const argv[], int flags);
int proc_register(pid_t pid, const char *name, int flags);
void proc_watchdog_loop(void);

#endif