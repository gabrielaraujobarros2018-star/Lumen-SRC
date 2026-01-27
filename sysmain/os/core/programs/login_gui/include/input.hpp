#pragma once
#include <stdint.h>

struct InputEvent {
    bool pressed;
    uint32_t key;
};

class Input {
public:
    Input();
    bool poll(InputEvent& ev);
};