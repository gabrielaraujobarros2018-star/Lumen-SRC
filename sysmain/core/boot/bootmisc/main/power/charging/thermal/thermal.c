static int temperature = 25;

void thermal_set(int t) {
    temperature = t;
}

int thermal_get(void) {
    return temperature;
}