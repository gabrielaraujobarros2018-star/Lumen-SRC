#include "gui_api.hpp"

namespace palisade::gui::api {

void dispatch(GuiCommand cmd, uint64_t target) {
    switch (cmd) {
        case GuiCommand::CreateSurface: break;
        case GuiCommand::DestroySurface: break;
        case GuiCommand::Redraw: break;
        case GuiCommand::Focus: break;
    }
}

}