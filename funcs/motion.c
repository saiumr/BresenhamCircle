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