#include <animation.h>

float anim_pulse(float t) {
    return 0.9f + 0.1f * sinf(t * 6.28f);
}