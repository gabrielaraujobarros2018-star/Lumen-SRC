#include "emoji_registry.hpp"

namespace palisade::features::emoji {

static Emoji registry[256];
static int count = 0;

void registerEmoji(const Emoji& e) {
    if (count < 256) registry[count++] = e;
}

const Emoji* lookup(uint32_t codepoint) {
    for (int i = 0; i < count; ++i)
        if (registry[i].codepoint == codepoint)
            return &registry[i];
    return nullptr;
}

}