cmake_minimum_required(VERSION 3.24)
project(algorithm_design_sorter)

set(CMAKE_CXX_STANDARD 17)

add_executable(algorithm_design sorter/sort_test.cpp sorter/BaseSorter.h sorter/InsertSorter.h sorter/SorterTester.h sorter/MergeSorter.h)