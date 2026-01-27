#include <sch.h>

void sch_tick(void) {
    struct task *t = sch_pick_next();

    if (!t)
        return;

    if (sch_should_preempt(t))
        context_switch(t);
}

struct task *sch_pick_next(void) {
    return task_highest_weight();
}