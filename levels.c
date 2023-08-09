#include"gameobj.h"
#include"levels.h"
void level_1(Layout* l){
    Bullet bullet;
    bullet.x = 9.;
    bullet.y = 9.;
    bullet.vel_x = 0.;
    bullet.vel_y = 0.; 
    bullet.radius = 10;

    Attractor attractor;
    attractor.x = 100;
    attractor.y = 100;
    attractor.mass = 10;
    attractor.radius = 30;

    Attractor att2;
    att2.x = 400;
    att2.y = 200;
    att2.mass = 10;
    att2.radius = 20;

    Target target;
    target.x = 360;
    target.y = 300;
    target.radius = 20;
    
    l->blt = &bullet;
    l->trgt = target;
    l->atrs[0] = attractor;
    l->atrs[1] = att2;
    l->number_of_attractors = 2;
}
