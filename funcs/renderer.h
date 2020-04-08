#ifndef _RENDERER_
#define _RENDERER_

#include "init.h"

bool setTarget(SDL_Texture* texture);

SDL_Texture* fixedSpace(int width, int height, Uint32 format);

void destroyTarget(SDL_Texture* texture);

SubPos globalToLocal(int x, int y, int granules);

int previewRect(SubPos tableSub);

int drawPerfectRect(int penCount);

#endif