cmake_minimum_required(VERSION 3.16)
project(cpp_learn)

set(CMAKE_CXX_STANDARD 20)

add_executable(Test Test.cpp)
add_executable(string_with_arr string_with_arr.cpp)
add_executable(cin_overflow cin_overflow.cpp)
add_executable(cin_empty_line cin_empty_line.cpp)
add_executable(cin_longer_line cin_longer_line.cpp)
add_executable(cin_with_getline cin_with_getline.cpp)
add_executable(string_demo string_demo.cpp)
add_executable(char_string_comp char_string_comp.cpp)
add_executable(str_io str_io.cpp)