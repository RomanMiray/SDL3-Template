#include "app/application.h"

#include "core/window.h"
#include "core/renderer.h"

#include <SDL3/SDL.h>

#include <stdexcept>

namespace AppConfig
{
    constexpr int window_width = 800;
    constexpr int window_height = 600;
    [[maybe_unused]] constexpr auto title = "SDL3-Templatek";
    [[maybe_unused]] constexpr auto version = "1.0.0";
}

Application::Application()
{
    if (!SDL_Init(SDL_INIT_AUDIO | SDL_INIT_VIDEO | SDL_INIT_EVENTS)) 
        throw std::runtime_error(std::string("SDL Initialization Failed: ") + SDL_GetError());


    window = std::make_unique<Window>(AppConfig::title, AppConfig::window_width, AppConfig::window_height);
    renderer = std::make_unique<Renderer>(*window);

    running = true;
}

Application::~Application()
{
    SDL_Quit();
}

int Application::run()
{
    Uint64 previous_ticks = SDL_GetTicks();

    while (running)
    {
        const Uint64 current_ticks = SDL_GetTicks();
        const double delta_time = static_cast<double>(current_ticks - previous_ticks) / 1000.0f;
        previous_ticks = current_ticks;

        process_events();
        update();
        render();
    }

    return 0;
}

void Application::process_events()
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_EVENT_QUIT)
        {
            running = false;
        }
    }
}

void Application::update()
{
    
}

void Application::render()
{
    renderer->clear(0, 0, 0, 0);

    renderer->present();
}