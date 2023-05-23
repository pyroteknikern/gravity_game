#include<SDL2/SDL.h>
#include"gamefuncs.h"

int main(){
    SDL_Renderer *renderer;
    SDL_Window *window;
    game_init(&renderer, &window);
    game_loop(renderer, window);
    game_destroy(renderer, window);
    
    return 1;
}