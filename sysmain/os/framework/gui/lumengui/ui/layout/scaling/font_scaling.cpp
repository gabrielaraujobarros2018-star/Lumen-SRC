namespace palisade::gui::layout::scaling {

int scaleFont(int size, float factor) {
    return static_cast<int>(size * factor);
}

}