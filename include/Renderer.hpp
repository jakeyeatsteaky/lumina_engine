#ifndef RENDERER_HPP
#define RENDERER_HPP

#include <SDL2/SDL.h>
#include <array>
#include <vector>

class Renderer
{
    std::vector<SDL_Surface*> m_surfaces;
    std::array<std::string, 4> m_pathsToSurfaces;

public:
    Renderer();
    ~Renderer();

    bool Load();
    void Clean();
};

#endif // end renderer hpp