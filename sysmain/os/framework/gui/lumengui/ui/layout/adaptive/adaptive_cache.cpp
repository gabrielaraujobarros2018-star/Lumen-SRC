namespace palisade::gui::layout::adaptive {

static bool cached = false;

void cacheLayout() {
    cached = true;
}

bool isCached() {
    return cached;
}

}