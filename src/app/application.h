#pragma once

#include <memory>

class Window;
class Renderer;

class Application
{
public:
    Application();
    ~Application();

    Application(const Application&) = delete;
    Application operator=(const Application&&) = delete;

    Application(Application&&) = delete;
    Application operator=(Application&&) = delete;

    // Start the main loop and return an exit code
    int run();

private:
    void process_events();
    void update();
    void render();

    bool running = false;

    std::unique_ptr<Window> window;
    std::unique_ptr<Renderer> renderer;
};