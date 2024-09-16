#include "Intersect.hpp"


double Intersect1D(double x1, double x2, double y1, double y2) {
    // function claculates intersection between two 1D segments
    double start = std::max(std::min(x1, x2), std::min(y1, y2));
    double end = std::min(std::max(x1, x2), std::max(y1, y2));
    if (start == end) {
        return start;
    }
    if (start < end) {
        throw ResultExistMany();
    }
    throw ResultNotExist();
}

Vector3D Intersect(const Segment3D& segment1, const Segment3D& segment2) {
    // calc basic vectors 
    // TODO: rename X,Y,t
    Vector3D X = segment1.getEnd() - segment1.getStart();
    Vector3D Y = segment2.getStart() - segment1.getStart();
    Vector3D Test = segment2.getEnd() - segment1.getStart();


    if (X.is_parallel_to(Y)) {
        if (Test.is_parallel_to(Y)) {
            if (Test.is_parallel_to(X)) {
                if (X.is_not_zero()) {
                    return X * Intersect1D(0, 1, (X * Y) / (X * X), (Test * X) / (X * X)) + segment1.getStart();
                }
                if (Y.is_not_zero()) {
                    return Y * Intersect1D(0, 0, 1, (Test * Y) / (Y * Y)) + segment1.getStart();
                }
                return segment1.getStart();
            }
            std::swap(Y, Test);
        }
        else {
            if (X == Vector3D(0, 0, 0)) {
                throw ResultNotExist(); // Сегменты не лежат на прямой
            }

            // swap Y and  Test for create plane base <X, Y>: X||Y and NOT X||Test
            std::swap(Y, Test);
        }
    }
    else{
        // Находятся ли векторы на одной плоскости
        Vector3D Test_norm_x = Test - Test.vector_projection_on(X);
        Vector3D Test_norm_y_x = Test_norm_x - Test_norm_x.vector_projection_on(Y);
        if (Test_norm_y_x.is_not_zero()) {
            throw ResultNotExist(); // Сегменты не лежат в одной плоскости
        }
    }
    // std::terminate();
    // X,Y - base vectors in plane
    
    double x_x = X*X;
    double y_y = Y*Y;
    double x_y = X*Y;
    // calc cordinates of vector t in <X,Y>  
    double test_x = (x_y * (Test*Y) - y_y * (Test*X))/(x_y*x_y - x_x*y_y);
    double test_y = (x_y * (Test*X) - x_x * (Test*Y))/(x_y*x_y - x_x*y_y);
    if (test_x + test_y <= 1 && test_x >= 0 && test_y <= 0) {
        return X*test_x/(1 - test_y) + segment1.getStart();
    }
    throw ResultNotExist();
}

/* 
[  FAILED  ] OneZeroSegment.NotExist
[  FAILED  ] OutPlanSegment.NotExist
[  FAILED  ] OnPlaneSegment.OneExist
// 
[  FAILED  ] OneZeroSegment.NotExist
[  FAILED  ] OnPlaneSegment.OneExist
*/