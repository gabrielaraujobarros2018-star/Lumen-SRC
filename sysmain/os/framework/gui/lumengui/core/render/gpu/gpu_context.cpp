namespace palisade::gui::render::gpu {

static bool initialized = false;

void init() {
    initialized = true;
}

bool ready() {
    return initialized;
}

}