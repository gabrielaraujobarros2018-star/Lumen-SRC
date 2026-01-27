#ifndef SETUP_WIZARD_H
#define SETUP_WIZARD_H

typedef enum {
    STEP_WELCOME = 0,
    STEP_WIFI,
    STEP_FRAMEWORK,
    STEP_DRIVERS,
    STEP_DONE
} setup_step_t;

void wizard_start(void);
void wizard_next(void);
void wizard_render(void);

#endif