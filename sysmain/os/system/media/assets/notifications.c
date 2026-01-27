#include <stdio.h>

typedef enum {
    INFO, WARN, ERROR
} notif_level_t;

void notify(notif_level_t lvl, const char *msg) {
    const char *tag = lvl == INFO ? "INFO" :
                      lvl == WARN ? "WARN" : "ERROR";
    printf("[notif:%s] %s\n", tag, msg);
}