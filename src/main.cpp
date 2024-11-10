
// Standard library imports
#include <iostream>

// Third party libraries
#include <SDL.h>
#include "grid.h"


bool running = true;
int width = 720;
int height = 480;
int fps = 60;

using namespace std;

int main(int arcc, char* argv[]) {

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        cout << "SDL could not be initialized: " << SDL_GetError();
    } else {
        cout << "SDL successfully initialized\n";
    }

    SDL_Window *window;

    window = SDL_CreateWindow(
        "Falling Sand",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        720,
        480,
        SDL_WINDOW_RESIZABLE    
    );
    if (window == NULL) {
        cout << "Error initilizing window: " << SDL_GetError() << endl;
    } else {
        cout << "Window successfully created" << endl;
    }
    
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL) {
        cout << "Error initilizing renderer: " << SDL_GetError() << endl;
    } else {
        cout << "renderer successfully created" << endl;
    }

    SDL_Event event;

    Grid grid(10, 10);
    cout << grid.toString() << endl;

    while (running) {

        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
            if (event.type == SDL_KEYDOWN) {
                if (event.key.keysym.sym == SDLK_ESCAPE) {
                    running = false;
                } else {
                    cout << "Key pressed: " << SDL_GetKeyName(event.key.keysym.sym) << endl;
                }
            }
            if (event.type == SDL_MOUSEMOTION) {
                cout << "Mouse moved to (" << event.motion.x << ", " << event.motion.y << ")" << endl;
            }
        }

        SDL_SetRenderDrawColor(renderer, 31, 31, 31, 255);
        SDL_RenderClear(renderer);
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}
