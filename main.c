#include <stdio.h>
#include "funcs/init.h"
#include "funcs/event.h"
#include "funcs/motion.h"
#include "funcs/renderer.h"

int main(int argc, const char** argv) {
    if (!init()) {
        printf("SYSTEM INIT FAILED!\n");
    }
    else {
        drawFlower();
        eventLoop();
    }

    return 0;
}

