#include <stdint.h>

namespace palisade::gui::api {

uint64_t allocateHandle() {
    static uint64_t next = 1;
    return next++;
}

}