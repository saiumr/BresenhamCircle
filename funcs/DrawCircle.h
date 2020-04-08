#include "init.h"
#define PI 3.141592653
/**
 * \brief Draw a circle filled or not.
 * 
 * \param renderer The renderer which should draw a circle.
 * \param x The x_coordinate of circle center.
 * \param y The y_coordinate of circle center.
 * \param radius The radius of circle.
 * \param flag The mode of circlr with 1 filled or 0 not.
 */
void drawCircle(SDL_Renderer* renderer, int x, int y, int radius, int flag);

void drawTriangle();
void drawSideFilling();

int* mathMatrix(int origin[], double T[][3]);
void TranslationTransformation(int Tx, int Ty);
// 每隔degree画一个小圆
void RotationTransformation(double degree);
void positiveLeafLine();