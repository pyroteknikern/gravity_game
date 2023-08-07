#ifndef gameobj_h
#define gameobj_h

typedef struct{
    int x;
    int y;
    int mass;
    int radius;
} Attractor;

typedef struct{
    double x;
    double y;

    double vel_x;
    double vel_y;
} Bullet;

#endif
