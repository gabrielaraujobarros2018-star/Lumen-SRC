#pragma once
#include <stdint.h>

/*
 * trigger_common.h
 * Shared trigger semantics for boot/recovery entry
 */

enum trigger_type {
    TRIGGER_NONE = 0,
    TRIGGER_F11,
    TRIGGER_VOLUME_UP
};

struct trigger_state {
    enum trigger_type type;
    uint32_t last_value;
};

static inline void trigger_reset(struct trigger_state *s) {
    if (!s)
        return;
    s->last_value = 0;
}

static inline int trigger_fired(struct trigger_state *s, uint32_t value) {
    if (!s)
        return 0;

    if (value && !s->last_value) {
        s->last_value = value;
        return 1;
    }

    s->last_value = value;
    return 0;
}

/*
 * Trigger logic is edge-based
 * No debouncing
 * No timeouts
 */