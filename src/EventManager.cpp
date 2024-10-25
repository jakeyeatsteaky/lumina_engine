#include <stdio.h>
#include <SDL2/SDL.h>

#include "EventManager.hpp"
#include "Logger.hpp"

EventManager::EventManager()
{
    LOG_("Created EventManager");
}

EventManager::~EventManager()
{
    LOG_("Destroying the Event Manager");
}

void EventManager::Poll()
{
    while(SDL_PollEvent(&m_event))
    {
        if(m_event.type == SDL_QUIT)
            m_quit = true;
    }
}