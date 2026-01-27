#include "gui.h"
#include <stdlib.h>

void gui_drivers_step(void (*next)()) {
    system("mkdir -p /palisade/os/drivers");
    system("curl -o /palisade/os/drivers/camera_driver.c https://raw.githubusercontent.com/gabrielaraujobarros2018-star/framework_resX_Palisade/main/camera_driver.c");

    system("gcc -O2 -Wall -c /palisade/os/drivers/camera_driver.c -o /palisade/os/drivers/camera_driver.o");
    system("gcc /palisade/os/drivers/camera_driver.o -o /palisade/os/drivers/camera_driver");

    system("chmod +x /palisade/os/drivers/camera_driver");

    next();
}