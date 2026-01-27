namespace palisade::gui::render::gpu {

bool shouldFallback() {
    return !ready();
}

}