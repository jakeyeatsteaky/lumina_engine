#ifndef WINDOW_HPP
#define WINDOW_HPP
#include <memory>
#include <SDL2/SDL.h>

constexpr int DEFAULT_SCREEN_WIDTH = 800;
constexpr int DEFAULT_SCREEN_HEIGHT = 600;

class Window
{
    std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)> m_SDLWindow;
    std::unique_ptr<SDL_Surface, decltype(&SDL_FreeSurface)> m_windowSurface;
    bool Init();

    
public:
    Window();
    ~Window();
    void update();
    void render();
    SDL_Window* Get();
    SDL_Surface* GetSurface();
    bool m_initialized;
};

#endif // end window_hpp