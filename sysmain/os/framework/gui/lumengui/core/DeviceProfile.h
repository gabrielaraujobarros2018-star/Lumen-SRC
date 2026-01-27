#pragma once

enum class DeviceType {
    Phone,
    Desktop
};

struct DeviceProfile {
    DeviceType type;
    int width;
    int height;
    float dpi;
};