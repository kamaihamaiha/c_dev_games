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
void drawLines();
void drawSun();
void resetBg();

void drawBg();

void drawRainBow();
void drawSky();
void drawRainBowCircle();

int main()
{
    //initgraph(800, 600);

    // 移动逻辑坐标原点到窗口中心
    //setorigin(400, 300);

    // 翻转逻辑坐标 y轴，使其向上
    //setaspectratio(1, -1);

    //resetBg();

    // 画圆
    // drawCircle();
        

   // drawMultiCircle();

    // drawTriangle2();

    //drawFiveSide();

    //drawLines();

    //drawSun();

    //getchar();


    //closegraph();

    //drawRainBow();

    drawSky();

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

/*
* 绘制多重类型的线段
*/
void drawLines() {

    // 描边样式
    setlinestyle(PS_SOLID, 4); // 实线
    line(-300, 200, 300, 200);

    setlinestyle(PS_DASH, 4); // 虚线
    line(-300, 150, 300, 150);

    setlinestyle(PS_DOT, 4); // 点线
    line(-300, 100, 300, 100);

    setlinestyle(PS_DASHDOT, 4); // 
    line(-300, 50, 300, 50);

    setlinestyle(PS_DASHDOTDOT, 4); // 
    line(-300, 0, 300, 0);

    setlinestyle(PS_NULL, 4); // 不可见
    line(-300, -50, 300, -50);

    // 端点样式
    setlinestyle(PS_ENDCAP_ROUND, 16);
    line(-300, -100, 300, -100);

    setlinestyle(PS_ENDCAP_SQUARE, 16);
    line(-300, -150, 300, -150);

    setlinestyle(PS_ENDCAP_FLAT, 16);
    line(-300, -200, 300, -200);

    // 连接样式
    setlinestyle(PS_JOIN_BEVEL, 64);
    POINT points1[3] = { {-150, 100}, {0, 200}, {150, 100}};
    polyline(points1, 3);

    setlinestyle(PS_JOIN_MITER, 64);
    POINT points2[3] = { {-150, 0}, {0, 100}, {150, 0} };
    polyline(points2, 3);

    setlinestyle(PS_JOIN_ROUND, 64);
    POINT points3[3] = { {-150, -100}, {0, 0}, {150, -100} };
    polyline(points3, 3);

    drawBg();
}

void drawSun() {
    setfillcolor(RED);
    solidcircle(200, 200, 80);
}

void resetBg() {

    setbkcolor(YELLOW);
    cleardevice();
}

void drawBg() {
    // 把背景色设置为天蓝色
    setbkcolor(RGB(134, 172, 242));
    cleardevice();
}

// 使用了 hsv 颜色
void drawRainBow() {

    initgraph(800, 600);
    float diffH = 360.0 / 600;
    float h = 0;
    for (size_t y = 0; y < 600; y++)
    {
        setlinecolor(HSVtoRGB(h, 1, 1));
        line(0, y, 800, y);
        h += diffH;
    }

    getchar();
    closegraph();
}

void drawSky() {
    initgraph(800, 600);
    float s = 0.76; // 最大饱和度
    float diffS = s / 600;

    for (size_t y = 0; y < 600; y++)
    {
        setlinecolor(HSVtoRGB(216, s, 0.95));
        line(0, y, 800, y);
        s -= diffS;
    }

    drawRainBowCircle();

    getchar();
    closegraph();
}

void drawRainBowCircle(){

    float max_radius = 200;
    float min_radius = 140;
    float h = 0;
    float diffH = 360.0 / (max_radius - min_radius);

    for (size_t y = min_radius; y < max_radius; y++)
    {
        setlinecolor(HSVtoRGB(h, 1, 1));
        circle(400, 600, y);
        h += diffH;
    }
   
}

