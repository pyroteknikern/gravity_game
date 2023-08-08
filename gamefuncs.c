#include<SDL2/SDL.h>
#include"gamefuncs.h"
#include"renderpages.h"
#include<stdio.h>
#include<stdbool.h>
#include<math.h>


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


void game_draw_objects(SDL_Renderer* renderer, Layout* layout, unsigned int number_of_attractors, float aim){
    for(int i = 0; i < number_of_attractors; i++){
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        DrawCircle(renderer, layout->atrs[i].x, layout->atrs[i].y, layout->atrs[i].radius);
    }
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    DrawCircle(renderer, layout->trgt.x, layout->trgt.y, 10);

    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
    DrawCircle(renderer, layout->blt->x, layout->blt->y, 5);
}


void game_animate(Layout* layout, unsigned int number_of_attractors){
    double ax = 0;
    double ay = 0;
    double a = 0;
    for(int i = 0; i < sizeof(layout->atrs)/sizeof(Attractor); i++){
	double dist_squared = pow(layout->atrs[i].x, 2) + pow(layout->atrs[i].y, 2);
        double ang = atan2(layout->atrs[i].y - layout->blt->y, layout->atrs[i].x - layout->blt->x);
	a = 0.1*layout->atrs[i].radius / dist_squared;
	ax += a * cos(ang);
	ay += a * sin(ang);	
    }

    layout->blt->vel_x += ax;
    layout->blt->vel_y += ay;
    layout->blt->x += layout->blt->vel_x;
    layout->blt->y += layout->blt->vel_y;
}
	
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
    float aim = 0.;
    unsigned int mode = 0;
    
     
    Bullet bullet;
    bullet.x = 9.;
    bullet.y = 9.;
    bullet.vel_x = 0.;
    bullet.vel_y = 0.; 
    
    Attractor attractor;
    attractor.x = 100;
    attractor.y = 100;
    attractor.mass = 10;
    attractor.radius = 30;

    Target target;
    target.x = 300;
    target.y = 300;

    Layout layout;
    layout.atrs[0] = attractor;
    layout.blt = &bullet;
    layout.trgt = target;
    unsigned int number_of_attractors = 1;

    while(run){
        while(SDL_PollEvent(&event)){
            if(event.type == SDL_QUIT){
                run = false;
            }
        }
    SDL_RenderClear(renderer); 
    game_animate(&layout, number_of_attractors);
    game_draw_objects(renderer, &layout, number_of_attractors, aim); 
    SDL_SetRenderDrawColor(renderer, 0,0,0,255);
    SDL_RenderPresent(renderer);
    SDL_Delay(1000/fps);
    }
}   

void game_destroy(SDL_Renderer* renderer, SDL_Window* window){
    SDL_DestroyWindow(window);
    SDL_Quit();
}
