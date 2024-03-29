#include<SDL2/SDL.h>
#include"gamefuncs.h"
#include<stdio.h>
#include<stdbool.h>
#include<math.h>
#include"levels.h"
#include"shapes.h"


void game_level_change(Layout* layout, unsigned int level, bool* run){
    switch(level){
        case 0:
	    level_1(layout);
	    break;
        case 1:
            level_2(layout);
	    break;
	case 2:
	    level_3(layout);
	    break;
	case 3:
	    level_4(layout);
	    break;
	case 4:
	    level_5(layout);
	    break;
	default:
	    *run = false;
	    break;
    }	    
}

void game_aim(Bullet* bullet, float direction){
    float vel = 1;
    bullet->vel_x = cos(direction) * vel;
    bullet->vel_y = sin(direction) * vel; 
}


void handle_events(SDL_Event* event, bool* run, float* direction, unsigned int* mode, Layout* layout, int level){   
    while(SDL_PollEvent(event)){
        if(event->type == SDL_QUIT){
            *run = false;
        }
	if(event->type == SDL_KEYDOWN){
	    if(event->key.keysym.sym == SDLK_r){
	        *direction += 0.1;
	    }
	    if(event->key.keysym.sym == SDLK_l){
	        *direction -= 0.1;
            }
	    if(event->key.keysym.sym == SDLK_f){
                *mode = 1;
	    }
	    if(event->key.keysym.sym == SDLK_q){
		*mode = 0;
		game_level_change(layout, level, run);
            }	   
    	}
    }
}

		
void game_draw_objects(SDL_Renderer* renderer, Layout* layout, float aim){
    for(int i = 0; i < layout->number_of_attractors; i++){
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        DrawCircle(renderer, layout->atrs[i].x, layout->atrs[i].y, layout->atrs[i].radius);
    }
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    DrawCircle(renderer, layout->trgt.x, layout->trgt.y, layout->trgt.radius);

    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
    DrawCircle(renderer, layout->blt->x, layout->blt->y, layout->blt->radius);

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    DrawCircle(renderer, layout->blt->x+ 20*cos(aim), layout->blt->y+20*sin(aim), 1);
}


void game_animate(Layout* layout){
    for(int i = 0; i < 3; i++){
        double ax = 0;
        double ay = 0;
        double a = 0;
        for(int j = 0; j < layout->number_of_attractors; j++){
	    double dist_squared = pow(layout->atrs[j].x-layout->blt->x, 2) + pow(layout->atrs[j].y-layout->blt->y, 2);
            double ang = atan2(layout->atrs[j].y - layout->blt->y, layout->atrs[j].x - layout->blt->x);
	    a = 2*layout->atrs[j].radius / dist_squared;
	    ax += a * cos(ang);
	    ay += a * sin(ang);	
    	}

    	layout->blt->vel_x += ax;
    	layout->blt->vel_y += ay;
    	layout->blt->x += layout->blt->vel_x;
    	layout->blt->y += layout->blt->vel_y;
	}
}

void game_init(SDL_Renderer** renderer, SDL_Window** window){
    *window = SDL_CreateWindow("gravity game",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        1200, 900,
        SDL_WINDOW_SHOWN
        );
    *renderer = SDL_CreateRenderer(*window,
        -1, SDL_RENDERER_ACCELERATED
        );
}


void game_check_collisions(Layout* layout, unsigned int* level, unsigned int* mode, bool* run_ptr){
    bool col = false;
    for(int i = 0; i < layout->number_of_attractors; i++){
	double dist = sqrt(pow(layout->atrs[i].x - layout->blt->x, 2) + pow(layout->atrs[i].y - layout->blt->y, 2));
        if(dist < layout->atrs[i].radius+layout->blt->radius){
	    *mode = 0;
	    col = true;
        }
    }
    	
    double dist = sqrt(pow(layout->trgt.x - layout->blt->x, 2) + pow(layout->trgt.y - layout->blt->y, 2));
    if(dist < layout->trgt.radius+layout->blt->radius){
	*level += 1;
	*mode = 0;
	col = true;
    }  
    if(!col){return;}
    game_level_change(layout, *level, run_ptr);
}


void game_loop(SDL_Renderer* renderer, SDL_Window* window){
    bool run = true;
    const int fps = 60;
    SDL_Event event;
    unsigned int mode = 0;
    float direction = 0.; 
    unsigned int level = 0;
    
    Layout layout;
    Bullet bullet;
    layout.blt = &bullet;
    
    level_1(&layout);

    while(run){
    handle_events(&event, &run, &direction, &mode, &layout, level);
    SDL_RenderClear(renderer);
    switch(mode){
        case 0:
	    game_aim(layout.blt, direction);
	    break; 
	case 1:
	    game_animate(&layout);
            game_check_collisions(&layout, &level, &mode, &run); 
    }
    game_draw_objects(renderer, &layout, direction); 
    SDL_SetRenderDrawColor(renderer, 0,0,0,255);
    SDL_RenderPresent(renderer);
    SDL_Delay(1000/fps);
    }
}   


void game_destroy(SDL_Renderer* renderer, SDL_Window* window){
    SDL_DestroyWindow(window);
    SDL_Quit();
}
