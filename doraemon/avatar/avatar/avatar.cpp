#include <stdio.h>
#include <easyx.h>

#define PI 3.14

void sleep();
void sleepShort();

// 绘制哆啦A梦头像
int main()
{
    
    // 初始化窗体 1080 * 1024
    initgraph(1080, 1024);

    // 背景色为 白色
    setbkcolor(WHITE);
    cleardevice();

    // step1 绘制头部：椭圆
    setlinecolor(BLACK);
    setlinestyle(PS_SOLID, 10);

    setfillcolor(BLUE);
    fillellipse(118, 125, 990, 931);
    sleep();

    // step2 绘制脸部：椭圆
    setlinecolor(BLACK);
    setlinestyle(PS_SOLID, 10);

    setfillcolor(WHITE);
    fillellipse(189, 271, 919, 931);
    sleep();

    // step3 绘制眼睛：眼眶（椭圆） + 眼珠（同心圆）
    fillellipse(375, 170, 555, 420); // 眼眶1
    fillellipse(555, 170, 735, 420); // 眼眶2

    setfillcolor(BLACK);
    solidcircle(484, 333, 25);
    solidcircle(617, 333, 25);
    sleep();

    setfillcolor(WHITE);
    fillcircle(484, 333, 10);
    fillcircle(617, 333, 10);
    sleep();

    // step4 绘制鼻子
    setfillcolor(RED);
    fillcircle(554, 420, 32);
    line(554, 455, 554, 825);
    sleep();

    // step5 绘制嘴巴：弧形
    arc(320, 510, 789, 827, PI, PI * 2);
    sleep();

    // step6 绘制胡须
    line(125, 313, 296, 410);
    sleepShort();
    line(83, 444, 270, 474);
    sleepShort();
    line(83, 595, 262, 537);
    sleepShort();
    line(819, 414, 990, 320);
    sleepShort();
    line(845, 478, 1029, 448);
    sleepShort();
    line(853, 542, 1029, 660);

    getchar();
    closegraph();
}

void sleep() {
    Sleep(1000);
}

void sleepShort() {
    Sleep(300);
}
