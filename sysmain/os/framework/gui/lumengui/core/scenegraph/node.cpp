#include "node.hpp"

namespace palisade::gui::scene {

Node createNode(uint64_t id) {
    return {id, 0, 0};
}

}