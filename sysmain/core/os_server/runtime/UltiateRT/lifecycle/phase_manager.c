#include <stdio.h>

typedef enum {
    PHASE_EARLY,
    PHASE_RUNTIME,
    PHASE_USER
} runtime_phase;

static runtime_phase current_phase;

void phase_set(runtime_phase p) {
    current_phase = p;
    printf("Runtime phase set: %d\n", p);
}

runtime_phase phase_get(void) {
    return current_phase;
}

void phase_manager_init(void) {
    phase_set(PHASE_EARLY);
}