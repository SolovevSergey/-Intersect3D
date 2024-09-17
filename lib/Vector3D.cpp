#include "Vector3D.hpp"
#include <cmath>


bool Vector3D::is_equal(double a, double b){
    // return std::fabs(a - b) < std::numeric_limits<double>::epsilon();
    return std::fabs(a - b) < Vector3D::EPS;
}; 

Vector3D::Vector3D(double x, double y, double z) : X(x), Y(y), Z(z) {};

Vector3D::Vector3D() : X(0), Y(0), Z(0) {};


double Vector3D::getX() const {
    return X;
}   

double Vector3D::getY() const {
    return Y;
}   

double Vector3D::getZ() const {
    return Z;
}   


double Vector3D::operator*(const Vector3D& other) const {
    return X * other.X + Y * other.Y + Z * other.Z;
}


double Vector3D::abs() const {
    return sqrt(X * X + Y * Y + Z * Z);
}

Vector3D Vector3D::operator+(const Vector3D& other) const{
    return Vector3D(X + other.X, Y + other.Y, Z + other.Z);
};
Vector3D Vector3D::operator-(const Vector3D& other) const{
    return Vector3D(X - other.X, Y - other.Y, Z - other.Z);
};

Vector3D Vector3D::operator*(double other) const{
    return Vector3D(X * other, Y * other, Z * other);
};

Vector3D Vector3D::operator/(double other) const{
    return Vector3D(X / other, Y / other, Z / other);
};

double Vector3D::scalar_projection_on(const Vector3D& other) const{
    return (*this) * other / other.abs();
};

Vector3D Vector3D::vector_projection_on(const Vector3D& other) const{
    return other * ((*this) * other) / (other * other);
};

bool Vector3D::is_parallel_to(const Vector3D& other) const {
    return is_equal( (*this * other)*(*this * other), (*this * *this) * (other * other));
};

bool Vector3D::operator==(const Vector3D& other) const{
    return is_equal(X, other.X) && is_equal(Y, other.Y) && is_equal(Z, other.Z);
};

bool Vector3D::operator!=(const Vector3D& other) const{
    return !(*this == other);
}

bool Vector3D::is_not_zero() const{
    return  *this != Vector3D(0, 0, 0);
}

std::ostream& operator<<(std::ostream& stream, const Vector3D& vector){
    stream << "(" << vector.getX() << "," << vector.getY() << "," << vector.getZ() << ")";
    return stream;
}