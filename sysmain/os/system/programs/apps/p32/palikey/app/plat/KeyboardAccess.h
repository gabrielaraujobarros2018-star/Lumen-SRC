#ifndef PALIKEY_KEYBOARD_ACCESS_H
#define PALIKEY_KEYBOARD_ACCESS_H

class KeyboardAccess {
public:
    virtual ~KeyboardAccess() = default;

    virtual bool isDefaultKeyboard() const = 0;
    virtual void requestDefaultKeyboard() = 0;
};

/*
 Android: launch ACTION_INPUT_METHOD_SETTINGS
 iOS: user-driven, cannot be forced
 PalisadeOS: kernel permission + config
*/

#endif