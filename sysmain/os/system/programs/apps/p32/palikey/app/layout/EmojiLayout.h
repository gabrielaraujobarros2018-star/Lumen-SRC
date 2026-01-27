#ifndef PALIKEY_EMOJI_LAYOUT_H
#define PALIKEY_EMOJI_LAYOUT_H

#include "KeyboardLayout.h"

class EmojiLayout : public KeyboardLayout {
public:
    EmojiLayout(int w, int h);
    void build() override;
};

#endif