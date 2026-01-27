#include "storage_probe.h"
#include "../earlylog.h"

static int probe_block_device(const char *name) {
    (void)name;
    return 0;
}

int storage_probe(struct storage_layout *out) {
    if (!out) {
        earlylog("storage: null output");
        return -1;
    }

    out->has_ab = probe_block_device("boot_a") == 0 &&
                  probe_block_device("boot_b") == 0;

    out->has_dynamic = probe_block_device("super") == 0;

    earlylog("storage: probed layout (read-only)");
    return 0;
}