#include "test.h"


void TestOneExist(const Vector3D& a, const Vector3D& b, const Vector3D& c, const Vector3D& d, const Vector3D& result) {
    Vector3D o = Vector3D();
    EXPECT_EQ(Intersect(Segment3D(o + a, o + b), Segment3D(o + c, o + d)), result);
    EXPECT_EQ(Intersect(Segment3D(o + a, o + b), Segment3D(o + d, o + c)), result);
    EXPECT_EQ(Intersect(Segment3D(o + b, o + a), Segment3D(o + c, o + d)), result);
    EXPECT_EQ(Intersect(Segment3D(o + b, o + a), Segment3D(o + d, o + c)), result);
    
    EXPECT_EQ(Intersect(Segment3D(o + c, o + d), Segment3D(o + a, o + b)), result);
    EXPECT_EQ(Intersect(Segment3D(o + d, o + c), Segment3D(o + a, o + b)), result);
    EXPECT_EQ(Intersect(Segment3D(o + c, o + d), Segment3D(o + b, o + a)), result);
    EXPECT_EQ(Intersect(Segment3D(o + d, o + c), Segment3D(o + b, o + a)), result);
}


void TestManyExist(const Vector3D& a, const Vector3D& b, const Vector3D& c, const Vector3D& d) {
    Vector3D o = Vector3D();
    EXPECT_THROW(Intersect(Segment3D(o + a, o + b), Segment3D(o + c, o + d)), ResultExistMany);
    EXPECT_THROW(Intersect(Segment3D(o + a, o + b), Segment3D(o + d, o + c)), ResultExistMany);
    EXPECT_THROW(Intersect(Segment3D(o + b, o + a), Segment3D(o + c, o + d)), ResultExistMany);
    EXPECT_THROW(Intersect(Segment3D(o + b, o + a), Segment3D(o + d, o + c)), ResultExistMany);
    
    EXPECT_THROW(Intersect(Segment3D(o + c, o + d), Segment3D(o + a, o + b)), ResultExistMany);
    EXPECT_THROW(Intersect(Segment3D(o + d, o + c), Segment3D(o + a, o + b)), ResultExistMany);
    EXPECT_THROW(Intersect(Segment3D(o + c, o + d), Segment3D(o + b, o + a)), ResultExistMany);
    EXPECT_THROW(Intersect(Segment3D(o + d, o + c), Segment3D(o + b, o + a)), ResultExistMany);
}


void TestNotExist(const Vector3D& a, const Vector3D& b, const Vector3D& c, const Vector3D& d) {
    Vector3D o = Vector3D();
    EXPECT_THROW(Intersect(Segment3D(o + a, o + b), Segment3D(o + c, o + d)), ResultNotExist);
    EXPECT_THROW(Intersect(Segment3D(o + a, o + b), Segment3D(o + d, o + c)), ResultNotExist);
    EXPECT_THROW(Intersect(Segment3D(o + b, o + a), Segment3D(o + c, o + d)), ResultNotExist);
    EXPECT_THROW(Intersect(Segment3D(o + b, o + a), Segment3D(o + d, o + c)), ResultNotExist);
    
    EXPECT_THROW(Intersect(Segment3D(o + c, o + d), Segment3D(o + a, o + b)), ResultNotExist);
    EXPECT_THROW(Intersect(Segment3D(o + d, o + c), Segment3D(o + a, o + b)), ResultNotExist);
    EXPECT_THROW(Intersect(Segment3D(o + c, o + d), Segment3D(o + b, o + a)), ResultNotExist);
    EXPECT_THROW(Intersect(Segment3D(o + d, o + c), Segment3D(o + b, o + a)), ResultNotExist);
}


int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  // ::testing::InitGoogleMock(&argc, argv);
  

  std::cout << Vector3D::EPS << std::endl;

  return RUN_ALL_TESTS();
}