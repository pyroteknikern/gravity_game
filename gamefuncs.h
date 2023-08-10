#ifndef gamefuncs_h
#define gamefuncs_h
#include<SDL2/SDL.h>
#include<stdbool.h>
#include"gameobj.h"
void game_init(SDL_Renderer**, SDL_Window**);
void game_loop(SDL_Renderer*, SDL_Window*);
void game_destroy(SDL_Renderer*, SDL_Window*);    
void game_check_collisions(Layout*, unsigned int*, unsigned int*, bool*);
void game_animate(Layout*);
void game_draw_objects(SDL_Renderer*, Layout*, float);
void game_aim(Bullet*, float);
void game_level_change(Layout*, unsigned int, bool*);
#endif
