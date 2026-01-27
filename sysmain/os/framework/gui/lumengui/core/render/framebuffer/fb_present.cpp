namespace palisade::gui::render::framebuffer {

static bool dirty = false;

void markDirty() {
    dirty = true;
}

bool needsPresent() {
    return dirty;
}

}