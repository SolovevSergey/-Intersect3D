#include "test.h"


static void OneExist(const Vector3D& A){
    Vector3D O = Vector3D(0, 0, 0);
    TestOneExist(O, A, A, A*2, A);
}

static void ManyExist(const Vector3D& A) {
    TestManyExist(A, A*3, A*2, A*4);
}

static void NotExist(const Vector3D& A) {
    TestNotExist(A, A*2, A*3, A*4);
}

TEST(SegmentParallel, OneExist) {
    OneExist(Vector3D(1, 0, 0));
    OneExist(Vector3D(0, 0, 1));
    OneExist(Vector3D(0, 1, 0));
    OneExist(Vector3D(1, 1, 1));
    OneExist(Vector3D(1.03, 0, 0));
    OneExist(Vector3D(7, 0, 1e4));
    OneExist(Vector3D(0, 1e-4, 1.9));
    OneExist(Vector3D(1e4, 1e-4, 0));
}

TEST(SegmentParallel, NotExist) {
    NotExist(Vector3D(1, 0, 0));
    NotExist(Vector3D(0, 0, 1));
    NotExist(Vector3D(0, 1, 0));
    NotExist(Vector3D(1, 1, 1));

    NotExist(Vector3D(1.03, 0, 0));
    NotExist(Vector3D(7, 0, 1e4));
    NotExist(Vector3D(0, 1e-4, 1.9));
    NotExist(Vector3D(1e4, 1e-4, 0));
}

TEST(SegmentParallel, ManyExist) {
    ManyExist(Vector3D(1, 0, 0));
    ManyExist(Vector3D(0, 0, 1));
    ManyExist(Vector3D(0, 1, 0));
    ManyExist(Vector3D(1, 1, 1));

    ManyExist(Vector3D(1.03, 0, 0));
    ManyExist(Vector3D(7, 0, 1e4));
    ManyExist(Vector3D(0, 1e-4, 1.9));
    ManyExist(Vector3D(1e4, 1e-4, 0));
}