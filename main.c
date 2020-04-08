#include <stdio.h>
#include <stdlib.h>
#include "funcs/init.h"
#include "funcs/event.h"
#include "funcs/motion.h"
#include "funcs/renderer.h"

int main(int argc, const char **argv)
{
    if (!init())
    {
        printf("SYSTEM INIT FAILED!\n");
    }
    else
    {
        int granules = 20;
        SDL_Texture *space;

        // Set Target
        // space = fixedSpace(WINDOW_WIDTH, WINDOW_HEIGHT, SDL_PIXELFORMAT_RGBA8888);
        // setTarget(space);

        // all paintings
        SDL_SetRenderDrawColor(render, 137, 255, 48, 255);
        //drawSpace(granules);

        //---Computer Graphic Experiment Homework---//
        //******************************************//
        // drawCircle(render, 200, 200, 100, 1);
        // drawTriangle();
        // drawSideFilling();
        TranslationTransformation(400, 0);
        RotationTransformation(18);
        positiveLeafLine();
        // view texture space for graphic experiment
        viewSpace(space);
        //******************************************//

        // ---------------------------------- //
        // drawRects(Rects, TotalRectsSubPos);
        // ---------------------------------- //

        // Clear Target
        //setTarget(NULL);

        // drawFlower();
        //eventLoop(space, granules);
    }

    return 0;
}