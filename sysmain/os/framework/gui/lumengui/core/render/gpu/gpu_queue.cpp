namespace palisade::gui::render::gpu {

static int queued = 0;

void submit() {
    queued++;
}

int pending() {
    return queued;
}

}