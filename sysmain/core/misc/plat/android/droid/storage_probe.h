#pragma once
#include <stdint.h>

struct storage_layout {
    int has_ab;
    int has_dynamic;
};

int storage_probe(struct storage_layout *out);