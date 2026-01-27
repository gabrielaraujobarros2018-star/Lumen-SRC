#pragma once
#include "framebuffer.hpp"
#include "input.hpp"
#include "storage.hpp"

class LoginGUI {
public:
    LoginGUI();
    void run();

private:
    Framebuffer fb;
    Input input;
    UserProfile profile;
    int field;
    bool done;
};