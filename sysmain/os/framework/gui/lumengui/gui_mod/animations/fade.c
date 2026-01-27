#include <animation.h>

float anim_fade(float t) {
    if (t < 0) return 0;
    if (t > 1) return 1;
    return t;
}