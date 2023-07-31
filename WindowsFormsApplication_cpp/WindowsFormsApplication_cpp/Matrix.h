#pragma once
#include <vector>
#include <algorithm>
#include<math.h>
#include"Error.h"
#include<string>


#define misRange 0.000000001
#define _USE_MATH_DEFINES 
#define M_PI       3.14159265358979323846


// google naming style https://google.github.io/styleguide/cppguide.html#Naming
class Matrix {
	std::string name_;
	std::vector<std::vector<double>> data_;
	size_t row;
	size_t col;
public:

	Matrix() {};
	Matrix(std::vector<std::vector<double>> data) :data_(data), row(data.size()), col(data[0].size()) {};
	Matrix(std::string name, std::vector<std::vector<double>> data) :name_(name), data_(data), row(data.size()), col(data[0].size()) {};
	Matrix(const Matrix& t) :row(t.row), col(t.col), data_(t.data_) {};
	System::String^ GetResult();

	friend const Matrix operator+(const Matrix& x, const Matrix& y);
	friend const Matrix operator-(const Matrix& x, const Matrix& y);
	friend const Matrix operator*(const Matrix& x, const Matrix& y);
	friend const int Rank(Matrix x);
	friend const Matrix Transpose(const Matrix& x);
	friend const Matrix operator/(Matrix x, Matrix y);  // Linear system
	friend const double Determinants(Matrix x);
	friend const Matrix Inverse(Matrix x);
	friend const Matrix Adj(const Matrix& x);
	friend const Matrix Pm(const Matrix& x, double&);
	friend const Matrix Eigen(const Matrix& x, std::vector<double>&);
	friend const Matrix LeastSquare(const Matrix& x, const Matrix& y);
	friend const std::vector<Matrix> Rref(Matrix x);

	size_t GetRow() const { return row; };
	size_t GetCol() const { return col; }
};

