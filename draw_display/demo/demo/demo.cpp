#include <stdio.h>
#include <easyx.h>

int main()
{
    initgraph(800, 600);

    setbkcolor(WHITE);
    cleardevice();

    // 1. 绘制圆角矩形
    setfillcolor(RGB(232, 235, 240));
    solidroundrect(100, 50, 700, 450, 20, 20);

    // 2. 绘制蓝黑色矩形
    setfillcolor(RGB(71, 78, 94));
    solidrectangle(100, 390, 700, 410);

    // 3. 绘制蓝黑色圆角矩形
    solidroundrect(100, 50, 700, 410, 20, 20);

    // 4. 绘制天蓝色矩形屏幕
    setfillcolor(RGB(115, 199, 235));
    solidrectangle(120, 70, 680, 390);

    // 5. 绘制银色圆形摄像头
    setfillcolor(RGB(232, 235, 240));
    solidcircle(400, 60, 5);

    // 6. 绘制蓝黑色圆形开机键
    setfillcolor(RGB(71, 78, 94));
    solidcircle(400, 430, 12);

    // 7. 绘制深灰色椭圆底座
    setfillcolor(RGB(218, 219, 224));
    solidellipse(275, 515, 525, 545);

    // 8. 绘制银色梯形支架. 就是绘制多边形
    setfillcolor(RGB(232, 235, 240));
    POINT bigTrapezoid[4] = {
        {345, 450},
        {455, 450},
        {475, 530},
        {325, 530}
    };
    solidpolygon(bigTrapezoid, 4);

    // 9. 绘制深灰色梯形阴影
    setfillcolor(RGB(218, 219, 224));
    POINT smallTrapezoid[4] = {
        {345, 450},
        {455, 450},
        {460, 470},
        {340, 470}
    };
    solidpolygon(smallTrapezoid, 4);


    getchar();
    closegraph();
    
    return 0;
}


