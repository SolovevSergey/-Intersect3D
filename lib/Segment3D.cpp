#include "Segment3D.hpp"

Segment3D::Segment3D(const Vector3D& start, const Vector3D& end): start(start), end(end) {};

Vector3D Segment3D::getStart() const {
    return start;
}

Vector3D Segment3D::getEnd() const {
    return start;
}


std::ostream& operator<<(std::ostream& stream, const Segment3D& segment) {
    stream << "{" << segment.getStart() << "-" << segment.getEnd() << "}";
    return stream;
}