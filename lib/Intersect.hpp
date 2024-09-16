#pragma once
#include "Segment3D.hpp"
#include "Exception.hpp"

// TODO: delete in relise version
double Intersect1D(double x1, double x2, double y1, double y2); 

Vector3D Intersect(const Segment3D& segment1, const Segment3D& segment2);
