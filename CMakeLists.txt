cmake_minimum_required(VERSION 3.10)

project(project3)

option(USE_STATIC "Use static library" ON)

add_executable(project3 HW4.c)

add_library(arr_handling
STATIC
    Sortfolder/arr_handler.h
    Sortfolder/gen_arr.c
    Sortfolder/sort.c
    Sortfolder/single_array.c
    Sortfolder/benchmark.c
)

target_link_libraries(HW4 arr_handling)
