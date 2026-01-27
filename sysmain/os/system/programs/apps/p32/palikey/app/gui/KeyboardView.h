#ifndef PALIKEY_KEYBOARD_VIEW_H
#define PALIKEY_KEYBOARD_VIEW_H

#include <vector>
#include "../layout/KeyboardLayout.h"
#include "KeyWidget.h"

class KeyboardView {
public:
    KeyboardView(KeyboardLayout& layout);
    void build();
    char handleTouch(int x, int y);

    const std::vector<KeyWidget>& widgets() const;

private:
    KeyboardLayout& layoutRef;
    std::vector<KeyWidget> keys;
};

#endif