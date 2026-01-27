#include <sch.h>

int sch_task_prio(struct task *t) {
    if (!t) return PRIO_BG;

    if (t->flags & TASK_SYSTEM)
        return PRIO_SYS;

    if (t->flags & TASK_FOREGROUND)
        return PRIO_FG;

    return PRIO_BG;
}

int sch_prio_weight(int prio) {
    switch (prio) {
        case PRIO_SYS: return 1024;
        case PRIO_FG:  return 512;
        case PRIO_BG:  return 128;
        default:       return 128;
    }
}