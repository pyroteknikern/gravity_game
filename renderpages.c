#include<SDL2/SDL.h>
#include"gamefuncs.h"
#include"renderpages.h"
#include"gameobj.h"

void DrawCircle(SDL_Renderer * renderer, int centreX, int centreY, int radius)
{
   const int diameter = (radius * 2);

   int x = (radius - 1);
   int y = 0;
   int tx = 1;
   int ty = 1;
   int error = (tx - diameter);

   while (x >= y)
   {
      //  Each of the following renders an octant of the circle
      SDL_RenderDrawPoint(renderer, centreX + x, centreY - y);
      SDL_RenderDrawPoint(renderer, centreX + x, centreY + y);
      SDL_RenderDrawPoint(renderer, centreX - x, centreY - y);
      SDL_RenderDrawPoint(renderer, centreX - x, centreY + y);
      SDL_RenderDrawPoint(renderer, centreX + y, centreY - x);
      SDL_RenderDrawPoint(renderer, centreX + y, centreY + x);
      SDL_RenderDrawPoint(renderer, centreX - y, centreY - x);
      SDL_RenderDrawPoint(renderer, centreX - y, centreY + x);

      if (error <= 0)
      {
         ++y;
         error += ty;
         ty += 2;
      }

      if (error > 0)
      {
         --x;
         tx += 2;
         error += (tx - diameter);
      }
   }
}

void render_level_1(SDL_Renderer* renderer, Attractor* a, Bullet* b){
    a->x = 200;
    a->y = 200;
    a->mass = 10;
    a->radius = 50;
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    DrawCircle(renderer, a->x, a->y, a->radius);
    SDL_RenderPresent(renderer);
}



void render_menu(SDL_Renderer* renderer){
    Button start_button;
    start_button.color_r = 255;
    start_button.color_g = 0;
    start_button.color_b = 0;
    start_button.color_brightnes = 255;
    start_button.rect.w = 50;
    start_button.rect.h = 20;
    start_button.rect.x = 30;
    start_button.rect.y = 30;
    render_button(renderer, &start_button);
    SDL_RenderPresent(renderer);
}

void render_map_selector(SDL_Renderer* renderer){
    Button back_button;
    back_button.color_r = 0;
    back_button.color_g = 255;
    back_button.color_b = 0;
    back_button.color_brightnes = 255;
    back_button.rect.w = 50;
    back_button.rect.h = 20;
    back_button.rect.x = 60;
    back_button.rect.y = 30;
    render_button(renderer, &back_button);
    SDL_RenderPresent(renderer);
}


void render_button(SDL_Renderer* renderer, Button* btn){
    SDL_SetRenderDrawColor(renderer, btn->color_r, btn->color_g, btn->color_b, btn->color_brightnes);
    SDL_RenderFillRect(renderer, &btn->rect);
}

