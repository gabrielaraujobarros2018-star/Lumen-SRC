#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include "palisade_ap.h"

static pid_t hostapd_pid = -1;

static int launch_hostapd(const char *conf_path)
{
    pid_t pid = fork();
    if (pid < 0) return -1;

    if (pid == 0) {
        execl("/usr/sbin/hostapd",
              "hostapd",
              "-dd",
              conf_path,
              NULL);
        _exit(1);
    }

    hostapd_pid = pid;
    return 0;
}

int palisade_start_ap_2ghz(void)
{
    return launch_hostapd("/palisade/os/wifi/wf_con/ap_2ghz.conf");
}

int palisade_start_ap_5ghz(void)
{
    return launch_hostapd("/palisade/os/wifi/wf_con/ap_5ghz.conf");
}

int palisade_stop_ap(void)
{
    if (hostapd_pid <= 0) return -1;

    kill(hostapd_pid, SIGTERM);
    waitpid(hostapd_pid, NULL, 0);
    hostapd_pid = -1;
    return 0;
}