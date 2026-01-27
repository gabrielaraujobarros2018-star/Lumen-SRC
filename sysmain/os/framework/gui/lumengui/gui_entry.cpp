// PalisadeOS SystemGUI entry point
// OS-level framework binary (freestanding)

extern "C" void _start();

namespace palisade::systemgui {

static volatile bool gui_running = false;

void init_graphics()
{
    // Initialize OS GUI framework state
    // No hardware access, compositor will bind later
}

void init_input()
{
    // Register input channels with OS framework
}

void main_loop()
{
    gui_running = true;

    while (gui_running) {
        // Event-driven GUI loop placeholder
        // Real events dispatched by framework services
    }
}

void shutdown()
{
    gui_running = false;
}

} // namespace palisade::systemgui

extern "C" void _start()
{
    using namespace palisade::systemgui;

    init_graphics();
    init_input();
    main_loop();
    shutdown();

    // Halt safely if main loop ever exits
    for (;;) {
        asm volatile("wfe");
    }
}