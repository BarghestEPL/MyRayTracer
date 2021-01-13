#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>


// IMAGE
#define FOV 45
#define W 800
#define H 600

typedef struct{
    float x, y, z;
} vec_t;

void vec_sub(vec_t *a, vec_t *b, vec_t *out);
void vec_cross(vec_t *a, vec_t *b, vec_t *out);
void vec_unit(vec_t *v, vec_t *out);

typedef struct{
    vec_t *pos, *dir;
} ray_t;

typedef struct{
    float rad;
    vec_t *pos;
} sphere_t;

SDL_bool sphere_hit(sphere_t *sph, ray_t *ray);