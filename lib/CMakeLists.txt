cmake_minimum_required(VERSION 3.28)

project(IntersectLib VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)


set(LIB_SOURCE 
    Exception.cpp
    Intersect.cpp
    Segment3D.cpp
    Vector3D.cpp
)

add_library(Intersect ${LIB_SOURCE})
