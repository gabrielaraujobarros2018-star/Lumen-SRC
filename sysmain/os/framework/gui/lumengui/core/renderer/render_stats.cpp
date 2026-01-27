namespace palisade::gui::renderer {

static int frames = 0;

void frameRendered() {
    frames++;
}

int frameCount() {
    return frames;
}

}