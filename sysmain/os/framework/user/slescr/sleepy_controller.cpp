#include "sleepy_controller.hpp"

namespace palisade::features::sleepy {

static bool armed = false;

void armSleepTimer() {
    armed = true;
}

void cancelSleep() {
    armed = false;
}

}