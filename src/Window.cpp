#include "Window.hpp"
#include "Logger.hpp"

Window::Window() : m_SDLWindow(nullptr, SDL_DestroyWindow), m_initialized(false)
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
    return true;
}

void Window::update()
{
    SDL_UpdateWindowSurface(Get());
}

SDL_Window* Window::Get()
{
    return m_SDLWindow.get();
}

