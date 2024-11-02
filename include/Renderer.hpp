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

class Renderer : public Listener
{
    std::vector<SDL_Surface*> m_imageSurfaces;
    std::array<std::string, 4> m_pathsToSurfaces;
    SDL_Surface* m_activeSurface;
    std::unique_ptr<SDL_Renderer, decltype(&SDL_DestroyRenderer)> m_SDLRenderer;
    Window& m_appWindow;
    bool m_initialized;

public:
    Renderer() = delete;
    Renderer(Window& appWindow);
    ~Renderer();

    bool load();
    void cleanUp();
    void clear();
    void render();
    void updateActiveSurface(int idx);

    virtual void handleEvent(const SDL_Event& event) override;
};

#endif // end renderer hpp