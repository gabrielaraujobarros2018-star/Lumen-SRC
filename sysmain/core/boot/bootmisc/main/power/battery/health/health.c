static int battery_health = 100;

void battery_degrade(void) {
    if (battery_health > 0) battery_health--;
}

int battery_health_percent(void) {
    return battery_health;
}