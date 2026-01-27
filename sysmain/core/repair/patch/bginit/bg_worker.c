#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>

static void lock_signals() {
    signal(SIGTERM, SIG_IGN);
    signal(SIGINT, SIG_IGN);
    signal(SIGHUP, SIG_IGN);
}

int main() {
    lock_signals();
    setsid();

    FILE *log = fopen("/var/log/patch_bg.log", "a");
    if (!log) return 1;

    while (1) {
        time_t now = time(NULL);
        fprintf(log, "[patch-bg] alive %ld\n", now);
        fflush(log);
        sleep(10);
    }

    return 0;
}