#ifndef PALIKEY_ENGINE_H
#define PALIKEY_ENGINE_H

#include <string>
#include <vector>

class PalikeyEngine {
public:
    PalikeyEngine();
    void setKeySpacing(int px);
    void setKeyboardScale(float scale);
    void inputCharacter(char c);
    void backspace();
    std::string getBuffer() const;

private:
    std::vector<char> buffer;
    int keySpacingPx;
    float keyboardScale;
};

#endif