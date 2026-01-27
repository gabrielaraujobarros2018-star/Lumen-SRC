#ifndef PALIKEY_SYMBOL_LAYOUT_H
#define PALIKEY_SYMBOL_LAYOUT_H

#include "KeyboardLayout.h"

class SymbolLayout : public KeyboardLayout {
public:
    SymbolLayout(int w, int h);
    void build() override;
};

#endif