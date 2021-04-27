#include <SDL2/SDL.h>
#include "core.h"
#include <stdbool.h>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;
SDL_Event event;

void createWindow(){ 
    window = SDL_CreateWindow( "hello_sdl2", 50, 50, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
}

void createRenderer(){
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

int getEvents(){
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            quitGame();
            return 1;
        }
    }
    return 0;
}

void update() {
    SDL_SetRenderDrawColor( renderer, 100, 149, 237, 255);
    SDL_RenderClear( renderer );
    SDL_RenderPresent( renderer );
}

void quitGame() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}