#include "test.h"

static void OneExist(const Vector3D& A, const Vector3D& B, double alpha) {
    TestOneExist(B, B, B + A * (1 - alpha), B + A*alpha, B);
}

static void NotExist(const Vector3D& A, const Vector3D& B) {
    if(!A.is_parallel_to(B)) {
        TestNotExist(B, B, Vector3D(0, 0, 0), A);   
    }
}


TEST(OneZeroSegment, OneExist) {
    OneExist(Vector3D(1, 0, 0), Vector3D(0, 1, 0), 0.1);
    OneExist(Vector3D(1, 1, 0), Vector3D(0, 0, 1), 0.4);
    OneExist(Vector3D(1, 0, 3), Vector3D(1, 0, 0), 0);
    OneExist(Vector3D(1, 3, 4), Vector3D(1, 1, 1), 1);
    OneExist(Vector3D(1, 0, 0), Vector3D(1.03, 0, 0), 0.7);
    OneExist(Vector3D(1, 0, 1e-4), Vector3D(7, 0, 1e4), 0.9);
    OneExist(Vector3D(1, 1e4, 0), Vector3D(0, 1e-4, 1.9), 0.3);
    OneExist(Vector3D(1, 23, 45), Vector3D(1e4, 1e-4, 0), 0.1);
}

TEST(OneZeroSegment, NotExist) {
    NotExist(Vector3D(1, 0, 0), Vector3D(0, 1, 0));
    NotExist(Vector3D(1, 1, 0), Vector3D(0, 0, 1));
    NotExist(Vector3D(1, 0, 3), Vector3D(1, 0, 0));
    NotExist(Vector3D(1, 3, 4), Vector3D(1, 1, 1));
    NotExist(Vector3D(1, 0, 0), Vector3D(1.03, 0, 0));
    NotExist(Vector3D(1, 0, 1e-4), Vector3D(7, 0, 1e4));
    NotExist(Vector3D(1, 1e4, 0), Vector3D(0, 1e-4, 1.9));
    NotExist(Vector3D(1, 23, 45), Vector3D(1e4, 1e-4, 0));
}
