#ifndef PALIKEY_QWERTY_LAYOUT_H
#define PALIKEY_QWERTY_LAYOUT_H

#include "KeyboardLayout.h"

class QwertyLayout : public KeyboardLayout {
public:
    QwertyLayout(int width, int height);
    void build() override;

private:
    void addRow(const char* row, int yOffset, int keyCount);
};

#endif