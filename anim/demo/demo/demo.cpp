#include <stdio.h>
#include <easyx.h>
#include <math.h>

#define PI 3.14

void drawStar(int radius, double start_angle, int offsetX, int offsetY);

void loop_line();

int main()
{
    
    initgraph(800, 600);
    setorigin(400, 300);
    setaspectratio(1, -1);

    setbkcolor(RGB(164, 225, 202));
    cleardevice();
    setfillcolor(WHITE);
    setpolyfillmode(WINDING); // 这个填充模式下，五角星会被填满

    
   // loop_line();


    int loop_radius = 200;
    POINT loop_center;
    double diff_angle = PI / 30;
    int frame = 0;
    
    while (1) {

        loop_center.x = cos(PI / 2 + frame * diff_angle) * loop_radius;
        loop_center.y = sin(PI / 2 + frame * diff_angle) * loop_radius;
        frame++;
        cleardevice();
        drawStar(40, PI / 2 + frame * diff_angle * 2, loop_center.x, loop_center.y);
        Sleep(40);
    }


    getchar();
    closegraph();

    return 0;
}

void loop_line() {
    int x = -400, y = 0;
    int radius = 60;
    int dx = 5;

    while (1) {

        cleardevice();
        drawStar(radius, PI / 2, x, y);
        Sleep(40);

        x = x + dx;

        if (x == -400 || x == 400) {
            dx = -dx;
        }
    }
}

void drawStar(int radius, double start_angle, int offsetX, int offsetY) {
    /*
    * 绘制五角星
    * 1. 确定5个点（圆上等分）
    * 2. 用三角函数计算点的坐标
    * 3. 连接非相邻的点
    */ 

    // const double start_angle = PI / 2;
    const double delta = 2 * PI / 5;

    int size = 5;
    //int radius = 60;
    POINT points[5];
    
    for (int i = 0; i < size; i++) {
        points[i].x = cos(start_angle + i * 2 * delta) * radius + offsetX;
        points[i].y = sin(start_angle + i * 2 * delta) * radius + offsetY;
    }

    solidpolygon(points, size);
    
}
