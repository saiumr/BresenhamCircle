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
            SDL_SetRenderDrawColor(render, 0, 0, 0, 255);
        }
    }
    return success;
}

// once started initialized three tables "Rects" "RectsFilled" "TotalRectsSubPos" and malloced "RectsClickedStore"
bool initRectsTable(int sideLength, int rowCraft, int columnCraft, int gap) {
    int i;
    int j;
    TotalRectsSubPos.row = rowCraft;
    TotalRectsSubPos.column = columnCraft;

    // row
    Rects = (SDL_Rect**)malloc(rowCraft * sizeof(SDL_Rect*));
    RectsFilled = (bool**)malloc(rowCraft * sizeof(bool*));

    for (i = 0; i < rowCraft; ++i) {
        // column
        Rects[i] = (SDL_Rect*)malloc(columnCraft * sizeof(SDL_Rect));
        RectsFilled[i] = (bool*)malloc(columnCraft * sizeof(bool));
        for (j = 0; j < columnCraft; ++j) {
            RectsFilled[i][j] = false;
            Rects[i][j].h = sideLength - gap;
            Rects[i][j].w = sideLength - gap;
            Rects[i][j].x = sideLength * (j + 1) + gap;
            Rects[i][j].y = sideLength * (i + 1) + gap;
        }
    }
    RectsClickedStore = (SubPos*)malloc(rowCraft * columnCraft * sizeof(SubPos));

    return true;
}