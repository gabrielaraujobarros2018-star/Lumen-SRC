#include "KeyWidget.h"

KeyWidget::KeyWidget(const KeyRect& rect)
    : geometry(rect) {}

bool KeyWidget::hitTest(int px, int py) const {
    return px >= geometry.x &&
           px <= geometry.x + geometry.w &&
           py >= geometry.y &&
           py <= geometry.y + geometry.h;
}

char KeyWidget::symbol() const {
    return geometry.symbol;
}

int KeyWidget::x() const { return geometry.x; }
int KeyWidget::y() const { return geometry.y; }
int KeyWidget::width() const { return geometry.w; }
int KeyWidget::height() const { return geometry.h; }