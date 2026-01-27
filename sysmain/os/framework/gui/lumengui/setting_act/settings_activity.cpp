namespace palisade::gui::settings {

static bool open = false;

void show() {
    open = true;
}

void hide() {
    open = false;
}

bool visible() {
    return open;
}

}