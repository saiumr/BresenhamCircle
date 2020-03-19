#!/bin/bash
gcc main.c funcs/DrawCircle.c funcs/init.c -lSDL2 -o main.out
./main.out
rm main.out
