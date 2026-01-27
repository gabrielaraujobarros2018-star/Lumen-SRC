#include "system.hpp"
#include "gui.hpp"
#include "storage.hpp"

extern "C" void _start() {
    system::log("Login GUI start\n");

    if (!user_exists()) {
        LoginGUI gui;
        gui.run();
    }

    system::log("User configured\n");
    system::halt();
}