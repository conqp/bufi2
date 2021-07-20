cmake_minimum_required(VERSION 3.21)
project(bufi)

set(CMAKE_CXX_STANDARD 20)

add_library(bufi src/bufi.cpp src/FinancingProject.cpp src/FinancingProject.h)
add_executable(unit4 src/unit4.cpp)
target_link_libraries(unit4 bufi)