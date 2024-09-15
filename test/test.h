#pragma once
#include "../lib/Intersect.hpp"

#include <gtest/gtest.h>
// #include <gmock/gmock.h>

Vector3D GetRandomVec();

void TestOneExist(const Vector3D& a, const Vector3D& b, const Vector3D& c, const Vector3D& d, const Vector3D& result);

void TestNotExist(const Vector3D& a, const Vector3D& b, const Vector3D& c, const Vector3D& d);

void TestManyExist(const Vector3D& a, const Vector3D& b, const Vector3D& c, const Vector3D& d);