#include <SDL2/SDL.h>
#include "Renderer.hpp"
#include "Logger.hpp"

Renderer::Renderer(Window& appWindow) : 
            m_activeSurface(nullptr),
            m_appWindow(appWindow)
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

    LOG_("Creating image surfaces: ", numSurfaces);
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

    // initialize active surface
    m_activeSurface = m_imageSurfaces.at(0);
    return success;
}

void Renderer::clear()
{
    SDL_Surface* surface = m_appWindow.GetSurface();
    SDL_FillRect(surface, nullptr, SDL_MapRGB(surface->format, 0xFF, 0xF1, 0xAB));
}

void Renderer::render()
{
    SDL_Surface* windowSurface = m_appWindow.GetSurface();
    SDL_BlitSurface(m_activeSurface, NULL, const_cast<SDL_Surface*>(windowSurface), NULL);

    // Perform rendering operations
    // ...

    // Update the window surface after rendering
    SDL_UpdateWindowSurface(m_appWindow.Get());
}

void Renderer::updateActiveSurface(int idx)
{
    if (idx < 0) 
        idx = 0;
    if( idx > (int)m_imageSurfaces.size())
        idx = (int)m_imageSurfaces.size() - 1; 

    m_activeSurface = m_imageSurfaces[idx];
}

void Renderer::handleEvent(const SDL_Event& event)
{

    if(event.key.keysym.sym == SDLK_UP)
        updateActiveSurface(0);

    if(event.key.keysym.sym == SDLK_LEFT)
        updateActiveSurface(1);

    if(event.key.keysym.sym == SDLK_RIGHT)
        updateActiveSurface(2);
    
    if(event.key.keysym.sym == SDLK_DOWN)
        updateActiveSurface(3);
}