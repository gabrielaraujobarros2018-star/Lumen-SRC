#ifndef PALIKEY_KEYBOARD_LAYOUT_H
#define PALIKEY_KEYBOARD_LAYOUT_H

#include <vector>

struct KeyRect {
    int x;
    int y;
    int w;
    int h;
    char symbol;
};

class KeyboardLayout {
public:
    KeyboardLayout(int width, int height);
    virtual ~KeyboardLayout() = default;

    virtual void build() = 0;
    const std::vector<KeyRect>& keys() const;

protected:
    int screenWidth;
    int screenHeight;
    int rowHeight;
    std::vector<KeyRect> keyRects;
};

#endif