<<<<<<< HEAD
# 摘要：
在大型项目和商业化项目中，Qt的开发工具应该选择VS Studio+CMake，下面介绍如何在VS2022中创建Qt项目。

# 确认相关程序
## Qt5.15.2
1. 确认下载时Kit选择了msvc2019_64bit、Tools选择了CMake
2. 确认msvc2019_64bit和CMake的路径被写入环境变量。

<!-- 这是一张图片，ocr 内容为： -->
![](https://cdn.nlark.com/yuque/0/2026/png/27393008/1774701347112-64c4c66d-6593-4921-be5c-911f2fd9e2d9.png)

## VS2022
确认VS2022下载并安装了如下两个扩展：

<!-- 这是一张图片，ocr 内容为： -->
![](https://cdn.nlark.com/yuque/0/2026/png/27393008/1774701423807-dc4e1cae-9ac1-4c7f-9eb5-afef903126e0.png)

# 创建项目
打开VS2022，使用如下模板

<!-- 这是一张图片，ocr 内容为： -->
![](https://cdn.nlark.com/yuque/0/2026/png/27393008/1774701586216-fc7f0420-9db3-4f0c-b8c3-9300afe395dc.png)

<font style="color:#DF2A3F;">Build System选择CMake Project for Qt</font>

<!-- 这是一张图片，ocr 内容为： -->
![](https://cdn.nlark.com/yuque/0/2026/png/27393008/1774701651971-0a61f7b4-7b6c-4761-aa2b-0335166e001a.png)

创<font style="color:#DF2A3F;">建好后，如果刚开始就显示CMake生成失败，那么就检查</font>`<font style="color:#DF2A3F;">CMakeUserPresets.json</font>`<font style="color:#DF2A3F;">文件，将</font>`<font style="color:#DF2A3F;">Ninja</font>`<font style="color:#DF2A3F;">修改为</font>`<font style="color:#DF2A3F;">Visual Studio 17 2022</font>`<font style="color:#DF2A3F;">。</font>

<!-- 这是一张图片，ocr 内容为： -->
![](https://cdn.nlark.com/yuque/0/2026/png/27393008/1774701838614-dfe15d35-3b37-44aa-8549-912596f60502.png)

生成成功之后，就可以build看看能否出现窗口了。

# 修改代码结构（可选）
对于大型项目需要将源代码区分开来，目前我们使用如下结构：

<!-- 这是一张图片，ocr 内容为： -->
![](https://cdn.nlark.com/yuque/0/2026/png/27393008/1774701989682-6e05917b-4842-47c3-a6a8-8927c407c896.png)

那么同样的，CMakeLists也应该跟着修改，以适配增加的文件和修改的代码结构。

```cmake
# CMake最低版本
cmake_minimum_required(VERSION 3.16)

# 项目名称
project(New_Qt_ProjectQt)

# 设置C++标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 自动处理Qt元对象、UI、资源文件
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# 指定UI文件搜索路径
set(CMAKE_AUTOUIC_SEARCH_PATHS ${PROJECT_SOURCE_DIR}/src/ui)

# 查找Qt5组件
find_package(Qt5 REQUIRED COMPONENTS Widgets)

# 头文件目录
include_directories(${PROJECT_SOURCE_DIR}/src/include)

# 遍历所有源码
file(GLOB_RECURSE HEADER_FILES ${PROJECT_SOURCE_DIR}/src/include/*.h)
file(GLOB_RECURSE SOURCE_FILES ${PROJECT_SOURCE_DIR}/src/cpp/*.cpp)
file(GLOB_RECURSE UI_FILES ${PROJECT_SOURCE_DIR}/src/ui/*.ui)
# 遍历资源文件
file(GLOB_RECURSE QRC_FILES ${PROJECT_SOURCE_DIR}/src/resources/*.qrc)

# 生成可执行文件
add_executable(${PROJECT_NAME} WIN32
    ${HEADER_FILES}
    ${SOURCE_FILES}
    ${UI_FILES}
    ${QRC_FILES}
)

# 链接Qt5 Widgets库
target_link_libraries(${PROJECT_NAME} PRIVATE Qt5::Widgets)
```

我随便修改了下.ui文件，运行。

<!-- 这是一张图片，ocr 内容为： -->
![](https://cdn.nlark.com/yuque/0/2026/png/27393008/1774702099462-088a35cd-d24e-4c55-a7ac-3e8d558032fd.png)

=======
# New_Qt_Project
创建Qt项目的正确方法
>>>>>>> f0756c147daa7cce7519c4029b940f821f6785b6
