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
    // TODO: rename x,y,t
    Vector3D x = segment1.getEnd() - segment1.getStart();
    Vector3D y = segment2.getStart() - segment1.getStart();
    Vector3D test = segment2.getEnd() - segment1.getStart();

    if (x.is_parallel_to(y)) {
        if (test.is_parallel_to(y)) {
            if (x.is_not_zero()) {
                return x * Intersect1D(0, 1, (x*y) / (x * x), (test * x) / (x * x)) + segment1.getStart();
            }
            if (y.is_not_zero()) {
                return y * Intersect1D(0, 0, 1, (test * y) / (y * y)) + segment1.getStart();
            }
            return segment1.getStart();
        }
        else {
            // swap x and t 
            std::swap(x, test);
        }
    }
    else{
        // Находятся ли векторы на одной плоскости
        Vector3D test_norm_x = test - test.vector_projection_on(x);
        Vector3D test_norm_y_x = test_norm_x - test_norm_x.vector_projection_on(y);
        if (test_norm_y_x.is_not_zero()) {
            throw ResultNotExist(); // Сегменты не лежат в одной плоскости
        }
    }
    std::terminate();
    // x,y - base vectors in plane
    
    double x_x = x*x;
    double y_y = y*y;
    double x_y = x*y;
    // calc cordinates of vector t in <x,y>  
    double test_x = (x_y * (test*y) - y_y * (test*x))/(x_y*x_y - x_x*y_y);
    double test_y = (x_y * (test*x) - x_x * (test*y))/(x_y*x_y - x_x*y_y);
    if (test_x + test_y <= 1 && test_x <= 0 && test_y >= 0) {
        return y*test_y/(std::abs(test_x) + 1) + segment1.getStart();
    }
    throw ResultNotExist();
}