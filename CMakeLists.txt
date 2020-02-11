# 指定cmake的版本
cmake_minimum_required(VERSION 3.14)

# 设置项目信息
project(algorithm)

# 设置变量的值
set(CMAKE_CXX_STANDARD 11)

add_library(sort sort/sort.cpp sort/sort.h)
link_libraries(sort)

# 添加生成的目标文件及依赖
add_executable(algorithm main.cpp)

