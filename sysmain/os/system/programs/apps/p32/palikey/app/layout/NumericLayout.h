#ifndef PALIKEY_NUMERIC_LAYOUT_H
#define PALIKEY_NUMERIC_LAYOUT_H

#include "KeyboardLayout.h"

class NumericLayout : public KeyboardLayout {
public:
    NumericLayout(int w, int h);
    void build() override;

private:
    void addRow(const char* row, int y);
};

#endif