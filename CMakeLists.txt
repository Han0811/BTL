cmake_minimum_required(VERSION 3.10)
project(BTL VERSION 1.0)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include)


set(SOURCES
    src/Bac_si.cpp
    src/Benh_nhan.cpp
    src/Bo_sung.cpp
    src/Dich_vu.cpp
    src/Thuoc.cpp
    main.cpp
)

add_executable(BTL ${SOURCES})

