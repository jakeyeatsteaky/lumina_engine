#include "App.hpp"
#include "Logger.hpp"
#include "Utility.hpp"

SDLInit::SDLInit() : initError(-1)
{
    
    if(SDL_Init(SDL_INIT_VIDEO) < 0) {
            ERR("Failed to init SDL.  Error: %s", SDL_GetError());
            return;
    }
    LOG_("Initialized SDL");
    initError = 0;
}

SDLInit::~SDLInit()
{
    LOG_("Destroying SDL Instance");
    SDL_Quit();
}

App::App() : m_window(nullptr), m_surface(nullptr)
{
    LOG_("Created App");
}

App::~App() 
{

}

bool App::Init()
{
    bool ret = false;
    
    if(m_sdlInit.initError < 0) {
        ERR("Failed to init SDL");
        return ret;
    }
    
    m_window = std::make_unique<Window>();
    if(!m_window)
    {
        ERR("Error Creating Window object");
        return ret;
    }

    if(!m_window->m_initialized)
        return ret;


    m_surface = SDL_GetWindowSurface(m_window->Get());

    if(!m_surface)
    {
        ERR("Error assigning surface to window.");
        return ret;
    }

    m_eventManager = std::make_unique<EventManager>();
    if(!m_eventManager)
    {
        ERR("Error created Event Manager.");
    }

    ret = true;
    return ret;
}

void App::Input()
{
    m_eventManager->Poll();
}

void App::Update()
{
    m_window->update();
}

void App::Render()
{
    std::string getSeconds = GetDateAndTime();
    getSeconds = getSeconds.substr(17,19);
    
    int num = stoi(getSeconds);
    int R = num >> 0;
    int G = num >> 1;
    int B = num >> 2;
    SDL_FillRect(m_surface, nullptr, SDL_MapRGB(m_surface->format, R, G, B));
}

void App::CleanUp()
{

}

bool App::AppShouldQuit()
{
    return m_eventManager->m_quit;
}

void App::Run()
{
    if(!Init())
    {
        ERR("Failed to Initialize the Application");
        return;
    }

    while(!AppShouldQuit())
    {
        Input();
        Update();
        Render();

        util::TimeDelay_ms(100);
    }

    CleanUp();
}
