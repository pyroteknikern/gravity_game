#include"gameobj.h"
#include"levels.h"

void level_1(Layout* l){

    l->blt->x = 100.;
    l->blt->y = 100.;
    l->blt->vel_x = 0.;
    l->blt->vel_y = 0.; 
    l->blt->radius = 10;

    Attractor a1;
    a1.x = 200;
    a1.y = 200;
    a1.mass = 10;
    a1.radius = 30;

    Target target;
    target.x = 490;
    target.y = 400;
    target.radius = 20;
    
    l->trgt = target;
    l->atrs[0] = a1;
    l->number_of_attractors = 2;
}

void level_2(Layout* l){
	
    l->blt->x = 30.;
    l->blt->y = 30.;
    l->blt->vel_x = 0.;
    l->blt->vel_y = 0.; 
    l->blt->radius = 10;

    Attractor a1;
    a1.x = 200;
    a1.y = 200;
    a1.mass = 10;
    a1.radius = 30;

    Attractor a2;
    a2.x = 500;
    a2.y = 300;
    a2.mass = 10;
    a2.radius = 20;

    Target target;
    target.x = 460;
    target.y = 600;
    target.radius = 20;
    
    l->trgt = target;
    l->atrs[0] = a1;
    l->atrs[1] = a2;
    l->number_of_attractors = 2;
}



void level_3(Layout* l){
	
    l->blt->x = 1000.;
    l->blt->y = 400.;
    l->blt->vel_x = 0.;
    l->blt->vel_y = 0.; 
    l->blt->radius = 10;

    Attractor a1;
    a1.x = 100;
    a1.y = 100;
    a1.mass = 10;
    a1.radius = 30;

    Attractor a2;
    a2.x = 400;
    a2.y = 200;
    a2.mass = 10;
    a2.radius = 20;

    Attractor a3;
    a3.x = 800;
    a3.y = 900;
    a3.mass = 200;
    a3.radius = 100;

    Target target;
    target.x = 360;
    target.y = 300;
    target.radius = 20;
    
    l->trgt = target;
    l->atrs[0] = a1;
    l->atrs[1] = a2;
    l->atrs[2] = a3;
    l->number_of_attractors = 3;
}


void level_4(Layout* l){
	
    l->blt->x = 100;
    l->blt->y = 800;
    l->blt->vel_x = 0.;
    l->blt->vel_y = 0.; 
    l->blt->radius = 10;

    Attractor a1;
    a1.x = 200;
    a1.y = 200;
    a1.mass = 20;
    a1.radius = 30;

    Attractor a2;
    a2.x = 800;
    a2.y = 200;
    a2.mass = 20;
    a2.radius = 30;

    Target target;
    target.x = 360;
    target.y = 300;
    target.radius = 20;
    
    l->trgt = target;
    l->atrs[0] = a1;
    l->atrs[1] = a2;
    l->number_of_attractors = 2;
}



void level_5(Layout* l){
	
    l->blt->x = 9.;
    l->blt->y = 9.;
    l->blt->vel_x = 0.;
    l->blt->vel_y = 0.; 
    l->blt->radius = 10;

    Attractor a1;
    a1.x = 100;
    a1.y = 100;
    a1.mass = 10;
    a1.radius = 30;

    Attractor a2;
    a2.x = 400;
    a2.y = 200;
    a2.mass = 10;
    a2.radius = 20;

    Target target;
    target.x = 360;
    target.y = 300;
    target.radius = 20;
    
    l->trgt = target;
    l->atrs[0] = a1;
    l->atrs[1] = a2;
    l->number_of_attractors = 2;
}
