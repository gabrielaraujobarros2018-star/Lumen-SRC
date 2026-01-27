#include <stdio.h>
#include <string.h>

#define MAX_STACK 16

static char undo_stack[MAX_STACK][64];
static char redo_stack[MAX_STACK][64];
static int undo_top = 0, redo_top = 0;

void action_commit(const char *a) {
    if (undo_top < MAX_STACK)
        strncpy(undo_stack[undo_top++], a, 63);
    redo_top = 0;
}

const char *undo(void) {
    if (undo_top == 0) return NULL;
    const char *a = undo_stack[--undo_top];
    strncpy(redo_stack[redo_top++], a, 63);
    return a;
}

const char *redo(void) {
    if (redo_top == 0) return NULL;
    const char *a = redo_stack[--redo_top];
    strncpy(undo_stack[undo_top++], a, 63);
    return a;
}