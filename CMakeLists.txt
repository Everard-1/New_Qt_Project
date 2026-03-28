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