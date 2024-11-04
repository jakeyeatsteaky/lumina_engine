#ifndef WINDOW_HPP
#define WINDOW_HPP

#include "Listener.hpp"

#include <memory>
#include <SDL2/SDL.h>

constexpr int DEFAULT_SCREEN_WIDTH = 800;
constexpr int DEFAULT_SCREEN_HEIGHT = 600;

class Window : public Listener
{
    std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)> m_SDLWindow;
    bool Init();

    
public:
    Window();
    ~Window();
    SDL_Window* Get();
    bool m_initialized;

    virtual void handleEvent(const SDL_Event& event) override;
};

#endif // end window_hpp