#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <cmath>
#include <chrono>
#include <thread>

enum class DeviceClass {
    Desktop,
    Phone
};

struct Vec2 {
    float x;
    float y;
};

struct Rect {
    Vec2 position;
    Vec2 size;
};

class Clock {
public:
    static float timeSeconds() {
        using namespace std::chrono;
        static auto start = high_resolution_clock::now();
        auto now = high_resolution_clock::now();
        return duration<float>(now - start).count();
    }
};

class SunlightState {
public:
    float angle;
    float intensity;

    SunlightState() : angle(0.0f), intensity(1.0f) {}

    void update(float time) {
        angle = std::fmod(time * 6.0f, 360.0f);
        intensity = 0.6f + 0.4f * std::sin(time * 0.5f);
    }
};

class ShadowHandle {
public:
    int id;
    Rect bounds;

    ShadowHandle(int i, const Rect& r) : id(i), bounds(r) {}
};

class ShadowRegistry {
    std::vector<ShadowHandle> shadows;
    int nextId = 1;

public:
    int registerShadow(const Rect& r) {
        shadows.emplace_back(nextId, r);
        return nextId++;
    }

    const std::vector<ShadowHandle>& getShadows() const {
        return shadows;
    }
};

class LayoutNode {
protected:
    Rect rect;
    std::vector<std::shared_ptr<LayoutNode>> children;
    int shadowId = -1;

public:
    virtual ~LayoutNode() = default;

    void setRect(const Rect& r) {
        rect = r;
    }

    const Rect& getRect() const {
        return rect;
    }

    void addChild(const std::shared_ptr<LayoutNode>& node) {
        children.push_back(node);
    }

    virtual void layout(DeviceClass device) {
        for (auto& c : children) {
            c->layout(device);
        }
    }

    virtual void render() {
        for (auto& c : children) {
            c->render();
        }
    }

    void attachShadow(ShadowRegistry& registry) {
        shadowId = registry.registerShadow(rect);
    }
};

class Panel : public LayoutNode {
public:
    void layout(DeviceClass device) override {
        if (device == DeviceClass::Phone) {
            rect.size.x *= 0.95f;
            rect.size.y *= 0.95f;
        }
        LayoutNode::layout(device);
    }

    void render() override {
        std::cout << "Render Panel at "
                  << rect.position.x << ", "
                  << rect.position.y << "\n";
        LayoutNode::render();
    }
};

class Dock : public LayoutNode {
public:
    void layout(DeviceClass device) override {
        if (device == DeviceClass::Desktop) {
            rect.size.y = 80.0f;
        } else {
            rect.size.y = 64.0f;
        }
        LayoutNode::layout(device);
    }

    void render() override {
        std::cout << "Render Dock\n";
        LayoutNode::render();
    }
};

class Window : public LayoutNode {
public:
    void layout(DeviceClass device) override {
        if (device == DeviceClass::Phone) {
            rect.position = {0, 0};
        }
        LayoutNode::layout(device);
    }

    void render() override {
        std::cout << "Render Window\n";
        LayoutNode::render();
    }
};

class LayoutTree {
    std::shared_ptr<LayoutNode> root;

public:
    LayoutTree() {
        root = std::make_shared<Panel>();
    }

    std::shared_ptr<LayoutNode> getRoot() {
        return root;
    }

    void layout(DeviceClass device) {
        root->layout(device);
    }

    void render() {
        root->render();
    }
};

class UHSUIEngine {
    DeviceClass device;
    LayoutTree layoutTree;
    ShadowRegistry shadowRegistry;
    SunlightState sunlight;
    bool running = false;

public:
    UHSUIEngine(DeviceClass d) : device(d) {}

    void buildDefaultLayout() {
        auto root = layoutTree.getRoot();
        root->setRect({{0, 0}, {1280, 720}});

        auto window = std::make_shared<Window>();
        window->setRect({{100, 100}, {800, 500}});

        auto dock = std::make_shared<Dock>();
        dock->setRect({{0, 640}, {1280, 80}});

        window->attachShadow(shadowRegistry);
        dock->attachShadow(shadowRegistry);

        root->addChild(window);
        root->addChild(dock);
    }

    void update(float time) {
        sunlight.update(time);
    }

    void renderFrame() {
        std::cout << "Sun angle: " << sunlight.angle
                  << " intensity: " << sunlight.intensity << "\n";

        layoutTree.render();

        for (const auto& s : shadowRegistry.getShadows()) {
            std::cout << "Shadow ID " << s.id << " at "
                      << s.bounds.position.x << ", "
                      << s.bounds.position.y << "\n";
        }
    }

    void run() {
        running = true;
        buildDefaultLayout();

        while (running) {
            float time = Clock::timeSeconds();
            update(time);
            layoutTree.layout(device);
            renderFrame();

            std::this_thread::sleep_for(std::chrono::milliseconds(16));
            if (time > 1.0f) {
                running = false;
            }
        }
    }
};

int main() {
    UHSUIEngine engine(DeviceClass::Desktop);
    engine.run();
    return 0;
}