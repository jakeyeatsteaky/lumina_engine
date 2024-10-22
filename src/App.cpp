#include "App.hpp"

App::App() : m_window(nullptr), m_surface(nullptr) 
{

}

App::~App() 
{
    SDL_Quit();
}

bool App::Init()
{
    bool ret = false;
    m_window = std::make_unique<Window>();
    if(m_window)
    {
        if(!m_window->m_initialized)
            return ret;
        else    
            printf("Window object Successfully created");
    }

    
}