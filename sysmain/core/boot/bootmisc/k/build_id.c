#include "build_id.h"

struct build_identity {
    const char *build_id;
    const char *arch;
};

__attribute__((section(".rodata")))
const struct build_identity palisade_build_identity = {
    .build_id = PALISADE_BUILD_ID,
    .arch = PALISADE_ARCH
};