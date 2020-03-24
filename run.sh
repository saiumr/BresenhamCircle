#!/bin/bash
gcc main.c funcs/DrawCircle.c funcs/init.c funcs/motion.c funcs/event.c funcs/renderer.c -lSDL2 -o main.out
./main.out
rm main.out
