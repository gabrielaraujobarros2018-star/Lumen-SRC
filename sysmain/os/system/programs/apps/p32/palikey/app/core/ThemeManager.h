#ifndef THEME_MANAGER_H
#define THEME_MANAGER_H

#include <string>

class ThemeManager {
public:
    ThemeManager();
    void setTheme(const std::string& name);
    std::string getTheme() const;
    std::string backgroundColor() const;
    std::string keyColor() const;

private:
    std::string currentTheme;
};

#endif