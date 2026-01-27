#ifndef GUI_H
#define GUI_H

/* Welcome screen */
void gui_welcome(void (*next)());

/* i don't know */
void gui_wifi_step(void (*next)());

/* Assets installation step */
void gui_assets_step(void (*next)());

/* Drivers installation step */
void gui_drivers_step(void (*next)());

/* Final screen */
void gui_finish(void);

#endif
