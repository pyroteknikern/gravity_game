#ifndef gamefuncs_h
#define gamefuncs_h
#include<SDL2/SDL.h>

void game_init(SDL_Renderer**, SDL_Window**);
void game_loop(SDL_Renderer*, SDL_Window*);
void game_destroy(SDL_Renderer*, SDL_Window*);    


#endif
