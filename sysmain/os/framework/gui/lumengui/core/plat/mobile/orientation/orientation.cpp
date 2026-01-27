namespace palisade::gui::platform::mobile {

static int orientation = 0;

void setOrientation(int o) {
    orientation = o;
}

int getOrientation() {
    return orientation;
}

}