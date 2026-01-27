#include <stdio.h>
#include <string.h>

int recovery_shell(void) {
    char cmd[32];
    printf("PalisadeOS Recovery Mode\n");
    printf("Type 'admin' to enter maintenance shell\n");

    while (1) {
        printf("> ");
        if (!fgets(cmd, sizeof(cmd), stdin)) break;
        cmd[strcspn(cmd, "\n")] = 0;

        if (strcmp(cmd, "admin") == 0) {
            printf("Admin shell granted\n");
            return 0;
        }
        printf("Unknown command\n");
    }
    return -1;
}