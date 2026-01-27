#ifndef PALIKEY_KEY_WIDGET_H
#define PALIKEY_KEY_WIDGET_H

#include "../layout/KeyboardLayout.h"

class KeyWidget {
public:
    KeyWidget(const KeyRect& rect);
    bool hitTest(int px, int py) const;
    char symbol() const;

    int x() const;
    int y() const;
    int width() const;
    int height() const;

private:
    KeyRect geometry;
};

#endif