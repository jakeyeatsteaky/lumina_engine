#ifndef RENDERER_HPP
#define RENDERER_HPP
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <array>
#include <vector>
#include <memory>
#include <string>

#include "Window.hpp"
#include "Listener.hpp"

class SDL_IMGInit
{

};

class Renderer : public Listener
{
    std::unique_ptr<SDL_Renderer, decltype(&SDL_DestroyRenderer)> m_SDLRenderer;
    Window& m_appWindow;
    bool m_initialized;

public:
    Renderer() = delete;
    Renderer(Window& appWindow);
    ~Renderer();

    bool loadTextures();
    void cleanUp();
    void clear();
    void render();

    virtual void handleEvent(const SDL_Event& event) override;
};

#endif // end renderer hpp