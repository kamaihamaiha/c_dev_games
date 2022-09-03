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
    circle(0, 0, 150);

    getchar();

    closegraph();

    return 0;
}

