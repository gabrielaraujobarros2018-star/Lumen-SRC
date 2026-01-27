#pragma once
#include <string>

class Context;
class Renderer;

class Screen {
public:
    virtual std::string id() const = 0;
    virtual void onEnter(Context&) {}
    virtual void onExit(Context&) {}
    virtual void render(Renderer&, Context&) = 0;
    virtual ~Screen() {}
};