#pragma once

#include <string>

class SDL_Window;

class Window 
{
public:
    Window(const std::string& title, const int width, const int height);
    ~Window();

    Window(const Window&) = delete;
    Window& operator=(const Window&) = delete;

    Window(Window&&) = delete;
    Window& operator=(Window&&) = delete;

    SDL_Window* get() const { return window; }

private:
    SDL_Window* window = nullptr;
};