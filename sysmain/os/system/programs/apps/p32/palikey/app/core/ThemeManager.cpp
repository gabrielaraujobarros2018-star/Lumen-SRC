#include "ThemeManager.h"

ThemeManager::ThemeManager() : currentTheme("dark") {}

void ThemeManager::setTheme(const std::string& name) {
    if (!name.empty()) {
        currentTheme = name;
    }
}

std::string ThemeManager::getTheme() const {
    return currentTheme;
}

std::string ThemeManager::backgroundColor() const {
    return currentTheme == "light" ? "#FFFFFF" : "#101010";
}

std::string ThemeManager::keyColor() const {
    return currentTheme == "light" ? "#DDDDDD" : "#303030";
}