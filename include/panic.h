#pragma once
#include <stdint.h>

__attribute__((noreturn))
void panic(uint32_t code);