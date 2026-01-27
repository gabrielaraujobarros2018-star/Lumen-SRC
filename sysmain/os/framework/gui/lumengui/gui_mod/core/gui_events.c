#include <gui_module.h>

static struct gui_event queue[64];
static int q_head = 0;
static int q_tail = 0;

void gui_event_push(int type, int value) {
    queue[q_tail].type = type;
    queue[q_tail].value = value;
    q_tail = (q_tail + 1) % 64;
}

int gui_event_pop(struct gui_event *out) {
    if (q_head == q_tail)
        return 0;

    *out = queue[q_head];
    q_head = (q_head + 1) % 64;
    return 1;
}