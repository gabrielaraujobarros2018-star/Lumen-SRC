extern void system_suspend(void);

void system_wake(void) {
    system_suspend(); /* clear state via shared logic */
}