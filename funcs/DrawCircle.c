#include "DrawCircle.h"
#include <math.h>
// 这里的函数是图形学实验的函数,说白了就是本人的作业
// 不要启用
// 还有 为了看到动态效果 我加了很多SDL_Delay(x)
// 要是谁觉得运行的慢了，就把x的值改小

/**
 * Draw Circle use Bresenham Algo, 
 * Fill Circle use X-ray screen.
 */
void drawCircle(SDL_Renderer* renderer, int x, int y, int radius, int flag) {
    int d = 1 - radius;
    int coordinate_x = 0;
    int coordinate_y = radius;
    int lineCount;
    int point_x;

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

        // I don't know why unuseful suddenly
        // if (flag == 1) {
        //     for (lineCount = 0; lineCount < 2; ++lineCount) {
        //         SDL_RenderDrawLine(renderer, pixelReflect[lineCount].x, pixelReflect[lineCount].y, \
        //         pixelReflect[lineCount + 2].x, pixelReflect[lineCount + 2].y);
        //         SDL_RenderDrawLine(renderer, pixelReflect[lineCount + 4].x, pixelReflect[lineCount + 4].y, \
        //         pixelReflect[lineCount + 6].x, pixelReflect[lineCount + 6].y);
        //     }
        // }

        if (flag == 1) {
            for (point_x = pixelReflect[6].x + 1; point_x < pixelReflect[4].x; ++point_x) {
                SDL_RenderDrawPoint(render, point_x, pixelReflect[6].y);
            }
            for (point_x = pixelReflect[5].x + 1; point_x < pixelReflect[7].x; ++point_x) {
                SDL_RenderDrawPoint(render, point_x, pixelReflect[5].y);
            }
            for (point_x = pixelReflect[2].x + 1; point_x < pixelReflect[0].x; ++point_x) {
                SDL_RenderDrawPoint(render, point_x, pixelReflect[2].y);
            }
            for (point_x = pixelReflect[1].x + 1; point_x < pixelReflect[3].x; ++point_x) {
                SDL_RenderDrawPoint(render, point_x, pixelReflect[1].y);
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

void drawTriangle() {
    SDL_Point p1 = {100, 300};
    SDL_Point p2 = {200, 200};
    SDL_Point p3 = {400, 300};
    SDL_Point Triangle[4] = {p1, p2, p3, p1};

    SDL_RenderDrawLines(render, Triangle, 4);

    float x, y, k1, k2;
    k1 = (float)(p2.y - p1.y) / (p2.x - p1.x);
    k2 = (float)(p3.y - p2.y) / (p3.x - p2.x);

    float xs,xe;
    xs = p2.x;
    xe = p2.x;

    for (y = p2.y; y < p3.y; ++y) {
        for (x = xs; x < xe; ++x) {
            SDL_SetRenderDrawColor(render, 252, 145, 226, 255);
            SDL_RenderDrawPoint(render, x, y);
        }
        xs = xs + 1/k1;
        xe = xe + 1/k2;
        
        SDL_SetRenderDrawColor(render, 137, 255, 48, 255);       
        SDL_RenderDrawLines(render, Triangle, 4);

        SDL_RenderPresent(render);
        SDL_Delay(20);
    }

}

void drawSideFilling() {
    SDL_Point p1 = {20, 20};
    SDL_Point p2 = {20, 200};
    SDL_Point p3 = {200, 200};
    SDL_Point p4 = {200, 20};
    SDL_Point Triangle[5] = {p1, p2, p3, p4, p1};

    SDL_RenderDrawLines(render, Triangle, 5);

    // 求补
    int xs, xe;
    xs = p1.x;
    xe = WINDOW_WIDTH;
    
    int x, y;
    for (y = p1.y; y < p2.y; ++y) {
        for (x = xs; x < xe; ++x) {
            SDL_SetRenderDrawColor(render, 252, 145, 226, 255);
            SDL_RenderDrawPoint(render, x, y);
            
        }

        SDL_SetRenderDrawColor(render, 137, 255, 48, 255);
        SDL_RenderDrawLines(render, Triangle, 5);

        SDL_RenderPresent(render);
        SDL_Delay(10);
    }

    for (y = p1.y; y < p2.y; ++y) {
        for (x = p3.x; x < xe; ++x) {
            SDL_SetRenderDrawColor(render, 0, 0, 0, 255);
            SDL_RenderDrawPoint(render, x, y);
        }

        SDL_SetRenderDrawColor(render, 137, 255, 48, 255);
        SDL_RenderDrawLines(render, Triangle, 5);

        SDL_RenderPresent(render);
        SDL_Delay(10);
    }

}

int* mathMatrix(int origin[], double T[][3]) {
    int i, j, k;
    int* result = (int*)malloc(3*sizeof(int));
    for (i = 0; i< 3; ++i) {
        result[i] = 0;
    }
    for (i = 0; i < 1; ++i) {
        for (j = i; j < 3; ++j) {
            for (k = 0; k < 3; ++k) {
                result[j] += origin[k] * T[k][j];
            }
        }
    }

    return result;
}

// 直线段的平移变换
void TranslationTransformation(int Tx, int Ty) {
    SDL_Point originPiont[2] = {
        {10, 10},
        {100, 150}
    };
    SDL_RenderDrawLines(render, originPiont, 2);

    SDL_Point resultPoint[2] = {
        originPiont[0],
        originPiont[1],
    };

    int origin0[3] = {originPiont[0].x, originPiont[0].y, 1};
    int origin1[3] = {originPiont[1].x, originPiont[1].y, 1};
    
    double Tt[3][3] = {
        {1,  0,  0},
        {0,  1,  0},
        {Tx, Ty, 1}
    };

    int* result0 = mathMatrix(origin0, Tt);
    int* result1 = mathMatrix(origin1, Tt);

    resultPoint[0].x = result0[0];
    resultPoint[0].y = result0[1];
    resultPoint[1].x = result1[0];
    resultPoint[1].y = result1[1];

    SDL_RenderDrawLines(render, resultPoint, 2);
}

// 等分大圆在分点上画小圆
void RotationTransformation(double degree) {
    double radian = degree / 180 * PI;
    // 将屏幕中心当做坐标原点
    // 先画上一个半径100px的圆
    drawCircle(render, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, 100, 0);
    SDL_SetRenderDrawColor(render, 252, 145, 226, 255);
    // bug原因：局部坐标系和全局坐标系之间应该有一个转换(已修改完成)
    // 为了便于理解数据我就这样写了，实际上global<-->local，可以理解为global是全局坐标系下的坐标
    // 由于错误地采用了int类型，在计算旋转矩阵时造成了精度损失，按道理所有小圆的圆心都在大圆圆环上
    int globalCenterCricleMatrix[3] = {100, 0, 1};
    int localCenterCricle[2] = {globalCenterCricleMatrix[0] + WINDOW_WIDTH / 2, -globalCenterCricleMatrix[1] + WINDOW_HEIGHT / 2};
    double Ts[3][3] = {
        {cos(radian),  sin(radian), 0},
        {-sin(radian), cos(radian), 0},
        {0,            0,           1}
    };
    for (int i = 1; i <= 360 / degree; ++i) {
        drawCircle(render, localCenterCricle[0], localCenterCricle[1], 30, 0);
        int* result = mathMatrix(globalCenterCricleMatrix, Ts);
        globalCenterCricleMatrix[0] = result[0];
        globalCenterCricleMatrix[1] = result[1];
        localCenterCricle[0] = result[0] + WINDOW_WIDTH / 2;
        localCenterCricle[1] = -result[1] + WINDOW_HEIGHT / 2;
    }
}

void positiveLeafLine() {
    int a,n,cx,cy,gx,gy,flag,k;
	double r,p,th,x,y,pi;
	a=150;n=5;pi=3.14;
	cx=WINDOW_WIDTH * 3/4;
	cy=WINDOW_HEIGHT * 3/4;
     p=1;
	for(p=1;p>=0.1;p-=0.1)//p是比例系数，控制着r的变换
	{	
		for(th=0;th<=2*pi;th+=pi/2000)
		{	
            r=abs(a*sin(n*th)*p);
            x=(r*cos(th));
            y=(r*sin(th));
            gx=(cx+x);
            gy=(cy+y);
            SDL_SetRenderDrawColor(render, 255*p/2, 0, 255*p/20, 255);
            SDL_RenderDrawPoint(render, gx, gy);
        }
    }

    // 参数方程画圆
    // 以点O（a，b）为圆心，以r为半径的圆的参数方程是 x=a+r·cosθ, y=b+r·sinθ, （其中θ为参数）
    // 以下为测试代码
    /*
    for(th=0;th<=2*pi;th+=pi/2000)
    {	
        r=abs(100*sin(1*th));
        x=(r*cos(th));
        y=(r*sin(th));
        gx=(cx+x);
        gy=(cy+y);
        SDL_SetRenderDrawColor(render, 255*p/2, 0, 255*p/20, 255);
        SDL_RenderDrawPoint(render, gx, gy);
        SDL_RenderDrawPoint(render, 100*cos(th)+cx, 100*sin(th)+cx);
    }
    */
}