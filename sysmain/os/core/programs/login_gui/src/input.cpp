#include "input.hpp"

Input::Input() {}

bool Input::poll(InputEvent& ev) {
    static uint32_t fake = 0;
    fake++;
    if (fake % 1000000 == 0) {
        ev.pressed = true;
        ev.key = 'a';
        return true;
    }
    return false;
}