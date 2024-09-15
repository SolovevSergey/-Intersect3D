#pragma once
#include <iostream>

class Vector3D final{
    double X;
    double Y;
    double Z;
public:
    static constexpr double EPS = 1e-10;
    static bool is_equal(double a, double b); 

    Vector3D(double x, double y, double z);
    Vector3D();

    double getX() const;
    double getY() const;
    double getZ() const;

    double operator*(const Vector3D& other) const;
    double abs() const;

    Vector3D operator+(const Vector3D& other) const;
    Vector3D operator-(const Vector3D& other) const;
    
    Vector3D operator*(double other) const;
    Vector3D operator/(double other) const;

    double scalar_projection_on(const Vector3D& other) const;
    Vector3D vector_projection_on(const Vector3D& other) const;

    bool is_parallel_to(const Vector3D& other) const;

    bool operator==(const Vector3D& other) const;
    bool operator!=(const Vector3D& other) const;

    bool is_not_zero() const;
};

std::ostream& operator<<(std::ostream& stream, const Vector3D& vector);