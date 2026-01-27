#include <palikey.h>

static struct palikey_state state;

void palikey_init(void) {
    state.layout = PALIK_LAYOUT_DEFAULT;
    state.shift = 0;
    state.alt = 0;
}

char palikey_translate(int keycode) {
    if (state.shift)
        return palikey_shift_map(keycode);

    return palikey_base_map(keycode);
}

void palikey_set_modifier(int mod, int on) {
    if (mod == PALIK_SHIFT) state.shift = on;
    if (mod == PALIK_ALT) state.alt = on;
}