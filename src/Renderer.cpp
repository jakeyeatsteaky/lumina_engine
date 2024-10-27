#include <SDL2/SDL.h>
#include "Renderer.hpp"
#include "Logger.hpp"

Renderer::Renderer(const SDL_Surface& windowSurface) : 
            m_windowSurface(windowSurface),
            m_activeSurface(nullptr)
{
    LOG_("Successfully created Renderer");
    
    m_pathsToSurfaces = {
        "../assets/moois.bmp",
        "../assets/1.bmp",
        "../assets/2.bmp",
        "../assets/3.bmp"
    };
}

Renderer::~Renderer()
{
    cleanUp();
}

void Renderer::cleanUp()
{
    int numSurfaces = (int)m_imageSurfaces.size();

    LOG_("Destroying %d image surfaces", numSurfaces);
    for(int i = 0; i < numSurfaces; i++)
    {
        SDL_FreeSurface(m_imageSurfaces[i]);
        m_imageSurfaces[i] = nullptr;
    }
}

bool Renderer::load()
{
    bool success = true;
    int numSurfaces = (int)m_pathsToSurfaces.size();

    LOG_("Creating %d image surfaces", numSurfaces);
    for(int i = 0; i < numSurfaces; i++)
    {
        SDL_Surface* nextSurface = SDL_LoadBMP(m_pathsToSurfaces[i].c_str());
        if(!nextSurface)
        {
            ERR("Failed to load the SDL Image. Error: %s\n", SDL_GetError());
            success = false;
            continue;
        }
        else
        {
            m_imageSurfaces.push_back(nextSurface);
        }
    }
    return success;
}

void Renderer::render()
{
    SDL_BlitSurface(m_activeSurface, NULL, const_cast<SDL_Surface*>(&m_windowSurface), NULL);
}