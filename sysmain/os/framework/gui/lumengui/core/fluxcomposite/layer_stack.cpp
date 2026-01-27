namespace palisade::gui::compositor {

static int layerCount = 0;

void pushLayer() {
    layerCount++;
}

int layers() {
    return layerCount;
}

}