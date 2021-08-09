cmake_minimum_required(VERSION 3.19)
project(my_memory_pool)

set(CMAKE_CXX_STANDARD 14)

add_executable(my_memory_pool main.cpp src/memory/memory_pool.cpp include/memory/memory_pool.h src/memory/memory_chunk.cpp include/memory/memory_chunk.h src/memory/memory_cell.cpp include/memory/memory_cell.h include/common.h include/gc/interface/gc_factory.h src/gc/mark_clean.cpp include/gc/mark_clean.h)