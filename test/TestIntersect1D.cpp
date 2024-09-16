#include "test.h"


static void OneExist(double x1, double x2, double y1, double y2, double result) {
    EXPECT_EQ(Intersect1D(x1, x2, y1, y2), result);
    EXPECT_EQ(Intersect1D(x1, x2, y2, y1), result);
    EXPECT_EQ(Intersect1D(x2, x1, y1, y2), result);
    EXPECT_EQ(Intersect1D(x2, x1, y2, y1), result);
    EXPECT_EQ(Intersect1D(y1, y2, x1, x2), result);
    EXPECT_EQ(Intersect1D(y1, y2, x2, x1), result);
    EXPECT_EQ(Intersect1D(y2, y1, x1, x2), result);
    EXPECT_EQ(Intersect1D(y2, y1, x2, x1), result);
}

TEST(TestIntersect1D, OneExist) {
    OneExist(0, 1, 1, 2, 1);
}


static void NotExist(double x1, double x2, double y1, double y2) {
    EXPECT_THROW(Intersect1D(x1, x2, y1, y2), ResultNotExist);
    EXPECT_THROW(Intersect1D(x1, x2, y2, y1), ResultNotExist);
    EXPECT_THROW(Intersect1D(x2, x1, y1, y2), ResultNotExist);
    EXPECT_THROW(Intersect1D(x2, x1, y2, y1), ResultNotExist);
    EXPECT_THROW(Intersect1D(y1, y2, x1, x2), ResultNotExist);
    EXPECT_THROW(Intersect1D(y1, y2, x2, x1), ResultNotExist);
    EXPECT_THROW(Intersect1D(y2, y1, x1, x2), ResultNotExist);
    EXPECT_THROW(Intersect1D(y2, y1, x2, x1), ResultNotExist);
}

TEST(TestIntersect1D, NotExist) {
    NotExist(0, 1, 2, 3);
}


static void ManyExist(double x1, double x2, double y1, double y2) {
    EXPECT_THROW(Intersect1D(x1, x2, y1, y2), ResultExistMany);
    EXPECT_THROW(Intersect1D(x1, x2, y2, y1), ResultExistMany);
    EXPECT_THROW(Intersect1D(x2, x1, y1, y2), ResultExistMany);
    EXPECT_THROW(Intersect1D(x2, x1, y2, y1), ResultExistMany);
    EXPECT_THROW(Intersect1D(y1, y2, x1, x2), ResultExistMany);
    EXPECT_THROW(Intersect1D(y1, y2, x2, x1), ResultExistMany);
    EXPECT_THROW(Intersect1D(y2, y1, x1, x2), ResultExistMany);
    EXPECT_THROW(Intersect1D(y2, y1, x2, x1), ResultExistMany);
}

TEST(TestIntersect1D, ManyExist) {
    ManyExist(0, 2, 1, 3);
}