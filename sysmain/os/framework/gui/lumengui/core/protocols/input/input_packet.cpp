namespace palisade::gui::protocol::input {

int pack(int dev, int code) {
    return (dev << 8) | code;
}

}