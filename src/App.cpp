#include "App.hpp"
#include "Logger.hpp"
#include "Utility.hpp"
#include "Renderer.hpp"

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

App::App() :    m_window(nullptr), 
                m_eventManager(nullptr),
                m_renderer(nullptr)
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
    
    m_window = std::make_shared<Window>();
    if(!m_window)
    {
        ERR("Error Creating Window object");
        return ret;
    }

    if(!m_window->m_initialized)
        return ret;

    m_renderer = std::make_unique<Renderer>(*m_window->GetSurface());
    if(!m_renderer->load())
    {
        ERR("Error loading surfaces");
        return ret;
    }

    m_eventManager = std::make_unique<EventManager>();
    if(!m_eventManager)
    {
        ERR("Error created Event Manager.");
        return ret;
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
    m_renderer->render();
    m_window->render();
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

