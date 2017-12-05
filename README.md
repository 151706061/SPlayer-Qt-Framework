# SPlayer-Qt-Framework
SPlayer项目的Qt界面代码，界面是用纯代码实现的，没有借助Qt设计师，也没有任何业务逻辑代码。此代码实现了一个窗口应有的大部分功能，若需要其他功能请自行扩展。

**以前此框架的DWM特性是我自己用Qt函数模拟的，因此原本“真窗口”很多很方便很人性化的功能很难做到，而且也无法与系统紧密结合，仅能做到形似而已，现在我已废弃原来那种简陋的做法，选择引用[@Bringer-of-Light](https://github.com/Bringer-of-Light)的代码仓库[Qt-Nice-Frameless-Window](https://github.com/Bringer-of-Light/Qt-Nice-Frameless-Window)，此仓库是重载nativeEvent使用原生Windows API来做的，效果比以前好很多，支持很多DWM特性，比如窗口阴影和Aero特效等，而且能与系统完美紧密结合。更多其他优点请使用后自行体会。**

## 效果图
![01](/SPlayer/Snapshot/SPlayer.png)

## 注意
- 进度条是自绘控件，这个Widget我没有下工夫设计，应该不如QSlider好用，实际应用时可自行替换为QSlider。
- 所有的按钮都是自绘控件，没有用QPushButton的原因是因为要切贴图，不方便使用样式表。但这种方法换皮肤时比较麻烦，大家可以自行替换为QPushButton，按钮图片使用StyleSheet指定就可以了，换皮肤时只要加载其他样式表按钮的样式也会同时改变，很方便。
- 界面是模仿暴风影音做的，部分按钮贴图也提取自暴风影音。暴风集团拥有暴风影音的外观及其相关贴图素材的一切权利。
- **请尽量使用最新版的MSVC编译器，并安装最新版的Windows SDK。MinGW及其他编译环境未测试，无法保证一定能编译通过。我只用VS，VS下有问题可以一起探讨，其他环境下出现问题不要找我。**

## 克隆或下载
1. Git命令行克隆**【推荐】**

```text
git clone --recursive https://github.com/wangwenx190/SPlayer-Qt-Framework.git
```

或者

```text
git clone https://github.com/wangwenx190/SPlayer-Qt-Framework.git
git submodule update --init --recursive
```

如果某个子模块更新失败，请尝试以下命令：

```text
git submodule foreach --recursive git fetch --tags
```

然后重新运行更新：

```text
git submodule update --init --recursive
```

2. 浏览器直接下载**【不推荐】**

您可以直接用浏览器下载GitHub提供的压缩包，但这个压缩包是不包含子模块的，请您自行下载对应版本的子模块后解压到正确的位置。

## 许可协议
```text
MIT License

Copyright (c) 2017 wangwenx190

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
```
