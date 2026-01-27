struct gyro_data {
    int x, y, z;
};

struct gyro_data gyro_read(void) {
    return (struct gyro_data){0, 0, 0};
}