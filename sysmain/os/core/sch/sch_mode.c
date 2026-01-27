#include <sch.h>

static int hybrid_enabled = 1;

void sch_set_hybrid(int on) {
    hybrid_enabled = on;
}

int sch_should_preempt(struct task *t) {
    if (!hybrid_enabled)
        return 1;

    if (t->flags & TASK_COOPERATIVE)
        return 0;

    return 1;
}