#pragma once
#include "Vector3D.hpp"

class Segment3D final{
    Vector3D start;
    Vector3D end;
public:
    Segment3D(const Vector3D& start, const Vector3D& end);
    
    Vector3D getStart() const;
    Vector3D getEnd() const;
};

std::ostream& operator<<(std::ostream& stream, const Segment3D& segment);