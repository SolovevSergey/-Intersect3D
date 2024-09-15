#include "test.h"

// #include <random>

Vector3D GetRandomVec(){
    // return Vector3D(rand()%10, rand()%10, rand()%10);
    return Vector3D(0, 0, 0);
}

void TestOneExist(const Vector3D& a, const Vector3D& b, const Vector3D& c, const Vector3D& d, const Vector3D& result) {
    Vector3D o = GetRandomVec();
    ASSERT_EQ(Intersect(Segment3D(o + a, o + b), Segment3D(o + c, o + d)), result);
    ASSERT_EQ(Intersect(Segment3D(o + a, o + b), Segment3D(o + d, o + c)), result);
    ASSERT_EQ(Intersect(Segment3D(o + b, o + a), Segment3D(o + c, o + d)), result);
    ASSERT_EQ(Intersect(Segment3D(o + b, o + a), Segment3D(o + d, o + c)), result);
    
    ASSERT_EQ(Intersect(Segment3D(o + c, o + d), Segment3D(o + a, o + b)), result);
    ASSERT_EQ(Intersect(Segment3D(o + d, o + c), Segment3D(o + a, o + b)), result);
    ASSERT_EQ(Intersect(Segment3D(o + c, o + d), Segment3D(o + b, o + a)), result);
    ASSERT_EQ(Intersect(Segment3D(o + d, o + c), Segment3D(o + b, o + a)), result);
}


void TestManyExist(const Vector3D& a, const Vector3D& b, const Vector3D& c, const Vector3D& d) {
    Vector3D o = GetRandomVec();
    ASSERT_THROW(Intersect(Segment3D(o + a, o + b), Segment3D(o + c, o + d)), ResultExistMany);
    ASSERT_THROW(Intersect(Segment3D(o + a, o + b), Segment3D(o + d, o + c)), ResultExistMany);
    ASSERT_THROW(Intersect(Segment3D(o + b, o + a), Segment3D(o + c, o + d)), ResultExistMany);
    ASSERT_THROW(Intersect(Segment3D(o + b, o + a), Segment3D(o + d, o + c)), ResultExistMany);
    
    ASSERT_THROW(Intersect(Segment3D(o + c, o + d), Segment3D(o + a, o + b)), ResultExistMany);
    ASSERT_THROW(Intersect(Segment3D(o + d, o + c), Segment3D(o + a, o + b)), ResultExistMany);
    ASSERT_THROW(Intersect(Segment3D(o + c, o + d), Segment3D(o + b, o + a)), ResultExistMany);
    ASSERT_THROW(Intersect(Segment3D(o + d, o + c), Segment3D(o + b, o + a)), ResultExistMany);
}


void TestNotExist(const Vector3D& a, const Vector3D& b, const Vector3D& c, const Vector3D& d) {
    Vector3D o = GetRandomVec();
    ASSERT_THROW(Intersect(Segment3D(o + a, o + b), Segment3D(o + c, o + d)), ResultNotExist);
    ASSERT_THROW(Intersect(Segment3D(o + a, o + b), Segment3D(o + d, o + c)), ResultNotExist);
    ASSERT_THROW(Intersect(Segment3D(o + b, o + a), Segment3D(o + c, o + d)), ResultNotExist);
    ASSERT_THROW(Intersect(Segment3D(o + b, o + a), Segment3D(o + d, o + c)), ResultNotExist);
    
    ASSERT_THROW(Intersect(Segment3D(o + c, o + d), Segment3D(o + a, o + b)), ResultNotExist);
    ASSERT_THROW(Intersect(Segment3D(o + d, o + c), Segment3D(o + a, o + b)), ResultNotExist);
    ASSERT_THROW(Intersect(Segment3D(o + c, o + d), Segment3D(o + b, o + a)), ResultNotExist);
    ASSERT_THROW(Intersect(Segment3D(o + d, o + c), Segment3D(o + b, o + a)), ResultNotExist);
}


int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  // ::testing::InitGoogleMock(&argc, argv);
  
  return RUN_ALL_TESTS();
}