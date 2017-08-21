cmake_minimum_required(VERSION 3.8)
project(study)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c graph/dense_graph.c graph/dense_graph.h graph/sparse_graph.c graph/sparse_graph.h list/list.c list/list.h)
add_executable(study ${SOURCE_FILES})