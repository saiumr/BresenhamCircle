#include "event.h"

int eventLoop() {
    SDL_Event event;
    bool quit = false;
    while (!quit) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                printf("goodbye!\n");
                quit = true;
            }
        }
        SDL_RenderPresent(render);
        SDL_Delay(100);
    }
    SDL_DestroyRenderer(render);
    SDL_DestroyWindow(window);
    SDL_Quit();
    
    return 0;
}