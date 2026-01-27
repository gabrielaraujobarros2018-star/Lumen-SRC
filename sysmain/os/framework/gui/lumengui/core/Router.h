#pragma once
#include <string>

class ScreenRegistry;
class Context;

class Router {
    ScreenRegistry& registry;
    Screen* current = nullptr;
public:
    Router(ScreenRegistry& r) : registry(r) {}

    void navigate(const std::string& id, Context& ctx) {
        if (current) current->onExit(ctx);
        current = registry.get(id);
        if (current) current->onEnter(ctx);
    }

    Screen* active() { return current; }
};