#include<stdio.h>
#include<easyx.h>

int main()
{
	initgraph(800, 600);
	setbkcolor(RGB(169, 92, 10));
	cleardevice();

	// draw ears & ears shadow & ears highlight
	int radius = 90;
	setfillcolor(RGB(130, 69, 4)); // 绘制耳朵阴影
	solidcircle(200, 130, radius);
	solidcircle(600, 130, radius);

	setfillcolor(RGB(255, 178, 50)); // 绘制耳朵
	solidcircle(200, 120, radius);
	solidcircle(600, 120, radius);

	// 绘制高亮区域
	HRGN rgnLeft = CreateEllipticRgn(100, 30, 290, 210);
	HRGN rgnRight = CreateEllipticRgn(510, 30, 690, 210);
	HRGN rgnDst = CreateEllipticRgn(0, 0, 0, 0);

	CombineRgn(rgnDst, rgnLeft, rgnRight, RGN_OR);
	setcliprgn(rgnDst); // 设置裁剪区域

	setfillcolor(RGB(243, 154, 2)); 
	solidcircle(200, 130, radius);
	solidcircle(600, 130, radius);

	// 绘制耳朵里面的下半部分浅色橄榄型区域
	setfillcolor(RGB(255, 178, 50));
	solidcircle(200, 210, 90);
	solidcircle(600, 210, 90);

	// 取消剪切区域
	DeleteObject(rgnLeft);
	DeleteObject(rgnRight);
	DeleteObject(rgnDst);
	setcliprgn(NULL);

	// 绘制头部 & 高光
	setfillcolor(RGB(255, 178, 50));
	solidcircle(400, 300, 250);

	// 创建剪切区域
	HRGN headRgn = CreateEllipticRgn(150, 50, 650, 550);
	setcliprgn(headRgn);
	setfillcolor(RGB(243, 154, 2));
	solidcircle(400, 320, 250);
	DeleteObject(headRgn);
	setcliprgn(NULL);

	// 绘制眼睛
	setfillcolor(RGB(51, 34, 8));
	solidcircle(275, 300, 25);
	solidcircle(525, 300, 25);

	
	// 绘制嘴巴
	setfillcolor(RGB(130, 69, 4));
	solidellipse(310, 385, 490, 485);
	setfillcolor(WHITE);
	solidellipse(310, 380, 490, 480);

	// 绘制鼻子和胡须
	setfillcolor(RGB(51, 34, 8));
	solidcircle(400, 420, 15);

	setlinestyle(PS_SOLID, 3);
	setlinecolor(RGB(51, 34, 8));
	line(400, 420, 370, 450);
	line(400, 420, 430, 450);


	getchar();

	getchar();
	closegraph();

	return 0;
}

