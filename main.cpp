#include <stdio.h>
#include <stdexcept>
#include <SDL2/SDL.h>

#include "App.hpp"

#define _mu_ [[maybe_unused]]

int main([[maybe_unused]] int argc, [[maybe_unused]] char** argv)
{
    App app;

    try {
        app.Run();
    } catch (const std::runtime_error& e) {
        printf("Runtime error has occurred: %s\n", e.what());
    } catch (const std::exception& e) {
        printf("Exception has occurred: %s\n", e.what());
    }

    return 0;

}