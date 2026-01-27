#include <pal_sys.h>

void insp_collect(struct sys_state *s) {
    s->tasks = task_count();
    s->mem_free = mem_free_pages();
    s->uptime = sys_uptime();
}

void insp_render(struct sys_state *s) {
    draw_text("Tasks:", 10, 10);
    draw_int(s->tasks, 80, 10);
}