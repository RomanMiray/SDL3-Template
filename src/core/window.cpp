#include "core/window.h"

#include <stdexcept>
#include <SDL3/SDL.h>

Window::Window(const std::string& title, const int width, const int height)
{
    window = SDL_CreateWindow(title.c_str(), width, height, 0);
    if (!window) throw std::runtime_error(std::string("Failed to create window: ") + SDL_GetError());
}

Window::~Window()
{
    if (window)
    {
        SDL_DestroyWindow(window);
        window = nullptr;
    }
}