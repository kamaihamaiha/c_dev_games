#include <easyx.h>
#include <stdio.h>
#include <math.h>

#define PI 3.14

typedef struct {
    int x;
    int y;
}Point;

void drawCircle();
void drawDots();
void drawMultiCircle();
void drawTriangle();
void drawTriangle2();
void drawFiveSide(); // 绘制正五边形

int main()
{
    initgraph(800, 600);

    // 移动逻辑坐标原点到窗口中心
    setorigin(400, 300);

    // 翻转逻辑坐标 y轴，使其向上
    setaspectratio(1, -1);

    // 画圆
    // drawCircle();
        

   // drawMultiCircle();

    drawTriangle2();

    drawFiveSide();

    getchar();


    closegraph();

    return 0;
}

void drawCircle() {
    circle(0, 0, 150);
}

void drawMultiCircle() {
    // 绘制同心圆
    for (size_t r = 50; r < 300; r += 50)
    {
        circle(0, 0, r);
    }
}

void drawDots() {
    // 绘制1000个点
    for (size_t i = 0; i < 1000; i++)
    {
        int x = rand() % (800 + 1) - 400;
        int y = rand() % (600 + 1) - 300;
        putpixel(x, y, WHITE);
    }
};

void drawTriangle() {
    // 先确定三个点
    Point p1, p2, p3;
    p1 = {0, 200};
    p2 = { 200, -200 };
    p3 = { -200, -200 };

    line(p1.x, p1.y, p2.x, p2.y);
    line(p2.x, p2.y, p3.x, p3.y);
    line(p3.x, p3.y, p1.x, p1.y);
}

// 使用 EasyX 库提供的 polygon 函数
void drawTriangle2() {
    POINT points[] = { {0, 200}, {200, -200}, {-200, -200} };
    polygon(points, 3);
}

void drawFiveSide() {
    double startAngle = PI / 2;
    double diffAngel = PI * 2 / 5;

    const int side = 5;
    int radius = 200;
    POINT points[side];

    for (size_t i = 0; i < side; i++)
    {
        double curAngle = startAngle + i * diffAngel;
        points[i].x = cos(curAngle) * radius;
        points[i].y = sin(curAngle) * radius;
    }

    polygon(points, side);
}

