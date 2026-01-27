#pragma once
#include <string>

namespace palisade::features::emoji {

struct Emoji {
    uint32_t codepoint;
    std::string name;
};

void registerEmoji(const Emoji& e);
const Emoji* lookup(uint32_t codepoint);

}