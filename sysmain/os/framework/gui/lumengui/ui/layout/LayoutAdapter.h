#pragma once
#include "DeviceProfile.h"

struct LayoutMetrics {
    int columns;
    int dockSize;
    bool gestureNav;
};

class LayoutAdapter {
public:
    virtual LayoutMetrics metrics(const DeviceProfile&) = 0;
};