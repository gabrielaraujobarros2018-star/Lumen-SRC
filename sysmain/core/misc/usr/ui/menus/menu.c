#include <stdint.h>

static uint32_t menu_items = 0;

void menu_add_item(void) {
    menu_items++;
}

uint32_t menu_item_count(void) {
    return menu_items;
}

void menu_reset(void) {
    menu_items = 0;
}