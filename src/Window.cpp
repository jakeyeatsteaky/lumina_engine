#include "Window.hpp"

Window::Window() : m_SDLWindow(nullptr, SDL_DestroyWindow), m_initialized(false)
{
    m_initialized = Init();
}

Window::~Window()
{
    printf("Destroying the Window object");
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
            printf("Failed to create SDL Window.  Error: %s\n", SDL_GetError());
            return false;
    }
    m_SDLWindow.reset(window);
    return true;
}