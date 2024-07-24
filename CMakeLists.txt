cmake_minimum_required(VERSION 3.27)

project(sl C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -pedantic")

add_library(sl STATIC src/sl.c src/sl.h)
set_target_properties(sl PROPERTIES PUBLIC_HEADER sl.h)

find_program(M4 m4)
if (M4)
    add_custom_target(sl.h ALL COMMAND m4 -I${CMAKE_SOURCE_DIR} src/sl.m4 > ${CMAKE_BINARY_DIR}/sl.h DEPENDS src/sl.c src/sl.h)
    message(STATUS "generated ${CMAKE_BINARY_DIR}/sl.h")
else ()
    message(WARNING "m4 not found, sl.h will not be generated")
endif ()

enable_testing()

add_executable(sl_test src/sl_test.c src/sl.c)
add_test(NAME sl_test COMMAND sl_test)