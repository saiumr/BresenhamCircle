#include "init.h"

bool init() {
    bool success = true;

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        SDL_LogError(SDL_LOG_CATEGORY_SYSTEM, "sdl init failed!\n");
        success = false;
    }
    else {
        window = SDL_CreateWindow("viewPort", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                    WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
        if (!window) {
            SDL_LogError(SDL_LOG_CATEGORY_ERROR, "window created failed!\n");
            success = false;
        }
        else {
            render = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
            if (!render) {
                SDL_LogError(SDL_LOG_CATEGORY_RENDER, "render init failed!\n");
                success = false;
            }
            SDL_SetRenderDrawBlendMode(render, SDL_BLENDMODE_BLEND);
            SDL_SetRenderDrawColor(render, 0, 255, 0, 255);
        }
    }
    return success;
}