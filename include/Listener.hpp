#ifndef LISTENER_HPP
#define LISTENER_HPP
#include <SDL2/SDL.h>

#include "Logger.hpp"

class Listener
{
public:
    virtual ~Listener() {LOG("Listener being destroyed");};
    virtual void handleEvent(const SDL_Event& event) = 0;
    virtual void handleDeltaTime(const double& dt) = 0;
};

#endif//