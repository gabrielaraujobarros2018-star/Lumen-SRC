#include <pal_sys.h>

int pal_sys_read(const char *node, char *out) {
    if (!strcmp(node, "mem")) {
        return pal_dump_mem(out);
    }
    if (!strcmp(node, "sch")) {
        return pal_dump_sch(out);
    }
    return -1;
}