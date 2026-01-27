#pragma once
#include <stdint.h>

namespace palisade::gui::compositor {

void submitLayer(uint64_t surfaceId);
void composeFrame();

}