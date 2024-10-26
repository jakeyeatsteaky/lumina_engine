#include <SDL2/SDL.h>
#include "Renderer.hpp"
#include "Logger.hpp"

Renderer::Renderer()
{
    LOG_("Successfully created Renderer");
    
    m_pathsToSurfaces = 
    {
        "../moois.bmp",
        "../1.bmp",
        "../2.bmp",
        "../3.bmp"
    };
}

Renderer::~Renderer()
{
    Clean();
}

void Renderer::Clean()
{
    int numSurfaces = (int)m_surfaces.size();

    LOG_("Destroying %d image surfaces", numSurfaces);
    for(int i = 0; i < numSurfaces; i++)
    {
        SDL_FreeSurface(m_surfaces[i]);
        m_surfaces[i] = nullptr;
    }
}

bool Renderer::Load()
{
    bool success = true;
    int numSurfaces = (int)m_pathsToSurfaces.size();

    LOG_("Creating %d image surfaces", numSurfaces);
    for(int i = 0; i < numSurfaces; i++)
    {
        SDL_Surface* nextSurface = SDL_LoadBMP(m_pathsToSurfaces[i]);
        if(!nextSurface)
        {
            ERR("Failed to load the SDL Image. Error: %s\n", SDL_GetError());
            success = false;
            continue;
        }
        else
        {
            m_surfaces.push_back();
        }

    }
}

bool App::LoadImages()
{
    bool success = true;

    m_imageSurface = SDL_LoadBMP("../assets/moois.bmp");

    if(m_imageSurface == nullptr)
    {
        ERR("Failed to load the SDL Image.  Error: %s", SDL_GetError());
        success = false;
    }
    else
    {
        LOG("Loaded all assets successfully");
    }

    return success;
}