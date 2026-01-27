namespace palisade::features::battery {

int estimateRemainingMinutes(int percent) {
    return percent * 6;
}

}