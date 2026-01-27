namespace palisade::gui::input {

static int focusedSurface = -1;

void setFocus(int id) {
    focusedSurface = id;
}

int currentFocus() {
    return focusedSurface;
}

}