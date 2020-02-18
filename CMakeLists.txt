# 指定cmake的版本
cmake_minimum_required(VERSION 3.14)

# 设置项目信息
project(algorithm)

# 设置变量的值
set(CMAKE_CXX_STANDARD 11)

add_library(sort sort/sort.cpp sort/sort.h)
add_library(search search/search.cpp search/search.h)
add_library(string "string/string.cpp" "string/string.h")

link_libraries(sort)
link_libraries(search)
link_libraries(string)

# 添加生成的目标文件及依赖
add_executable(algorithm main.cpp)

