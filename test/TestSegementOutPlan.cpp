#include "test.h"


static void NotExist(const Vector3D& A, const Vector3D& B, const Vector3D& C) {
    if (!A.is_parallel_to(B) && !B.is_parallel_to(C) && !C.is_parallel_to(A)) {
        TestNotExist(Vector3D(0, 0, 0), B, C, A);
    }
}

TEST(SegmentOutPlane, NotExist) {
    NotExist(Vector3D(1, 0, 0), Vector3D(0, 1, 0), Vector3D(1e4, 1e-4, 0));
    NotExist(Vector3D(1, 1, 0), Vector3D(0, 0, 1), Vector3D(1, 0, 3));
    NotExist(Vector3D(1, 0, 3), Vector3D(1, 0, 0), Vector3D(1, 3, 4));
    NotExist(Vector3D(1, 3, 4), Vector3D(1, 1, 1), Vector3D(1, 0, 0));
    NotExist(Vector3D(1, 0, 0), Vector3D(1.03, 0, 0), Vector3D(0, 1e4, 3));
    NotExist(Vector3D(1, 0, 1e-4), Vector3D(7, 0, 1e4), Vector3D(1, 0, 2));
    NotExist(Vector3D(1, 1e4, 0), Vector3D(0, 1e-4, 1.9), Vector3D(1, 3, 2));
    NotExist(Vector3D(1, 23, 45), Vector3D(1e4, 1e-4, 0), Vector3D(-1, 0, 3));
}