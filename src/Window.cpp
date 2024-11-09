#include "Window.hpp"
#include "Logger.hpp"

Window::Window() :  m_SDLWindow(nullptr, SDL_DestroyWindow),
                    m_initialized(false)
{
    m_initialized = Init();
    LOG_("Created Window");
}

Window::~Window()
{
    LOG_("Destroying the Window object");
}

static bool bUseFullscreen = false;
bool Window::Init()
{
    SDL_DisplayMode displayMode;
    SDL_GetCurrentDisplayMode(0, &displayMode);
    int width = displayMode.w;
    int height = displayMode.h;

    if(!bUseFullscreen)
    {
        width = DEFAULT_SCREEN_WIDTH;
        height = DEFAULT_SCREEN_HEIGHT;
    }

    SDL_Window* window = SDL_CreateWindow( "Lumina Engine", 
                                SDL_WINDOWPOS_CENTERED, 
                                SDL_WINDOWPOS_CENTERED, 
                                width, 
                                height, 
                                SDL_WINDOW_SHOWN);
    if(!window) {
            ERR("Failed to create SDL Window.  Error: %s", SDL_GetError());
            return false;
    }
    m_SDLWindow.reset(window);

    if(bUseFullscreen)
    {
        SDL_SetWindowFullscreen(m_SDLWindow.get(),SDL_WINDOW_FULLSCREEN);
    }

    return true;
}

SDL_Window* Window::Get()
{
    return m_SDLWindow.get();
}

void Window::handleEvent(const SDL_Event& event)
{
    if(event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_KP_ENTER)
        printf("WADDUP\n");
}

void Window::handleDeltaTime(const double& /*dt*/)
{
    // doesnt need to implement this
    ERR(__FUNCTION__, " shouldnt be getting called");
}