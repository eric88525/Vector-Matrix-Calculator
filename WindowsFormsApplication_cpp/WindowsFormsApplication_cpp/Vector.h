#pragma once
#include<string>
#include<vector>
#include"Error.h"
#define PI 3.14159265
#define misRange 0.000000001
class Vector
{
	std::string name;
	std::vector<double> data;
public:
	Vector() {};
	Vector(std::vector<double> data) :data(data) {}
	Vector(std::string name, std::vector<double> data) :name(name), data(data) {}
	Vector(const Vector& t) :name(t.name), data(t.data) {}
	Vector(double v) { data.push_back(v); }

	System::String^ GetResult();

	friend const Vector operator+(const Vector& x, const Vector& y);
	friend const Vector operator-(const Vector& x, const Vector& y);
	friend const Vector operator*(const Vector& x, const Vector& y);
	friend const Vector Norm(const Vector& x);
	friend const Vector Normalization(const Vector& x);
	friend const Vector CrossProduct(const Vector& x, const Vector& y);
	friend const Vector Component(const Vector& x, const Vector& y);
	friend const Vector Projection(const Vector& x, const Vector& y);
	friend const Vector Area(const Vector& x, const Vector& y);
	friend const bool IsParallel(const Vector& x, const Vector& y);
	friend const bool IsOrthogonal(const Vector& x, const Vector& y);
	friend const Vector Angle(const Vector& x, const Vector& y);
	friend const Vector PN(const Vector& x, const Vector& y);
	friend const bool IsLI(const Vector& x, const Vector& y);
	friend const std::vector<Vector> Ob(std::vector<Vector>);

	void SetName(std::string name) { name = name; }

};