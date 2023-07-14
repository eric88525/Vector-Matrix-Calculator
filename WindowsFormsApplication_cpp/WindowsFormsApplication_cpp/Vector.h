#pragma once
#include<string>
#include<vector>
#include"Error.h"
#define PI 3.14159265
#define misRange 0.000000001
class Vector
{
public:
    std::string name;
    std::vector<double> data;
    Vector() {};
    Vector(std::vector<double> data);
    Vector(std::string name, std::vector<double> data);
    System::String^ GetResult();
    friend const Vector operator+(const Vector& x, const Vector& y);
    friend const Vector operator-(const Vector& x, const Vector& y);
    friend const Vector operator*(const Vector& x, const Vector& y);
    friend const double Norm(const Vector& x);
    friend const Vector Normalization(const Vector& x);
    friend const Vector CrossProduct(const Vector& x, const Vector& y);
    friend const Vector Component(const Vector& x, const Vector& y);
    friend const Vector Projection(const Vector& x, const Vector& y);
    friend const double Area(const Vector& x, const Vector& y);
    friend const bool IsParallel(const Vector& x, const Vector& y);
    friend const bool IsOrthogonal(const Vector& x, const Vector& y);
    friend const double Angle(const Vector& x, const Vector& y);
    friend const Vector PN(const Vector& x, const Vector& y);
    friend const bool IsLI(const Vector& x, const Vector& y);
    friend const std::vector<Vector> Ob(std::vector<Vector>);
};