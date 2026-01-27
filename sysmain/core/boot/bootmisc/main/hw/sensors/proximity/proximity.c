static int object_near = 0;

void proximity_set(int v) {
    object_near = v;
}

int proximity_read(void) {
    return object_near;
}