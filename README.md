# SPlayer-Qt-Framework
SPlayer项目的Qt界面代码，界面是用纯代码实现的，没有借助Qt设计师，也没有任何业务逻辑代码。此代码实现了一个窗口应有的大部分功能，若需要其他功能请自行扩展。

**以前此框架的DWM特性是我自己用Qt函数模拟的，因此原本“真窗口”很多很方便很人性化的功能很难做到，而且也无法与系统紧密结合，仅能做到形似而已，现在我已废弃原来那种简陋的做法，选择引用[@Bringer-of-Light](https://github.com/Bringer-of-Light)的代码仓库[Qt-Nice-Frameless-Window](https://github.com/Bringer-of-Light/Qt-Nice-Frameless-Window)，此仓库是重载nativeEvent使用原生Windows API来做的，效果比以前好很多，支持很多DWM特性，比如窗口阴影和Aero特效等，而且能与系统完美紧密结合。更多其他优点请使用后自行体会。**

## 效果图
![01](/SPlayer/Snapshot/SPlayer.png)

## 注意
- 进度条是自绘控件，这个Widget我没有下工夫设计，应该不如QSlider好用，实际应用时可自行替换为QSlider。
- 所有的按钮都是自绘控件，没有用QPushButton的原因是因为要切贴图，不方便使用样式表。但这种方法换皮肤时比较麻烦，大家可以自行替换为QPushButton，按钮图片使用StyleSheet指定就可以了，换皮肤时只要加载其他样式表按钮的样式也会同时改变，很方便。
- 界面是模仿暴风影音做的，部分按钮贴图也提取自暴风影音。暴风集团拥有暴风影音的外观及其相关贴图素材的一切权利。

## 编译
- ~~如果发现无法编译通过，请删除代码中的所有中文注释及中文标点符号，或将所有代码文件的编码格式改为**UTF-8 BOM**。~~
我已经把所有文件的编码格式都改成**UTF-8 BOM**（MSVC编译器推荐带BOM）了，已经没有这方面的问题了。
- 原来的框架是基于我自己的项目的，因此用到了QOpenGLWidget，现在界面单独提取出来之后就用不到QOpenGLWidget了，但之前手懒所以一直没有去掉对QOpenGLWidget的依赖，现在才去掉，确实是我自己的原因，在此只能对大家说声不好意思了。
- **请使用MSVC编译器编译，并注意安装Windows SDK，否则无法编译通过**（目前已知MinGW编译器编译不过）。

## 许可协议
[MIT](/LICENSE.md)，请查看代码仓库根目录下的[LICENSE.md](/LICENSE.md)文件。
