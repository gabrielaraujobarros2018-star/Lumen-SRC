namespace palisade::gui::render::framebuffer {

static int width = 0;
static int height = 0;

void configure(int w, int h) {
    width = w;
    height = h;
}

int getWidth() {
    return width;
}

int getHeight() {
    return height;
}

}