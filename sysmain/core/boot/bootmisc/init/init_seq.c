#include <init.h>

static const char *init_sequence[] = {
    "mm_init",
    "device_probe",
    "net_init",
    "input_init",
    "userland",
    NULL
};

int init_seq_execute(void) {
    for (int i = 0; init_sequence[i]; i++) {
        int ret = init_run_stage(init_sequence[i]);
        if (ret < 0)
            return ret;
    }
    return 0;
}