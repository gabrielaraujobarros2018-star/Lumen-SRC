#ifndef PALIKEY_KEYBOARD_SETTINGS_H
#define PALIKEY_KEYBOARD_SETTINGS_H

class KeyboardSettings {
public:
    KeyboardSettings();

    void setKeySpacing(int px);
    void setScale(float scale);
    void setDarkTheme(bool enabled);

    int keySpacing() const;
    float scale() const;
    bool darkTheme() const;

private:
    int spacingPx;
    float keyboardScale;
    bool useDarkTheme;
};

#endif