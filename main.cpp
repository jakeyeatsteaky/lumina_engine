#include <stdio.h>
#include <SDL2/SDL.h>

#define _mu_ [[maybe_unused]]

constexpr int SCREEN_WIDTH = 800;
constexpr int SCREEN_HEIGHT = 600;

#if 0
    [ ] Lazy Foo Tut 2: Getting an Image on the screen
    [ ] Make App class and encapsulate SDL items in to another class
        [ ] Make Window Class
        [ ] Make Event Manager
#endif



int main([[maybe_unused]] int argc, [[maybe_unused]] char** argv)
{
    SDL_Window* window = nullptr;

    SDL_Surface* surface = nullptr;

    SDL_Surface* _mu_ image = nullptr;

    // initialize SDL
    if(SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL failed to init.  Error: %s\n", SDL_GetError());
        return -1;
    }
    
    window = SDL_CreateWindow( "Lumina Engine", 
                                SDL_WINDOWPOS_UNDEFINED, 
                                SDL_WINDOWPOS_UNDEFINED, 
                                SCREEN_WIDTH, 
                                SCREEN_HEIGHT, 
                                SDL_WINDOW_SHOWN);
    if(!window) {
            printf("Failed to create SDL Window.  Error: %s\n", SDL_GetError());
            return -1;
    }

    surface = SDL_GetWindowSurface(window);
    
    SDL_FillRect(surface, nullptr, SDL_MapRGB(surface->format, 0xF0, 0xBA, 0xFF));

    SDL_UpdateWindowSurface(window);

    SDL_Event e; 
    bool quit = false;
    while(quit == false)
    {
        while(SDL_PollEvent(&e))
        {
            if( e.type == SDL_QUIT)
                quit = true;
        }
    }

    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;

}