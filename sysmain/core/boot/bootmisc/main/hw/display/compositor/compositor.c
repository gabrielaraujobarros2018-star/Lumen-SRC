static int frames = 0;

void compositor_commit(void) {
    frames++;
}

int compositor_frame_count(void) {
    return frames;
}