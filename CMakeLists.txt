cmake_minimum_required(VERSION 3.29)
project(single_instance_checker C)

include(FetchContent)

FetchContent_Declare(
        hard_assert
        GIT_REPOSITORY https://github.com/CesarBerriot/hard_assert.git
        GIT_TAG master
)
FetchContent_MakeAvailable(hard_assert)

FetchContent_Declare(
        make_string
        GIT_REPOSITORY https://github.com/CesarBerriot/make_string.git
        GIT_TAG master
)
FetchContent_MakeAvailable(make_string)


add_library(single_instance_checker STATIC single_instance_checker.c)
target_include_directories(single_instance_checker PUBLIC include)
target_compile_options(single_instance_checker PRIVATE -ansi -pedantic-errors -std=c11 -Wall -Wextra)
target_link_libraries(single_instance_checker PRIVATE hard_assert)
target_link_libraries(single_instance_checker PRIVATE make_string)