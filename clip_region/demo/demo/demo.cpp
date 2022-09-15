#include<stdio.h>
#include<easyx.h>
#include<math.h>

#define PI 3.14

void clipDemo();
void combineDemo();

int main()
{
    initgraph(800, 800);
    setorigin(400, 400);
    setaspectratio(1, -1);

    setbkcolor(WHITE);
    cleardevice();

    // 设置描边
    setlinecolor(BLACK);
    setlinestyle(PS_SOLID, 5);

    // 剪切区域
    // clipDemo();
    combineDemo();

    getchar();
    closegraph();

    return 0;
}

void clipDemo() {

    // 先建立剪切区域
    int radius = 150;
    HRGN rgn = CreateEllipticRgn(250, 250, 550, 550);
    setcliprgn(rgn);


    circle(0, 0, radius);
    for (int i = 0; i < 6; i++) {
        int x = cos(PI / 3 * i) * radius;
        int y = sin(PI / 3 * i) * radius;
        circle(x, y, radius);
    }

    // 绘制完成后，需要将剪切区域设置为空
    setcliprgn(NULL);
    DeleteObject(rgn);  // 销毁区域
}

void combineDemo() {
    int radius = 150;
    HRGN rgn1 = CreateEllipticRgn(250, 250, 550, 550);
    HRGN rgn2 = CreateEllipticRgn(250, 100, 550, 400);
    HRGN rgn = CreateEllipticRgn(0, 0, 0, 0);

    // 组合区域
    CombineRgn(rgn, rgn1, rgn2, RGN_DIFF);
    setcliprgn(rgn);

    circle(0, 0, radius);
    for (int i = 0; i < 6; i++) {
        int x = cos(PI / 3 * i) * radius;
        int y = sin(PI / 3 * i) * radius;
        circle(x, y, radius);
    }

    // 绘制完成后，需要将剪切区域设置为空
    setcliprgn(NULL);
    DeleteObject(rgn);  // 销毁区域
    DeleteObject(rgn1);
    DeleteObject(rgn2);
}


