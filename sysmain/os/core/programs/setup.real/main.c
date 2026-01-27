#include <stdio.h>
#include <stdlib.h>

/* Forward declarations from setup logic */
void wizard_start(void);
void wizard_render(void);
void wizard_next(void);

int main(int argc, char **argv)
{
    (void)argc;
    (void)argv;

    printf("PalisadeOS Setup\n");
    printf("----------------\n");

    wizard_start();

    /*
     * Simple linear execution for now.
     * GUI or event loop can replace this later.
     */
    wizard_render();
    wizard_next();
    wizard_render();
    wizard_next();
    wizard_render();
    wizard_next();
    wizard_render();

    printf("Setup finished.\n");
    return 0;
}