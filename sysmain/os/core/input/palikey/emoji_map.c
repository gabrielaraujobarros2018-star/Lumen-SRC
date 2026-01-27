#include <palikey.h>

static const char *emoji_table[] = {
    ":smile:", "😀",
    ":fire:",  "🔥",
    ":heart:", "❤️",
    ":skull:", "💀",
    NULL
};

const char *emoji_lookup(const char *token) {
    for (int i = 0; emoji_table[i]; i += 2) {
        if (!strcmp(emoji_table[i], token))
            return emoji_table[i + 1];
    }
    return NULL;
}