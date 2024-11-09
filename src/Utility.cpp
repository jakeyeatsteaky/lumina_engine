#include "Utility.hpp"

#include <SDL2/SDL.h>
#include <chrono>
#include <thread>


void util::TimeDelay_ms(uint32_t ms, bool use_rote)
{
    if(use_rote)
        std::this_thread::sleep_for(std::chrono::milliseconds(ms));     
    else
        SDL_Delay(ms);
}