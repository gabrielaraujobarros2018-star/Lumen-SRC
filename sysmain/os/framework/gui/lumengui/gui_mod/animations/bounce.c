#include <animation.h>

float anim_bounce(float t) {
    return 1.0f - fabsf(sinf(6.28f * t)) * (1.0f - t);
}