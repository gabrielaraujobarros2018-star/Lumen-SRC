#include <animation.h>
#include <gui_module.h>

void anim_start(struct animation *a, int type) {
    a->type = type;
    a->time = 0;
    a->active = 1;
}

void anim_update(struct animation *a) {
    if (!a->active) return;

    a->time += frame_delta() * gui_anim_speed();
    if (a->time >= 1.0f)
        a->active = 0;
}