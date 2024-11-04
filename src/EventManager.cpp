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
    SDL_Event event;
    while(SDL_PollEvent(&event))
    {
        for(auto& callback : m_callbacks)
        {
            callback(event);
        }
    }
}

void EventManager::addEventListener(EventCallback callback)
{
    m_callbacks.push_back(callback);
}