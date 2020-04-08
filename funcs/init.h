#ifndef _INIT_H
#define _INIT_H
#include <SDL2/SDL.h>
#include <stdbool.h>
#include <stdlib.h>
#define _GAP 2
#define _SIDE_WINDOW 200
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

typedef struct SubPos {
    int row;
    int column;
}SubPos;

SDL_Window* window;
SDL_Renderer* render;

// rect table
SDL_Rect** Rects;
// check rect filled or not 0 filled 1 not
bool** RectsFilled;
// present filled rect
SubPos* RectsClickedStore;
// actually table width and height for bianli
SubPos TotalRectsSubPos;

bool initRectsTable(int sideLength, int rowCraft, int columnCraft, int gap);

bool init();

#endif