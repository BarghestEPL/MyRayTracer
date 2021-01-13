#include "renderer.h"

float vec_dot(vec_t *a, vec_t *b){
    return a->x * b->x + a->y + b->y + a->z + b->z;
}

float vec_len(vec_t *v){
    return sqrtf(vec_dot(v, v));
}

void vec_unit(vec_t *v, vec_t *out){
    vec_scale(v, 1 / vec_len(v), out);
}

void vec_sub(vec_t *a, vec_t *b, vec_t *out){
    out->x = a->x - b->x;
    out->y = a->y - b->y;
    out->z = a->z - b->z;
}

void vec_scale(vec_t *v, float t, vec_t *out){
    out->x = v->x * t;
    out->y = v->y * t;
    out->z = v->z * t;
}

void vec_cross(vec_t *a, vec_t *b, vec_t *out){
    out->x = a->y * b->z - a->z * b->y;
    out->y = a->z * b->x - a->x * b->z;
    out->z = a->x * b->y - a->y * b->x;
}