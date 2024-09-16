cmake_minimum_required(VERSION 3.28)

project(IntersectGoogleTest VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)


set(TEST_SOURCE 
    test.cpp
    TestOneZeroSegment.cpp
    TestParallelSegment.cpp
    TestSegementOutPlan.cpp
    TestSegmentOnPlane.cpp
    TestTwoZeroSegment.cpp
    TestIntersect1D.cpp
)

add_executable(test ${TEST_SOURCE})
