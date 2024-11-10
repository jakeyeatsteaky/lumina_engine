#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <glm/glm.hpp>
#include "Renderer.hpp"
#include "Logger.hpp"

Renderer::Renderer(Window &appWindow) : m_SDLRenderer(nullptr, SDL_DestroyRenderer),
                                        m_appWindow(appWindow),
                                        m_initialized(false),
                                        m_dt(0.0)
{
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
    LOG("Renderer Cleaned up and destroyed");
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

constexpr double scale_factor = 4.0;
float playerX = 10;
float playerY = 50;

glm::vec2 playerPosition(playerX, playerY);
glm::vec2 playerVelocity(2.5, 1.0);

void Renderer::render()
{
    SDL_SetRenderDrawColor(m_SDLRenderer.get(), 0x03, 0xff, 0x3a, 0xFF);
    SDL_RenderClear(m_SDLRenderer.get());

    // Perform rendering operations
    // ...

    SDL_Surface* surface = IMG_Load("../assets/pngs/black_cat_sprite_sheet.png");
    if(!surface)
    {
        ERR("Failed to create surface: ", SDL_GetError());
    }

    SDL_Texture* texture = SDL_CreateTextureFromSurface(m_SDLRenderer.get(), surface);
    if(!texture)
    {
        ERR("Failed to create texture: ", SDL_GetError());
    }

    SDL_FreeSurface(surface);

    int32_t tex_width = 11;
    int32_t tex_startX = 10;
    int32_t tex_height = 35;
    int32_t tex_startY = 33;

    SDL_Rect src = {tex_startX, tex_startY, tex_width, tex_height};

    float scaledWidth =  (float)tex_width * scale_factor;
    float scaledHeight = (float)tex_height * scale_factor;

    playerPosition.x += playerVelocity.x * m_dt;
    playerPosition.y += playerVelocity.y * m_dt;
    SDL_Rect dst = {
                    (int32_t)playerPosition.x, 
                    (int32_t)playerPosition.y, 
                    (int32_t)scaledWidth, 
                    (int32_t)scaledHeight};

    SDL_RenderCopy(m_SDLRenderer.get(), texture, &src, &dst);

    SDL_DestroyTexture(texture);
    // Update the window surface after rendering
    SDL_RenderPresent(m_SDLRenderer.get());
}

void Renderer::handleEvent(const SDL_Event & /*event*/)
{
}

void Renderer::handleDeltaTime(const double& dt)
{
    m_dt = dt;
    //LOG("\tRenderer:: Dt updated");
}