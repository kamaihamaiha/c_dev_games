## 安装 EasyX 

[代码](./../easyx_demo/easyx_demo/easyx_demo.cpp)

- [网址](easyx.cn)
- [在线文档](https://docs.easyx.cn/zh-cn/intro)

### 使用

- 因为 EasyX内部实现使用 C++语法，因此源文件需要是 C++的扩展名
- 包含头文件：`easyx.h`
- 使用创建窗口函数:
  - 创建: `initgraph()`
  - 删除: `closegraph()`
- 为了避免窗口一闪而过，用 `getchar()` 阻塞   
- 绘制圆形
- 物理坐标
  - 原点在左上角
  - 位置不可以改变
- 逻辑坐标
  - 逻辑坐标默认原点在左上角
  - 原点位置可以改变，用 `setorigin(int x, int y);`
  - 翻转逻辑坐标轴的方向：`setaspectratio(float xasp, float yasp);`
  

#### 绘制圆形

- `circle()`
