#pragma once

#include <cstdint>

class SDL_Renderer;
class Window;

class Renderer
{
public:
    Renderer(Window& window);
    ~Renderer();

    Renderer(const Renderer&) = delete;
    Renderer& operator=(const Renderer&) = delete;

    Renderer(Renderer&&) = delete;
    Renderer& operator=(Renderer&&) = delete;


    void clear(std::uint8_t r, std::uint8_t g, std::uint8_t b, std::uint8_t a);
    void present();

    SDL_Renderer* get() const { return renderer; }

private:
    SDL_Renderer* renderer = nullptr;
};