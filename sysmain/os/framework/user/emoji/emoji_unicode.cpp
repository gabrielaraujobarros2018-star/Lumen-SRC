namespace palisade::features::emoji {

bool isEmoji(uint32_t cp) {
    return cp >= 0x1F300 && cp <= 0x1FAFF;
}

}