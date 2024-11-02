#include "Window.hpp"
#include "Logger.hpp"

Window::Window() :  m_SDLWindow(nullptr, SDL_DestroyWindow),
                    m_windowSurface(nullptr, SDL_FreeSurface),
                    m_initialized(false)
{
    m_initialized = Init();
    LOG_("Created Window");
}

Window::~Window()
{
    LOG_("Destroying the Window object");
}

bool Window::Init()
{
    SDL_Window* window = SDL_CreateWindow( "Lumina Engine", 
                                SDL_WINDOWPOS_UNDEFINED, 
                                SDL_WINDOWPOS_UNDEFINED, 
                                DEFAULT_SCREEN_WIDTH, 
                                DEFAULT_SCREEN_HEIGHT, 
                                SDL_WINDOW_SHOWN);
    if(!window) {
            ERR("Failed to create SDL Window.  Error: %s", SDL_GetError());
            return false;
    }
    m_SDLWindow.reset(window);

    SDL_Surface* surface = SDL_GetWindowSurface(m_SDLWindow.get());

    if(!surface)
    {
        ERR("Failed to create sdl window surface. Error: %s\n", SDL_GetError());
        return false;
    }

    m_windowSurface.reset(surface);

    return true;
}

SDL_Window* Window::Get()
{
    return m_SDLWindow.get();
}

SDL_Surface* Window::GetSurface()
{
    return m_windowSurface.get();
}

void Window::handleEvent(const SDL_Event& event)
{
    if(event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_KP_ENTER)
        printf("WADDUP\n");
}

