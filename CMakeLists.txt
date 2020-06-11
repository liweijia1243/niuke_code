set(PROJECT_NAME Niuke_Code )

project(${PROJECT_NAME})

include_directories("/usr/include/eigen3")

cmake_minimum_required(VERSION 2.8)

set( CMAKE_BUILD_TYPE Release )

set( CMAKE_CXX_FLAGS "-std=c++11" )

add_executable(levenshtein levenshtein.cpp)

add_executable(helloworld 你好.cpp)

add_executable(yanghui_tri 杨辉三角形.cpp)

add_executable(find_7 挑7.cpp)

add_executable(perfect_num perfect_number.cpp)

add_executable(string_add 高精度加法.cpp)

add_executable(piao 机票统计.cpp)

add_executable(zuichang testxx.cpp)

add_executable(24_points 24点.cpp)

add_executable(poker_compare 扑克牌比大小.cpp)
