#include <popup.h>
#include <animation.h>

void popup_show(struct popup *p) {
    p->visible = 1;
    anim_start(&p->anim, ANIM_FADE_IN);
}

void popup_hide(struct popup *p) {
    anim_start(&p->anim, ANIM_FADE_OUT);
}

void popup_render(struct popup *p) {
    if (!p->visible)
        return;

    anim_update(&p->anim);
    draw_panel(p->x, p->y, p->w, p->h, p->anim.alpha);
}