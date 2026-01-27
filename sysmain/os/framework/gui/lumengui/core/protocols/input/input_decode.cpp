namespace palisade::gui::protocol::input {

int decode(int packet) {
    return packet & 0xFF;
}

}