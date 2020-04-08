#include "event.h"

void freeTable(int row) {
    int i;
    for (i = 0; i < row; ++i) {
        free(Rects[i]);
        free(RectsFilled[i]);
    }
    free(Rects);
    free(RectsFilled);
    free(RectsClickedStore);
}

int eventLoop(SDL_Texture* space, int granuels) {
    int penCount = 0;
    bool penDown = false;
    SubPos subPos = {-1, -1};
    SDL_Event event;
    bool quit = false;
    while (!quit) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                printf("goodbye!\n");
                quit = true;
            }
            if (event.type == SDL_MOUSEMOTION) {
                int x = event.motion.x;
                int y = event.motion.y;
                subPos = globalToLocal(x, y, granuels);
            }
            if (event.type == SDL_MOUSEBUTTONDOWN) {
                penDown = true;
            }
            if (event.type == SDL_MOUSEBUTTONUP) {
                penDown = false;
            }
            if (penDown) {
                if (subPos.row == -1 || subPos.column == -1 || RectsFilled[subPos.row][subPos.column]) continue;
                RectsClickedStore[penCount].row = subPos.row;
                RectsClickedStore[penCount].column = subPos.column;
                RectsFilled[subPos.row][subPos.column] = true;
                ++penCount;
                // printf("{%d %d}", subPos.row, subPos.column);
            }
        }
        SDL_RenderClear(render);
        SDL_RenderCopy(render, space, NULL, NULL);
        previewRect(subPos);
        drawPerfectRect(penCount);
        SDL_RenderPresent(render);
        SDL_Delay(60);
    }
    freeTable(TotalRectsSubPos.row);
    destroyTarget(space);
    SDL_DestroyRenderer(render);
    SDL_DestroyWindow(window);
    SDL_Quit();
    
    return 0;
}

// 专门为图形学实验写的，不要启用
void viewSpace(SDL_Texture* space) {
    SDL_Event event;
    bool quit = false;
    while (!quit) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                printf("goodbye!\n");
                quit = true;
            }
        }
        //SDL_RenderClear(render);
        //SDL_RenderCopy(render, space, NULL, NULL);
        SDL_RenderPresent(render);
        SDL_Delay(60);
    }
    freeTable(TotalRectsSubPos.row);
    destroyTarget(space);
    SDL_DestroyRenderer(render);
    SDL_DestroyWindow(window);
    SDL_Quit();
}