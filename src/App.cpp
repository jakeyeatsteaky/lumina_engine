#include "App.hpp"
#include "Logger.hpp"
#include "Utility.hpp"
#include "Renderer.hpp"

SDLInit::SDLInit() : initError(-1)
{

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
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

App::App() : m_window(nullptr),
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

    if (m_sdlInit.initError < 0)
    {
        ERR("Failed to init SDL");
        return ret;
    }

    m_window = std::make_shared<Window>();
    if (!m_window)
    {
        ERR("Error Creating Window object");
        return ret;
    }

    if (!m_window->m_initialized)
        return ret;

    m_renderer = std::make_unique<Renderer>(*m_window);
    if (!m_renderer->loadTextures())
    {
        ERR("Error loading surfaces");
        return ret;
    }

    m_eventManager = std::make_unique<EventManager>();
    if (!m_eventManager)
    {
        ERR("Error created Event Manager.");
        return ret;
    }

    AddCallbacks();

    ret = true;
    return ret;
}

void App::Input()
{
    m_eventManager->Poll();
}

int g_prevTime = 0;
double g_dt = 0;

void App::Update()
{
    int time_to_wait = core::MPF - (SDL_GetTicks() - g_prevTime);
    if(time_to_wait > 0)
        util::TimeDelay_ms(time_to_wait);

    // difference in ticks since the last frame converted to seconds
    g_dt = (SDL_GetTicks() - g_prevTime) / 1000.0f;

    m_eventManager->UpdateDeltaTime(g_dt);

    g_prevTime = SDL_GetTicks();
}

void App::Render()
{
    m_renderer->clear();
    // more render calls here?

    m_renderer->render();
}

void App::CleanUp()
{
}

bool App::AppShouldQuit()
{
    return m_shouldQuit;
}

void App::Run()
{
    if (!Init())
    {
        ERR("Failed to Initialize the Application");
        return;
    }

    LOG("App successfully initialized.  Start Lumina Up and Running");
    while (!AppShouldQuit())
    {
        Input();
        Update(); // caps timestep
        Render();

        util::TimeDelay_ms(10);
    }

    CleanUp();
}

void App::AddCallbacks()
{
    // system event callbacks
    m_eventManager->addEventListener(
        [this](const SDL_Event &event)
        {
            handleEvent(event);
        });

    m_eventManager->addEventListener(
        [this](const SDL_Event &event)
        {
            if (m_renderer)
                m_renderer->handleEvent(event);
        });

    m_eventManager->addEventListener(
        [this](const SDL_Event &event)
        {
            if (m_window)
                m_window->handleEvent(event);
        });


    // system delta time callbacks
    m_eventManager->addDeltaTimeEvent(
        [this](const double& dt)
        {
            handleDeltaTime(dt);
        });

    m_eventManager->addDeltaTimeEvent(
        [this](const double& dt)
        {
            if (m_renderer)
                m_renderer->handleDeltaTime(dt);
        });
}

void App::handleEvent(const SDL_Event &event)
{
    if (event.type == SDL_QUIT)
        m_shouldQuit = true;

    if (event.type == SDL_KEYDOWN)
    {
        if (event.key.keysym.sym == SDLK_ESCAPE)
            m_shouldQuit = true;
    }
}

void App::handleDeltaTime(const double& dt)
{
    m_currentSysDt = dt;
    LOG("App:: Dt updated ", dt);
}
