#ifndef _INIT_H
#define _INIT_H
#include <SDL2/SDL.h>
#include <stdbool.h>
#include <stdlib.h>
#define _GAP 2
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

typedef struct SubPos {
    int row;
    int column;
}SubPos;

SDL_Window* window;
SDL_Renderer* render;

SDL_Rect** Rects;

bool init();

SubPos initRectsTable(int sideLength, int rowCraft, int columnCraft, int gap);

SubPos RectsSubPos;

#endif