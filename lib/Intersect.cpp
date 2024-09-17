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
    Vector3D BaseX = segment1.getEnd() - segment1.getStart(); // segment1_parallel_base_vector
    Vector3D BaseY = segment2.getStart() - segment1.getStart(); // second base vector on plane <segment1, segment2>
    Vector3D Test = segment2.getEnd() - segment1.getStart(); // test vector


    if (BaseX.is_parallel_to(BaseY)) {
        if (Test.is_parallel_to(BaseY)) {
            if (Test.is_parallel_to(BaseX)) {
                if (BaseX.is_not_zero()) {
                    return BaseX * Intersect1D(0, 1, (BaseX * BaseY) / (BaseX * BaseX), (Test * BaseX) / (BaseX * BaseX)) + segment1.getStart();
                }
                if (BaseY.is_not_zero()) {
                    return BaseY * Intersect1D(0, 0, 1, (Test * BaseY) / (BaseY * BaseY)) + segment1.getStart();
                }
                return segment1.getStart();
            }
            // BaseX||BaseY and NOT BaseX||Test
            // => for create plane base <BaseX, BaseY> 
            // do: swap BaseY and  Test
            std::swap(BaseY, Test);
            // BaseX NOT || BaseY
        }
        else {
            if (BaseX == Vector3D(0, 0, 0)) {
                throw ResultNotExist(); // Segments don't stay straight
            }
            // BaseX||BaseY and NOT BaseX||Test
            // => for create plane base <BaseX, BaseY> 
            // do: swap BaseY and  Test
            std::swap(BaseY, Test);
            // BaseX NOT || BaseY
        }
    }
    else{
        Vector3D Test_norm_x = Test - Test.vector_projection_on(BaseX);
        Vector3D Test_norm_y_x = Test_norm_x - Test_norm_x.vector_projection_on(BaseY);
        if (Test_norm_y_x.is_not_zero()) {
            throw ResultNotExist(); // Segments don't stay straight
        }
    }
    // BaseX,BaseY - base vectors in plane
    double x_x = BaseX * BaseX;
    double y_y = BaseY * BaseY;
    double x_y = BaseX * BaseY;
    // calc cordinates of vector t in <BaseX,BaseY>  
    double test_x = (x_y * (Test * BaseY) - y_y * (Test * BaseX))/(x_y * x_y - x_x * y_y);
    double test_y = (x_y * (Test * BaseX) - x_x * (Test * BaseY))/(x_y * x_y - x_x * y_y);
    if (test_x + test_y <= 1 && test_x >= 0 && test_y <= 0) {
        return BaseX * test_x/(1 - test_y) + segment1.getStart();
    }
    throw ResultNotExist();
}
