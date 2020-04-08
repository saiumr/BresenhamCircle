#include "renderer.h"

bool setTarget(SDL_Texture* texture) {
    return SDL_SetRenderTarget(render, texture) == 0 ? true : false;
}

SDL_Texture* fixedSpace(int width, int height, Uint32 format) {
    return SDL_CreateTexture(render, format, 
                    SDL_TEXTUREACCESS_TARGET,
                    width, height);
}

void destroyTarget(SDL_Texture* texture) {
    if (texture) SDL_DestroyTexture(texture);
}

SubPos globalToLocal(int x, int y, int granules) {
    SubPos penSubPos;
    // nnmmb!!!!! make the same mistake again
    penSubPos.column = x / granules - 1;
    penSubPos.row = y / granules - 1;

    // over table range
    if (penSubPos.column > TotalRectsSubPos.column) {
        penSubPos.row = -1;
        penSubPos.column = -1;
    }

    // mei shen me dio yong de debug
    // printf("{%d %d}", penSubPos.row, penSubPos.column);

    return penSubPos;
}

int previewRect(SubPos tableSub) {
    if (tableSub.row == -1 || tableSub.column == -1) return 1;
    SDL_SetRenderDrawColor(render, 255, 255, 255, 100);
    SDL_RenderFillRect(render, &Rects[tableSub.row][tableSub.column]);
    return 0;
}

int drawPerfectRect(int penCount) {
    int i;
    if (penCount < 1) return 1;
    SDL_SetRenderDrawColor(render, 255, 255, 255, 255);
    for (i = 0; i < penCount; ++i) {
        SDL_RenderFillRect(render, &Rects[RectsClickedStore[i].row][RectsClickedStore[i].column]);
    }
    return 0;
}
