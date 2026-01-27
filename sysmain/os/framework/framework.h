#ifndef PALISADE_FRAMEWORK_H
#define PALISADE_FRAMEWORK_H

#include <stdint.h>

typedef enum {
    FRAMEWORK_STATE_UNINITIALIZED = 0,
    FRAMEWORK_STATE_INITIALIZED,
    FRAMEWORK_STATE_FAILED,
    FRAMEWORK_STATE_DISABLED
} framework_state_t;

typedef struct framework {
    const char *name;
    uint32_t version;
    framework_state_t state;

    int  (*init)(void);
    void (*shutdown)(void);
    void (*panic)(void);
} framework_t;

int framework_register(framework_t *fw);
void framework_panic_all(void);

#endif