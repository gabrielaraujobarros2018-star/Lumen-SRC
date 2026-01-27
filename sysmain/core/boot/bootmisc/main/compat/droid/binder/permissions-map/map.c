#include <stdint.h>
#include <string.h>

struct binder_permission {
    const char *service;
    uint32_t uid;
};

static struct binder_permission perm_table[] = {
    { "surfaceflinger", 1000 },
    { "media.audio_flinger", 1000 },
    { "telephony.registry", 1001 },
};

int binder_check_permission(const char *service, uint32_t uid) {
    for (unsigned i = 0; i < sizeof(perm_table)/sizeof(perm_table[0]); i++) {
        if (!strcmp(service, perm_table[i].service)) {
            return perm_table[i].uid == uid;
        }
    }
    return 0;
}