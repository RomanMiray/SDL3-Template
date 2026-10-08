#include "core/renderer.h"
#include "core/window.h"

#include <SDL3/SDL.h>

#include <stdexcept>

Renderer::Renderer(Window& window)
{
    renderer = SDL_CreateRenderer(window.get(), nullptr);
    if (!renderer) throw std::runtime_error(std::string("Failed to create Renderer: ") + SDL_GetError());
}

Renderer::~Renderer()
{
    SDL_DestroyRenderer(renderer);
    renderer = nullptr;
}

void Renderer::clear(std::uint8_t r, std::uint8_t g, std::uint8_t b, std::uint8_t a)
{
    SDL_SetRenderDrawColor(renderer, r, g, b, a);
    SDL_RenderClear(renderer);
}

void Renderer::present()
{
    SDL_RenderPresent(renderer);
}