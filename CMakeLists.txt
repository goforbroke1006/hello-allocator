cmake_minimum_required(VERSION 3.16)
project(hello_allocator)

set(CMAKE_CXX_STANDARD 14)

add_executable(hello_allocator main.cpp allocator/linear_allocator.h allocator/stack_allocator.h allocator/__basic.h allocator/__consts.h __types.h)