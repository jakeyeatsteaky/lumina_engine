#ifndef RENDERER_HPP
#define RENDERER_HPP

#include <SDL2/SDL.h>
#include <array>
#include <vector>
#include <memory>
#include <string>

class Renderer
{
    std::vector<SDL_Surface*> m_imageSurfaces;
    std::array<std::string, 4> m_pathsToSurfaces;
    const SDL_Surface& m_windowSurface;
    SDL_Surface* m_activeSurface;

public:
    Renderer(const SDL_Surface& windowSurface);
    ~Renderer();

    bool load();
    void cleanUp();

    void render();
};

#endif // end renderer hpp