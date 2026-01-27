#include "EmojiLayout.h"

EmojiLayout::EmojiLayout(int w, int h)
    : KeyboardLayout(w, h) {}

void EmojiLayout::build() {
    keyRects.clear();

    const char emojis[] = {
        0x01, 0x02, 0x03, 0x04, 0x05, 0
    };

    int count = 5;
    int kw = screenWidth / count;

    for (int i = 0; i < count; ++i) {
        KeyRect k;
        k.x = i * kw;
        k.y = 0;
        k.w = kw;
        k.h = rowHeight;
        k.symbol = emojis[i]; /* UTF mapping handled by renderer */
        keyRects.push_back(k);
    }
}