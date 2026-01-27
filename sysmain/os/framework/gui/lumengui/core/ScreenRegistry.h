#pragma once
#include <map>
#include <memory>
#include "Screen.h"

class ScreenRegistry {
    std::map<std::string, std::unique_ptr<Screen>> screens;
public:
    void registerScreen(Screen* screen) {
        screens[screen->id()] = std::unique_ptr<Screen>(screen);
    }

    Screen* get(const std::string& id) {
        return screens[id].get();
    }
};