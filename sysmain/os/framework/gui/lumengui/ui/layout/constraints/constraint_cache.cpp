namespace palisade::gui::layout::constraints {

static int last = 0;

void store(int v) {
    last = v;
}

int recall() {
    return last;
}

}