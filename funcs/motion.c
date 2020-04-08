#include "motion.h"

void drawFlower() {
    // Example
        drawCircle(render, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2 - 50, 50, 1);
        drawCircle(render, WINDOW_WIDTH / 2 + 50, WINDOW_HEIGHT / 2 -50 + 50, 50, 0);
        drawCircle(render, WINDOW_WIDTH / 2 - 50, WINDOW_HEIGHT / 2 - 50 - 50, 50, 0);
        drawCircle(render, WINDOW_WIDTH / 2 + 50, WINDOW_HEIGHT / 2 - 50 - 50, 50, 0);
        drawCircle(render, WINDOW_WIDTH / 2 - 50, WINDOW_HEIGHT / 2 - 50 + 50, 50, 0);
        drawCircle(render, WINDOW_WIDTH / 2 - 30, WINDOW_HEIGHT - 40, 30, 0);
        drawCircle(render, WINDOW_WIDTH / 2 + 30, WINDOW_HEIGHT - 90, 30, 0);
        SDL_RenderDrawLine(render, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2 - 50, WINDOW_WIDTH / 2, WINDOW_HEIGHT);
}

void drawSpace(int Granules) {
    int lineWidthLen = WINDOW_WIDTH - Granules;
    int lineHeightLen = WINDOW_HEIGHT - Granules;
    int i;
    int j;
    int line;

    int trueWlength = 0;
    int trueHlength = 0;

    // added side window
    for (i = 1; trueWlength + _SIDE_WINDOW < lineWidthLen; ++i) {
        trueWlength = i * Granules;
    }

    for (j = 1; trueHlength < lineHeightLen; ++j) {
        trueHlength = j * Granules;
    }

    SDL_SetRenderDrawColor(render, 193, 193, 193, 100);
    for (line = 0; line < j; ++line) {
        SDL_RenderDrawLine(render, Granules, (line + 1) * Granules, trueWlength, (line + 1) * Granules);
    }

    for (line = 0; line < i; ++line) {
        SDL_RenderDrawLine(render, (line + 1) * Granules, Granules, (line + 1) * Granules, trueHlength);
    }
    SDL_SetRenderDrawColor(render, 0, 0, 0, 255);

    initRectsTable(Granules, j - 2, i - 2, _GAP);
}

void drawRects(SDL_Rect** table, SubPos tableSub) {
    int i;
    SDL_SetRenderDrawColor(render,149, 207, 167, 120);
    for (i = 0; i < tableSub.row; ++i) {
        SDL_RenderFillRects(render, table[i], tableSub.column);
    }
    SDL_SetRenderDrawColor(render, 0, 0, 0, 255);
}
