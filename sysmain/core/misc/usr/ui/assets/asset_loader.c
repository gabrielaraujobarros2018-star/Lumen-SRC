#include <stdint.h>

static const char *asset_root = "/palisade/os/srv/framework-resourceX/assets";

const char *asset_path(const char *name) {
    static char buf[128];
    int i = 0;

    while (asset_root[i]) {
        buf[i] = asset_root[i];
        i++;
    }

    buf[i++] = '/';

    int j = 0;
    while (name[j] && i < 127) {
        buf[i++] = name[j++];
    }

    buf[i] = 0;
    return buf;
}
