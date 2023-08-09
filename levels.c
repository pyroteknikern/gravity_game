#include"gameobj.h"
#include"levels.h"

void level_1(Layout* l){

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
