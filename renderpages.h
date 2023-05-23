#ifndef renderpages_h
#define renderpages_h
#include<SDL2/SDL.h>
#include"gameobj.h"

typedef struct{
    SDL_Rect rect; 
    int color_r;
    int color_g;
    int color_b;
    int color_brightnes;
    char* text;
} Button;

void render_level_1(SDL_Renderer*, Attractor*, Bullet*);

void render_menu(SDL_Renderer*);
void render_map_selector(SDL_Renderer*);
void render_button(SDL_Renderer*, Button*);


#endif