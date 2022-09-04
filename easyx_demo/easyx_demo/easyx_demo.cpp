#include <easyx.h>
#include <stdio.h>


int main()
{
    initgraph(800, 600);

    // 移动逻辑坐标原点到窗口中心
    setorigin(400, 300);

    // 翻转逻辑坐标 y轴，使其向上
    setaspectratio(1, -1);

    // 画圆
    //circle(0, 0, 150);

    // 绘制1000个点
    for (size_t i = 0; i < 1000; i++)
    {
        int x = rand() % (800 + 1) - 400;
        int y = rand() % (600 + 1) - 300;
        putpixel(x, y, WHITE);
    }

    // 绘制同心圆
    for (size_t r = 50; r < 300; r+=50)
    {
        circle(0, 0, r);
    }

    getchar();


    closegraph();

    return 0;
}

