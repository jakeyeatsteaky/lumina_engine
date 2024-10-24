#include <stdio.h>
#include <stdexcept>
#include <SDL2/SDL.h>

#include "App.hpp"
#include "Logger.hpp"

#define _mu_ [[maybe_unused]]

#if 0
    [ ] Lazy Foo Tut 2: Getting an Image on the screen
        [ ] Make App class and encapsulate SDL items in to another class
            [x] Make Window Class
            [x] Make Event Manager
            [x] Fix Crash 
                [x] Put print statements in Window and EventManager constructors.
                    to see where the crash is happening.
        [ ] Import Logger into project

#endif



int main([[maybe_unused]] int argc, [[maybe_unused]] char** argv)
{

    App app;

    try {
        app.Run();
    } catch (const std::runtime_error& e) {
        ERR("Runtime error has occurred: %s\n", e.what());
    } catch (const std::exception& e) {
        ERR("Exception has occurred: %s\n", e.what());
    }

    return 0;

}