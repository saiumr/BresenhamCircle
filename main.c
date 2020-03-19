#include <stdio.h>
#include "funcs/init.h"
#include "funcs/DrawCircle.h"

int main(int argc, const char** argv) {
    if (!init()) {
        printf("SYSTEM INIT FAILED!\n");
    }
    else {
        // Example
        drawCircle(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2 - 50, 50, 1);
        drawCircle(WINDOW_WIDTH / 2 + 50, WINDOW_HEIGHT / 2 -50 + 50, 50, 0);
        drawCircle(WINDOW_WIDTH / 2 - 50, WINDOW_HEIGHT / 2 - 50 - 50, 50, 0);
        drawCircle(WINDOW_WIDTH / 2 + 50, WINDOW_HEIGHT / 2 - 50 - 50, 50, 0);
        drawCircle(WINDOW_WIDTH / 2 - 50, WINDOW_HEIGHT / 2 - 50 + 50, 50, 0);
        drawCircle(WINDOW_WIDTH / 2 - 30, WINDOW_HEIGHT - 40, 30, 0);
        drawCircle(WINDOW_WIDTH / 2 + 30, WINDOW_HEIGHT - 90, 30, 0);
        SDL_RenderDrawLine(render, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2 - 50, WINDOW_WIDTH / 2, WINDOW_HEIGHT);
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
    }

    return 0;
}

