#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Renderer.hpp"
#include "Logger.hpp"

Renderer::Renderer(Window &appWindow) : m_SDLRenderer(nullptr, SDL_DestroyRenderer),
                                        m_appWindow(appWindow),
                                        m_initialized(false)
{

    // int numDrivers = SDL_GetNumRenderDrivers();
    // for (int i = 0; i < numDrivers; ++i)
    // {
    //     // SDL_RendererInfo info;
    //     // if (SDL_GetRenderDriverInfo(i, &info) == 0)
    //     // {
    //     //     LOG_("Renderer Driver Available: ", info.name);
    //     // }
    // }

    SDL_Renderer *renderer = nullptr;
    SDL_Window *sdlWindow = m_appWindow.Get();
    renderer = SDL_CreateRenderer(sdlWindow, -1, SDL_RENDERER_ACCELERATED /* | SDL_REDERER_PRESENTVSYNC */);

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

bool Renderer::loadTextures()
{
    bool success = true;

    return success;
}

void Renderer::clear()
{
}

void Renderer::render()
{
    SDL_SetRenderDrawColor(m_SDLRenderer.get(), 0x03, 0xff, 0x3a, 0xFF);
    SDL_RenderClear(m_SDLRenderer.get());

    // Perform rendering operations
    // ...

    SDL_Surface* surface = IMG_Load("../assets/pngs/black_cat_sprite_sheet.png");
    SDL_Texture* texture = SDL_CreateTextureFromSurface(m_SDLRenderer.get(), surface);
    SDL_FreeSurface(surface);

    SDL_Rect src = {10,33,11,35};

    SDL_Rect dst = {100, 100, 110, 350};

    SDL_RenderCopy(m_SDLRenderer.get(), texture, &src, &dst);

    SDL_DestroyTexture(texture);
    // Update the window surface after rendering
    SDL_RenderPresent(m_SDLRenderer.get());
}

void Renderer::handleEvent(const SDL_Event & /*event*/)
{
}