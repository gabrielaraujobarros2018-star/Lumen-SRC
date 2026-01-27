namespace palisade::gui::keyboard {

static bool pressed[256];

bool isPressed(int key) {
    return pressed[key];
}

}