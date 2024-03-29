#ifndef gameobj_h
#define gameobj_h


typedef struct{
    unsigned int x;
    unsigned int y;
    unsigned int mass;
    unsigned int radius;
} Attractor;


typedef struct{
    unsigned int radius;

    double x;
    double y;

    double vel_x;
    double vel_y;
} Bullet;


typedef struct{
    unsigned int radius;
    unsigned int x;
    unsigned int y;
} Target;


typedef struct{
    Bullet* blt;
    Target trgt;
    unsigned int number_of_attractors;    
    Attractor atrs[10];
} Layout;


#endif
