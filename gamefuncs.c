#include<SDL2/SDL.h>
#include"gamefuncs.h"
#include"renderpages.h"
#include<stdio.h>
#include<stdbool.h>

void game_init(SDL_Renderer** renderer, SDL_Window** window){
    *window = SDL_CreateWindow("gravity game",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        640, 480,
        SDL_WINDOW_SHOWN
        );
    *renderer = SDL_CreateRenderer(*window,
        -1, SDL_RENDERER_ACCELERATED
        );
}

void game_loop(SDL_Renderer* renderer, SDL_Window* window){
    bool run = true;
    int fps = 60;
    SDL_Event event;
    Uint32 level = 0;
    float aim = 0.;
    void (*page_renderer)(SDL_Renderer*, float, Bullet*, Uint32);
    Bullet bullet;
    bullet.x=10;
    bullet.y=10;   
    page_renderer = &render_level_1;   
    Uint32 mode = 0; //0 for aim, 1 for animate
    while(run){
        while(SDL_PollEvent(&event)){
            if(event.type == SDL_QUIT){
                run = false;
            }
        }
    (*page_renderer)(renderer, aim, &bullet, mode);
    
    
    SDL_Delay(1000/fps);
    }
}   

void game_destroy(SDL_Renderer* renderer, SDL_Window* window){
    SDL_DestroyWindow(window);
    SDL_Quit();
}
