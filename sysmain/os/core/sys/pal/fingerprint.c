#include <pal_sys.h>

static const char fingerprint[] =
    "PalisadeOS-1.0.6-20260125-snapshot";

const char *pal_build_fp(void) {
    return fingerprint;
}