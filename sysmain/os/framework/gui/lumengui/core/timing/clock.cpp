#include "clock.hpp"

namespace palisade::gui::time {

uint64_t now() {
    static uint64_t t = 0;
    return ++t;
}

}