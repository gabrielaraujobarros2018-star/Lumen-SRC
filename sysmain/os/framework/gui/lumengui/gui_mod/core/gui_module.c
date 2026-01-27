#include <gui_module.h>

static struct gui_module modules[32];
static int module_count = 0;

int gui_register_module(const char *name,
                        void (*init)(void),
                        void (*update)(void)) {
    if (module_count >= 32)
        return -1;

    modules[module_count].name = name;
    modules[module_count].init = init;
    modules[module_count].update = update;
    module_count++;
    return 0;
}

void gui_init_all(void) {
    for (int i = 0; i < module_count; i++) {
        if (modules[i].init)
            modules[i].init();
    }
}

void gui_update_all(void) {
    for (int i = 0; i < module_count; i++) {
        if (modules[i].update)
            modules[i].update();
    }
}