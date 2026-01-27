#include <stdio.h>

typedef struct {
    const char *name;
    int (*init)(void);
} driver_t;

static int dummy_init(void) {
    printf("driver initialized\n");
    return 0;
}

static driver_t drivers[] = {
    {"display", dummy_init},
    {"input", dummy_init},
    {"camera", dummy_init},
};

void drivers_init_all(void) {
    for (unsigned i = 0; i < sizeof(drivers)/sizeof(drivers[0]); i++) {
        drivers[i].init();
    }
}