#include <stdio.h>

static int frame_id = 0;

void render_sync_tick(void) {
    frame_id++;
}

void render_sync_init(void) {
    frame_id = 0;
    printf("Render sync initialized\n");
}