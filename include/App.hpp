#ifndef APP_HPP
#define APP_HPP

#include <SDL2/SDL.h>
#include <memory>

#include "Window.hpp"

class App
{
public: 
    App();
    ~App();

    bool Init();

    void Input();
    void Update();
    void Render();

private:
    std::unique_ptr<Window> m_window;
    std::unique_ptr<EventManager> m_event;

};

#endif