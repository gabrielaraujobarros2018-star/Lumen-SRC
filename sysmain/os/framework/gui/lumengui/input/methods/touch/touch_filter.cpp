namespace palisade::gui::touch {

bool filterNoise(int pressure) {
    return pressure > 2;
}

}