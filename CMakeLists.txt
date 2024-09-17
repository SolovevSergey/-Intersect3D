cmake_minimum_required(VERSION 3.28)

project(Intersect VERSION 0.0.1 LANGUAGES CXX)

add_subdirectory(lib)
add_subdirectory(test)

set(CMAKE_CXX_STANDARD 17)

target_link_libraries(test
PRIVATE gtest
PRIVATE gmock
PRIVATE pthread
PRIVATE Intersect
)
