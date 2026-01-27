namespace palisade::gui::layout::adaptive {

static int screenClass = 0;

void evaluate(int width, int height) {
    screenClass = (width > height) ? 1 : 2;
}

int currentClass() {
    return screenClass;
}

}