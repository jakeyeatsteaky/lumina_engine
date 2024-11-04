#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Renderer.hpp"
#include "Logger.hpp"

Renderer::Renderer(Window &appWindow) : 
            m_SDLRenderer(nullptr, SDL_DestroyRenderer),
            m_appWindow(appWindow),
            m_initialized(false)
{

    int numDrivers = SDL_GetNumRenderDrivers();
    for (int i = 0; i < numDrivers; ++i)
    {
        SDL_RendererInfo info;
        if (SDL_GetRenderDriverInfo(i, &info) == 0)
        {
            LOG_("Renderer Driver Available: ", info.name);
        }
    }

    SDL_Renderer *renderer = nullptr;
    SDL_Window *sdlWindow = m_appWindow.Get();
    renderer = SDL_CreateRenderer(sdlWindow, -1, SDL_RENDERER_ACCELERATED);

    if (!renderer)
    {
        ERR("Unable to create SDL Renderer. Error: ", SDL_GetError());
        return;
    }

    m_SDLRenderer.reset(renderer);

    int imgFlags = IMG_INIT_PNG;
    if (!(IMG_Init(imgFlags) & imgFlags))
    {
        ERR("SDL_image could not be initialized.  Error: ", IMG_GetError());
        return;
    }

    m_initialized = true;
    LOG_("Successfully created Renderer");
}

bool Renderer::init()
{
    bool ret = false;

    return ret;
}

Renderer::~Renderer()
{
    cleanUp();
}

void Renderer::cleanUp()
{

}

bool Renderer::load()
{
    bool success = true;

    return success;
}

void Renderer::clear()
{

}

void Renderer::render()
{
    SDL_SetRenderDrawColor(m_SDLRenderer.get(), 0xf3, 0xff, 0xa3, 0xFF);
    // Perform rendering operations
    // ...

    // Update the window surface after rendering
    SDL_UpdateWindowSurface(m_appWindow.Get());
}

void Renderer::handleEvent(const SDL_Event &event)
{

}