#include "gui.hpp"
#include "system.hpp"

LoginGUI::LoginGUI() : field(0), done(false) {
    for (int i = 0; i < 32; i++) {
        profile.username[i] = 0;
        profile.password[i] = 0;
    }
    profile.uid = 1000;
}

void LoginGUI::run() {
    while (!done) {
        fb.clear(0x00202020);
        fb.draw_text(50, 40, "Welcome to PalisadeOS");
        fb.draw_text(50, 80, "Username:");
        fb.draw_text(50, 120, profile.username);
        fb.draw_text(50, 160, "User ID:");
        fb.draw_text(50, 200, "Password (optional):");
        fb.draw_text(50, 240, profile.password);
        fb.draw_rect(50, 300, 120, 40, 0x0044AA44);
        fb.draw_text(60, 310, "DONE");

        InputEvent ev;
        if (input.poll(ev) && ev.pressed) {
            if (field < 31) {
                profile.username[field++] = (char)ev.key;
            } else {
                save_user(profile);
                done = true;
            }
        }
        fb.present();
    }
}