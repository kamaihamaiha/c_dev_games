# 安装 EasyX 

[代码](./../easyx_demo/easyx_demo/easyx_demo.cpp)

- [网址](easyx.cn)
- [在线文档](https://docs.easyx.cn/zh-cn/intro)

## 使用

- [初识图形库](#初识图形库)
- [坐标系统](#坐标系统)
- [基本图形绘制](#基本图形绘制)
- [多边形](#多边形)
- [形状的样式](#形状的样式)

### 初识图形库

- 因为 EasyX内部实现使用 C++语法，因此源文件需要是 C++的扩展名
- 包含头文件：`easyx.h`
- 使用创建窗口函数:
  - 创建: `initgraph()`
  - 删除: `closegraph()`
- 为了避免窗口一闪而过，用 `getchar()` 阻塞   


### 坐标系统
- 物理坐标
  - 原点在左上角
  - 位置不可以改变
- 逻辑坐标
  - 逻辑坐标默认原点在左上角
  - 原点位置可以改变，用 `setorigin(int x, int y);`
  - 翻转逻辑坐标轴的方向：`setaspectratio(float xasp, float yasp);`

### 基本图形绘制
- [安装 EasyX](#安装-easyx)
  - [使用](#使用)
    - [初识图形库](#初识图形库)
    - [坐标系统](#坐标系统)
    - [基本图形绘制](#基本图形绘制)
      - [绘制圆形](#绘制圆形)
      - [绘制点](#绘制点)
        - [随机绘制很多点](#随机绘制很多点)
      - [绘制线](#绘制线)
      - [绘制矩形](#绘制矩形)
      - [绘制椭圆](#绘制椭圆)
      - [绘制圆角矩形](#绘制圆角矩形)
      - [绘制扇形](#绘制扇形)
      - [绘制圆弧](#绘制圆弧)
    - [多边形](#多边形)
  

#### 绘制圆形

- `void circle0(int x, int y, int radius);`

#### 绘制点

- `putpixel(int x, int y, COLORREF color);`
  - 点占一个像素
  - 第三个参数是颜色，可以用符号常量
    - BLACK
    - BLUE
    - GREEN
    - CYAN: 青
    - RED
    - MAGENTA: 紫
    - BROWN
    - YELLOW
    - WHITE

##### 随机绘制很多点

- 用到 `rand()` 函数
  - 该函数返回的是部位负数的随机值
  - 得到取值范围在 [-400, 400]
    - `rand() % (800 + 1) - 400;`
  - 得到取值范围在 [-300, 300]
    - `rand() % (600 + 1) - 300;`
  
#### 绘制线

函数原型: `void line(int x1, int y1, int x2, int y2);`

#### 绘制矩形
函数原型: `void rectangle(int left, int top, int right, int bottom);`

#### 绘制椭圆
函数原型: `void ellipse(int left, int top, int right, int bottom);`
  - left: 椭圆外切矩形的左上角 x 坐标
  - top: 椭圆外切矩形的左上角 y 坐标
  - right: 椭圆外切矩形的右下角 x 坐标
  - bottom: 椭圆外切矩形的右下角 y 坐标
  
#### 绘制圆角矩形
函数原型: `void reoundrect(int left, int top, int right, int bottom, int ellipsewidth, int elllipseheight);`

#### 绘制扇形

函数原型: `void pie(int left, int top, int right, int bottom, double stangle, double endangle);`

#### 绘制圆弧

函数原型: `void pie(int left, int top, int right, int bottom, double stangle, double endangle)`

### 多边形

函数原型: 
- `void polygon(const POINT *points, int num);`: 图形是封闭的
- `void polyline(const POINT *points, int num);`: 图形不是封闭的

- 绘制正五边形
  - 求顶点坐标，需要用到三角函数，引入头文件: `math.h`
  - C 语言的三角函数用的是弧度制