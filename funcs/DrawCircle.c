#include "init.h"
#include "DrawCircle.h"

/**
 * Draw Circle use Bresenham Algo, 
 * Fill Circle use X-ray screen.
 */
void drawCircle(SDL_Renderer* renderer, int x, int y, int radius, int flag) {
    int d = 1 - radius;
    int coordinate_x = 0;
    int coordinate_y = radius;
    int lineCount;

    // 45 degree is fine
    for (coordinate_x = 0; coordinate_x <= coordinate_y; ++coordinate_x) {
        SDL_Point pixelReflect[8] = {
            {coordinate_x + x, coordinate_y + y},  // 1
            {-coordinate_x + x, -coordinate_y + y},  // 3
            {-coordinate_x + x, coordinate_y + y},  // 2
            {coordinate_x + x, -coordinate_y + y},  // 4
            {coordinate_y + x, coordinate_x + y},  // 1
            {-coordinate_y + x, -coordinate_x + y},  // 3
            {-coordinate_y + x, coordinate_x + y},  // 2
            {coordinate_y + x, -coordinate_x + y}  // 4
        };
        
        SDL_RenderDrawPoints(render, pixelReflect, 8);

        if (flag == 1) {
            for (lineCount = 0; lineCount < 2; ++lineCount) {
                SDL_RenderDrawLine(renderer, pixelReflect[lineCount].x, pixelReflect[lineCount].y, \
                pixelReflect[lineCount + 2].x, pixelReflect[lineCount + 2].y);
                SDL_RenderDrawLine(renderer, pixelReflect[lineCount + 4].x, pixelReflect[lineCount + 4].y, \
                pixelReflect[lineCount + 6].x, pixelReflect[lineCount + 6].y);
            }
        }
        
        if (d > 0) {
            d = d + 2 * (coordinate_x - coordinate_y) + 5;
            --coordinate_y;
        }
        else {
            d = d + 2 * coordinate_x + 3;
            coordinate_y = coordinate_y;
        }
    }
}
