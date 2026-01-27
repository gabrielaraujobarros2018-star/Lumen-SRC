struct accel_data {
    int x, y, z;
};

struct accel_data accel_read(void) {
    return (struct accel_data){0, 0, 1};
}