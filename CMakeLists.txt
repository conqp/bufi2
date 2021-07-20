cmake_minimum_required(VERSION 3.19)
project(bufi)

set(CMAKE_CXX_STANDARD 20)

add_library(bufi src/FinancingProject.cpp src/FinancingProject.h src/bufi.cpp src/bufi.h src/functions.h src/InvestmentProject.cpp src/InvestmentProject.h)
add_executable(unit4 src/unit4.cpp)
target_link_libraries(unit4 bufi)