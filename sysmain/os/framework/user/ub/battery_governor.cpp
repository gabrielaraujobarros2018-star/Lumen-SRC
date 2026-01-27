#include "battery_governor.hpp"

namespace palisade::features::battery {

static bool ultra = false;

void enableUltraSaving(bool state) {
    ultra = state;
}

bool isUltraSaving() {
    return ultra;
}

}