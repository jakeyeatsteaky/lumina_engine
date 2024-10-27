#ifndef APP_HPP
#define APP_HPP

#include <SDL2/SDL.h>
#include <memory>

#include "Window.hpp"
#include "EventManager.hpp"
#include "Renderer.hpp"

class SDLInit
{
    SDLInit();
    ~SDLInit();
    int initError;
public:
    friend class App;
};

class App
{
public: 
    App();
    ~App();

    void Run();
private:
    SDLInit m_sdlInit;

    bool Init();
    void Input();
    void Update();
    void Render();
    void CleanUp();
    bool AppShouldQuit();

    std::shared_ptr<Window> m_window;
    std::unique_ptr<EventManager> m_eventManager;
    std::unique_ptr<Renderer> m_renderer;

};

#endif