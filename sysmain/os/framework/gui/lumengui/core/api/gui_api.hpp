#pragma once
#include <stdint.h>

namespace palisade::gui::api {

enum class GuiCommand : uint32_t {
    CreateSurface,
    DestroySurface,
    Redraw,
    Focus
};

void dispatch(GuiCommand cmd, uint64_t target);

}