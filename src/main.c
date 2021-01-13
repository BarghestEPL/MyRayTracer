#include "renderer.h"

// CONSTANT
const vec_t up = {0, 1, 0};
const float fov_rad = 3.14 * FOV * 0.5 / 180;
const float ratio = H / W;

// CAMERA
vec_t cam_pos = {0, 1, 10};
vec_t cam_ang = {0, 3, 0};

// gcc main.c renderer.c -o main -lSDL2main -lSDL2 -lm
int main(int argc, char *argv[]){
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;

    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow("Ray Tracing", 100, 100, W, H, 0);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);

    SDL_bool run = SDL_TRUE;
    while(run){
        SDL_Event event;
        while(SDL_PollEvent(&event)){
            switch(event.type){
                case SDL_QUIT:
                    run = SDL_FALSE;
                    break;
                default:
                    break;
            }
        }

        vec_t eye;
        vec_sub(&cam_ang, &cam_pos, &eye);
        vec_unit(&eye, &eye);

        vec_t vpr;
        vec_cross(&eye, &up, &vpr);
        vec_unit(&vpr, &vpr);

        vec_t vpu;
        vec_cross(&vpr, &eye, &vpu);
        vec_unit(&vpu, &vpu);

        for(int i = 0; i < W; i++){
            for(int j = 0; j < H; j++){

            }
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderPresent(renderer);
        SDL_RenderClear(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return EXIT_SUCCESS;
}