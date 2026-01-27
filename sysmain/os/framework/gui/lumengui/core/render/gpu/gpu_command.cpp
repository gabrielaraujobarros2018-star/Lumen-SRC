namespace palisade::gui::render::gpu {

int encodeCommand(int op, int arg) {
    return (op << 16) | (arg & 0xFFFF);
}

}